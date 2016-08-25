// Driver to test class tree

#include<iostream>
#include"binarytree.h"
#include"rbtree.h"

int main()
{
	RBTree<int> rbtree;
	int val;
	
	for(int i = 0; i < 10; i++)
	{
		std::cin>>val;
		rbtree.insertNode(val);
	}

	//tree.preOrderTraversal();
	rbtree.inOrderTraversal();
	//tree.postOrderTraversal();
	
	return 0;
}
