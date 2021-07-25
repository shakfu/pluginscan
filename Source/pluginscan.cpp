#include <string.h>
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#define JUCE_GLOBAL_MODULE_SETTINGS_INCLUDED 1
#define DEBUG 1
#include "interface.h"

namespace py = pybind11;


using namespace pybind11::literals;

PYBIND11_MODULE(pluginscan, m)
{
    m.doc() = "pluginscan module: a library to scan for plugins.";
    m.attr("__version__") = "0.0.1";

    py::class_<PluginScanner>(m, "PluginScanner")
        .def(pybind11::init([]() { return new PluginScanner(); }))
        .def("scanPlugins", &PluginScanner::scanPlugins)
        .def("getFileOrIdentifier", &PluginScanner::getFileOrIdentifier)
        .def("getManufacturer", &PluginScanner::getManufacturer)
        .def("getName", &PluginScanner::getName)
        .def("getNumPlugins", &PluginScanner::getNumPlugins);
}

