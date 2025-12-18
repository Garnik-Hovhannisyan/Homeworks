#include <iostream>
#include <string>

#include "Engine.h"
#include "Car.h"
#include "Derived.h"
#include "Parking.h"

int main()
{
    int parkingSize = 10;

	Parking& park = Parking::getInstance(parkingSize);

    Toyota car1("Camry", 2025);
    car1.info();
	park.parkCar(car1);

    Nissan car2("Versa", 2024);
    car2.info();
    park.parkCar(car2);

    Bmw car3("X5", 2023);
    car3.info();
    park.parkCar(car3);

    park.info();
    return 0;
}