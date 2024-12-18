#include <pybind11/pybind11.h>
#include <PyInterface.h>
#include <Data.h>
#include <Pets.h>

// when building dll
#ifdef DEPLOY

namespace py = pybind11;

PYBIND11_MODULE(backend, modHandle) {
    // link modules for python

    py::class_<DataManagement> dataClass = PythonInterface::ExposeCPPClass<DataManagement>(modHandle, "DataManagement");
    
    dataClass.def(py::init<std::string&>()); // class constructor where you specify file path for data to save

    dataClass.def(
        "GetUserData", 
        &DataManagement::GetUserData,
        "Read the JSON user data file. Returns a string version of the JSON data."
    );

    dataClass.def(
        "SaveJSONValueAtPath",
        &DataManagement::SaveJSONValueAtPath,
        "Save 'JSONData' under JSON keys specified in 'Path' separated by periods, inside the user data JSON file.",
        py::arg("Path"), py::arg("JSONData")
    );

    dataClass.def(
        "GetValueFromPath",
        &DataManagement::GetValueFromPath,
        "Get a JSON value from JSON keys specified in 'Path' that are period separated.",
        py::arg("Path")
    );
}

#elif defined(TEST)

#include <iostream>

// when i need a console to print
// easier to debug and run

int main() {

}

#endif
