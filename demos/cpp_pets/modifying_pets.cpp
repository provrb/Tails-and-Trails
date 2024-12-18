#ifdef TEST

#include <Pets.h>

int main() {
    Pets petInterface;

    PetDescription pet1;
    pet1.breed = "dog idk";
    pet1.name = "ethan";
    pet1.heightIn = 100;
    pet1.weight = 123;

    PetDescription pet2;
    pet2.breed = "dog 2312";
    pet2.name = "ethan2";
    pet2.heightIn = 130;
    pet2.weight = 140;

    PetDescription pet3;
    pet3.breed = "cat suads";
    pet3.name = "etfa2";
    pet3.heightIn = 420;
    pet3.weight = 640;

    petInterface.AddPet(pet1.weight, pet1.heightIn, pet1.name, pet1.breed);
    petInterface.AddPet(pet2.weight, pet2.heightIn, pet2.name, pet2.breed);
    petInterface.AddPet(pet3.weight, pet3.heightIn, pet3.name, pet3.breed);

    std::cout << "Added all 3 pets. This is the resulting JSON file." << std::endl;
    petInterface.OutputPetFile();
    std::cout << std::endl;

    petInterface.EditPet(pet1.name, 1932); // edit pet 1 weight
    petInterface.EditPet(pet2.name, 0, 3022); // edit pet 2 height
    petInterface.EditPet(pet3.name, 0, 0, "golden retriever"); // edit pet 3 breed

    std::cout << "Edited all 3 pets. This is the resulting JSON file." << std::endl;
    petInterface.OutputPetFile();
}

#endif
