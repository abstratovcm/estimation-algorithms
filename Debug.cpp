#include <iostream>
#include "matrix.hpp"

int main()
{

    Matrix<int> test(3, 4, 3);
    Matrix<int> test2(5, 5, 2);
    test.printSize();

    test = test2;
    test(2, 2) = 4;
    test(0, 0) = 2;
    test(0, 2) = 0;
    test.print();
    test.printSize();
    std::cout << "transpose:" << std::endl;
    test.printTranspose();
    test.reshape();
    test.print();
    test.printSize();
    test.printTranspose();

    return 0;
}
