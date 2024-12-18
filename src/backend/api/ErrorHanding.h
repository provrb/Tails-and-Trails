#pragma once

#include <Macros.h>
#include <string>

enum class ErrorCode {
    kNoError            = 0,
    kJSONParsingError   = 0x10,
    kUserDataCorrupt    = 0x40,
    kJSONKeyDoesntExist = 0x60,
    kFailedSavingData   = 0x10,
    kPetAlreadyExists   = 0x932,
    kPetDoesNotExist    = 0x302, // just make sure you call AddPet and not EditPet and you wont get this
    kPetIndexNotFound   = 0x125
};

// Reserved for future use
enum class ErrorSeverity {
    kLow,
    kMedium,
    kHigh,
    kPanic
};

struct ErrorInfo {
    ErrorCode code;
    std::string msg;
    
    explicit ErrorInfo(ErrorCode c, std::string msg)
        : code(c), msg(msg)
    {
    }
};

namespace {
    static ErrorCode m_LastError = ErrorCode::kNoError; // Last error set by a c++ runtime function
}

class BackendExceptions {
public:
    BackendExceptions() = delete;
    ~BackendExceptions() = delete;

    static void             SetLastError(_IN_ ErrorCode code);
    static inline ErrorCode GetLastError() { return ::m_LastError; }
    static inline void      ResetLastError() { ::m_LastError = ErrorCode::kNoError; }
    static std::string      GetErrorDescription(_IN_ ErrorCode code); // return a human readable string describing the error
    static void             FatalExit(_IN_ ErrorCode code);        // show error code with description in a message box and exit
    static void             ThrowException(_IN_ ErrorCode code);
};