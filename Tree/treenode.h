#ifndef TREENODE_H
#define TREENODE_H

template<typename Node> class BinaryTree;
template<typename Node>
class TreeNode {
	friend class Tree<Node>;
public:
	TreeNode(const Node &d):leftPtr(0), data(d), rightPtr(0){}
	Node getData() const{return data;}
private:
	TreeNode<Node> *leftPtr;
	Node data;
	TreeNode<Node> *rightPtr;
};

#endif
