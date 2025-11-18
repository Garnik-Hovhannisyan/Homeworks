#include <iostream>
#include <string>

#include "engine.h"
#include "car.h"
#include "derived.h"

int main()
{
    Toyota car1("Camry", 2025);
    car1.info();
    Nissan car2("Versa", 2024);
    car2.info();
    Bmw car3("X5", 2023);
    car3.info();

    return 0;
}