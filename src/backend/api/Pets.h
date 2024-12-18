#pragma once

#include <Data.h>
#include <ErrorHanding.h>
#include <Macros.h>
#include <ctype.h>
#include <unordered_map>
#include <iostream>

struct PetDescription {
    std::string name;
    std::string breed;
    uint32_t    weight;
    uint32_t    heightIn; // height in inches
};

class Pets : private DataManagement {
public:
    Pets() : DataManagement("pets.json")
    {
    };

    ErrorCode AddPet(
        _IN_ uint32_t weight,
        _IN_ uint32_t heightIN,
        _IN_ std::string& name,
        _IN_ std::string& breed
    );

    ErrorCode EditPet(
        _IN_ std::string& name,
        _IN_ _OPTIONAL_ uint32_t weight   = 0,
        _IN_ _OPTIONAL_ uint32_t heightIn = 0,
        _IN_ _OPTIONAL_ std::string breed = "default"
    );

    ErrorCode RemovePet(_IN_ std::string& name);
    inline void OutputPetFile() { std::cout << ReadUserData().dump(4) << std::endl; }

    std::unordered_map<std::string, PetDescription> GetSavedPets();
};
