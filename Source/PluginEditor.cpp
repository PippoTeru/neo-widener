#include "PluginProcessor.h"
#include "PluginEditor.h"

NeoWidenerAudioProcessorEditor::NeoWidenerAudioProcessorEditor (NeoWidenerAudioProcessor& p)
    : AudioProcessorEditor (&p), audioProcessor (p)
{
    setSize (400, 300);
}

NeoWidenerAudioProcessorEditor::~NeoWidenerAudioProcessorEditor()
{
}

void NeoWidenerAudioProcessorEditor::paint (juce::Graphics& g)
{
    g.fillAll (getLookAndFeel().findColour (juce::ResizableWindow::backgroundColourId));

    g.setColour (juce::Colours::white);
    g.setFont (15.0f);
    g.drawFittedText ("Neo Widener", getLocalBounds(), juce::Justification::centred, 1);
}

void NeoWidenerAudioProcessorEditor::resized()
{
}