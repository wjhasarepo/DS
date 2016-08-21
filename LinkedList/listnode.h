#ifndef LISTNODE_H
#define LISTNODE_H

template<class Node> class List;
template<class Node>
class ListNode{
	friend class List<Node>;
public:
	ListNode(const Node &);
	Node getData() const;
private:
	Node data;
	ListNode<Node> *nextPtr;
};

template<class Node>
ListNode<Node>::ListNode(const Node &info):data(info), nextPtr(NULL) {}

template<class Node>
Node ListNode<Node>::getData() const {return data;}

#endif
