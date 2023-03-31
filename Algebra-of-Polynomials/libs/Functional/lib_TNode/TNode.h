#ifndef LIB_TNODE_TNODE_H_
#define LIB_TNODE_TNODE_H_
#include "..\lib_Node\Node.h"
template <typename T>
class TNode : public Node {
	T* left;
	T* right;
public:
	T* getLeft();
	T* getRight();
};

#endif // !LIB_TNODE_TNODE_H_