// Driver to test class tree

#include<iostream>
#include"binarytree.h"

int main()
{
	Tree<int> tree;
	int val;
	
	for(int i = 0; i < 10; i++)
	{
		std::cin>>val;
		tree.insertNode(val);
	}

	tree.preOrderTraversal();
	tree.inOrderTraversal();
	tree.postOrderTraversal();
	
	return 0;
}
