#pragma once

enum class ErrorCodes {
    kJSONParsingError   = 0x10,
    kUserDataCorrupt    = 0x40,
    kJSONKeyDoesntExist = 0x60,
};
