// SPDX-License-Identifier: GPL-2.0+
#pragma once

#include "ui_selectsupporteddevice.h"

#include <QDialog>

#include <memory>
#include "usb/usbdevice.h"

struct libusb_context;
class NewDeviceModelFromExisting;

/**
 * Offers the user a device selection dialog. If you call any of the -Modal methods,
 * the method will block and show a dialog for selection or for a usb error
 * message. The method returns as soon as the user closes the dialog.
 *
 * An example to get a user selected device:
 * std::unique_ptr<USBDevice> device = SelectDevice().showSelectDeviceModal(context);
 */
class SelectSupportedDevice : public QDialog
{
    Q_OBJECT

public:
    explicit SelectSupportedDevice(QWidget *parent = 0);
    std::unique_ptr<USBDevice> showSelectDeviceModal(libusb_context *context);
    void showLibUSBFailedDialogModel(int error);
private:
    void updateDeviceList();
    void updateSupportedDevices();
    std::unique_ptr<Ui::SelectSupportedDevice> ui;
    UniqueUSBid selectedDevice = 0;
    NewDeviceModelFromExisting* newDeviceFromExistingDialog;
};
