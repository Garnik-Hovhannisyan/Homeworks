#include <iostream>

#include "Parking.h"

Parking::Parking(int total) : m_total(total), m_occupied(0) {}

bool Parking::parkCar(const Car& car)
{
	if (m_occupied < m_total)
	{
		m_occupied++;
		std::cout << "Car parked successfully." << std::endl;
		return true;
	}
	else
	{
		std::cout << "Parking is full." << std::endl;
		return false;
	}
}

void Parking::leaveCar(const Car& car)
{
	if (m_occupied > 0)
	{
		m_occupied--;
		std::cout << "Car left the parking." << std::endl;
	}
	else
	{
		std::cout << "No cars in the parking." << std::endl;
	}
}

void Parking::info()
{
	std::cout << "\nParking Information: " << std::endl;
	std::cout << "Total spots: " << m_total << std::endl;
	std::cout << "Occupied spots: " << m_occupied << std::endl;
}

Parking& Parking::getInstance(int total)
{
	static Parking instance(total);
	return instance;
}
