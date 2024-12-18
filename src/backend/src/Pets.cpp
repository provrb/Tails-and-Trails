#include "Pets.h"

ErrorCode PetInterface::AddPet(_IN_ uint32_t weight, _IN_ uint32_t heightIN, _IN_ std::string& name, _IN_ std::string& breed)
{
    std::string petsPath = "Pets." + name;
    
    if ( DoesJSONPathExist(petsPath) )
        return ErrorCode::kPetAlreadyExists;

    JSON data = {
        {"Name", name},
        {"Weight", weight},
        {"HeightIn", heightIN},
        {"Breed", breed}
    };
    
    std::string strJSONData = data.dump();
    bool saved = SaveJSONValueAtPath(petsPath, strJSONData);

    return (!saved) ? ErrorCode::kFailedSavingData : ErrorCode::kNoError;
}

ErrorCode PetInterface::EditPet(_IN_ std::string& name, _IN_ _OPTIONAL_ uint32_t weight, _IN_ _OPTIONAL_ uint32_t heightIn, _IN_ _OPTIONAL_ std::string breed)
{
    std::string petsPath = "Pets." + name;
    if ( !DoesJSONPathExist(petsPath) ) {
        std::cout << "Path: " << petsPath << " doesn't exist" << std::endl;
        return ErrorCode::kPetDoesNotExist;
    }

    JSON petInfo = JSON::parse(GetValueFromPath(petsPath));

    // if value passed is not default value set it to value passed in parameter, otherwise dont change it
    if ( weight != 0 ) petInfo["Weight"] = weight;
    if ( heightIn != 0 ) petInfo["HeightIn"] = heightIn;
    if ( breed != "default" ) petInfo["Breed"] = breed;

    std::string strPetInfo = petInfo.dump();

    std::cout << "Modified pet info: " << strPetInfo << std::endl;

    bool saved = SaveJSONValueAtPath(petsPath, strPetInfo);

    return (!saved) ? ErrorCode::kFailedSavingData : ErrorCode::kNoError;
}

ErrorCode PetInterface::RemovePet(_IN_ std::string& name)
{
    std::string petsPath = "Pets." + name;
    if ( !DoesJSONPathExist(petsPath) )
        return ErrorCode::kPetDoesNotExist;

    JSON fileData = ReadUserData();
    if ( !fileData.contains("Pets") )
        return ErrorCode::kJSONParsingError;

    JSON petInfo = fileData["Pets"];
    if ( !petInfo.contains(name) )
        return ErrorCode::kPetDoesNotExist;

    petInfo.erase(name);
    bool saved = SaveJSONDataToFile(petInfo);

    return (!saved) ? ErrorCode::kFailedSavingData : ErrorCode::kNoError;
}

std::unordered_map<std::string, std::string> PetInterface::GetSavedPets()
{
    JSON data = ReadUserData();
    if ( !data.contains("Pets") ) {
        BackendExceptions::SetLastError(ErrorCode::kPetIndexNotFound);
        return {};
    }
        
    JSON petInfo = data["Pets"];
    std::unordered_map<std::string, std::string> savedPets;
    for ( auto& pair : petInfo.items()) {
        if ( !pair.value().is_array() || savedPets.find(pair.key()) == savedPets.end() )
            continue; // not valid pet
    
        savedPets[pair.key()] = pair.value().dump();
    }

    return savedPets;
}
