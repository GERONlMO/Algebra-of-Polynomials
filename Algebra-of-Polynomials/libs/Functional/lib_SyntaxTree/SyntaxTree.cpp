#include <stdexcept>
#include "SyntaxTree.h"


// Реализация конструктора
template <typename T, typename T1>
SyntaxTree<T, T1>::SyntaxTree() {
    root = nullptr;
}

// Реализация деструктора
template <typename T, typename T1>
SyntaxTree<T, T1>::~SyntaxTree() {
    deleteTree(root);
}

// Реализация метода для создания арифметического дерева
template <typename T, typename T1>
void SyntaxTree<T, T1>::create(T* source, int size) {
    for (int i = size - 1; i > 0; i--) {
        insert(source[i]);
    }
}

// Реализация метода для добавления узла в дерево
template <typename T, typename T1>
void SyntaxTree<T, T1>::insert(T obj) {
    root = addNodeRecursive(root, obj);
    getTreeRoot();
}

// Реализация метода для вычисления значения выражения в дереве
template <typename T, typename T1>
int SyntaxTree<T, T1>::evaluate() {
    Node<T>* temp = treeRoot;
    createSyntaxTreeStack(temp);
    Stack<T> additional = Stack<T>(10);
    while (!stack.isEmpty()) {

    }
}

// Рекурсивный метод для добавления узла в дерево
template <typename T, typename T1>
Node<T>* SyntaxTree<T, T1>::addNodeRecursive(Node<T>* current, T data) {
    bool flag = false;

    if (current == nullptr)
        return new Node<T>*(data);
    else if (current->getRight() == nullptr) {
        if (data == '-' || data == '/' || data == '^')
            flag = true;
        current->setRight(addNodeRecursive(current->getRight(), data));
    }
    else if (current->getLeft() == nullptr) {
        if (data == '-' || data == '/' || data == '^')
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
}

// Рекурсивный метод для внесения значений узлов в стек
template <typename T, typename T1>
void SyntaxTree<T, T1>::createSyntaxTreeStack(Node<T> *current) {
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
}

template <typename T, typename T1>
void SyntaxTree<T, T1>::getTreeRoot() {
    while (root->getTop() != root) root = root->getTop();
    treeRoot = root;
}

// Рекурсивный метод для удаления дерева
template <typename T, typename T1>
void SyntaxTree<T, T1>::deleteTree(Node<T>* current) {
    if (current != nullptr) {
        deleteTree(current->left);
        deleteTree(current->right);
        delete current;
    }
}

template <typename T, typename T1>
std::string SyntaxTree<T, T1>::toString() {

    std::string result = "layout 1 - " + treeRoot->getValue() + "\n" +  "layout 2 - " + treeRoot->getLeft()->getValue() + " " + treeRoot->getRight()->getValue() +
             "\nlayout 3 - " + treeRoot->getLeft()->getLeft()->getValue() + " " + treeRoot->getLeft()->getRight() + " " + treeRoot->getRight()->getLeft()->getValue() +
             " " + treeRoot->getRight()->getRight()->getValue();
    return result;
}