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
	List();
	int clear();
	int push_back(T obj);
	T pop_back();
	int push_front(T obj);
	T pop_front();
	int empty();
	int size();
};

#endif // !LIB_LIST_LIST_H_