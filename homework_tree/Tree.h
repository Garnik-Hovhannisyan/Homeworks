#ifndef TREE_H
#define TREE_H

#include <iostream>
#include <vector>
#include "Queue.h"

template <typename T>
struct TreeNode
{
	T m_val;
	std::vector<TreeNode*> childrens;

	TreeNode() {}
	TreeNode(T val) : m_val(val) {}

	void addChild(TreeNode* child)
	{
		childrens.push_back(child);
	}

	void print(TreeNode<T>* root) const
	{
		myQueue::Queue<TreeNode<T>*> q;
		q.push(root);

		while (!q.empty())
		{
			TreeNode<T>* current = q.front();
			q.pop();

			for (auto i = 0; i < current->childrens.size(); i++)
			{
				q.push(current->childrens[i]);
			}
			std::cout << "val = " << current->m_val << std::endl;
		}
	}

	~TreeNode()
	{
		for (auto child : childrens)
		{
			delete child;
		}
	}
};

#endif // TREE_H