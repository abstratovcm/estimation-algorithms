#ifndef ASSERTION_H
#define ASSERTION_H

#include <string>
#include <iostream>
#include <sstream>

#include "error.hpp"

#define assertTrue(condition) \
    __assertTrue(#condition, condition, __LINE__, __FILE__)

#define assertFalse(condition) \
    __assertFalse(#condition, condition, __LINE__, __FILE__)

#define assertEquals(expected, actual) \
    __assertEquals(#expected, #actual, expected, actual, __LINE__, __FILE__)

#define assertThrown(error, function, ...) \
    __assertThrown<error>(__LINE__, __FILE__, #error, #function, function, ##__VA_ARGS__)

#define assertNotThrown(error, function, ...) \
    __assertNotThrown<error>(__LINE__, __FILE__, #error, #function, function, ##__VA_ARGS__)
class Assertion
{
public:
    static void __assertTrue(const char *condition_str, bool condition, int line, const char *file);

    static void __assertFalse(const char *condition_str, bool condition, int line, const char *file);

    static void __assertEquals(const char *expected_str, const char *actual_str, bool expected, bool actual, int line, const char *file);

    template <typename ExceptionType, typename FunctionType, typename... Args>
    static void __assertThrown(int line, const char *file, const char *error_str, const char *function_str, FunctionType &&function, Args &&...args);

    template <typename ExceptionType, typename FunctionType, typename... Args>
    static void __assertNotThrown(int line, const char *file, const char *error_str, const char *function_str, FunctionType &&function, Args &&...args);

    static void insertLocation(std::stringstream &error, int line, const char *file);
};

#include "../tpl/assertion.tpp"

#endif // ASSERTION_H