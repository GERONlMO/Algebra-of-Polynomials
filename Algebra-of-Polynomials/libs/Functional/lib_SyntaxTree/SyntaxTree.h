#ifndef LIB_SYNTAXTREE_SYNTAXTREE_H_
#define LIB_SYNTAXTREE_SYNTAXTREE_H_
#include "..\lib_Tree\Tree.h"

template <typename T>
class SyntaxTree : public Tree<T> {
private:
	Node* root;
	Node* addNodeRecursive(Node* current, T data);
	int evaluateRecursive(Node* current);
	void deleteTree(Node* current);
public:
	SyntaxTree();
	~SyntaxTree();

	void create(T* source) override;
	void insert(T obj) override;
	void remove(T obj) override;
	T find(T key) override;

	int evaluate();
};
#endif // !LIB_SYNTAXTREE_SYNTAXTREE_H_
