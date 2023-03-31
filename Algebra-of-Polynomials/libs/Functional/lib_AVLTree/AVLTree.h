#ifndef LIB_AVLTREE_AVLTREE_H_
#define LIB_AVLTREE_AVLTREE_H_
#include "..\lib_Tree\Tree.h"
#include "..\lib_Node\Node.h"
template <typename T>
class AVLTree : public Tree {
	Node element;
public:
	void create(T* source);
	bool insert(T obj);
	bool remove(T obj);
	T find(std::string key);
	void balance();
};
#endif // !LIB_AVLTREE_AVLTREE_H_
