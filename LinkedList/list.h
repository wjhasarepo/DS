#ifndef LIST_H
#define LIST_H

#include <iostream>
#include "assert.h"
#include "listnode.h"
using namespace std;

template<class Node>
class List{
public:
	List();
	~List();
	void insertAtFront(const Node &);
	void insertAtBack(const Node &);
	bool removeFromFront();
	bool removeFromBack();
	bool removeAt(Node &);
	bool isEmpty() const;
	void print() const;
private:
	ListNode<Node> *firstPtr;
	ListNode<Node> *lastPtr;
	ListNode<Node> *getNewNode(const Node &);
};

template<class Node>
List<Node>::List(): firstPtr(0), lastPtr(0) {}

template<class Node>
List<Node>::~List()
{
	if(!isEmpty())
	{
		cout<<"Destroy nodes ..."<<endl;
		ListNode<Node> *curPtr = firstPtr;
		ListNode<Node> *tempPtr;

		while(curPtr != 0)
		{
			tempPtr = curPtr;
			cout<<tempPtr->data<<endl;
			curPtr = curPtr->nextPtr;
			delete tempPtr;
		}
	}

	cout<<"All node destroyed"<<endl;
}

template<class Node>
void List<Node>::insertAtFront(const Node &value)
{
	ListNode<Node> *newPtr = getNewNode(value);
	
	if(isEmpty())
		firstPtr = lastPtr = newPtr;
	else
		newPtr->nextPtr = firstPtr;
		firstPtr = newPtr;
}

template<class Node>
void List<Node>::insertAtBack(const Node &value)
{
	ListNode<Node> *newPtr = getNewNode(value);
	
	if(isEmpty())
		firstPtr = lastPtr = newPtr;
	else
		lastPtr->nextPtr = newPtr;
		lastPtr = newPtr;
}

template<class Node>
bool List<Node>::removeFromFront()
{
	if(isEmpty())
		return false;
	else
	{
		ListNode<Node> *tempPtr = firstPtr;

		if(firstPtr == lastPtr)
			firstPtr = lastPtr = 0;
		else
			firstPtr = firstPtr->next;

		delete tempPtr;
	}

	return true;
}

template<class Node>
bool List<Node>::removeFromBack()
{
	if(isEmpty())
		return false;
	else
	{
		ListNode<Node> *tempPtr = lastPtr;

		if(firstPtr == lastPtr)
			firstPtr = lastPtr = 0;
		else
		{
			ListNode<Node> *currentPtr = firstPtr;

			while(currentPtr->nextPtr != lastPtr)
				currentPtr = currentPtr->nextPtr;

			lastPtr = currentPtr;
			currentPtr->nextPtr = 0;
		}

		delete tempPtr;
	}

	return true;
}

template<class Node>
bool List<Node>::removeAt(Node &value)
{
	if(isEmpty())
		return false;
	else
	{
		ListNode<Node> **tempPtr = &firstPtr;
		
		while(((*tempPtr)->nextPtr)->data != value)
		{
			tempPtr = &(*tempPtr)->nextPtr;
		}

		*tempPtr = (*tempPtr)->nextPtr;
	}

	return true;
}
			
template<class Node>
bool List<Node>::isEmpty() const
{
 	return firstPtr == 0;
}

template<class Node>
ListNode<Node> *List<Node>::getNewNode(const Node &value)
{
	ListNode<Node> *ptr = new ListNode<Node>(value);
	assert(ptr != 0);
	return ptr;
}

template<class Node>
void List<Node>::print() const
{
 	if(isEmpty())
	{
		cout<<"The list is empty"<<endl;
		return;
	}

	ListNode<Node> *currentPtr = firstPtr;

	while(currentPtr != 0)
	{
		cout<<currentPtr->data<<" ";
		currentPtr = currentPtr->nextPtr;
	}
	
	cout<<endl;
}

#endif
