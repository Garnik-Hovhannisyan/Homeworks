#include <iostream>

#include "List.h"

int main()
{
    mylist::List<int> listInt;
    listInt.push_back(10);
	listInt.push_front(20);
	listInt.pop_back();

    mylist::List<char> listChar;
	listChar.push_back('A');
    listChar.push_front('B');
    listChar.pop_back();

	return 0;
}
