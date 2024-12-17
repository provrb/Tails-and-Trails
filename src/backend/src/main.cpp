#include "PyInterface.h"
#include "Data.h"

#include <iostream>

int main() {
    std::cout << "Creating data" << std::endl;

    DataManagement data;

    std::string dogDetails = "{\"Breed\": \"German Shepard\", \"Age\": 13}";

    std::cout << "Created data management class" << std::endl;

    //data.SaveKeyValue("Pets.Pet1", dogDetails);
    //data.SaveKeyValue("Pets.Rocky", dogDetails);
    std::string p = "Dogs.Dog1.d";
    data.GetValueFromPath(p);

    return 0;
}
