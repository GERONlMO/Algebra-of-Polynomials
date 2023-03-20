#ifndef LIB_TREE_TREE_H_
#define LIB_TREE_TREE_H_

#include <iostream>
template <typename Type>
class Tree {
	virtual int insert(Type obj) {};
	virtual int remove(Type obj) {};
	virtual Type find(std::string key) {};
	virtual void balance() {};
};

#endif // !LIB_TREE_TREE_H_