// SPDX-License-Identifier: GPL-2.0+

#include <QCheckBox>
#include <QCloseEvent>
#include <QComboBox>
#include <QDockWidget>
#include <QLabel>
#include <QSignalBlocker>

#include <cmath>

#include "TriggerDock.h"
#include "dockwindows.h"

#include "hantekdso/controlspecification.h"
#include "settings.h"
#include "sispinbox.h"
#include "utils/printutils.h"

TriggerDock::TriggerDock(DsoSettingsScope *scope, const Dso::ControlSpecification *spec, QWidget *parent,
                         Qt::WindowFlags flags)
    : QDockWidget(tr("Trigger"), parent, flags), scope(scope), mSpec(spec) {

    // Initialize lists for comboboxes
    for (ChannelID channel = 0; channel < mSpec->channels; ++channel)
        this->sourceStandardStrings << tr("CH%1").arg(channel + 1);
    // add "smooth" source
    for (ChannelID channel = 0; channel < mSpec->channels; ++channel)
        this->sourceStandardStrings << tr("CH%1 smooth").arg(channel + 1);

    // Initialize elements
    this->modeLabel = new QLabel(tr("Mode"));
    this->modeComboBox = new QComboBox();
    for (Dso::TriggerMode mode : mSpec->triggerModes) this->modeComboBox->addItem(Dso::triggerModeString(mode));

    this->slopeLabel = new QLabel(tr("Slope"));
    this->slopeComboBox = new QComboBox();
    for (Dso::Slope slope : Dso::SlopeEnum) this->slopeComboBox->addItem(Dso::slopeString(slope));

    this->sourceLabel = new QLabel(tr("Source"));
    this->sourceComboBox = new QComboBox();
    this->sourceComboBox->addItems(this->sourceStandardStrings);

    this->dockLayout = new QGridLayout();
    this->dockLayout->setColumnMinimumWidth(0, 64);
    this->dockLayout->setColumnStretch(1, 1);
    this->dockLayout->addWidget(this->modeLabel, 0, 0);
    this->dockLayout->addWidget(this->modeComboBox, 0, 1);
    this->dockLayout->addWidget(this->sourceLabel, 1, 0);
    this->dockLayout->addWidget(this->sourceComboBox, 1, 1);
    this->dockLayout->addWidget(this->slopeLabel, 2, 0);
    this->dockLayout->addWidget(this->slopeComboBox, 2, 1);

    this->dockWidget = new QWidget();
    SetupDockWidget(this, dockWidget, dockLayout);

    // Set values
    setMode(scope->trigger.mode);
    setSlope(scope->trigger.slope);
    setSource(scope->trigger.source);

    // Connect signals and slots
    connect(this->modeComboBox, static_cast<void (QComboBox::*)(int)>(&QComboBox::currentIndexChanged),
            [this, spec](int index) {
                this->scope->trigger.mode = mSpec->triggerModes[(unsigned)index];
                emit modeChanged(this->scope->trigger.mode);
            });
    connect(this->slopeComboBox, static_cast<void (QComboBox::*)(int)>(&QComboBox::currentIndexChanged),
            [this](int index) {
                this->scope->trigger.slope = (Dso::Slope)index;
                emit slopeChanged(this->scope->trigger.slope);
            });
    connect(this->sourceComboBox, static_cast<void (QComboBox::*)(int)>(&QComboBox::currentIndexChanged),
            [this](int index) {
                bool smooth = index >= (int)mSpec->channels;
                this->scope->trigger.source = (unsigned)index & (mSpec->channels - 1) ;
                emit sourceChanged((unsigned)index & (mSpec->channels - 1), smooth );
            });
}

/// \brief Don't close the dock, just hide it
/// \param event The close event that should be handled.
void TriggerDock::closeEvent(QCloseEvent *event) {
    this->hide();

    event->accept();
}

void TriggerDock::setMode(Dso::TriggerMode mode) {
    int index = std::find(mSpec->triggerModes.begin(), mSpec->triggerModes.end(), mode) - mSpec->triggerModes.begin();
    QSignalBlocker blocker(modeComboBox);
    modeComboBox->setCurrentIndex(index);
}

void TriggerDock::setSlope(Dso::Slope slope) {
    QSignalBlocker blocker(slopeComboBox);
    slopeComboBox->setCurrentIndex((int)slope);
}

void TriggerDock::setSource(unsigned int id) {
    if ( id >= (unsigned int)this->sourceStandardStrings.count() )
        return;
    QSignalBlocker blocker(sourceComboBox);
    sourceComboBox->setCurrentIndex(id);
}
