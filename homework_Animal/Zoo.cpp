#include <iostream>

#include "Zoo.h"
#include "Animal.h"
#include "Derived.h"

Zoo::Zoo(int size) : size(size)
{
	arr = new Animal* [size];

	for (int i = 0; i < size; i++)
	{
		arr[i] = nullptr;
	}
}

Zoo::Zoo(const Zoo& other) : size(other.size)
{
	arr = new Animal* [size];

	for (int i = 0; i < size; i++)
	{
		arr[i] = other.arr[i]->clone();
	}
}

Zoo& Zoo::operator=(const Zoo& other)
{
	if (this != &other)
	{
		for (int i = 0; i < size; i++)
		{
			delete arr[i];
		}
		delete[] arr;

		size = other.size;
		arr = new Animal* [size];

		for (int i = 0; i < size; i++)
		{
			arr[i] = other.arr[i]->clone();
		}
	}
	return *this;
}

Zoo::Zoo(Zoo&& other) : size(other.size), arr(other.arr)
{
	other.size = 0;
	other.arr = nullptr;
}

Zoo& Zoo::operator=(Zoo&& other)
{
	if (this != &other)
	{
		for (int i = 0; i < size; i++)
		{
			delete arr[i];
		}
		delete[] arr;
	}

	size = other.size;
	arr = other.arr;

	other.size = 0;
	other.arr = nullptr;

	return *this;
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
	for (int i = 0; i < size; i++)
	{
		delete arr[i];
	}
	delete[] arr;
}