#include "../ext/json.hpp"

#include <string>
#include <fstream>

using JSON = nlohmann::json;

class DataManagement {
public:
    DataManagement();
    ~DataManagement();

    std::vector<std::string> GetArrayFromKey(std::string key);
    std::string   GetUserData();                       // return user data json as a string. for frontend.
    bool          SaveKeyValue(std::string parentKey, std::unordered_map<std::string, std::string> keyValues);
    bool          SaveArrayInKey(std::string key, std::vector<std::string> value); // save multiple strings in one key
    std::string   GetValueFromKey(std::string key);
    bool          AppendValue(std::string key, std::string value);
private:
    JSON          ReadUserData();                      // read user data path into a json
    bool          SaveJSONDataToFile(JSON toSave);     // Save JSON data to user data file 
    void          WriteToFile(JSON json);
    void          WriteToFile(std::string data);

    const char*   m_UserDataPath = "./user_data.json"; // current directory
    JSON          m_UserDataJSON;
    std::fstream  m_File;
};
