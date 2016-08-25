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
	void inOrderTraversal() const;
private:
	RBTreeNode<Node> **rootPtr;

	void insertNodeHelper(RBTreeNode<Node> **, const Node &);
	void insertFixHelper(RBTreeNode<Node> **, const Node &);
	void leftRotateHelper(RBTreeNode<Node> **, const Node &);
	void rightRotateHelper(RBTreeNode<Node> **, const Node &);
	
	void inOrderHelper(RBTreeNode<Node> **) const;
};

template<typename Node>
RBTree<Node>::RBTree() 
{
	rootPtr = 0;
}

template<typename Node>
void RBTree<Node>::insertNode(const Node &value)
{
	insertNodeHelper(&(*rootPtr), value);
}

template<typename Node>
void RBTree<Node>::insertNodeHelper(RBTreeNode<Node> **ptr, const Node &value)
{
	if(*ptr == 0)
	{
		*ptr = new RBTreeNode<Node>(value);
		assert(*ptr!=0);
		
		insertFixHelper(&(*ptr), value);
	}
	else
	{
		if(value < (*ptr)->data)
			insertNodeHelper(&((*ptr)->leftPtr), value);
		else if(value > (*ptr)->data)
			insertNodeHelper(&((*ptr)->rightPtr), value);
		else
			std::cout<<value<<" has duplicates..."<<std::endl;
	}
}

template<typename Node>
void RBTree<Node>::insertFixHelper(RBTreeNode<Node> **x_ptr, const Node &value)
{
	(*x_ptr)->color = "red";
	while ( (*x_ptr)->data != (*rootPtr)->data && ((*x_ptr)->parent->color == "red") ) 
	{
       		if ( (*x_ptr)->parent == (*x_ptr)->parent->parent->leftPtr ) 
		{
           		/* If x's parent is a left, y is x's riRBht 'uncle' */
           		RBTreeNode<Node> **y_ptr;
			*y_ptr = (*x_ptr)->parent->parent->rightPtr;
           		if ((*y_ptr)->color == "red") 
			{
				/* case 1 - change the colors */
				(*x_ptr)->parent->color = "black";
				(*x_ptr)->color = "black";
				(*x_ptr)->parent->parent->color = "red";
				/* Move x up the tree */
				*x_ptr = (*x_ptr)->parent->parent;
           		}
           		else 
			{
				/* y is a black node */
				if ((*x_ptr) == (*x_ptr)->parent->rightPtr) 
				{
					/* and x is to the right */ 
					/* case 2 - move x up and rotate */
					*x_ptr = (*x_ptr)->parent;
					leftRotateHelper(&(*x_ptr), value);
				}
				/* case 3 */
				(*x_ptr)->parent->color = "black";
				(*x_ptr)->parent->parent->color = "red";
				rightRotateHelper(&((*x_ptr)->parent->parent), value);
			}
       		}
       		else 
		{
          		 /* repeat the "if" part with right and left exchanged */
			/* If x's parent is a left, y is x's right 'uncle' */
                        RBTreeNode<Node> **y_ptr;
			*y_ptr = (*x_ptr)->parent->parent->leftPtr;
                        if ((*y_ptr)->color == "red")
                        {
                                /* case 1 - chanRBe the colors */
                                (*x_ptr)->parent->color = "black";
                                (*x_ptr)->color = "black";
                                (*x_ptr)->parent->parent->color = "red";
                                /* Move x up the tree */
                                *x_ptr = (*x_ptr)->parent->parent;
                        }
                        else
                        {
                                /* y is a black node */
                                if (*x_ptr == (*x_ptr)->parent->leftPtr) {
                                        /* and x is to the right */
                                        /* case 2 - move x up and rotate */
                                        *x_ptr = (*x_ptr)->parent;
                                        leftRotateHelper(&(*x_ptr), value);
                                }
                                /* case 3 */
                                (*x_ptr)->parent->color = "black";
                                (*x_ptr)->parent->parent->color = "red";
                                leftRotateHelper(&((*x_ptr)->parent->parent), value);
                        }

       		}
	}
    	/* Colour the root black */
    	(*rootPtr)->color = "black"; 
}

template<typename Node>
void RBTree<Node>::leftRotateHelper(RBTreeNode<Node> **x_ptr, const Node &value)
{
	RBTreeNode<Node> **y_ptr;
	*y_ptr = (*x_ptr)->rightPtr;
	(*x_ptr)->rightPtr = (*y_ptr)->leftPtr;
	(*y_ptr)->leftPtr->parent = *x_ptr;
	(*y_ptr)->parent = (*x_ptr)->parent;
	if ( (*x_ptr)->parent == NULL )
	{ 
		rootPtr = &(*y_ptr);
	}
    	else
	{
		/* x was on the left of its parent */
        	if ( (*x_ptr) == (*x_ptr)->parent->leftPtr )
            		(*x_ptr)->parent->leftPtr = *y_ptr;
		/* x must have been on the right */
        	else
            		(*x_ptr)->parent->rightPtr = *y_ptr;
	}
    	/* Finally, put x on y's left */
    	(*y_ptr)->leftPtr = *x_ptr;
    	(*x_ptr)->parent = *y_ptr;
}

template<class Node>
void RBTree<Node>::rightRotateHelper(RBTreeNode<Node> **x_ptr, const Node &value)
{
        RBTreeNode<Node> **y_ptr;
        *y_ptr = (*x_ptr)->leftPtr;
        (*x_ptr)->leftPtr = (*y_ptr)->leftPtr;
        (*y_ptr)->rightPtr->parent = *x_ptr;
        (*y_ptr)->parent = (*x_ptr)->parent;
        if ( (*x_ptr)->parent == 0 )
	{
                rootPtr = &(*y_ptr);
	}
        else
        {
                /* x was on the left of its parent */
                if (*x_ptr == (*x_ptr)->parent->leftPtr)
                        (*x_ptr)->parent->rightPtr = *y_ptr;
                /* x must have been on the right */
                else
                        (*x_ptr)->parent->leftPtr = *y_ptr;
        }
        /* Finally, put x on y's left */
        (*y_ptr)->leftPtr = *x_ptr;
        (*x_ptr)->parent = *y_ptr;
}

template<typename Node>
void RBTree<Node>::inOrderTraversal() const
{
        inOrderHelper(&(*rootPtr));
}

template<typename Node>
void RBTree<Node>::inOrderHelper(RBTreeNode<Node> **ptr) const
{
        if(ptr!=0)
        {
                inOrderHelper(&(*ptr)->leftPtr);
                std::cout<<(*ptr)->data<<' '<<(*ptr)->color<<' ';
                inOrderHelper(&(*ptr)->rightPtr);
        }
}

#endif
