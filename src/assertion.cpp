#include "assertion.hpp"

void Assertion::__assertTrue(const char *condition_str, bool condition, int line, const char *file)
{
    std::stringstream error;
    if (!condition)
    {
        insertLocation(error, line, file);
        error << "expecting true but it is false: " << condition_str;
        throw(Exception(error.str()));
    }
}

void Assertion::__assertFalse(const char *condition_str, bool condition, int line, const char *file)
{
    std::stringstream error;
    if (condition)
    {
        insertLocation(error, line, file);
        error << "expecting false but it is true: " << condition_str;
        throw(Exception(error.str()));
    }
}

void Assertion::__assertEquals(const char *expected_str, const char *actual_str, bool expected, bool actual, int line, const char *file)
{
    std::stringstream error;
    if (expected != actual)
    {
        insertLocation(error, line, file);
        error << "expecting " << expected_str << " to be equal to " << actual_str << ", but it is different";
        throw(Exception(error.str()));
    }
}

void Assertion::insertLocation(std::stringstream &error, int line, const char *file)
{
    error << "assertion: line " << line << ", file " << file << std::endl;
}