#include "List.h"

template <typename T>
List<T>::List() {
    _size = 0;
    last = nullptr;
    first = nullptr;
}

template <typename T>
int List<T>::clear() {
    while (first != nullptr) {
        Node<T>* temp = first;
        first = first->getRight();
        delete temp;
    }
    last = nullptr;
    _size = 0;
    return 0;
}

template <typename T>
int List<T>::push_back(T obj) {
    Node<T>* node = new Node<T>(obj);
    if (last == nullptr) {
        first = node;
        last = node;
    }
    else {
        last->setRight(node);
        node->setLeft(last);
        last = node;
    }
    _size++;
    return 0;
}

template <typename T>
T List<T>::pop_back() {
    if (last == nullptr) {
        throw "List is empty";
    }
    T result = last->getValue();
    Node<T>* temp = last;
    last = last->getLeft();
    if (last != nullptr) {
        last->setRight(nullptr);
    }
    else {
        first = nullptr;
    }
    delete temp;
    _size--;
    return result;
}

template <typename T>
int List<T>::push_front(T obj) {
    Node<T>* node = new Node<T>(obj);
    if (first == nullptr) {
        first = node;
        last = node;
    }
    else {
        first->setLeft(node);
        node->setRight(first);
        first = node;
    }
    _size++;
    return 0;
}

template <typename T>
T List<T>::pop_front() {
    if (first == nullptr) {
        throw "List is empty";
    }
    T result = first->getValue();
    Node<T>* temp = first;
    first = first->getRight();
    if (first != nullptr) {
        first->setLeft(nullptr);
    }
    else {
        last = nullptr;
    }
    delete temp;
    _size--;
    return result;
}

template <typename T>
int List<T>::empty() {
    return first == nullptr;
}

template <typename T>
int List<T>::size() {
    return _size;
}