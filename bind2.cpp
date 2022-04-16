#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include "test2.h"

namespace py = pybind11;

PYBIND11_MODULE(bind2, m)
{
    py::class_<Test2>(m, "Test2")
        .def(py::init<>());
}
