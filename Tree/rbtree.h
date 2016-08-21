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
	void rightRotate(const Node &);
private:
	Node<Node> *rootPtr;

	void insertNodeHelper(Node<Node> **, const Node &);
	void insertFixHelper(Node<Node> **, const Node &);
	void leftRotateHelper(Node<Node> **, const Node &);
	void rightRotateHelper(Node<Node> **, const Node &);
};

template<typename Node>
RBTree<Node>::Tree() 
{
	rootPtr = 0;
}

template<typename Node>
RBTree<Node>::insertNode(const Node &value);
{
	insertNodeHelper(&rootPtr, value);
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
           		/* If x's parent is a left, y is x's riRBht 'uncle' */
           		*y_ptr = (*x_ptr)->parent->parent->rightPtr;
           		if ( *y_ptr->colour == "red" ) 
			{
				/* case 1 - chanRBe the colours */
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
					leftRotate( T, &(*x_ptr) );
				}
				/* case 3 */
				(*x_ptr)->parent->colour = "black";
				(*x_ptr)->parent->parent->colour = "red";
				rightRotate( T, &((*x_ptr)->parent->parent) );
			}
       		}
       		else 
		{
          		 /* repeat the "if" part with right and left exchanged */
			/* If x's parent is a left, y is x's right 'uncle' */
                        *y_ptr = (*x_ptr)->parent->parent->leftPtr;
                        if ( *y_ptr->colour == "red" )
                        {
                                /* case 1 - chanRBe the colours */
                                (*x_ptr)->parent->color = "black";
                                (*x_ptr)->colour = "black";
                                (*x_ptr)->parent->parent->color = "red";
                                /* Move x up the tree */
                                *x_ptr = (*x_ptr)->parent->parent;
                        }
                        else
                        {
                                /* y is a black node */
                                if ( (*x_ptr) == (*x_ptr)->parent->leftPtr ) {
                                        /* and x is to the right */
                                        /* case 2 - move x up and rotate */
                                        *x_ptr = (*x_ptr)->parent;
                                        leftRotate( T, &(*x_ptr) );
                                }
                                /* case 3 */
                                (*x_ptr)->parent->colour = "black";
                                (*x_ptr)->parent->parent->colour = "red";
                                leftRotate( T, &((*x_ptr)->parent->parent) );
                        }

       		}
	}
    	/* Colour the root black */
    	rootPtr->colour = "black"; 
}

template<class Node>
void leftRotateHelper(TreeNode<Node> **x_ptr, const Node &value)
{
	TreeNode<Node> **y_ptr;
	(*y_ptr) = (*x_ptr)->rightPtr;
	(*x_ptr)->rightPtr = (*y_ptr)->leftPtr;
	(*y_ptr)->leftPtr->parent = (*x_ptr);
	(*y_ptr)->parent = (*x_ptr)->parent;
	if ( (*x_ptr)->parent == NULL )
	{ 
		rootPtr = y_ptr;
	}
    	else
	{
		/* x was on the left of its parent */
        	if ( (*x_ptr) == (*x_ptr)->parent->left )
            		(*x_ptr)->parent->left = (*y_ptr);
		/* x must have been on the right */
        	else
            		(*x_ptr)->parent->right = (*y_ptr);
	}
    	/* Finally, put x on y's left */
    	(*y_ptr)->leftPtr = (*x_ptr);
    	(*x_ptr)->parent = (*y_ptr);
}

template<class Node>
void rightRotateHelper(TreeNode<Node> **x_ptr, const Node &value)
{
        TreeNode<Node> **y_ptr;
        (*y_ptr) = (*x_ptr)->leftPtr;
        (*x_ptr)->leftPtr = (*y_ptr)->leftPtr;
        (*y_ptr)->rightPtr->parent = (*x_ptr);
        (*y_ptr)->parent = (*x_ptr)->parent;
        if ( (*x_ptr)->parent == 0 )
	{
                rootPtr = y_ptr;
	}
        else
        {
                /* x was on the left of its parent */
                if ( (*x_ptr) == (*x_ptr)->parent->leftPtr )
                        (*x_ptr)->parent->rightPtr = (*y_ptr);
                /* x must have been on the right */
                else
                        (*x_ptr)->parent->leftPtr = (*y_ptr);
        }
        /* Finally, put x on y's left */
        (*y_ptr)->leftPtr = (*x_ptr);
        (*x_ptr)->parent = (*y_ptr);
}

