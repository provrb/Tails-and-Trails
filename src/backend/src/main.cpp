#include <pybind11/pybind11.h>
#include <PyInterface.h>
#include <Data.h>

#ifdef DEPLOY

// when building dll

namespace py = pybind11;

PYBIND11_MODULE(backend, modHandle) {

    // link modules for python
    auto dataClass = PythonInterface::ExposeCPPClass<DataManagement>(modHandle, "DataManagement");
    dataClass.def(py::init()); // class constructor
    dataClass.def("GetUserData", &DataManagement::GetUserData);
    dataClass.def("SaveJSONValueAtPath", &DataManagement::SaveJSONValueAtPath, py::arg("Path"), py::arg("JSONData"));
    dataClass.def("GetValueFromPath", &DataManagement::GetValueFromPath, py::arg("Path"));
}

#elif defined(TEST)

#include <iostream>

// when i need a console to print
// easier to debug and run

int main() {
    
}

#endif
