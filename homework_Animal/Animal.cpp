#include <iostream>
#include "Animal.h"

Animal::Animal(std::string name, std::string color, int age, double weight) 
	: name(name), color(color), age(age), weight(weight) {}

void Animal::eat() const
{
	std::cout << name << " eating" << std::endl;
}

void Animal::sleep() const
{
	std::cout << name << " sleeping" << std::endl;
}

void Animal::info() const 
{
	std::cout << "Name - " << name << std::endl;
	std::cout << "Color - " << color << std::endl;
	std::cout << "Age - " << age << std::endl;
	std::cout << "Weight - " << weight << std::endl;
}

std::string Animal::getName() const
{
	return name;
}

bool Animal::operator>(const Animal& other) const
{
	if (this->weight > other.weight)
	{
		return true;
	}

	else 
	{
		return false;
	}
}

bool Animal::operator<(const Animal& other) const
{
	if (this->weight < other.weight)
	{
		return true;	
	}

	else
	{
		return false;
	}
}

bool Animal::operator==(const Animal& other) const
{
	if (this->weight == other.weight)
	{
		return true;
	}

	else
	{
		return false;
	}
}