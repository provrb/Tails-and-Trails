#include "../api/PyInterface.h"
#include "../api/Data.h"

#include <iostream>

int main() {
    DataManagement data;
    std::unordered_map<std::string, std::string> dogDetails = {
        {"Breed", "d"},
        {"Weight", "40"}
    };
    
    std::cout << "Created data management class" << std::endl;

    // Save the "Dog" under the "Pets" key
    data.SaveKeyValue("Pets", dogDetails);

    return 0;
}