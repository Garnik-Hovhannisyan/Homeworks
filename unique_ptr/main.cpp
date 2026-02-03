#include <iostream>
#include <utility>

#include "unique_ptr.h"

int main()
{
    my::unique_ptr<int> ptr1(new int(5));
    my::unique_ptr<int> ptr2(new int(8));

	// TEST SWAP
	std::cout << "Before swap: ptr1 = " << *ptr1 << ", ptr2 = " << *ptr2 << std::endl;
	ptr1.swap(ptr2);
	std::cout << "After swap: ptr1 = " << *ptr1 << ", ptr2 = " << *ptr2 << std::endl;	

	// TEST RESET
	std::cout << "\nBefore reset ptr1 = " << *ptr1 << std::endl;
	ptr1.reset(new int(58));
	std::cout << "After reest ptr1 = " << *ptr1 << std::endl;

	// TEST RELEASE
	int* temp_ptr = nullptr;
	std::cout << "\nBefore release ptr1 = " << *ptr1 << std::endl;
	temp_ptr = ptr1.release();
	if (ptr1.get() == nullptr)
	{
		std::cout << "After release ptr1 = nullptr" << std::endl;
	}
	if (temp_ptr != nullptr)
	{
		std::cout << "Temp pointer = " << *temp_ptr << std::endl;
	}
	delete temp_ptr;

    return 0;
}