#ifndef QUEUE_H
#define QUEUE_H

#include "List.h"

namespace myQueue
{
template <typename T>
class Queue : public mylist::List<T>
{
public:
	void push(const T& val)
	{
		this->push_back(val);
	}

	void pop()
	{
		this->pop_front();
	}

	T& front()
	{
		return mylist::List<T>::front();
	}

	bool empty() const
	{
		return mylist::List<T>::empty();
	}
};
}

#endif // QUEUE_H