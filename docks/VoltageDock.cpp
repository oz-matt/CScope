// SPDX-License-Identifier: GPL-2.0+

#include <QCheckBox>
#include <QCloseEvent>
#include <QComboBox>
#include <QDockWidget>
#include <QLabel>
#include <QSignalBlocker>

#include <cmath>

#include "VoltageDock.h"
#include "dockwindows.h"

#include "settings.h"
#include "sispinbox.h"
#include "utils/printutils.h"

// probe attenuation
#define ATTENUATION 10.0

template<typename... Args> struct SELECT {
    template<typename C, typename R>
    static constexpr auto OVERLOAD_OF( R (C::*pmf)(Args...) ) -> decltype(pmf) {
        return pmf;
    }
};

VoltageDock::VoltageDock(DsoSettingsScope *scope, const Dso::ControlSpecification *spec, QWidget *parent, Qt::WindowFlags flags)
    : QDockWidget(tr("Voltage"), parent, flags), scope(scope), spec(spec) {

    // Initialize lists for comboboxes
    for (Dso::Coupling c: spec->couplings)
        couplingStrings.append(Dso::couplingString(c));

    for( auto e: Dso::MathModeEnum ) {
        modeStrings.append(Dso::mathModeString(e));
    }

    for (double gainStep: scope->gainSteps) {
        gainStrings << valueToString(gainStep, UNIT_VOLTS, 0);
        attnStrings << valueToString(gainStep * ATTENUATION, UNIT_VOLTS, 0);
    }
    dockLayout = new QGridLayout();
    dockLayout->setColumnMinimumWidth(0, 64);
    dockLayout->setColumnStretch(1, 1);

    // Initialize elements
    int row = 0;
    for (ChannelID channel = 0; channel < scope->voltage.size(); ++channel) {
        ChannelBlock b;

        b.miscComboBox=(new QComboBox());
        b.gainComboBox=(new QComboBox());
        b.invertCheckBox=(new QCheckBox(tr("Invert")));
        b.attnCheckBox=(new QCheckBox(tr("X10 probe")));
        b.usedCheckBox=(new QCheckBox(scope->voltage[channel].name));

        channelBlocks.push_back(std::move(b));

        if (channel < spec->channels)
            b.miscComboBox->addItems(couplingStrings);
        else
            b.miscComboBox->addItems(modeStrings);

        b.gainComboBox->addItems(gainStrings);

        dockLayout->addWidget( b.usedCheckBox, row, 0 );
        dockLayout->addWidget( b.gainComboBox, row++, 1 );
        dockLayout->addWidget( b.invertCheckBox, row, 0 );
        if (channel < spec->channels) {
            dockLayout->addWidget( b.attnCheckBox, row++, 1) ;
        } else {
            dockLayout->addWidget( b.miscComboBox, row++, 1 );
            setMode(scope->voltage[channel].couplingOrMathIndex);
        }

        setGain(channel, scope->voltage[channel].gainStepIndex);
        setUsed(channel, scope->voltage[channel].used);
        setAttn(channel, scope->voltage[channel].probeUsed);
        setInverted(channel, scope->voltage[channel].inverted);
        //printf("VD::setInverted %d %d\n", channel, scope->voltage[channel].inverted);

        connect(b.gainComboBox, SELECT<int>::OVERLOAD_OF(&QComboBox::currentIndexChanged), [this,channel](int index) {
            this->scope->voltage[channel].gainStepIndex = (unsigned)index;
            emit gainChanged(channel, this->scope->gain(channel));
        });
        connect(b.attnCheckBox, &QAbstractButton::toggled, [this,channel](bool attn) {
            this->setAttn( channel, attn );
            this->scope->voltage[channel].probeUsed = attn;
            this->scope->voltage[channel].probeAttn = attn ? ATTENUATION : 1;
            emit gainChanged(channel, this->scope->gain(channel));
            emit probeAttnChanged( channel, attn, attn ? ATTENUATION : 1 );
        });
        connect(b.invertCheckBox, &QAbstractButton::toggled, [this,channel](bool checked) {
            this->scope->voltage[channel].inverted = checked;
            emit invertedChanged( channel, checked );
        });
        connect(b.miscComboBox, SELECT<int>::OVERLOAD_OF(&QComboBox::currentIndexChanged), [this,channel,spec,scope](int index){
            this->scope->voltage[channel].couplingOrMathIndex = (unsigned)index;
            if (channel < spec->channels) {
                //printf("miscComboBox CH%d, index %d\n", channel, index );
                //emit couplingChanged(channel, scope->coupling(channel, spec));
            } else {
                emit modeChanged(Dso::getMathMode(this->scope->voltage[channel]));
            }
        });
        connect(b.usedCheckBox, &QAbstractButton::toggled, [this,channel](bool checked) {
            this->scope->voltage[channel].used = checked;
            emit usedChanged(channel, checked);
        });
    }

    dockWidget = new QWidget();
    SetupDockWidget(this, dockWidget, dockLayout);
}

/// \brief Don't close the dock, just hide it
/// \param event The close event that should be handled.
void VoltageDock::closeEvent(QCloseEvent *event) {
    hide();
    event->accept();
}

void VoltageDock::setCoupling(ChannelID channel, unsigned couplingIndex) {
    if (channel >= spec->channels) return;
    if (couplingIndex >= spec->couplings.size()) return;
    QSignalBlocker blocker(channelBlocks[channel].miscComboBox);
    channelBlocks[channel].miscComboBox->setCurrentIndex((int)couplingIndex);
}

void VoltageDock::setGain(ChannelID channel, unsigned gainStepIndex) {
    if (channel >= scope->voltage.size()) return;
    if (gainStepIndex >= scope->gainSteps.size()) return;
    QSignalBlocker blocker(channelBlocks[channel].gainComboBox);
    channelBlocks[channel].gainComboBox->setCurrentIndex((unsigned)gainStepIndex);
}

void VoltageDock::setAttn(ChannelID channel, bool attn) {
    if (channel >= scope->voltage.size()) return;
    QSignalBlocker blocker(channelBlocks[channel].gainComboBox);
    int index = channelBlocks[channel].gainComboBox->currentIndex();
    channelBlocks[channel].gainComboBox->clear();
    channelBlocks[channel].gainComboBox->addItems( attn ? attnStrings : gainStrings );
    channelBlocks[channel].gainComboBox->setCurrentIndex( index );
    channelBlocks[channel].attnCheckBox->setChecked(attn);
    this->scope->voltage[channel].probeUsed = attn;
    this->scope->voltage[channel].probeAttn = attn ? ATTENUATION : 1.0;
}

void VoltageDock::setMode(unsigned mathModeIndex) {
    QSignalBlocker blocker(channelBlocks[spec->channels].miscComboBox);
    channelBlocks[spec->channels].miscComboBox->setCurrentIndex((int)mathModeIndex);
}

void VoltageDock::setUsed(ChannelID channel, bool used) {
    if (channel >= scope->voltage.size()) return;
    QSignalBlocker blocker(channelBlocks[channel].usedCheckBox);
    channelBlocks[channel].usedCheckBox->setChecked(used);
}

void VoltageDock::setInverted(ChannelID channel, bool inverted) {
    if (channel >= scope->voltage.size()) return;
    QSignalBlocker blocker(channelBlocks[channel].invertCheckBox);
    channelBlocks[channel].invertCheckBox->setChecked(inverted);
}
