#include <iostream>

void* operator new(size_t size)
{
	if (size == 0) size = 1;
	std::cout << "Allocated: " << size << " bytes" << std::endl;
	return malloc(size);
}

void operator delete(void* ptr, size_t size)
{
	std::cout << "Dealocated: " << size << " bytes" << std::endl;
	free(ptr);
}

int main()
{
	int size = 13;

	int* ptr = new int(size);
	delete ptr;

	return 0;
}