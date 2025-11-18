#include <iostream>
#include "Matrix.h"
#include "Car.h"

int main()
{
    Matrix mat(3, 1);

    Car car1("Toyota", "Corolla", 2020);
    Car car2("Nissan", "Versa", 2021);
    Car car3("Bmw", "X5", 2022);
    
    mat[0][0] = car1;
    mat[1][0] = car2;
    mat[2][0] = car3;

    std::cout << mat << std::endl;
}
