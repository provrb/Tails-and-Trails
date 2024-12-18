#include "Pets.h"

ErrorCode Pets::AddPet(_IN_ uint32_t weight, _IN_ uint32_t heightIN, _IN_ std::string& name, _IN_ std::string& breed)
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

ErrorCode Pets::EditPet(_IN_ std::string& name, _IN_ _OPTIONAL_ uint32_t weight, _IN_ _OPTIONAL_ uint32_t heightIn, _IN_ _OPTIONAL_ std::string breed)
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

ErrorCode Pets::RemovePet(_IN_ std::string& name)
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

std::unordered_map<std::string, PetDescription> Pets::GetSavedPets()
{
    return std::unordered_map<std::string, PetDescription>();
}
