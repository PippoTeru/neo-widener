#pragma once

#include <JuceHeader.h>
#include "PluginProcessor.h"

class NeoWidenerAudioProcessorEditor  : public juce::AudioProcessorEditor
{
public:
    NeoWidenerAudioProcessorEditor (NeoWidenerAudioProcessor&);
    ~NeoWidenerAudioProcessorEditor() override;

    void paint (juce::Graphics&) override;
    void resized() override;

private:
    NeoWidenerAudioProcessor& audioProcessor;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (NeoWidenerAudioProcessorEditor)
};