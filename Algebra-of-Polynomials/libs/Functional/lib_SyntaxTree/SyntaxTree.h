#ifndef LIB_SYNTAXTREE_SYNTAXTREE_H_
#define LIB_SYNTAXTREE_SYNTAXTREE_H_

#include <map>
#include "Node.h"
#include "Stack.h"
#include "Monom.h"

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
	Node<T>* addNodeRecursive(Node<T>* current, T data) {
        bool flag = false;

        if (current == nullptr){
            Node<T>* tmp = new Node<T>(data);
            return tmp;
        }

        else if (current->getRight() == nullptr) {
            if (data == "-" || data == "/" || data == "^")
                flag = true;
            current->setRight(addNodeRecursive(current->getRight(), data));
        }
        else if (current->getLeft() == nullptr) {
            if (data == "-" || data == "/" || data == "^")
                flag = true;
            current->setLeft(addNodeRecursive(current->getLeft(), data));
        }
        if (!operationsPriority.contains(current->getRight()->getValue()) && !operationsPriority.contains(current->getLeft()->getValue())) {
            current = current->getTop();
            return current;
        }

        if (flag) {
            current = current->getLeft();
            current->setTop(root);
            current->setLeft(addNodeRecursive(current->getLeft(), data));
        } else {
            current = current->getRight();
            current->setTop(root);
            current->setRight(addNodeRecursive(current->getRight(), data));
        }

        return current;
    };
    void getTreeRoot() {
        while (root->getTop() != root) root = root->getTop();
        treeRoot = root;
    };
	void createSyntaxTreeStack(Node<T> *current) {
        if (current == nullptr) throw std::logic_error("The tree is empty");
        if (current->getRight() != nullptr)
            stack.push(current->getRight()->getValue());
        if (current->getLeft() != nullptr)
            stack.push(current->getLeft()->getValue());
        if (operationsPriority.contains(current->getRight()->getValue())) {
            current = current->getRight();
            evaluateRecursive(current);
        }
        if (operationsPriority.contains(current->getLeft()->getValue())) {
            current = current->getLeft();
            evaluateRecursive(current);
        }
    };
	void deleteTree(Node<T>* current) {
        if (current != nullptr) {
            deleteTree(current->getLeft());
            deleteTree(current->getRight());
            delete current;
        }
    };
public:
    SyntaxTree() {
        root = nullptr;
    };
    ~SyntaxTree() {
        deleteTree(root);
    };

	void create(T* source, int size) {
        for (int i = size - 1; i > 0; i--) {
            insert(source[i]);
        }
    };
	void insert(T obj) {
        root = addNodeRecursive(root, obj);
        getTreeRoot();
    };
	int evaluate() {
        Node<T>* temp = treeRoot;
        createSyntaxTreeStack(temp);
        Stack<T> additional = Stack<T>(10);
        while (!stack.isEmpty()) {

        }
    };
    std::string toString() {
        std::string result = "layout 1 - " + treeRoot->getValue() + "\n" +
                "layout 2 - " + treeRoot->getLeft()->getValue() + " " + treeRoot->getRight()->getValue() +
                "\nlayout 3 - " + treeRoot->getLeft()->getLeft()->getValue() + " " + treeRoot->getLeft()->getRight()->getValue() + " " + treeRoot->getRight()->getLeft()->getValue() + " " + treeRoot->getRight()->getRight()->getValue();
        return result;
    };
};
#endif // !LIB_SYNTAXTREE_SYNTAXTREE_H_
