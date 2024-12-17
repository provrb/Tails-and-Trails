#include "../ext/json.hpp"

#include <string>
#include <fstream>
#include <Macros.h>

using JSON = nlohmann::json;

class DataManagement {
public: // Functions to use in Python
    DataManagement();
    ~DataManagement();

    /*
        Save a string version of arbiturary python JSON type
        to a path of keys, seperated by periods
        For example, 'path' = "Pets.MyDog". Save 'jsonData' in Pets with a key value of MyDog.
    */
    bool SaveJSONValueAtPath(_IN_ const std::string& path, _IN_ std::string& jsonData);
                             
    std::string              GetUserData();                             // Return user data json as a string. Make sure to convert to arbituary json type
    std::string              GetValueFromPath(_IN_ std::string path);   // get value stored in key using period seperated path of key
    std::string              GetJSONUserData();                         // Read the json user data and put it in a string
private: // Functions to use in C++
    std::vector<std::string> JSONKeysFromPath(_IN_ const std::string& path); // Get keys for values from a seperated period path
    JSON                     ReadUserData();                            // read user data path into a json
    bool                     SaveJSONDataToFile(_IN_ JSON toSave);      // Save JSON data to user data file 

    const char*              m_UserDataPath = "./user_data.json"; // current directory
    std::fstream             m_File;
};
