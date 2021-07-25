# pluginscan

Audio plugin scanner as python extension using JUCE and pybind11


## Credits

This project is made possible by, and directly derivative of, Jack Devlin's ctype / juce python scanner project which was excellently explained in the following blog posts:

1. [Managing plugins in Logic Pro X with Python - 1](https://jdevlin.me/blog/2019-10-25-logicpropluginspython-1)
2. [Managing plugins in Logic Pro X with Python - 2](https://jdevlin.me/blog/2019-11-28-logicpropluginspython-2)
3. [Managing plugins in Logic Pro X with Python - 2](https://jdevlin.me/blog/2019-12-11-logicpropluginspython-3)

The Github repos for the above posts are:
- <https://github.com/jd-13/logicpropluginspython-scripts>
- <https://github.com/jd-13/logicpropluginspython-jucebinding>


## What's Different?

This is project starts off from the same premise (using JUCE's plugin scanner) and code as Jack Devlin's project, but with the following current differences:

- pybind11 instead of ctypes

- `scanPlugins` function instead of scan on instanciation of `PluginScanner`

- not suppressing stdout or stderr (yet)

- plugin size is quite large (25MB) due to static linking


## Usage

```python
import pluginscan

p = pluginscan.PluginScanner()
p.scanPlugins()
# ... wait
for i in range(p.getNumPlugins()):
	print(p.getMaufacturer(i), p.getName(i), p.getFileOrIdentifier(i))

```

## To Build

Assumes JUCE SDK is in `$HOME/JUCE` and the platform is macOS.

To build the extension:

```
$ make

```

## Next Steps

- Drop deprecated functionality
- Wrap more of the JUCE plugin scanning api
- Add vst and vst3 support

