#include <iostream>

#include "Vector.h"
#include "Queue.h"
#include "Stack.h"

int main()
{
	// VECTOR
	std::cout << "Testing Vector class:" << std::endl;
	Vector<int> vec1 = { 1, 2, 3, 4, 5 };

	std::cout << "vec1 info: size = " << vec1.size() << " capacity = " << vec1.capacity() << std::endl;

	for (size_t i = 0; i < vec1.size(); i++)
	{
		std::cout << "vec1[" << i << "] = " << vec1[i] << std::endl;
	}
	// QUEUE
	std::cout << "\nTesting Queue class:" << std::endl;
	Queue<double> q;

	q.push(1.2);
	q.push(2.3);
	q.push(3.4);

	std::cout << "Queue front: " << q.front() << std::endl;
	std::cout << "Queue back: " << q.back() << std::endl;
	std::cout << "Queue size: " << q.size() << std::endl;

	if (q.empty())
	{
		std::cout << "Queue is empty." << std::endl;
	}
	else 
	{
		std::cout << "Queue is not empty." << std::endl;
	}
	// STACK
	std::cout << "\nTesting Stack class:" << std::endl;
	Stack<std::string> s;

	if (s.empty())
	{
		std::cout << "Stack is empty." << std::endl;
	}
	else
	{
		std::cout << "Stack is not empty." << std::endl;
	}

	s.push("first");
	s.push("second");
	s.push("third");

	std::cout << "Stack top: " << s.top() << std::endl;
	std::cout << "Stack size: " << s.size() << std::endl;
	s.pop();
	std::cout << "Stack top after pop: " << s.top() << std::endl;
	std::cout << "Stack size after pop: " << s.size() << std::endl;

	

	return 0;
}