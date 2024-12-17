#include <python3.12/Python.h>
#include <iostream>
#include <unordered_map>

class PythonInterface {
public:
    PythonInterface();
    ~PythonInterface();

    // Check if a module 'modName' is loaded, in m_Moduless
    bool IsModuleLoaded(const char* modName);

    // Load a python module of 'modName'
    // Insert it into m_Modules if it exists
    // Return the module.
    PyObject* LoadPythonModule(const char* modName);

    // Return a PyObject of a class in module 'modName'
    // of class 'className' if it exists.
    PyObject* GetClass(const char* modName, const char* className);;

    // Call the method of a class in Python
    template <typename ...Args>
    PyObject* CallClassMethod(const char* modName, const char* className, const char* methodName, Args&&... args);

    // Get an already created Python class that can be used between
    // C++ and Python files interchancably
    PyObject* GetInlineClass(const char* modName, const char* className);
private:
    std::unordered_map<const char*, PyObject*> m_Modules;
    std::unordered_map<const char*, PyObject*> m_Classes;
};
