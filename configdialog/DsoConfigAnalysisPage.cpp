// SPDX-License-Identifier: GPL-2.0+

#include "DsoConfigAnalysisPage.h"

DsoConfigAnalysisPage::DsoConfigAnalysisPage(DsoSettings *settings, QWidget *parent)
    : QWidget(parent), settings(settings) {
    // Initialize lists for comboboxes
    QStringList windowFunctionStrings;
    windowFunctionStrings << tr("Rectangular") << tr("Hamming") << tr("Hann") << tr("Cosine") << tr("Lanczos")
                          << tr("Bartlett") << tr("Triangular") << tr("Gauss") << tr("Bartlett-Hann") << tr("Blackman")
                          //<< tr("Kaiser")
                          << tr("Nuttall") << tr("Blackman-Harris") << tr("Blackman-Nuttall") << tr("Flat top");

    // Initialize elements
    windowFunctionLabel = new QLabel(tr("<b>Window function</b>"));
    windowFunctionComboBox = new QComboBox();
    windowFunctionComboBox->addItems(windowFunctionStrings);
    windowFunctionComboBox->setCurrentIndex((int)settings->post.spectrumWindow);

    referenceLevelLabel = new QLabel(tr("<b>Reference level</b><br/>0 dBu = -2.2 dBV<br/>0 dBm(@600 Ω) = -2.2 dBV<br/>0 dBm(@50 Ω) = -13 dBV"));
    referenceLevelSpinBox = new QDoubleSpinBox();
    referenceLevelSpinBox->setDecimals(1);
    referenceLevelSpinBox->setMinimum(-100.0);
    referenceLevelSpinBox->setMaximum(100.0);
    referenceLevelSpinBox->setValue(settings->post.spectrumReference);
    referenceLevelUnitLabel = new QLabel(tr("dBV"));
    referenceLevelLayout = new QHBoxLayout();
    referenceLevelLayout->addWidget(referenceLevelSpinBox);
    referenceLevelLayout->addWidget(referenceLevelUnitLabel);

    minimumMagnitudeLabel = new QLabel(tr("<b>Minimum magnitude</b>"));
    minimumMagnitudeSpinBox = new QDoubleSpinBox();
    minimumMagnitudeSpinBox->setDecimals(1);
    minimumMagnitudeSpinBox->setMinimum(-100.0);
    minimumMagnitudeSpinBox->setMaximum(100.0);
    minimumMagnitudeSpinBox->setValue(settings->post.spectrumLimit);
    minimumMagnitudeUnitLabel = new QLabel(tr("dBV"));
    minimumMagnitudeLayout = new QHBoxLayout();
    minimumMagnitudeLayout->addWidget(minimumMagnitudeSpinBox);
    minimumMagnitudeLayout->addWidget(minimumMagnitudeUnitLabel);

    spectrumLayout = new QGridLayout();
    spectrumLayout->addWidget(windowFunctionLabel, 0, 0);
    spectrumLayout->addWidget(windowFunctionComboBox, 0, 1);
    spectrumLayout->addWidget(referenceLevelLabel, 1, 0);
    spectrumLayout->addLayout(referenceLevelLayout, 1, 1);
    spectrumLayout->addWidget(minimumMagnitudeLabel, 2, 0);
    spectrumLayout->addLayout(minimumMagnitudeLayout, 2, 1);

    spectrumGroup = new QGroupBox(tr("Spectrum"));
    spectrumGroup->setLayout(spectrumLayout);

    mainLayout = new QVBoxLayout();
    mainLayout->addWidget(spectrumGroup);
    mainLayout->addStretch(1);

    setLayout(mainLayout);
}

/// \brief Saves the new settings.
void DsoConfigAnalysisPage::saveSettings() {
    settings->post.spectrumWindow = (Dso::WindowFunction)windowFunctionComboBox->currentIndex();
    settings->post.spectrumReference = referenceLevelSpinBox->value();
    settings->post.spectrumLimit = minimumMagnitudeSpinBox->value();
}
