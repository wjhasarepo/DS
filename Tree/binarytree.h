#ifndef TREE_H
#define TREE_H

#include<iostream>
#include"assert.h"
#include"treenode.h"

template<typename Node>
class BinaryTree{
public:
	BinaryTree();
	void insertNode(const Node &);
	void preOrderTraversal() const;
	void inOrderTraversal() const;
	void postOrderTraversal() const;
private:
	TreeNode<Node> *rootPtr;

	void insertNodeHelper(TreeNode<Node> **, const Node &);
	void preOrderHelper(TreeNode<Node> *) const;
	void inOrderHelper(TreeNode<Node> *) const;
	void postOrderHelper(TreeNode<Node> *) const;
};

template<typename Node>
BinaryTree<Node>::Tree() 
{
	rootPtr = 0;
}

template<typename Node>
void BinaryTree<Node>::insertNode(const Node &value)
{
	insertNodeHelper(&rootPtr, value);
}

template<typename Node>
void BinaryTree<Node>::insertNodeHelper(TreeNode<Node> **ptr, const Node &value)
{
	if(*ptr == 0)
	{
		*ptr = new TreeNode<Node>(value);
		assert(*ptr!=0);
	}
	else
	{
		if(value < (*ptr)->data)
			insertNodeHelper(&((*ptr)->leftPtr), value);
		else
			if(value > (*ptr)->data)
				insertNodeHelper(&((*ptr)->rightPtr), value);
			else
				std::cout<<value<<" has duplicates..."<<std::endl;
	}
}

template<typename Node> 
void BinaryTree<Node>::preOrderTraversal() const
{
	preOrderHelper(rootPtr);
}

template<typename Node>
void BinaryTree<Node>::preOrderHelper(TreeNode<Node> *ptr) const
{
	if(ptr!=0)
	{
		std::cout<<ptr->data<<' ';
		preOrderHelper(ptr->leftPtr);
		preOrderHelper(ptr->rightPtr);
	}
}

template<typename Node>
void BinaryTree<Node>::inOrderTraversal() const
{
	inOrderHelper(rootPtr);
}

template<typename Node>
void BinaryTree<Node>::inOrderHelper(TreeNode<Node> *ptr) const
{
	if(ptr!=0)
	{
		inOrderHelper(ptr->leftPtr);
		std::cout<<ptr->data<<' ';
		inOrderHelper(ptr->rightPtr);
	}
}

template<typename Node>
void BinaryTree<Node>::postOrderTraversal() const
{
	postOrderHelper(rootPtr);
}

template<typename Node>
void BinaryTree<Node>::postOrderHelper(TreeNode<Node> *ptr) const
{
	if(ptr!=0)
	{
		postOrderHelper(ptr->leftPtr);
		postOrderHelper(ptr->rightPtr);
		std::cout<<ptr->data<<' ';
	}
}

#endif
