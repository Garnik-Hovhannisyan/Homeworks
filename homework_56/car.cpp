#include <iostream>
#include "Car.h"

Car::Car()
{
	this->brand = "Empty";
	this->model = "Empty";
	this->year = 0;
}

Car::Car(std::string brand, std::string model, int year)
{
	this->brand = brand;
	this->model = model;
	this->year = year;
}

Car::Car(const Car& other)
{
	this->brand = other.brand;
	this->model = other.model;
	this->year = other.year;
}

Car& Car::operator=(const Car& other)
{
	if (this != &other)
	{
		this->brand = other.brand;
		this->model = other.model;
		this->year = other.year;
	}
	return *this;
}

std::ostream& operator << (std::ostream& os, const Car& car)
{
	os << car.brand << " " << car.model << " " << car.year;
	return os;
}