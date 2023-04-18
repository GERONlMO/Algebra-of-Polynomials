#ifndef LIB_LIST_LIST_H_
#define LIB_LIST_LIST_H_

#include <stdio.h>
#include "..\lib_Node\Node.h"

template <typename T>
class List {
	int _size;
	Node<T>* last;
	Node<T>* first;
public:
	List() {
		_size = 0;
		last = nullptr;
		first = nullptr;
	};

	List(const List& other) {
		_size = 0;
		last = nullptr;
		first = nullptr;

		Node<T>* current = other.last;
		while (current != nullptr) {
			push_back(current->getValue());
			current = current->getLeft();
		}
	}

	T get(int index) {
		if (index < 0 || index >= _size) {
			throw std::out_of_range("Index out of range");
		}
		Node<T>* current = first;
		for (int i = 0; i < index; i++) {
			current = current->getRight();
		}
		return current->getValue();
	}

	int clear() {
		while (first != nullptr) {
			Node<T>* temp = first;
			first = first->getRight();
			delete temp;
		}
		last = nullptr;
		_size = 0;
		return 0;
	};

	int resetList() {
		first = nullptr;
		last = nullptr;
		_size = 0;
		return 0;
	};

	int push_back(T obj) {
		Node<T>* node = new Node<T>(obj);
		if (last == nullptr) {
			first = node;
			last = node;
		}
		else {
			last->setRight(node);
			node->setLeft(last);
			last = node;
		}
		_size++;
		return 0;
	};

	T pop_back() {
		if (last == nullptr) {
			throw "List is empty";
		}
		T result = last->getValue();
		Node<T>* temp = last;
		last = last->getLeft();
		if (last != nullptr) {
			last->setRight(nullptr);
		}
		else {
			first = nullptr;
		}
		delete temp;
		_size--;
		return result;
	};

	int push_front(T obj) {
		Node<T>* node = new Node<T>(obj);
		if (first == nullptr) {
			first = node;
			last = node;
		}
		else {
			first->setLeft(node);
			node->setRight(first);
			first = node;
		}
		_size++;
		return 0;
	};

	T pop_front() {
		if (first == nullptr) {
			throw "List is empty";
		}
		T result = first->getValue();
		Node<T>* temp = first;
		first = first->getRight();
		if (first != nullptr) {
			first->setLeft(nullptr);
		}
		else {
			last = nullptr;
		}
		delete temp;
		_size--;
		return result;
	};

	int empty() {
		return first == nullptr;
	};

	int size() {
		return _size;
	};
};

#endif // !LIB_LIST_LIST_H_