#ifndef LIB_SYNTAXTREE_SYNTAXTREE_H_
#define LIB_SYNTAXTREE_SYNTAXTREE_H_

#include <map>
#include "..\lib_Tree\Tree.h"
#include "..\lib_Node\Node.h"

template <typename T>
class SyntaxTree : public Tree<T> {
    const std::map<char, int> operationsPriority = {
            {'(', 0},
            {'+', 1},
            {'-', 1},
            {'*', 2},
            {'/', 2},
            {'^', 3},
            {'~', 4}
    };
	Node<T>* root = nullptr;
	Node<T>* addNodeRecursive(Node<T>* current, T data);
	int evaluateRecursive(Node<T>* current);
	void deleteTree(Node<T>* current);
public:
	SyntaxTree();
	~SyntaxTree();

	void create(T* source, int size) override;
	void insert(T obj) override;
	void remove(T obj) override;
	T find(T key) override;

	int evaluate();
};
#endif // !LIB_SYNTAXTREE_SYNTAXTREE_H_
