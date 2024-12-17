#include "Data.h"

#include <iostream>
#include <filesystem>

DataManagement::DataManagement() {
    if ( !std::filesystem::exists(this->m_UserDataPath) )
        this->m_File.open(this->m_UserDataPath, std::fstream::out | std::fstream::app);
    else
        this->m_File.open(this->m_UserDataPath, std::fstream::out | std::fstream::in);
}

DataManagement::~DataManagement() {
    this->m_File.close();
}

std::string DataManagement::GetUserData() {
    // read file and put it into a string
    std::string output;
    std::stringstream contents;
    contents << this->m_File.rdbuf();

    output = std::move(contents.str());
    return output;
}

std::vector<std::string> DataManagement::JSONKeysFromPath(_IN_ const std::string& path) {
    std::istringstream pathStream(path);
    std::string segment;
    std::vector<std::string> keys;

    while ( std::getline(pathStream, segment, '.') )
        keys.push_back(segment);

    return keys;
}

bool DataManagement::SaveJSONValueAtPath(_IN_ const std::string& path, _IN_ std::string& jsonData) {
    JSON data = ReadUserData();

    try {
        JSON newJson = JSON::parse(jsonData);
        std::vector<std::string> keys = JSONKeysFromPath(path);
        JSON* currentLevel = &data;

        for ( size_t i = 0; i < keys.size(); ++i ) {
            const std::string& key = keys[i];

            if ( i < keys.size() - 1 ) {
                if ( !currentLevel->contains(key) ) {
                    ( *currentLevel )[key] = JSON::object();
                }
                currentLevel = &( *currentLevel )[key];
            }
            else
                ( *currentLevel )[key] = newJson;
        }

        SaveJSONDataToFile(data);
    }
    catch ( const std::exception& e ) {
        std::cerr << "Error parsing JSON string: " << e.what() << std::endl;
        return false;
    }

    return true;
}

std::string DataManagement::GetValueFromPath(_IN_ std::string path) {
    std::vector<std::string> keys = JSONKeysFromPath(path);
    JSON data = ReadUserData();

    try {
        JSON* scope = &data;
        for ( size_t i = 0; i < keys.size(); ++i ) {
            std::string key = keys[i];
            std::cout << i << " " << key << std::endl;

            if ( scope->contains(key) ) {
                if ( i == keys.size() - 1 ) {
                    std::cout << "Found value: " << ( *scope )[key] << std::endl;
                    return ( *scope )[key].dump();
                }
                scope = &( *scope )[key];
            }
            else {
                std::cout << "Key '" << key << "' not found." << std::endl;
                return ""; 
            }
        }
    }
    catch ( const std::exception& err ) {
        std::cerr << "Exception: " << err.what() << std::endl;
        return "";
    }

    return "";
}

std::string DataManagement::GetJSONUserData() {
    return ReadUserData().dump();
}

JSON DataManagement::ReadUserData() {
    try {
        JSON parsed;
        std::stringstream buffer;
        buffer << this->m_File.rdbuf();
        parsed = JSON::parse(buffer.str());

        return parsed;
    }
    catch ( std::exception& err ) {
        return JSON::object();
    }
}

bool DataManagement::SaveJSONDataToFile(_IN_ JSON toSave) {
    
    std::ofstream temp(this->m_UserDataPath, std::ofstream::in);
    temp.seekp(0, std::ios::beg);
    temp << toSave.dump(4) << std::endl;;
    temp.flush();

    return true;
}
