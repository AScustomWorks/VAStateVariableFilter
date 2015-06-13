/*
  ==============================================================================

    This file was auto-generated by the Introjucer!

    It contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"


//==============================================================================
VAStateVariableFilterProcessorEditor::VAStateVariableFilterProcessorEditor (VAStateVariableFilterProcessor& owner)
    : AudioProcessorEditor (owner)
{
    addAndMakeVisible (cutoffSlider = new Slider ("CutoffFreq"));
    cutoffSlider->setTooltip (translate("Logarithmic control of the filter\'s cutoff frequency."));
    cutoffSlider->setRange (22.5064, 130.096, 0);
    cutoffSlider->setSliderStyle (Slider::RotaryVerticalDrag);
    cutoffSlider->setTextBoxStyle (Slider::NoTextBox, false, 80, 20);
    cutoffSlider->addListener (this);

    addAndMakeVisible (resonanceSlider = new Slider ("Resonance"));
    resonanceSlider->setTooltip (translate("Filter\'s resonance control. Self-oscillation at 1.0."));
    resonanceSlider->setRange (0, 1, 0);
    resonanceSlider->setSliderStyle (Slider::RotaryVerticalDrag);
    resonanceSlider->setTextBoxStyle (Slider::NoTextBox, false, 80, 20);
    resonanceSlider->addListener (this);

    addAndMakeVisible (shelfGainSlider = new Slider ("PeakGain"));
    shelfGainSlider->setTooltip (translate("Shelf gain for the Band Shelving filter."));
    shelfGainSlider->setRange (-60, 10, 0);
    shelfGainSlider->setSliderStyle (Slider::RotaryVerticalDrag);
    shelfGainSlider->setTextBoxStyle (Slider::NoTextBox, false, 80, 20);
    shelfGainSlider->addListener (this);

    addAndMakeVisible (cutoffLabel = new Label ("new label",
                                          translate("Cutoff (Hz)")));
    cutoffLabel->setFont (Font (15.00f, Font::plain));
    cutoffLabel->setJustificationType (Justification::centred);
    cutoffLabel->setEditable (false, false, false);
    cutoffLabel->setColour (TextEditor::textColourId, Colours::black);
    cutoffLabel->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (resonanceLabel = new Label ("new label",
                                           translate("Resonance")));
    resonanceLabel->setFont (Font (15.00f, Font::plain));
    resonanceLabel->setJustificationType (Justification::centred);
    resonanceLabel->setEditable (false, false, false);
    resonanceLabel->setColour (TextEditor::textColourId, Colours::black);
    resonanceLabel->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (shelfGainLabel = new Label ("new label",
                                           translate("Shelf Gain")));
    shelfGainLabel->setFont (Font (15.00f, Font::plain));
    shelfGainLabel->setJustificationType (Justification::centred);
    shelfGainLabel->setEditable (false, false, false);
    shelfGainLabel->setColour (TextEditor::textColourId, Colours::black);
    shelfGainLabel->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (cutoffVal = new Label ("cutoff value",
                                              translate("label text")));
    cutoffVal->setFont (Font (15.00f, Font::plain));
    cutoffVal->setJustificationType (Justification::centred);
    cutoffVal->setEditable (false, false, false);
    cutoffVal->setColour (TextEditor::textColourId, Colours::black);
    cutoffVal->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (resVal = new Label ("resonance value",
                                           translate("label text")));
    resVal->setFont (Font (15.00f, Font::plain));
    resVal->setJustificationType (Justification::centred);
    resVal->setEditable (false, false, false);
    resVal->setColour (TextEditor::textColourId, Colours::black);
    resVal->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (shelfGainVal = new Label ("gain value",
                                            translate("label text")));
    shelfGainVal->setFont (Font (15.00f, Font::plain));
    shelfGainVal->setJustificationType (Justification::centred);
    shelfGainVal->setEditable (false, false, false);
    shelfGainVal->setColour (TextEditor::textColourId, Colours::black);
    shelfGainVal->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (filterTypeCBox = new ComboBox ("filter type"));
    filterTypeCBox->setTooltip (translate("Select the filter type used."));
    filterTypeCBox->setEditableText (false);
    filterTypeCBox->setJustificationType (Justification::centredLeft);
    filterTypeCBox->setTextWhenNothingSelected (String::empty);
    filterTypeCBox->setTextWhenNoChoicesAvailable (translate("(no choices)"));
    filterTypeCBox->addItem (translate("Lowpass"), 1);
    filterTypeCBox->addItem (translate("Bandpass"), 2);
    filterTypeCBox->addItem (translate("Highpass"), 3);
    filterTypeCBox->addItem (translate("Unit Gain BP"), 4);
    filterTypeCBox->addItem (translate("Band Shelving"), 5);
    filterTypeCBox->addItem (translate("Notch"), 6);
    filterTypeCBox->addItem (translate("Allpass"), 7);
    filterTypeCBox->addItem (translate("Peak"), 8);
    filterTypeCBox->addListener (this);
    // Set the ComboBox to select the Lowpass Filter by default
    filterTypeCBox->setSelectedItemIndex(0, sendNotification);

    // Add the window resizer component for the bottom right of the UI
    addAndMakeVisible(resizer = new ResizableCornerComponent(this, &resizeLimits));
    resizeLimits.setSizeLimits(owner.lastUIWidth, owner.lastUIHeight, 600, 300);

    setSize(owner.lastUIWidth, owner.lastUIHeight);

    // Use custom knob image strip for each slider.
    cutoffSlider->setLookAndFeel(&knobLookAndFeel);
    resonanceSlider->setLookAndFeel(&knobLookAndFeel);
    shelfGainSlider->setLookAndFeel(&knobLookAndFeel);

    startTimerHz(512);		// 512 Hz control rate
}

VAStateVariableFilterProcessorEditor::~VAStateVariableFilterProcessorEditor()
{
    cutoffSlider = nullptr;
    resonanceSlider = nullptr;
    shelfGainSlider = nullptr;
    cutoffLabel = nullptr;
    resonanceLabel = nullptr;
    shelfGainLabel = nullptr;
    cutoffVal = nullptr;
    resVal = nullptr;
    shelfGainVal = nullptr;
    filterTypeCBox = nullptr;
}

//==============================================================================
void VAStateVariableFilterProcessorEditor::paint (Graphics& g)
{
    g.fillAll (Colours::white);

}

void VAStateVariableFilterProcessorEditor::resized()
{
    cutoffSlider->setBounds (20, 72, 60, 60);
    resonanceSlider->setBounds (120, 72, 60, 60);
    shelfGainSlider->setBounds (220, 72, 60, 60);
    cutoffLabel->setBounds (15, 40, 65, 24);
    resonanceLabel->setBounds (115, 40, 65, 24);
    shelfGainLabel->setBounds (215, 40, 65, 24);
    cutoffVal->setBounds (14, 144, 72, 24);
    resVal->setBounds (114, 144, 72, 24);
    shelfGainVal->setBounds (214, 144, 72, 24);
    filterTypeCBox->setBounds (328, 40, 150, 24);

    resizer->setBounds(getWidth() - 16, getHeight() - 16, 16, 16);

    getProcessor().lastUIWidth = getWidth();
    getProcessor().lastUIHeight = getHeight();
}

// This timer periodically checks whether any of the filter's parameters have changed...
void VAStateVariableFilterProcessorEditor::timerCallback()
{
    VAStateVariableFilterProcessor& ourProcessor = getProcessor();

    cutoffSlider->setValue(ourProcessor.cutoff->getValue(), dontSendNotification);
    resonanceSlider->setValue(ourProcessor.resonance->getValue(), dontSendNotification);
    shelfGainSlider->setValue(ourProcessor.shelfGain->getValue(), dontSendNotification);

    filterTypeCBox->setSelectedItemIndex(ourProcessor.filterType->getValue(), dontSendNotification);

    // Note: convert pitch to frequency to display on the label
    cutoffVal->setText(String(pitchToFreq(ourProcessor.cutoff->getValue())) + " Hz", dontSendNotification);
    resVal->setText(String(ourProcessor.resonance->getValue()), dontSendNotification);
    shelfGainVal->setText(String(ourProcessor.shelfGain->getValue()) + " dB", dontSendNotification);
}

// This is our Slider::Listener callback, when the user drags a slider.
void VAStateVariableFilterProcessorEditor::sliderValueChanged(Slider* slider)
{
    if (AudioProcessorParameter* param = getParameterFromSlider(slider))
    {
        // It's vital to use setValueNotifyingHost to change any parameters that are automatable
        // by the host, rather than just modifying them directly, otherwise the host won't know
        // that they've changed.
        param->setValueNotifyingHost((float)slider->getValue());
    }
}

void VAStateVariableFilterProcessorEditor::sliderDragStarted(Slider* slider)
{
    if (AudioProcessorParameter* param = getParameterFromSlider (slider))
    {
        param->beginChangeGesture();
    }
}

void VAStateVariableFilterProcessorEditor::sliderDragEnded(Slider* slider)
{
    if (AudioProcessorParameter* param = getParameterFromSlider (slider))
    {
        param->endChangeGesture();
    }
}

void VAStateVariableFilterProcessorEditor::comboBoxChanged(ComboBox* comboBoxThatHasChanged)
{
    if (AudioProcessorParameter* param = getParameterFromComboBox(comboBoxThatHasChanged))
    {
        param->setValueNotifyingHost((float)comboBoxThatHasChanged->getSelectedItemIndex());
    }
}

AudioProcessorParameter* VAStateVariableFilterProcessorEditor::getParameterFromSlider(const Slider* slider) const
{
    if (cutoffSlider == slider)
        return getProcessor().cutoff;

    if (resonanceSlider == slider)
        return getProcessor().resonance;

    if (shelfGainSlider == slider)
        return getProcessor().shelfGain;

    return nullptr;		// if none of the above are true
}

AudioProcessorParameter* VAStateVariableFilterProcessorEditor::getParameterFromComboBox(const ComboBox* comboBox) const
{
    if (filterTypeCBox == comboBox)
        return getProcessor().filterType;

    return nullptr;
}
