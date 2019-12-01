// SPDX-License-Identifier: GPL-2.0+

#include <QCoreApplication>
#include <QDebug>
#include <QString>
#include <QTemporaryFile>
#include <libusb-1.0/libusb.h>
#include <memory>

#include "ezusb.h"
#include "uploadFirmware.h"
#include "usbdevice.h"

#include "dsomodel.h"

#define TR(str) QCoreApplication::translate("UploadFirmware", str)

bool UploadFirmware::startUpload(USBDevice *device) {
    if (device->isConnected() || !device->needsFirmware()) return false;

    // Open device
    libusb_device_handle *handle;
    int errorCode = libusb_open(device->getRawDevice(), &handle);
    if (errorCode != LIBUSB_SUCCESS) {
        handle = nullptr;
        errorMessage = TR("Couldn't open device: %1").arg(libUsbErrorString(errorCode));
        return false;
    }

    // Write firmware from resources to temp files
    QFile firmwareRes(
        QString(":/firmware/%1-firmware.hex").arg(QString::fromStdString(device->getModel()->firmwareToken)));
    auto temp_firmware_path = std::unique_ptr<QTemporaryFile>(QTemporaryFile::createNativeFile(firmwareRes));
    if (!temp_firmware_path) return false;
    temp_firmware_path->open();

    /* We need to claim the first interface */
    libusb_set_auto_detach_kernel_driver(handle, 1);
    int status = libusb_claim_interface(handle, 0);
    if (status != LIBUSB_SUCCESS) {
        errorMessage = TR("libusb_claim_interface() failed: %1").arg(libusb_error_name(status));
        libusb_close(handle);
        return false;
    }

    // Write firmware into internal RAM using first stage loader built into EZ-USB hardware
    status = ezusb_load_ram(handle, temp_firmware_path->fileName().toUtf8().constData(), FX_TYPE_FX2LP, 0);
    if (status != LIBUSB_SUCCESS) {
        errorMessage = TR("Writing the main firmware failed: %1").arg(libusb_error_name(status));
        libusb_release_interface(handle, 0);
        libusb_close(handle);
        return false;
    }

    libusb_release_interface(handle, 0);
    libusb_close(handle);

    return status == LIBUSB_SUCCESS;
}

const QString &UploadFirmware::getErrorMessage() const { return errorMessage; }

