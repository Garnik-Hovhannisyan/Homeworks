#include <iostream>

#include "Derived.h"
#include "Car.h"

// TOYOTA
Toyota::Toyota() : Car("Toyota", "Empty", 0) {}

Toyota::Toyota(std::string m_model, int m_year)
	: Car("Toyota", m_model, m_year) {
}

void Toyota::info()
{
	std::cout << "\nCar Information: " << std::endl;
	std::cout << "Brand - " << m_brand << std::endl;
	Car::info();
}

// NISSAN
Nissan::Nissan() : Car("Nissan", "Empty", 0) {}

Nissan::Nissan(std::string m_model, int m_year)
	: Car("Nissan", m_model, m_year) {
}

void Nissan::info()
{
	std::cout << "\nCar Information: " << std::endl;
	std::cout << "Brand - " << m_brand << std::endl;
	Car::info();
}

// BMW
Bmw::Bmw() : Car("Bmw", "Empty", 0) {}

Bmw::Bmw(std::string m_model, int m_year)
	: Car("Bmw", m_model, m_year) {
}

void Bmw::info()
{
	std::cout << "\nCar Information: " << std::endl;
	std::cout << "Brand - " << m_brand << std::endl;
	Car::info();
}