#include <iostream>

#include "Car.h"
#include "Engine.h"

Car::Car() : m_brand("Empty"), m_model("Empty"), m_year(0) {}

Car::Car(std::string brand, std::string model, int year) : m_brand(brand), m_model(model), m_year(year) {}

void Car::engineON()
{
	m_engine.start();
}

void Car::engineOFF()
{
	m_engine.stop();
}

void Car::drive() const
{
	if (m_engine.engineStatus())
	{
		std::cout << "Driving. The engine is ON " << std::endl;
	}
	else
	{
		std::cout << "Cannot drive. The engine is OFF." << std::endl;
	}
}

void Car::stop()
{
	std::cout << "Car stopped." << std::endl;
}

void Car::info()
{
	std::cout << "Model - " << m_model << std::endl;
	std::cout << "Year - " << m_year << std::endl;
}