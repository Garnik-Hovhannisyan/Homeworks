#include <iostream>
#include <list>
#include <ctime>

void deleteOddNumbers(std::list<int>& l)
{
	for (auto it = l.begin(); it != l.end(); )
	{
		if (*it % 2 != 0)
		{
			it = l.erase(it);
		}
		else
		{
			++it;
		}
	}
}

int main()
{
	srand(time(0));

	std::list<int> l1;
	for (int i = 0; i < 10; i++)
	{
		l1.push_back(rand() % 100);
	}

	std::cout << "Before: ";
	for (auto i : l1)
	{
		std::cout << i << " ";
	}

	deleteOddNumbers(l1);
	std::cout << "\nAfter: ";
	for (auto i : l1)
	{
		std::cout << i << " ";
	}

    return 0;
}