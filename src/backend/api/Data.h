#include "../ext/json.hpp"

#include <string>
#include <fstream>
#include <Macros.h>

using JSON = nlohmann::json;

// location on where to store user data such as pet info, preferences, etc
// contains a trailing slash
const std::string dataDirectory = "./data/";

class DataManagement {
public:
    explicit DataManagement(std::string& path);
    ~DataManagement();

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
private:
    std::vector<std::string> JSONKeysFromPath(_IN_ const std::string& path); // Get keys for values from a seperated period path
    JSON                     ReadUserData();                            // read user data path into a json
    bool                     SaveJSONDataToFile(_IN_ JSON toSave);      // Save JSON data to user data file 

    std::string              m_DataFilePath;
    std::fstream             m_File;
};
