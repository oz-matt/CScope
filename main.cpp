#include <QApplication>
#include <QCommandLineParser>
#include <QDebug>
#include <QLibraryInfo>
#include <QLocale>
#include <QSurfaceFormat>
#include <QTranslator>
#ifdef __linux__
#include <QStyleFactory>
#endif
#include <iostream>
#include <libusb-1.0/libusb.h>
#include <memory>

// Settings
#include "settings.h"
#include "viewconstants.h"

// DSO core logic
#include "dsomodel.h"
#include "hantekdsocontrol.h"
#include "usb/usbdevice.h"

// Post processing
#include "post/graphgenerator.h"
#include "post/mathchannelgenerator.h"
#include "post/postprocessing.h"
#include "post/spectrumgenerator.h"

// Exporter
#include "exporting/exportcsv.h"
#include "exporting/exporterprocessor.h"
#include "exporting/exporterregistry.h"
#include "exporting/exportimage.h"
#include "exporting/exportprint.h"

// GUI
#include "iconfont/QtAwesome.h"
#include "mainwindow.h"
#include "selectdevice/selectsupporteddevice.h"

// OpenGL setup
#include "glscope.h"

/// \brief Initialize the device with the current settings.
void applySettingsToDevice(HantekDsoControl *dsoControl, DsoSettingsScope *scope,
                           const Dso::ControlSpecification *spec) {
    bool mathUsed = scope->anyUsed(spec->channels);
    for (ChannelID channel = 0; channel < spec->channels; ++channel) {
        dsoControl->setGain(channel, scope->gain(channel) * DIVS_VOLTAGE);
        dsoControl->setTriggerLevel(channel, scope->voltage[channel].trigger);
        dsoControl->setChannelUsed(channel, mathUsed | scope->anyUsed(channel));
        dsoControl->setChannelInverted(channel, scope->voltage[channel].inverted);
        dsoControl->setProbe( channel, scope->voltage[channel].probeUsed, scope->voltage[channel].probeAttn );
    }

    dsoControl->setRecordTime(scope->horizontal.timebase * DIVS_TIME);
    dsoControl->setTriggerMode(scope->trigger.mode);
    dsoControl->setTriggerPosition(scope->trigger.position);
    dsoControl->setTriggerSlope(scope->trigger.slope);
    dsoControl->setTriggerSource(scope->trigger.source, scope->trigger.smooth);
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    HantekDsoControl dsoControl(nullptr);
    DsoSettings settings(nullptr);
    ExporterRegistry exportRegistry(nullptr, &settings);

    MainWindow w(&dsoControl, &settings, &exportRegistry);
    w.show();
    return a.exec();
}
