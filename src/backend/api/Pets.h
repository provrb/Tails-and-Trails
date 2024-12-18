#pragma once

#include <Data.h>
#include <ErrorHanding.h>
#include <Macros.h>
#include <ctype.h>
#include <unordered_map>

struct PetDescription {
    std::string name;
    std::string breed;
    uint32_t weight;
    uint32_t heightIn; // height in inches
};

class Pets : DataManagement {
public:
    ErrorCode AddPet(
        _IN_ uint32_t weight,
        _IN_ uint32_t heightIN,
        _IN_ std::string& name,
        _IN_ std::string& breed
    );

    ErrorCode EditPet(
        _IN_ std::string& name,
        _IN_ _OPTIONAL_ uint32_t weight   = -1,
        _IN_ _OPTIONAL_ uint32_t heightIn = -1,
        _IN_ _OPTIONAL_ std::string breed = "default"
    );

    ErrorCode RemovePet(
        _IN_ std::string& name
    );

    std::unordered_map<std::string, PetDescription> GetSavedPets();
private:
    std::string m_PetInfoPath = dataDirectory + "pets.json";
};
