#include <iostream>
#include "matrix.h"
#include <ctime>

int main()
{
    srand((unsigned int)time(0));

    Matrix mat1(3, 5);
    Matrix mat2 = mat1;

    std::cout << "Matrix:\n" << mat1 << std::endl;
    std::cout << "Matrix after pre increment:\n" << ++mat2 << std::endl;
    mat2++;
    std::cout << "Matrix after post increment:\n" << mat2 << std::endl;
    std::cout << "Matrix rotated 90 degrees:\n" << mat2.rotate90() << std::endl;
    std::cout << "Matrix multiplication:\n" << mat1 * mat2.rotate90() << std::endl;

    return 0;
}