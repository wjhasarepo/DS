#ifndef RBTREENODE_H
#define RBTREENODE_H

#include "string.h"

template<typename Node> class RBTree;
template<typename Node>
class RBTreeNode {
	friend class RBTree<Node>;
public:
	RBTreeNode(const Node &d):leftPtr(0), rightPtr(0), data(0), color(null){}
	Node getData() const{return data;}
private:
	RBTreeNode<Node> *leftPtr;
	RBTreeNode<Node> *rightPtr;
	Node data;
	string color;
};

#endif
