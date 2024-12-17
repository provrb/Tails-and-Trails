#include "Data.h"

#include <iostream>
#include <filesystem>

DataManagement::DataManagement() {
    this->m_File.open(this->m_UserDataPath, std::fstream::out | std::fstream::in);
    this->ReadUserData();
}

void DataManagement::WriteToFile(JSON json) {
    this->m_File << std::setw(4) << json << std::endl;
}

void DataManagement::WriteToFile(std::string data) {

}

DataManagement::~DataManagement() {
}

std::string DataManagement::GetUserData() {
    // read file and put it into a string
    std::string output;
    std::stringstream contents;
    contents << this->m_File.rdbuf();

    output = std::move(contents.str());
    return output;
}

bool DataManagement::AppendValue(std::string key, std::string value) {
    JSON data = ReadUserData();

}

bool DataManagement::SaveKeyValue(std::string parentKey, std::unordered_map<std::string, std::string> keyValues) {
    JSON data = ReadUserData();
    std::cout << "Saving key" << std::endl;

    if (!parentKey.empty()) {
        if (!data.contains(parentKey)) {
            data[parentKey] = JSON::object();
        }

        if (data[parentKey].is_object()) {
            for (auto& [key, value] : keyValues) {
                if (data[parentKey].contains(key)) {
                    if (data[parentKey][key].is_array()) {
                        data[parentKey][key].push_back(value);
                    } else {
                        JSON converted = { data[parentKey][key], value };
                        data[parentKey][key] = converted;
                    }
                } else {
                    data[parentKey][key] = value;
                }
            }
        } else {
            return false;
        }
    } else {
        for (auto& [key, value] : keyValues) {
            if (data.contains(key)) {
                if (data[key].is_array()) {
                    data[key].push_back(value);
                } else {
                    JSON converted = { data[key], value };
                    data[key] = converted;
                }
            } else {
                data[key] = value;
            }
        }
    }

    return SaveJSONDataToFile(data);
}


bool DataManagement::SaveArrayInKey(std::string key, std::vector<std::string> value) {

}

std::string DataManagement::GetValueFromKey(std::string key) {

}

std::vector<std::string> DataManagement::GetArrayFromKey(std::string key) {

}

JSON DataManagement::ReadUserData() {
    JSON parsed;
    if ( std::filesystem::file_size(this->m_UserDataPath) <= 0)
        return parsed; // empty

    this->m_File >> parsed;
    return parsed;
}

bool DataManagement::SaveJSONDataToFile(JSON toSave) {
    // open for writing
    int oldFileSize = std::filesystem::file_size(this->m_UserDataPath);
    WriteToFile(toSave);
    int newFileSIze = std::filesystem::file_size(this->m_UserDataPath);

    return ( newFileSIze > oldFileSize );
}
