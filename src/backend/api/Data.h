#pragma once

#include "json.hpp"
#include <string>
#include <fstream>
#include <Macros.h>

using JSON = nlohmann::json;

class DataManagement {
public:
    DataManagement(std::string path);
    ~DataManagement() = default;

    /*
        Save a string version of arbiturary python JSON type
        to a path of keys, seperated by periods
        For example, 'path' = "Pets.MyDog". Save 'jsonData' in Pets with a key value of MyDog.
    */
    bool                     SaveJSONValueAtPath(_IN_ const std::string& path, _IN_ std::string& jsonData);
    std::string              GetUserData();                             // Return user data json as a string. Make sure to convert to arbituary json type
    std::string              GetValueFromPath(_IN_ std::string path);   // get value stored in key using period seperated path of key
    bool                     SetUserDataPath(_IN_ std::string path);         // modify 'm_UserDataPath' to where json data will be saved
    inline std::string       GetUserDataPath() { return this->m_DataFilePath; }
    bool                     DoesJSONPathExist(_IN_ std::string path);
protected:
    JSON                     ReadUserData();                            // read user data path into a json
    bool                     SaveJSONDataToFile(_IN_ JSON toSave);      // Save JSON data to user data file 
    std::vector<std::string> JSONKeysFromPath(_IN_ const std::string& path); // Get keys for values from a seperated period path

private:
    std::string              m_DataFilePath;
};
