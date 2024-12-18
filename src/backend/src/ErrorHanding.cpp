#include "ErrorHanding.h"

#include <unordered_map>

std::unordered_map<ErrorCode, ErrorInfo> ErrorCodeDescription = {
    { ErrorCode::kJSONParsingError, ErrorInfo{ ErrorCode::kJSONParsingError, "There was an error parsing a JSON data file."} },
    // ....
};

void BackendExceptions::SetLastError(_IN_ ErrorCode code)
{
    ::m_LastError = code;
}

std::string BackendExceptions::GetErrorDescription(_IN_ ErrorCode code)
{
    if ( ErrorCodeDescription.contains(code) )
        return ErrorCodeDescription.at(code).msg;

    return "No Error Description For Error Code: " + std::to_string(static_cast<int>(code));
}

void BackendExceptions::FatalExit(_IN_ ErrorCode code)
{
    //MessageBoxA(NULL, GetErrorDescription(code).c_str(), "Fatal Exit. Error Thrown.", MB_OK | MB_ICONERROR);
    exit(static_cast<int>(code));
}

void BackendExceptions::ThrowException(_IN_ ErrorCode code)
{
}
