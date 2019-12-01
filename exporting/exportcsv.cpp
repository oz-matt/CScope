// SPDX-License-Identifier: GPL-2.0+

#include "exportcsv.h"
#include "exporterregistry.h"
#include "post/ppresult.h"
#include "settings.h"
#include "iconfont/QtAwesome.h"

#include <QCoreApplication>
#include <QTextStream>
#include <QFile>
#include <QFileDialog>
#include <QLocale>

ExporterCSV::ExporterCSV() {}

void ExporterCSV::create(ExporterRegistry *registry) { this->registry = registry; data.reset(); }

QIcon ExporterCSV::icon() { return iconFont->icon(fa::filetexto); }

QString ExporterCSV::name() { return QCoreApplication::tr("Export CSV"); }

ExporterInterface::Type ExporterCSV::type() { return Type::SnapshotExport; }

bool ExporterCSV::samples(const std::shared_ptr<PPresult> data) {
    this->data = std::move(data);
    return false;
}

bool ExporterCSV::save() {
    QStringList filters;
    filters << QCoreApplication::tr("Comma-Separated Values (*.csv)");

    QFileDialog fileDialog(nullptr, QCoreApplication::tr("Export file..."), QString(), filters.join(";;"));
    fileDialog.setFileMode(QFileDialog::AnyFile);
    fileDialog.setAcceptMode(QFileDialog::AcceptSave);
    if (fileDialog.exec() != QDialog::Accepted) return false;

    QFile csvFile(fileDialog.selectedFiles().first());
    if (!csvFile.open(QIODevice::WriteOnly | QIODevice::Text)) return false;

    QTextStream csvStream(&csvFile);
    csvStream.setRealNumberNotation(QTextStream::FixedNotation);
    csvStream.setRealNumberPrecision(10);

    size_t chCount = registry->settings->scope.voltage.size();
    std::vector<const SampleValues *> voltageData(size_t(chCount), nullptr);
    std::vector<const SampleValues *> spectrumData(size_t(chCount), nullptr);
    size_t maxRow = 0;
    bool isSpectrumUsed = false;
    double timeInterval = 0;
    double freqInterval = 0;

    // use semicolon as data separator if comma is already used as decimal separator - e.g. with german locale
    const char *sep = QLocale::system().decimalPoint() == ',' ? ";" : ",";

    for (ChannelID channel = 0; channel < chCount; ++channel) {
        if (data->data(channel)) {
            if (registry->settings->scope.voltage[channel].used) {
                voltageData[channel] = &(data->data(channel)->voltage);
                maxRow = std::max(maxRow, voltageData[channel]->sample.size());
                timeInterval = data->data(channel)->voltage.interval;
            }
            if (registry->settings->scope.spectrum[channel].used) {
                spectrumData[channel] = &(data->data(channel)->spectrum);
                maxRow = std::max(maxRow, spectrumData[channel]->sample.size());
                freqInterval = data->data(channel)->spectrum.interval;
                isSpectrumUsed = true;
            }
        }
    }

    // Start with channel names
    csvStream << "\"t / s\"";
    for (ChannelID channel = 0; channel < chCount; ++channel) {
        if (voltageData[channel] != nullptr) {
            csvStream << sep << "\"" << registry->settings->scope.voltage[channel].name << " / V\"";
        }
    }
    if (isSpectrumUsed) {
        csvStream << sep << "\"f / Hz\"";
        for (ChannelID channel = 0; channel < chCount; ++channel) {
            if (spectrumData[channel] != nullptr) {
                csvStream << sep << "\"" << registry->settings->scope.spectrum[channel].name << " / dB\"";
            }
        }
    }
    csvStream << "\n";

    for (unsigned int row = 0; row < maxRow; ++row) {
        csvStream << QLocale::system().toString( timeInterval * row );
        for (ChannelID channel = 0; channel < chCount; ++channel) {
            if (voltageData[channel] != nullptr) {
                csvStream << sep;
                if (row < voltageData[channel]->sample.size()) {
                    csvStream << QLocale::system().toString( voltageData[channel]->sample[row] );
                }
            }
        }

        if (isSpectrumUsed) {
            csvStream << sep << QLocale::system().toString( freqInterval * row );
            for (ChannelID channel = 0; channel < chCount; ++channel) {
                if (spectrumData[channel] != nullptr) {
                    csvStream << sep;
                    if (row < spectrumData[channel]->sample.size()) { 
                        csvStream << QLocale::system().toString( spectrumData[channel]->sample[row] );
                    }
                }
            }
        }
        csvStream << "\n";
    }

    csvFile.close();

    return true;
}


float ExporterCSV::progress() { 
    return data ? 1.0f : 0;
}
