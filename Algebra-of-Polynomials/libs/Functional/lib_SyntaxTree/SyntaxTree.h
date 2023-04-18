#ifndef LIB_SYNTAXTREE_SYNTAXTREE_H_
#define LIB_SYNTAXTREE_SYNTAXTREE_H_

#include <map>
#include "Node.h"
#include "Stack.h"
#include "Monom.h"

template <typename T, typename T1>
class SyntaxTree {
    const std::map<std::string, int> operationsPriority = {
            {"(", 0},
            {"+", 1},
            {"-", 1},
            {"*", 2},
            {"/", 2},
            {"^", 3},
            {"~", 4}
    };
    const std::string specialOperations[3] = {"/", "^", "-"};
    bool flag = false;
    Stack<T> stack = Stack<T>(10);
	Node<T>* root = nullptr;
    Node<T>* treeRoot = nullptr;
	Node<T>* addNodeRecursive(Node<T>* current, std::string data) {
        if (current == nullptr) {
            Node<T>* tmp = new Node<T>(data);
            treeRoot = tmp;
            return tmp;
        }
        if (current->getRight()!= nullptr && current->getLeft() != nullptr && !isOperation(current->getRight()->getValue()) && !isOperation(current->getLeft()->getValue())) current = current->getTop();
        flag = in(current->getValue());
        if (current->getRight() == nullptr) {
            if (!flag) {
                current->setRight(new Node<T>(data));
                current->getRight()->setTop(current);
                if (!isOperation(data)) {
                    return current;
                }
                return current->getRight();
            }
            if (current->getLeft()!= nullptr) {
                current->setRight(new Node<T>(data));
                current->getRight()->setTop(current);
                if(!isOperation(data)) {
                    return current;
                }
                return current->getRight();
            }
        }
        if (current->getLeft() == nullptr) {
            current->setLeft(new Node<T>(data));
            current->getLeft()->setTop(current);
            if (!isOperation(data)) {
                return current;
            }
            return current->getLeft();
        }
        return current;
    };

	void createSyntaxTreeStack(Node<T> *current) {
    };

    std::string toStringRecursive(Node<T>* root) {
        if (root == nullptr) {
            return "";
        }

        std::string result = "";
        if (root->getLeft() != nullptr || root->getRight() != nullptr) {
            std::string leftValue = toStringRecursive(root->getLeft());
            std::string rightValue = toStringRecursive(root->getRight());
            result += leftValue + " " + rightValue;
        }
        result += " " + root->getValue();
        return result;
    }

	void deleteTree(Node<T>* current) {
        if (current != nullptr) {
            deleteTree(current->getLeft());
            deleteTree(current->getRight());
            delete current;
        }
    };

    bool in(T data) {
        for (const auto & specialOperation : specialOperations) {
            if (std::string(data) == specialOperation)
                return true;
        }
        return false;
    }
    bool isOperation(T data) {
        return operationsPriority.contains(std::string(data));
    }
public:
    SyntaxTree() {
    };
    ~SyntaxTree() {
        deleteTree(root);
    };

	void create(T* source, int size) {
        for (int i = size - 1; i >= 0; i--) {
            insert(source[i]);
        }
    };
	void insert(T obj) {
        root = addNodeRecursive(root, obj);
    };
    std::string toString() {
        return toStringRecursive(treeRoot);
    };

};
#endif // !LIB_SYNTAXTREE_SYNTAXTREE_H_
