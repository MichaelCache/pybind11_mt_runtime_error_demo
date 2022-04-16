#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include "test.h"

namespace py = pybind11;

PYBIND11_MODULE(bind, m)
{
    py::class_<Test>(m, "Test")
        .def(py::init<>());
}
