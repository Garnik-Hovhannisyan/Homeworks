#include <iostream>

#include "List.h"
#include "Queue.h"
#include "Tree.h"

int main()
{
	TreeNode<int>* root = new TreeNode<int>(1);

	TreeNode<int>* node2 = new TreeNode<int>(2); //root children[0]
	TreeNode<int>* node3 = new TreeNode<int>(3);
	TreeNode<int>* node4 = new TreeNode<int>(4);
	TreeNode<int>* node5 = new TreeNode<int>(5);

	TreeNode<int>* node6 = new TreeNode<int>(6); //root children[1]
	TreeNode<int>* node7 = new TreeNode<int>(7);
	TreeNode<int>* node8 = new TreeNode<int>(8);


	root->addChild(node2);
	root->addChild(node6);

	node2->addChild(node3);
	node2->addChild(node4);
	node2->addChild(node5);

	node6->addChild(node7);
	node6->addChild(node8);

	
	root->print(root);

	delete root;
	return 0;
}
