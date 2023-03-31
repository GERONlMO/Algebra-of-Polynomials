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
	void setValue();
	void setKey();
	Node* getLeft();
	Node* getRight();
	Node* getTop();
	Node& operator= (const Node& node);
};

#endif // !LIB_NODE_NODE_H_