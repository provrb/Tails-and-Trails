import backend
import json

data = backend.DataManagement() # C++ data management class

# Details on some exported methods
print(help(data.GetUserData))
print(help(data.SaveJSONValueAtPath))
print(help(data.GetValueFromPath))

# Saving information to user data json
jsonDataToSave     = r"""{ "Breed": "German Shepard", "Age": 15  }""" # To save in user data for example
pathToSaveJsonData = "Pets.Joe"                                     # What keys we want 'jsonDataToSave' to be 
data.SaveJSONValueAtPath(pathToSaveJsonData, jsonDataToSave)          # Save our data at the path

# Getting information from user data using backend methods
savedUserData  = data.GetUserData()                   # saved json user data as a string
parsedUserData = json.loads(savedUserData)            # convert string user data to actual JSON type
prettyUserData = json.dumps(parsedUserData, indent=4) # add indenation to json

print(prettyUserData)                                 # Show our formatted json

