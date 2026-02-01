#include <iostream>
#include <exception>

#include "Vector.h"
#include "Queue.h"
#include "Stack.h"
#include "MyException.h"

int main()
{
	// VECTOR
	std::cout << "Testing Vector class:" << std::endl;
	my::Vector<int> vec1 = { 1, 2, 3, 4, 5 };

	std::cout << "vec1 info: size = " << vec1.size() << " capacity = " << vec1.capacity() << std::endl;

	for (size_t i = 0; i < vec1.size(); i++)
	{
		std::cout << "vec1[" << i << "] = " << vec1[i] << std::endl;
	}

	try
	{
		vec1.at(8);
	}
	catch (const MyException& ex)
	{
		std::cout << "\nException: " << ex.what() << std::endl;

	}
	catch (...)
	{
		std::cout << "UNKNOWN ERROR" << std::endl;
	}

	return 0;
}