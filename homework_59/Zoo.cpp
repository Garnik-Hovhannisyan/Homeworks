#include <iostream>

#include "Zoo.h"
#include "Animal.h"
#include "Derived.h"

Zoo::Zoo(int size) : size(size)
{
	std::cout << "CALL ZOO CONSTRUCTOR" << std::endl;
	arr = new Animal* [size];

	for (int i = 0; i < size; i++)
	{
		arr[i] = nullptr;
	}
}

void Zoo::showVoice() const
{
	for (int i = 0; i < size; i++)
	{
		arr[i]->voice();
	}
}

void Zoo::showInfo() const
{
	for (int i = 0; i < size; i++)
	{
		arr[i]->info();
	}
}

Zoo::~Zoo()
{
	std::cout << "CALL ZOO DESTRUCTOR" << std::endl;
	for (int i = 0; i < size; i++)
	{
		delete arr[i];
	}
}