#include <Python.h>
#include <iostream>
#include <unordered_map>
#include <pybind11/pybind11.h>
#include <Macros.h>

class PythonInterface {
public:
    PythonInterface();
    ~PythonInterface();

    // Check if a module 'modName' is loaded, in m_Moduless
    bool IsModuleLoaded(_IN_ const char* modName);

    /*
        Load a python module of 'modName'
        Insert it into m_Modules if it exists
        Return the module.
    */
    PyObject* LoadPythonModule(_IN_ const char* modName);

    /*
        Return a PyObject of a class in module 'modName'
        of class 'className' if it exists.
    */
    PyObject* GetClass(_IN_ const char* modName, _IN_ const char* className);;

    // Call the method of a class in Python
    template <typename ...Args>
    PyObject* CallClassMethod(
        _IN_ const char* modName, 
        _IN_ const char* className, 
        _IN_ const char* methodName, 
        _IN_ _OPTIONAL_ Args&&... args
    );

    /*
        Get an already created Python class that can be used between
        C++ and Python files interchancably
    */
    PyObject* GetInlineClass(_IN_ const char* modName, _IN_ const char* className);

    template <typename ClassType>
    inline static pybind11::class_<ClassType> ExposeCPPClass(
        _IN_ pybind11::module moduleHandle,
        _IN_ const char* className // name of the function or object to link
    ) {
        return pybind11::class_<ClassType>(moduleHandle, className);
    }

private:
    std::unordered_map<const char*, PyObject*> m_Modules;
    std::unordered_map<const char*, PyObject*> m_Classes;
};
