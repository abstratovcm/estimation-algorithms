#ifndef ERROR_H
#define ERROR_H

#include <string>

#define Exception(message) Error(message, __LINE__, __FILE__)

class Error
{
public:
    Error(const std::string &message);
    Error(const std::string &message, int line, const char *file);
    std::string message() const;

private:
    std::string message_;
};

#endif // ERROR_H