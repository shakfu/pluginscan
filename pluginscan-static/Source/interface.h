/*
  ==============================================================================

    interface.h
    Created: 6 Sep 2019 12:37:44pm
    Author:  Jack Devlin

  ==============================================================================
*/

#pragma once

#include "JuceHeader.h"

class PluginScanner {
public:
    PluginScanner();

    void scanPlugins();
    const char* getFileOrIdentifier(int index);
    const char* getManufacturer(int index);
    const char* getName(int index);
    int getNumPlugins();

private:
    juce::KnownPluginList _pluginList;
};
