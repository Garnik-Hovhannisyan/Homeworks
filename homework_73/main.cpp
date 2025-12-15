#include <iostream>

#include "Vector.h"

int main()
{
	Vector<int> vec(5);

	vec[0] = 5;
	vec[1] = 8;

	std::cout << "vec[0] = " << vec[0] << std::endl;
	std::cout << "vec[1] = " << vec[1] << std::endl;
	std::cout << "vec size = " << vec.size() << std::endl;
    return 0;
}