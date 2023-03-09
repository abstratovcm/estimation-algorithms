#include <iostream>
#include "matrix.hpp"
#include "assertion.hpp"

bool IsGreaterThan3(int num)
{
    if (num <= 3)
    {
        return false;
    }
    return true;
}

bool Test()
{
    return false;
}

int main()
{
    try
    {
        Assertion::assertThrown(Error, IsGreaterThan3, 1);
    }
    catch (Error &error)
    {
        std::cout << error.message() << std::endl;
    }

    return 0;
}
