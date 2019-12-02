#include "mainwindow.h"
#include "hantekdso/hantekdsocontrol.h"
#include <QApplication>
#include "settings.h"
#include "viewconstants.h"

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
    MainWindow w;
    w.show();
    return a.exec();
}
