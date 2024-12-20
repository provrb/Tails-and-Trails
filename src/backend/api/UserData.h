#pragma once

#include <Data.h>
#include <ErrorHanding.h>
#include <Macros.h>

enum class Gender {
    kMale,
    kFemale,
    kOther
};

class UserData : private DataManagement {
public:
    UserData() : DataManagement("user_data.json") {};

    // Add a vet to the user's vet list. If vet already exists return an error
    ErrorCode AddVetInfo(
        _IN_ std::string& vetName, 
        _IN_ _OPTIONAL_ std::string vetPhone="000-000-0000", 
        _IN_ _OPTIONAL_ std::string vetAddress="none"
    );

    void SetUsername(_IN_ std::string& username); // Set the username of the user
    void SetFirstName(_IN_ std::string& name); // Set the first name of the user
    void SetLastName(_IN_ std::string& name); // Set the last name of the user
    bool SetEmail(_IN_ std::string& email); // Set the email of the user
    bool SetProfilePicture(_IN_ std::string& url); // Set the profile picture of the user
    bool SetGender(_IN_ Gender gender); // Set the gender of the user, can be other. used for calculations
    bool SetDateOfBirth(_IN_ uint32_t month, _IN_ uint32_t day, _IN_ uint32_t year); // Set the date of birth of the user
    bool SetVetPhoneNumber(_IN_ std::string name, _IN_ std::string phone); // Set the phone number of the an existing vet
    bool SetVetAddress(_IN_ std::string name, _IN_ std::string address); // Set the address of an existing vet

    std::string GetEmail() const; 
    std::string GetUsername() const; 
    std::string GetFirstName() const; 
    std::string GetLastName() const; 
    
    uint32_t GetUserID() const; 
    uint32_t GetLoginStreak() const; 
private:
    void SetUserID(); // Set the user id of the user
};

