/*
  ==============================================================================

    This file was auto-generated by the Introjucer!

    It contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#ifndef PLUGINEDITOR_H_INCLUDED
#define PLUGINEDITOR_H_INCLUDED

#include "../JuceLibraryCode/JuceHeader.h"
#include "PluginProcessor.h"
#include "Resources/KnobLookAndFeel.h"
#include "Utilities/DspUtilities.h"


//==============================================================================
/**
*/
class VAStateVariableFilterProcessorEditor : public AudioProcessorEditor,
                                             public Timer,
                                             public SliderListener,
                                             public ComboBoxListener
{
public:
    VAStateVariableFilterProcessorEditor (VAStateVariableFilterProcessor& owner);
    ~VAStateVariableFilterProcessorEditor();

    //==============================================================================
    void timerCallback() override;
    void paint (Graphics&) override;
    void resized() override;
    void sliderValueChanged(Slider* sliderThatWasMoved);
    void sliderDragStarted(Slider*) override;
    void sliderDragEnded(Slider*) override;
    void comboBoxChanged(ComboBox* comboBoxThatHasChanged);
private:
    // GUI components
    ScopedPointer<Slider> cutoffSlider;
    ScopedPointer<Slider> resonanceSlider;
    ScopedPointer<Slider> shelfGainSlider;
    ScopedPointer<Label> cutoffLabel;
    ScopedPointer<Label> resonanceLabel;
    ScopedPointer<Label> shelfGainLabel;
    ScopedPointer<Label> cutoffVal;
    ScopedPointer<Label> resVal;
    ScopedPointer<Label> shelfGainVal;
    ScopedPointer<ComboBox> filterTypeCBox;

    KnobLookAndFeel knobLookAndFeel;
    TooltipWindow toolTipWindow;

    ScopedPointer<ResizableCornerComponent> resizer;	// Corner resizer
    ComponentBoundsConstrainer resizeLimits;			// Resizing limits

    AudioProcessorParameter* getParameterFromSlider(const Slider*) const;
    AudioProcessorParameter* getParameterFromComboBox(const ComboBox*) const;

    VAStateVariableFilterProcessor& getProcessor() const
    {
        return static_cast<VAStateVariableFilterProcessor&>(processor);
    }

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (VAStateVariableFilterProcessorEditor)
};


#endif  // PLUGINEDITOR_H_INCLUDED
