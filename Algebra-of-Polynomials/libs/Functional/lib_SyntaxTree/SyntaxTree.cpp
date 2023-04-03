#include "SyntaxTree.h"

// Реализация конструктора
template <typename T>
SyntaxTree<T>::SyntaxTree() {
    root = nullptr;
}

// Реализация деструктора
template <typename T>
SyntaxTree<T>::~SyntaxTree() {
    deleteTree(root);
}

template <typename T>
void SyntaxTree<T>::create(T* source) override {

}

// Реализация метода для добавления узла в дерево
template <typename T>
void SyntaxTree<T>::insert(T obj) override {
    root = addNodeRecursive(root, data);
}

// Реализация метода для вычисления значения выражения в дереве
template <typename T>
int SyntaxTree<T>::evaluate() {
    return evaluateRecursive(root);
}

// Рекурсивный метод для добавления узла в дерево
template <typename T>
Node* SyntaxTree<T>::addNodeRecursive(Node* current, T data) {
    if (current == nullptr) {
        return new Node(data);
    }

    if (current->left == nullptr) {
        current->left = addNodeRecursive(current->left, data);
    }
    else if (current->right == nullptr) {
        current->right = addNodeRecursive(current->right, data);
    }
    else {
        current->left = addNodeRecursive(current->left, data);
    }

    return current;
}

// Рекурсивный метод для вычисления значения выражения в дереве
template <typename T>
int SyntaxTree<T>::evaluateRecursive(Node* current) {
    if (current == nullptr) {
        return 0;
    }

    if (current->left == nullptr && current->right == nullptr) {
        return current->data - '0';
    }

    int leftValue = evaluateRecursive(current->left);
    int rightValue = evaluateRecursive(current->right);

    if (current->data == '+') {
        return leftValue + rightValue;
    }
    else if (current->data == '-') {
        return leftValue - rightValue;
    }
    else if (current->data == '*') {
        return leftValue * rightValue;
    }
    else if (current->data == '/') {
        return leftValue / rightValue;
    }

    return 0;
}

// Рекурсивный метод для удаления дерева
template <typename T>
void SyntaxTree<T>::deleteTree(Node* current) {
    if (current != nullptr) {
        deleteTree(current->left);
        deleteTree(current->right);
        delete current;
    }
}