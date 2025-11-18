#include <iostream>

void my_malloc(size_t size, void** ptr)
{
	*ptr = malloc(size);
}

void* operator new(size_t size)
{
	if (size == 0) size = 1;
	void* ptr = nullptr;
	my_malloc(size, &ptr);

	return ptr;
}

void operator delete(void* ptr)
{
	std::cout << "Memory dealocated! " << std::endl;
	free(ptr);
}

int main()
{
	int size = 13;
	void *ptr = nullptr;
	
	my_malloc(size, &ptr);

	if (!ptr)
	{
		std::cout << "Allocation failed! " << std::endl;
	}
	else
	{
		std::cout << "Memory allocated! " << std::endl;
	}

	delete ptr;
	return 0;
}