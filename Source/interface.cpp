/*
  ==============================================================================

    interface.cpp
    Created: 6 Sep 2019 12:37:44pm
    Author:  Jack Devlin

  ==============================================================================
*/


#include "interface.h"

PluginScanner::PluginScanner() {

}

void PluginScanner::scanPlugins() {
    
    juce::String pluginName;
    juce::AudioUnitPluginFormat aupf;
    juce::PluginDirectoryScanner scanner(_pluginList,
                                   aupf,
                                   aupf.getDefaultLocationsToSearch(),
                                   true,
                                   juce::File());

    while (true) {
        const juce::String nextName = scanner.getNextPluginFileThatWillBeScanned();
        
        if (!scanner.scanNextFile(true, pluginName)) {
            break;
        }
    }
}


const char* PluginScanner::getFileOrIdentifier(int index) {
    return static_cast<const char*>(_pluginList.getType(index)->fileOrIdentifier.toUTF8());
}

const char* PluginScanner::getManufacturer(int index) {
    return static_cast<const char*>(_pluginList.getType(index)->manufacturerName.toUTF8());
}

const char* PluginScanner::getName(int index) {
    return static_cast<const char*>(_pluginList.getType(index)->descriptiveName.toUTF8());
}

int PluginScanner::getNumPlugins() {
    return _pluginList.getNumTypes();
}
