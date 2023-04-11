#ifndef LIB_AVLTREE_AVLTREE_H_
#define LIB_AVLTREE_AVLTREE_H_
#include "..\lib_Tree\Tree.h"
#include "..\lib_Node\Node.h"
template <typename T>
class AVLTree : public Tree<T> {
	Node<T> element;
public:
	void create(T* source) override;
	bool insert(T obj) override;
	bool remove(T obj) override;
	T find(T key) override;
};
#endif // !LIB_AVLTREE_AVLTREE_H_
