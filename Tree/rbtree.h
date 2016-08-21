#ifndef RBTREE_H
#define RBTREE_H

#include<iostream>
#include"assert.h"
#include"rbtreenode.h"

template<typename Node>
class RBTree{
public:
	RBTree();
	void insertNode(const Node &);
	void insertFix(const Node &);
	void leftRotate(const Node &);
private:
	TreeNode<Node> *rootPtr;

	void insertNodeHelper(TreeNode<Node> **, const Node &);
	void insertFixHelper(TreeNode<Node> **, const Node &);
	void leftRotateHelper(TreeNode<Node> **, const Node &);
};

template<typename Node>
RBTree<Node>::Tree() 
{
	rootPtr = 0;
}

template<typename Node>
void RBTree<Node>::insertNodeHelper(TreeNode<Node> **ptr, const Node &value)
{
	if(*ptr == 0)
	{
		*ptr = new RBTreeNode(value);
		assert(*ptr!=0);
	}
	else
	{
		if(value < (*ptr)->value)
			insertNodeHelper(&((*ptr)->leftPtr), value);
		else if(value > (*ptr)->value)
			insertNodeHelper(&((*ptr)->rightPtr), value);
		else
			std::cout<<value<<" has duplicates..."<<std::endl;
	}
}

template<typename Node>
void RBTree<Node>::insertFixHelper(TreeNode<Node> **x_ptr, const Node &value)
{
	(*x_ptr)->color = "red";
	while ( ((*ptr) != *rootPtr && ((*ptr)->parent->color == "red") ) 
	{
       	if ( (*ptr)->parent == (*ptr)->parent->parent->leftPtr ) 
		{
           	/* If x's parent is a left, y is x's right 'uncle' */
           	*y_ptr = (*x_ptr)->parent->parent->rightPtr;
           	if ( *y_ptr->colour == "red" ) 
			{
				/* case 1 - change the colours */
				(*x_ptr)->parent->color = "black";
				(*x_ptr)->colour = "black";
				(*x_ptr)->parent->parent->color = "red";
				/* Move x up the tree */
				*x_ptr = (*x_ptr)->parent->parent;
           	}
           	else 
			{
				/* y is a black node */
				if ( (*x_ptr) == (*x_ptr)->parent->rightPtr ) {
					/* and x is to the right */ 
					/* case 2 - move x up and rotate */
					*x_ptr = (*x_ptr)->parent;
					left_rotate( T, &(*x_ptr) );
				}
				/* case 3 */
				(*x_ptr)->parent->colour = "black";
				(*x_ptr)->parent->parent->colour = "red";
				rightRotate( T, &((*x_ptr)->parent->parent) );
			}
       }
       else 
	   {
           /* repeat the "if" part with right and left
              exchanged */
       }
	}
    /* Colour the root black */
    rootPtr->colour = "black"; 
}
