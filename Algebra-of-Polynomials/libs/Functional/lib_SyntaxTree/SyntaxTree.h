#ifndef LIB_SYNTAXTREE_SYNTAXTREE_H_
#define LIB_SYNTAXTREE_SYNTAXTREE_H_

#include <map>
#include "..\lib_Node\Node.h"
#include "..\lib_Stack\Stack.h"
#include "..\lib_Monom\Monom.h"
#include <stdio.h>



template <typename T, typename T1>
class SyntaxTree {
    const std::map<char, int> operationsPriority = {
            {'(', 0},
            {'+', 1},
            {'-', 1},
            {'*', 2},
            {'/', 2},
            {'^', 3},
            {'~', 4}
    };
    Stack<T> stack = Stack<T>(10);
	Node<T>* root = nullptr;
    Node<T>* treeRoot = nullptr;
	Node<T>* addNodeRecursive(Node<T>* current, T data);
    void getTreeRoot();
	void createSyntaxTreeStack(Node<T>* current);
	void deleteTree(Node<T>* current);
public:
	SyntaxTree();
	~SyntaxTree();

	void create(T* source, int size);
	void insert(T obj);

	int evaluate();

    std::string toString();
};
#endif // !LIB_SYNTAXTREE_SYNTAXTREE_H_
