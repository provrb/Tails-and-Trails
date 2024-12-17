#include "../ext/json.hpp"

#include <string>
#include <fstream>

using JSON = nlohmann::json;

class DataManagement {
public: // Functions to use in Python
    DataManagement();
    ~DataManagement();

    std::string   GetUserData();                       // return user data json as a string. for frontend.
    bool          SaveKeyValue(const std::string& path, std::string& jsonData);
    std::string   GetValueFromPath(std::string path); // get value stored in key using period seperated path of key
    std::string   GetJSONUserData();                   // Read the json user data and put it in a string
private: // Functions to use in C++
    std::vector<std::string> JSONKeysFromPath(const std::string& path);            // Get keys for values from a seperated period path
    JSON          ReadUserData();                      // read user data path into a json
    bool          SaveJSONDataToFile(JSON toSave);     // Save JSON data to user data file 


    const char*   m_UserDataPath = "./user_data.json"; // current directory
    std::fstream  m_File;
};
