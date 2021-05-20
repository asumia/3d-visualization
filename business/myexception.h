#ifndef MYEXCEPTION_H
#define MYEXCEPTION_H

#include <iostream>

using namespace  std;

class myException : exception
{
private:
    string s;
public:
    myException(std::string str) : s(str) {}
    ~myException() throw() {}
    const char * what() const throw ()
    {
        return s.c_str();
    }
};

#endif // MYEXCEPTION_H
