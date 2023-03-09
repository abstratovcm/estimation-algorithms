template <typename ExceptionType, typename FunctionType, typename... Args>
void Assertion::__assertThrown(int line, const char *file, const char *error_str, const char *function_str, FunctionType &&function, Args &&...args)
{
    std::stringstream error;
    try
    {
        function(std::forward<Args>(args)...);
    }
    catch (const ExceptionType &)
    {
        // Expected exception was thrown
        return;
    }
    catch (...)
    {
        // Unexpected exception was thrown
        insertLocation(error, line, file);
        error << "unexpected exception was thrown at the function " << function_str;
        throw(Exception(error.str()));
    }
    // No exception was thrown
    insertLocation(error, line, file);
    error << "expected exception (" << error_str << ") was not thrown at the function " << function_str;
    throw(Exception(error.str()));
}

template <typename ExceptionType, typename FunctionType, typename... Args>
void Assertion::__assertNotThrown(int line, const char *file, const char *error_str, const char *function_str, FunctionType &&function, Args &&...args)
{
    std::stringstream error;
    try
    {
        function(std::forward<Args>(args)...);
    }
    catch (const ExceptionType &)
    {
        // Expected exception was thrown
        insertLocation(error, line, file);
        error << "expected exception (" << error_str << ") was thrown at the function " << function_str;
        throw(Exception(error.str()));
        return;
    }
    catch (...)
    {
        // Unexpected exception was thrown
        insertLocation(error, line, file);
        error << "unexpected exception was thrown at the function " << function_str;
        throw(Exception(error.str()));
    }
    // No exception was thrown
    return;
}