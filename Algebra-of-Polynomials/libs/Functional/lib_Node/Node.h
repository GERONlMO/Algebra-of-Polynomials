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
    Node(T key, T value) {
        this->key = key;
        this->value = value;
        left = nullptr;
        right = nullptr;
        top = nullptr;
    };
    Node(T value) {
        this->value = value;
        left = nullptr;
        right = nullptr;
        top = nullptr;
    };
    T getValue() {
        return value;
    };
	T getKey() {
        return key;
    };
	void setValue(T value) {
        this->value = value;
    };
	void setKey(T key) {
        this->key = key;
    };
	void setLeft(Node<T>* left) {
        this->left = left;
    };
	void setRight(Node<T>* right) {
        this->right = right;
    };
	void setTop(Node<T>* top) {
        this->top = top;
    };
	Node<T>* getLeft() {
        return left;
    };
	Node<T>* getRight() {
        return right;
    };
	Node<T>* getTop() {
        return top;
    };
	Node<T>& operator= (const Node<T>& node) {
        if (this == &node) return *this;
        key = node.key;
        value = node.value;
        left = node.left;
        right = node.right;
        top = node.top;
        return *this;
    };
};

#endif // !LIB_NODE_NODE_H_