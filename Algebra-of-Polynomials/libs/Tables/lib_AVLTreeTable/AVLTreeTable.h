#ifndef LIB_AVLTREETABLE_AVLTREETABLE_H_
#define LIB_AVLTREETABLE_AVLTREETABLE_H_
#include "../../Functional/lib_AVLTree/AVLTree.h"
#include "../lib_Table/Table.h"
template <typename T>
class AVLTreeTable : public Table<T>{
	AVLTree<T> tree;
public:
	int insert(T obj);
	int remove(T obj);
	int size();
	T find(std::string key);
	void print();
};

#endif // !LIB_AVLTREETABLE_AVLTREETABLE_H_