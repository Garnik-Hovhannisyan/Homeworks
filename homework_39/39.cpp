#include <iostream>
#include <ctime>

void fillArray(int* arr, int size)
{
	for (int i = 0; i < size; i++)
	{
		arr[i] = rand() % 10;
	}
}

void printArray(int* arr, int size)
{
	for (int i = 0; i < size; i++)
	{
		std::cout << arr[i] << " ";
	}
	std::cout << std::endl;
}

void* operator new[](size_t size)
{
	if (size == 0) size = 1;
	std::cout << "Allocated: " << size << " bytes" << std::endl;
	return malloc(size);
}

void operator delete[](void* ptr)
{
	std::cout << "Dealocated: " << std::endl;
	free(ptr);
}

int main()
{
	srand(time(0));
	int size = 13;

	int* arr = new int[size];

	fillArray(arr, size);
	printArray(arr, size);

	delete[] arr;
	return 0;
}