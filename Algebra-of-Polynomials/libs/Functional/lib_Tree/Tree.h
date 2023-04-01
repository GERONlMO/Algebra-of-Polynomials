#ifndef LIB_TREE_TREE_H_
#define LIB_TREE_TREE_H_
#include "..\lib_Node\Node.h"
template <typename T>
class Tree { 
public:
	virtual bool insert(T obj);
	virtual bool remove(T obj);
	virtual T find(std::string key);
};
#endif // !LIB_TREE_TREE_H_
