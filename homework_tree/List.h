#ifndef LIST_H
#define LIST_H

namespace mylist
{
template <typename T>
class List
{
protected:
	struct Node
	{
		Node* next;
		T m_data;

		Node() : next(nullptr) {}
		Node(T val) : next(nullptr), m_data(val) {}
	};

	Node* head;
	
public:
	List() : head(nullptr){}

	void push_front(const T& val)
	{
		Node* newNode = new Node(val);
		newNode->next = head;
		head = newNode;
	}

	void pop_front()
	{
		if (head != nullptr)
		{
			Node* temp = head;
			head = head->next;
			delete temp;
		}
	}

	void push_back(const T& val)
	{
		Node* newNode = new Node(val);
		if (head == nullptr)
		{
			head = newNode;
		}
		else 
		{
			Node* temp = head;
			while (temp->next != nullptr)
			{
				temp = temp->next;
			}
			temp->next = newNode;
		}
	}

	void pop_back()
	{
		if (head == nullptr) return;

		if (head->next == nullptr)
		{
			delete head;
			head = nullptr;
		}
		else
		{
			Node* temp = head;
			while (temp->next->next != nullptr)
			{
				temp = temp->next;
			}

			delete temp->next;
			temp->next = nullptr;
		}
	}

	bool empty() const
	{
		return head == nullptr;
	}

	T& front()
	{
		return head->m_data;
	}

	List(const List& other) = delete;
	List operator=(const List& other) = delete;

	~List()
	{
		while (head != nullptr)
		{
			pop_front();
		}
	}
};
}

#endif // LIST_H