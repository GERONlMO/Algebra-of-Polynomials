#ifndef LIB_TREE_TREE_H_
#define LIB_TREE_TREE_H_
#include "..\lib_Node\Node.h"
template <typename T>
class Tree { 
public:
	virtual void create(T* source);
	virtual void insert(T obj);
	virtual void remove(T obj);
	virtual T find(T key);
};
#endif // !LIB_TREE_TREE_H_
