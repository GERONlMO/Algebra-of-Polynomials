#include "Node.h"

template <typename T>
Node<T>::Node(T key, T value) {
	this->key = key;
	this->value = value;
	left = nullptr;
	right = nullptr;
	top = nullptr;
}

template <typename T>
T Node<T>::getValue() {
	return value;
}

template <typename T>
T Node<T>::getKey() {
	return key;
}

template <typename T>
void Node<T>::setValue(T value) {
	this->value = value;
}

template <typename T>
void Node<T>::setKey(T key) {
	this->key = key;
}

template <typename T>
Node<T>* Node<T>::getLeft() {
	return left;
}

template <typename T>
Node<T>* Node<T>::getRight() {
	return right;
}

template <typename T>
Node<T>* Node<T>::getTop() {
	return top;
}

template <typename T>
Node<T>& Node<T>::operator= (const Node<T>& node) {
	if (this == &node) return *this;
	key = node.key;
	value = node.value;
	left = node.left;
	right = node.right;
	top = node.top;
	return *this;
}