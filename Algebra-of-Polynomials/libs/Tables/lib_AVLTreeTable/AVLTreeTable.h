#ifndef LIB_AVLTREETABLE_AVLTREETABLE_H_
#define LIB_AVLTREETABLE_AVLTREETABLE_H_
#include "../../Functional/lib_AVLTree/AVLTree.h"
#include "../lib_Table/Table.h"

template <typename TKey, typename TValue, typename T>
class AVLTreeTable : public Table<TKey, TValue> {
	AVLTree<T> tree;
	int size();
public:
	virtual int insert(TKey key, TValue value);
	virtual int remove(TKey key);
	virtual TValue find(TKey key);
	virtual void print();
};

#endif // !LIB_AVLTREETABLE_AVLTREETABLE_H_