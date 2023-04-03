#ifndef LIB_NODE_NODE_H_
#define LIB_NODE_NODE_H_

#include <string>
template <typename T>
class Node {
	T value;
	T key;
	Node<T>* left;
	Node<T>* right;
	Node<T>* top;
	
public:
	Node(T key, T value);
    Node(T value);
	T getValue();
	T getKey();
	void setValue(T value);
	void setKey(T key);
	void setLeft(T left);
	void setRight(T right);
	void setTop(T top);
	Node<T>* getLeft();
	Node<T>* getRight();
	Node<T>* getTop();
	Node<T>& operator= (const Node<T>& node);
};

#endif // !LIB_NODE_NODE_H_