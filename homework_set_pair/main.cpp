#include <iostream>

#include "Set.h"
#include "Pair.h"

int main()
{
	// CLASS SET
	std::cout << "CHECK CLASS SET:" << std::endl;
    Set<int> set1;
	set1.insert(8);
	set1.insert(5);
	set1.insert(85);
	set1.insert(58);
	set1.insert(12);
	set1.insert(21);
	set1.insert(34);
	set1.insert(43);

	std::cout << "Set contains 21: " << (set1.contains(21) ? "true" : "false") << std::endl;
	std::cout << "Set contains 77: " << (set1.contains(77) ? "true" : "false") << std::endl;

	std::cout << "Preorder traversal: ";
	set1.preorder();
	std::cout << "\nPostorder traversal: ";
	set1.postorder();
	std::cout << "\nInorder traversal: ";
	set1.inorder();

	// CLASS PAIR
	std::cout << "\n\nCHECK CLASS PAIR:" << std::endl;

	Pair<int, std::string> pair1(5,"Hello World!");
	std::cout << "Key = " << pair1.getFirst() << std::endl;
	std::cout << "Value = " << pair1.getSecond() << std::endl;
    return 0;
}
