#ifndef FACADEOPERATIONRESULT_H
#define FACADEOPERATIONRESULT_H

#include <iostream>
#include <business/myexception.h>

using namespace std;

class FacadeOperationResult
{
private:
    string _errorMessage;
    bool _isSuccess;
public:
    FacadeOperationResult() {_isSuccess = true;}
    FacadeOperationResult(bool isSuccess);
    void SetErrorMessage(string errorMessage);
    void SetBoolValue(bool value);
    string GetErrorMessage();
    bool IsSuccess();
};

#endif // FACADEOPERATIONRESULT_H
