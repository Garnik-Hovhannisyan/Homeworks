#include <iostream>

#include "Vector.h"

int main()
{
	Vector<int> vec1 = { 1, 2, 3, 4, 5 };

	std::cout << "vec1 information: size = " << vec1.size() << " capacity = " << vec1.capacity() << std::endl;
	for (int i = 0; i < vec1.size(); i++)
	{
		std::cout << "vec1[" << i << "] = " << vec1[i] << std::endl;
	}

	Vector<double> vec2;
	vec2.push_back(3.14);
	vec2.push_back(5.08);
	vec2.push_back(8.05);
	std::cout << "\nvec2 information: size = " << vec2.size() << " capacity = " << vec2.capacity() << std::endl;
	for (int i = 0; i < vec2.size(); i++)
	{
		std::cout << "vec2[" << i << "] = " << vec2[i] << std::endl;
	}
	

    return 0;
}