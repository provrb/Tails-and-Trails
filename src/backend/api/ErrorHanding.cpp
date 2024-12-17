#include "ErrorHanding.h"


#include <unordered_map>

std::unordered_map<ErrorCode, ErrorInfo> ErrorCodeDescription = {
    { ErrorCode::kJSONParsingError, ErrorInfo{ ErrorCode::kJSONParsingError, "There was an error parsing a JSON data file."} },
    // ....
};

void Exception::SetLastError(_IN_ ErrorCode code)
{
    ::m_LastError = code;
}

std::string Exception::GetErrorDescription(_IN_ ErrorCode code)
{
    if ( ErrorCodeDescription.contains(code) )
        return ErrorCodeDescription.at(code).msg;

    return "No Error Description For Error Code: " + std::to_string(static_cast<int>(code));
}

void Exception::FatalExit(_IN_ ErrorCode code)
{
    //MessageBoxA(NULL, GetErrorDescription(code).c_str(), "Fatal Exit. Error Thrown.", MB_OK | MB_ICONERROR);
    exit(static_cast<int>(code));
}

void Exception::ThrowException(_IN_ ErrorCode code)
{
}
