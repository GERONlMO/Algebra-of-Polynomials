#ifndef LIB_NODE_NODE_H_
#define LIB_NODE_NODE_H_

#include <string>
template <typename T>
class Node {
	T value;
	T key;
	Node* left;
	Node* right;
	Node* top;
	
public:
	Node(T key, T value);
	T getValue();
	T getKey();
	void setValue(T value);
	void setKey(T key);
	void setLeft(T left);
	void setRight(T right);
	void setTop(T top);
	Node* getLeft();
	Node* getRight();
	Node* getTop();
	Node& operator= (const Node& node);
};

#endif // !LIB_NODE_NODE_H_