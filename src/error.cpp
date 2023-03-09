#include "error.hpp"

Error::Error(const std::string &message) : message_(message) {}

Error::Error(const std::string &message, int line, const char *file)
{
    message_ = message + "\nexception at line " + std::to_string(line) + ", " + file;
}

std::string Error::message() const
{
    return message_;
}
