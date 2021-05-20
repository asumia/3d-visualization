#include "FacadeOperationResult.h"

FacadeOperationResult::FacadeOperationResult(bool isSuccess)
{
    SetBoolValue(isSuccess);
}

void FacadeOperationResult::SetErrorMessage(string errorMessage)
{
    _errorMessage = errorMessage;
}

void FacadeOperationResult::SetBoolValue(bool value)
{
    _isSuccess = value;
}

string FacadeOperationResult::GetErrorMessage()
{
    return _errorMessage;
}

bool FacadeOperationResult::IsSuccess()
{
    return _isSuccess;
}
