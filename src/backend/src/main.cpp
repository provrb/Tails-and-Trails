#include <pybind11/pybind11.h>
#include <PyInterface.h>
#include <Data.h>
#include <Pets.h>

// when building dll
#ifdef DEPLOY

namespace py = pybind11;

PYBIND11_MODULE(backend, modHandle) {
    // link modules for python

    // Data interface functions
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

    // pet interface functions
    py::class_<PetInterface> petClass = PythonInterface::ExposeCPPClass<PetInterface>(modHandle, "PetInterface");
    petClass.def(
        "AddPet",
        &PetInterface::AddPet,
        "Add a pet to the JSON save file. Weight in lbs, height in inches. Returns an error code.",
        py::arg("Weight"), py::arg("Height"), py::arg("Name"), py::arg("Breed")
    );
    petClass.def(
        "EditPet",
        &PetInterface::EditPet,
        "Edit properties of a saved pet. Returns an error code. Select properties are optional.",
        py::arg("Name"), py::arg("Weight") = 0, py::arg("Height") = 0, py::arg("Breed") = "default"
    );
    petClass.def(
        "RemovePet",
        &PetInterface::RemovePet,
        "Remove a pet from the list of saved pets by name.",
        py::arg("Name")
    );
    petClass.def(
        "GetSavedPets",
        &PetInterface::GetSavedPets,
        "Get a map of saved pets with the pet name as the key and pet info as the value."
    );

}

#elif defined(TEST)

#include <iostream>

// when i need a console to print
// easier to debug and run

int main() {

}

#endif
