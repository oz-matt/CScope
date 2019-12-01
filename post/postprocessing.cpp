#include "postprocessing.h"

PostProcessing::PostProcessing(unsigned channelCount) : channelCount(channelCount) {
    qRegisterMetaType<std::shared_ptr<PPresult>>();
}

void PostProcessing::registerProcessor(Processor *processor) { processors.push_back(processor); }

void PostProcessing::convertData(const DSOsamples *source, PPresult *destination) {
    //printf( "PostProcessing::convertData()\n" );
    QReadLocker locker(&source->lock);
    if ( source->triggerPosition >=0 ) {
        destination->softwareTriggerTriggered = source->liveTrigger;
        destination->skipSamples = source->triggerPosition;
    } else {
        destination->softwareTriggerTriggered = false;
        destination->skipSamples = 0;
    }

    for (ChannelID channel = 0; channel < source->data.size(); ++channel) {
        const std::vector<double> &rawChannelData = source->data.at(channel);

        if (rawChannelData.empty()) { continue; }
        DataChannel *const channelData = destination->modifyData(channel);
        channelData->voltage.interval = 1.0 / source->samplerate;
        channelData->voltage.sample = rawChannelData;
        //printf( "PP CH%d: %d\n", channel+1, source->clipped );
        channelData->valid = ! ( source->clipped & (0x01 << channel) );
    }
}

void PostProcessing::input(const DSOsamples *data) {
    //printf( "PostProcessing::input()\n" );
    currentData.reset(new PPresult(channelCount));
    convertData(data, currentData.get());
    for (Processor *p : processors) 
        p->process(currentData.get());
    std::shared_ptr<PPresult> res = std::move(currentData);
    emit processingFinished(res);
}
