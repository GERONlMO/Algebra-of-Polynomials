#include <stdexcept>
#include "Stack.h"


template <class T>
Stack<T>::Stack() {
    size = 10;
    _top = -1;
    data = new T[size];
}

template <class T>
Stack<T>::Stack(int size) {
    this->size = size;
    _top = -1;
    data = new T[size];
}

template <class T>
int Stack<T>::push(T value) {
    if (isFull()) {
        T* newData = new T[size + 1];
        for (int i = 0; i < size; i++) {
            newData[i] = data[i];
        }
        delete[] data;
        data = newData;
        size++;
    }
    _top++;
    data[_top] = value;
    return 1;
}

template <class T>
int Stack<T>::pop() {
    if (isEmpty())
        throw std::logic_error("Stack is empty");
    else
        NULL;
    T tmp = data[_top];
    T* newData = new T[size - 1];
    for (int i = 0; i < size - 1; i++) {
        newData[i] = data[i];
    }
    _top--;
    size--;
    delete[] data;
    data = newData;
    return tmp;
}

template <class T>
bool Stack<T>::isFull() {
    return _top == size - 1;
}

template <class T>
bool Stack<T>::isEmpty() {
    return _top == -1;
}

template <class T>
T Stack<T>::top() {
    return data[_top];
}

template <class T>
Stack<T>& Stack<T>::operator=(const Stack<T>& stk) {
    if (this != &stk) {
        delete[] data;
        size = stk.size;
        _top = stk.top;
        data = new T[size];
        for (int i = 0; i <= _top; i++) {
            data[i] = stk.data[i];
        }
    }
    return *this;
}
