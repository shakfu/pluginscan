NAME := "pluginscan"
JUCE := "$(HOME)/JUCE/modules"
STDVER := "-std=c++11"
BUILDS := "Builds/MacOSX/build"
STATICLIB := "$(BUILDS)/Debug/libpluginscan.a"
PYBIND_INCLUDES := $(shell python3 -m pybind11 --includes)
PYBIND_EXTENSION := $(shell python3-config --extension-suffix)
PRODUCT := $(NAME)$(PYBIND_EXTENSION)

all: $(PRODUCT)


$(STATICLIB):
	@xcodebuild -project Builds/MacOSX/pluginscan.xcodeproj

$(PRODUCT): $(STATICLIB)
	@c++ -O3 -Wall -shared $(STDVER) -fPIC \
		-undefined dynamic_lookup \
		$(PYBIND_INCLUDES) \
		-I Source \
		-I JuceLibraryCode \
		-I $(JUCE) \
		Source/$(NAME).cpp \
		$(STATICLIB) \
		-framework AudioToolbox \
		-framework AudioUnit \
		-framework Cocoa \
		-framework CoreAudio \
		-framework CoreAudioKit \
		-framework CoreMIDI \
		-framework CoreFoundation \
		-framework CoreGraphics \
		-framework WebKit \
		-o $(PRODUCT)

test:
	@python3 -c "import pluginscan;p = pluginscan.PluginScanner();"

clean:
	@rm -rf $(BUILDS)
	@rm -f $(PRODUCT)
	@rm -rf __pycache__


.PHONY: all clean test

