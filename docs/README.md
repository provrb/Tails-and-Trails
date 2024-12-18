## Exported C++ Functions
Documentation for functions accessible through Python, coded in C++.

# PetInterface
Note: When modifying or accessing pets 'name' and 'breed' should always be lowercase to prevent case-sensitivity when accessing pets.

## AddPet function (backend)
Add information about a pet to a JSON file. All strings passed should
be lowercase so that retrieving pet information is not case-sensitive.

### Syntax
```
ErrorCode AddPet(
    [in] uint32_t     weight,
    [in] uint32_t     heightIn,
    [in] std::string& name,
    [in] std::string& breed 
)
```

### Parameters
```[in] uint32_t weight```

JSON Period Seperated Path: "Pets.(petname).Weight"

The weight of the pet in pounds (lbs). This value will be saved under the pets name with key 'Weight'.

```[in] uint32_t heightIn```

JSON Period Seperated Path: "Pets.(petname).HeightIn"

The height of the pet in inches (in). This value will be saved under the pets name with key 'HeightIn'

```[in] std::string& name```

JSON Period Seperated Path: "Pets.(petname)"

A string of the name of the pet to save. This name will be the key that saves all respective pet values such as weight, breed, etc. The name of the pet is also stored with this data even though it is a key. The name of the pet will be the parent key of the pets data.

```[in] std::string& breed```

JSON Period Seperated Path: "Pets.(petname).Breed"

A string of the breed of the pet to save. It is ideal that you store a valid breed for the pet but you can store anything in these field. Not recommended. 

### Return Value
AddPet returns an enum of 'ErrorCode'. If no error occurs, return value will be kNoError (0). On error, a non-zero value will be returned. An error code can be retrieved by calling BackendExceptions::GetLastError(), a description of the error code can be retrieved by calling BackendExceptions::GetErrorDescription(code).

## EditPet function (backend)
Edit the properties of a pet (weight, height, breed). A pet
current cannot be renamed **yet**.

### Syntax
```
ErrorCode EditPet(
    [in] std::string&      name,
    [in] [opt] uint32_t    weight   = 0,
    [in] [opt] uint32_t    heightIn = 0,
    [in] [opt] std::string breed    = "default"
)
```

### Parameters
```[in] std::string& name```

The name of the pet to modify. Currently there is no way to rename pets yet. Ideally this should be all lowercase so accessing pets is not case-sensitive.

```[in] [optional] uint32_t weight = 0```

The new weight in pounds of the pet to set. If modifying the weight of the pet, set this value to any non-zero unsigned integar. If you are not modifying this value, this parameter can remain zero, the value will not be modified in the JSON.

```[in] [optional] uint32_t heightIn = 0```

The new height in inches of the pet to set. If modifying the height of the pet, set this value to any non-zero unsigned integar. If you are not modifying this value, this parameter can remain zero, the value will not be modified in the JSON.

```[in] [optional] std::string breed = "default"```

The new breed of the pet to set. This string should ideally be all lowercase to avoid case-sensitivity. If you are not changing this value, change it from anything other than "default", otherwise, set it as "default"

### Return Value 
EditPet returns an enum of 'ErrorCode'. If no error occurs, return value will be kNoError (0). On error, a non-zero value will be returned. An error code can be retrieved by calling BackendExceptions::GetLastError(), a description of the error code can be retrieved by calling BackendExceptions::GetErrorDescription(code).

## RemovePet function (backend)
Remove and delete a pet from the JSON save file using the pets name, ideally all lowercase.

### Syntax
```
ErrorCode RemovePet(
    [in] std::string& name
)
```

### Parameters
```[in] std::string& name```

The name of the pet to remove.

### Return Value
RemovePet returns an enum of 'ErrorCode'. If no error occurs, return value will be kNoError (0). On error, a non-zero value will be returned. An error code can be retrieved by calling BackendExceptions::GetLastError(), a description of the error code can be retrieved by calling BackendExceptions::GetErrorDescription(code).

## GetSavedPets function (backend)
Return a map with the pet name as the key, and a string version of the JSON data as the value.

### Syntax
```
std::unordered_map<std::string, std::string> GetSavedPets(void);
```

### Parameters
```void```

No parameters required.

### Return Value
On error, GetSavedPets() returns an empty map and sets the last error using BackendExceptions::SetLastError(), you can retrieve the last error code using BackendExceptions::GetLastError(). On success, returns a populated map with the pet name as the key and JSON data as the value. 