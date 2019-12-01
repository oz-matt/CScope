// SPDX-License-Identifier: GPL-2.0+

#include <QDebug>
#include <QMutex>
#include <exception>

#include "post/graphgenerator.h"
#include "post/ppresult.h"
#include "hantekdso/controlspecification.h"
#include "scopesettings.h"
#include "utils/printutils.h"
#include "viewconstants.h"


static const SampleValues &useSpecSamplesOf(ChannelID channel, const PPresult *result,
                                            const DsoSettingsScope *scope) {
    static SampleValues emptyDefault;
    if (!scope->spectrum[channel].used || !result->data(channel)) return emptyDefault;
    return result->data(channel)->spectrum;
}


static const SampleValues &useVoltSamplesOf(ChannelID channel, const PPresult *result,
                                            const DsoSettingsScope *scope) {
    static SampleValues emptyDefault;
    if (!scope->voltage[channel].used || !result->data(channel)) return emptyDefault;
    return result->data(channel)->voltage;
}


GraphGenerator::GraphGenerator(const DsoSettingsScope *scope) : scope(scope) {}


void GraphGenerator::generateGraphsTYvoltage(PPresult *result) {
    //printf( "GraphGenerator::generateGraphsTYvoltage()\n" );
    unsigned skipSamples = result->skipSamples;

    result->vaChannelVoltage.resize(scope->voltage.size());
    for (ChannelID channel = 0; channel < scope->voltage.size(); ++channel) {
        ChannelGraph &target = result->vaChannelVoltage[channel];
        const SampleValues &samples = useVoltSamplesOf(channel, result, scope);

        // Check if this channel is used and available at the data analyzer
        if (samples.sample.empty()) {
            // Delete all vector arrays
            target.clear();
            continue;
        }
        // Check if the sample count has changed
        size_t sampleCount = samples.sample.size();
        if (sampleCount > 500000) {
            qWarning() << "Sample count too high!";
            throw new std::runtime_error("Sample count too high!");
        }
        sampleCount -= skipSamples;
        size_t neededSize = sampleCount * 2;

        // Set size directly to avoid reallocations
        target.reserve(neededSize);

        // What's the horizontal distance between sampling points?
        float horizontalFactor = (float)(samples.interval / scope->horizontal.timebase);

        // Fill vector array
        std::vector<double>::const_iterator dataIterator = samples.sample.begin();
        const float gain = (float)scope->gain(channel);
        const float offset = (float)scope->voltage[channel].offset;

        std::advance(dataIterator, skipSamples);

        for (unsigned int position = 0; position < sampleCount; ++position) {
            target.push_back(QVector3D(position * horizontalFactor - DIVS_TIME / 2,
                                       (float)*(dataIterator++) / gain + offset, 0.0));
        }
    }
}


void GraphGenerator::generateGraphsTYspectrum(PPresult *result) {
    //printf( "GraphGenerator::generateGraphsTYspectrum()\n" );
    ready = true;
    result->vaChannelSpectrum.resize(scope->spectrum.size());
    for (ChannelID channel = 0; channel < scope->voltage.size(); ++channel) {
        ChannelGraph &target = result->vaChannelSpectrum[channel];
        const SampleValues &samples = useSpecSamplesOf(channel, result, scope);

        // Check if this channel is used and available at the data analyzer
        if (samples.sample.empty()) {
            // Delete all vector arrays
            target.clear();
            continue;
        }
        // Check if the sample count has changed
        size_t sampleCount = samples.sample.size();
        if (sampleCount > 500000) {
            qWarning() << "Sample count too high!";
            throw new std::runtime_error("Sample count too high!");
        }
        size_t neededSize = sampleCount * 2;

        // Set size directly to avoid reallocations
        target.reserve(neededSize);

        // What's the horizontal distance between sampling points?
        float horizontalFactor = (float)(samples.interval / scope->horizontal.frequencybase);

        // Fill vector array
        std::vector<double>::const_iterator dataIterator = samples.sample.begin();
        const float magnitude = (float)scope->spectrum[channel].magnitude;
        const float offset = (float)scope->spectrum[channel].offset;

        for (unsigned int position = 0; position < sampleCount; ++position) {
            target.push_back(QVector3D(position * horizontalFactor - DIVS_TIME / 2,
                                       (float)*(dataIterator++) / magnitude + offset, 0.0));
        }
    }
}


void GraphGenerator::process(PPresult *data) {
    //printf( "GraphGenerator::process()\n" );
    if (scope->horizontal.format == Dso::GraphFormat::TY) {
        ready = true;
        generateGraphsTYvoltage(data);
        generateGraphsTYspectrum(data);
    } else
        generateGraphsXY(data, scope);
}


void GraphGenerator::generateGraphsXY(PPresult *result, const DsoSettingsScope *scope) {
    result->vaChannelVoltage.resize(scope->voltage.size());

    // Delete all spectrum graphs
    for (ChannelGraph &data : result->vaChannelSpectrum) data.clear();

    // Generate voltage graphs for pairs of channels
    for (ChannelID channel = 0; channel < scope->voltage.size(); channel += 2) {
        // We need pairs of channels.
        if (channel + 1 == scope->voltage.size()) {
            result->vaChannelVoltage[channel].clear();
            continue;
        }

        const ChannelID xChannel = channel;
        const ChannelID yChannel = channel + 1;

        const SampleValues &xSamples = useVoltSamplesOf(xChannel, result, scope);
        const SampleValues &ySamples = useVoltSamplesOf(yChannel, result, scope);

        // The channels need to be active
        if (!xSamples.sample.size() || !ySamples.sample.size()) {
            result->vaChannelVoltage[channel].clear();
            result->vaChannelVoltage[channel + 1].clear();
            continue;
        }

        // Check if the sample count has changed
        const size_t sampleCount = std::min(xSamples.sample.size(), ySamples.sample.size());
        ChannelGraph &drawLines = result->vaChannelVoltage[channel];
        drawLines.reserve(sampleCount * 2);

        // Fill vector array
        std::vector<double>::const_iterator xIterator = xSamples.sample.begin();
        std::vector<double>::const_iterator yIterator = ySamples.sample.begin();
        const double xGain = scope->gain(xChannel);
        const double yGain = scope->gain(yChannel);
        const double xOffset = scope->voltage[xChannel].offset;
        const double yOffset = scope->voltage[yChannel].offset;

        for (unsigned int position = 0; position < sampleCount; ++position) {
            drawLines.push_back(QVector3D((float)(*(xIterator++) / xGain + xOffset),
                                          (float)(*(yIterator++) / yGain + yOffset), 0.0));
        }
    }
}
