#ifndef LIB_SYNTAXTREE_SYNTAXTREE_H_
#define LIB_SYNTAXTREE_SYNTAXTREE_H_
#include "..\lib_Tree\Tree.h"
#include "..\lib_Node\Node.h"
template <typename T>
class SyntaxTree : public Tree {
	Node element;
public:
	void create(T* source);
	bool insert(T obj);
	bool remove(T obj);
	T find(std::string key);
};
#endif // !LIB_SYNTAXTREE_SYNTAXTREE_H_
