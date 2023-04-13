#ifndef LIB_NODE_NODE_H_
#define LIB_NODE_NODE_H_

#include <string>
template <typename T>
class Node {
    std::string value;
	T key;
	Node<T>* left;
	Node<T>* right;
	Node<T>* top;
	
public:
    Node(T key, std::string value) {
        this->key = key;
        this->value = value;
        left = nullptr;
        right = nullptr;
        top = nullptr;
    };
    Node(std::string value) {
        this->value = value;
        left = nullptr;
        right = nullptr;
        top = nullptr;
    };
	std::string getValue() {
        return value;
    };
	T getKey() {
        return key;
    };
	void setValue(std::string value) {
        this->value = value;
    };
	void setKey(T key) {
        this->key = key;
    };
	void setLeft(T left) {
        this->left = left;
    };
	void setRight(T right) {
        this->right = right;
    };
	void setTop(T top) {
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