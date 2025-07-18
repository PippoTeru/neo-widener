#include "PluginProcessor.h"
#include "PluginEditor.h"

NeoWidenerAudioProcessor::NeoWidenerAudioProcessor()
#ifndef JucePlugin_PreferredChannelConfigurations
     : AudioProcessor (BusesProperties()
                     #if ! JucePlugin_IsMidiEffect
                      #if ! JucePlugin_IsSynth
                       .withInput  ("Input",  juce::AudioChannelSet::stereo(), true)
                      #endif
                       .withOutput ("Output", juce::AudioChannelSet::stereo(), true)
                     #endif
                       )
#endif
{
}

NeoWidenerAudioProcessor::~NeoWidenerAudioProcessor()
{
}

const juce::String NeoWidenerAudioProcessor::getName() const
{
    return JucePlugin_Name;
}

bool NeoWidenerAudioProcessor::acceptsMidi() const
{
   #if JucePlugin_WantsMidiInput
    return true;
   #else
    return false;
   #endif
}

bool NeoWidenerAudioProcessor::producesMidi() const
{
   #if JucePlugin_ProducesMidiOutput
    return true;
   #else
    return false;
   #endif
}

bool NeoWidenerAudioProcessor::isMidiEffect() const
{
   #if JucePlugin_IsMidiEffect
    return true;
   #else
    return false;
   #endif
}

double NeoWidenerAudioProcessor::getTailLengthSeconds() const
{
    return 0.0;
}

int NeoWidenerAudioProcessor::getNumPrograms()
{
    return 1;
}

int NeoWidenerAudioProcessor::getCurrentProgram()
{
    return 0;
}

void NeoWidenerAudioProcessor::setCurrentProgram (int index)
{
}

const juce::String NeoWidenerAudioProcessor::getProgramName (int index)
{
    return {};
}

void NeoWidenerAudioProcessor::changeProgramName (int index, const juce::String& newName)
{
}

void NeoWidenerAudioProcessor::prepareToPlay (double sampleRate, int samplesPerBlock)
{
}

void NeoWidenerAudioProcessor::releaseResources()
{
}

#ifndef JucePlugin_PreferredChannelConfigurations
bool NeoWidenerAudioProcessor::isBusesLayoutSupported (const BusesLayout& layouts) const
{
  #if JucePlugin_IsMidiEffect
    juce::ignoreUnused (layouts);
    return true;
  #else
    if (layouts.getMainOutputChannelSet() != juce::AudioChannelSet::mono()
     && layouts.getMainOutputChannelSet() != juce::AudioChannelSet::stereo())
        return false;

   #if ! JucePlugin_IsSynth
    if (layouts.getMainOutputChannelSet() != layouts.getMainInputChannelSet())
        return false;
   #endif

    return true;
  #endif
}
#endif

void NeoWidenerAudioProcessor::processBlock (juce::AudioBuffer<float>& buffer, juce::MidiBuffer& midiMessages)
{
    juce::ScopedNoDenormals noDenormals;
    auto totalNumInputChannels  = getTotalNumInputChannels();
    auto totalNumOutputChannels = getTotalNumOutputChannels();

    for (auto i = totalNumInputChannels; i < totalNumOutputChannels; ++i)
        buffer.clear (i, 0, buffer.getNumSamples());
}

bool NeoWidenerAudioProcessor::hasEditor() const
{
    return true;
}

juce::AudioProcessorEditor* NeoWidenerAudioProcessor::createEditor()
{
    return new NeoWidenerAudioProcessorEditor (*this);
}

void NeoWidenerAudioProcessor::getStateInformation (juce::MemoryBlock& destData)
{
}

void NeoWidenerAudioProcessor::setStateInformation (const void* data, int sizeInBytes)
{
}

juce::AudioProcessor* JUCE_CALLTYPE createPluginFilter()
{
    return new NeoWidenerAudioProcessor();
}