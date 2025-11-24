#include <iostream>
#include "Amphibian.h"

void Amphibian::check() const
{
	if (inLand && inWater)
	{
		std::cout << "Animal is ambphibian!" << std::endl;
	}
	else
	{
		std::cout << "Animal is not ambphibian!" << std::endl;
	}
}
