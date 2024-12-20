#include "UserData.h"

ErrorCode UserData::AddVetInfo(_IN_ std::string& vetName, _IN_ _OPTIONAL_ std::string vetPhone, _IN_ _OPTIONAL_ std::string vetAddress)
{
    return ErrorCode();
}

void UserData::SetUsername(_IN_ std::string& username)
{
}

void UserData::SetFirstName(_IN_ std::string& name)
{
}

void UserData::SetLastName(_IN_ std::string& name)
{
}

bool UserData::SetEmail(_IN_ std::string& email)
{
    return false;
}

bool UserData::SetProfilePicture(_IN_ std::string& url)
{
    return false;
}

bool UserData::SetGender(_IN_ Gender gender)
{
    return false;
}

bool UserData::SetDateOfBirth(_IN_ uint32_t month, _IN_ uint32_t day, _IN_ uint32_t year)
{
    return false;
}

bool UserData::SetVetPhoneNumber(_IN_ std::string name, _IN_ std::string phone)
{
    return false;
}

bool UserData::SetVetAddress(_IN_ std::string name, _IN_ std::string address)
{
    return false;
}

std::string UserData::GetEmail() const
{
    return std::string();
}

std::string UserData::GetUsername() const
{
    return std::string();
}

std::string UserData::GetFirstName() const
{
    return std::string();
}

std::string UserData::GetLastName() const
{
    return std::string();
}

uint32_t UserData::GetUserID() const
{
    return 0;
}

uint32_t UserData::GetLoginStreak() const
{
    return 0;
}

void UserData::SetUserID()
{
}
