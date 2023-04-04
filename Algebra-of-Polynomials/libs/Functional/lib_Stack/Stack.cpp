#include "Stack.h"


template <class T>
stack<T>::stack() {
    size = 10;
    top = -1;
    data = new T[size];
}

template <class T>
stack<T>::stack(int size) {
    this->size = size;
    top = -1;
    data = new T[size];
}

template <class T>
int stack<T>::push(T value) {
    if (isFull()) {
        T* newData = new T[size + 1];
        for (int i = 0; i < size; i++) {
            newData[i] = data[i];
        }
        delete[] data;
        data = newData;
        size++;
    }
    top++;
    data[top] = value;
    return 1;
}

template <class T>
int stack<T>::pop() {
    isEmpty() ? throw string("Stack is empty") : NULL;
    T tmp = data[top];
    T* newData = new T[size - 1];
    for (int i = 0; i < size - 1; i++) {
        newData[i] = data[i];
    }
    top--;
    size--;
    delete[] data;
    data = newData;
    return tmp;
}

template <class T>
bool stack<T>::isFull() {
    return top == size - 1;
}

template <class T>
bool stack<T>::isEmpty() {
    return top == -1;
}

template <class T>
T stack<T>::top() {
    return data[top];
}

template <class T>
stack<T>& stack<T>::operator=(const stack<T>& stk) {
    if (this != &stk) {
        delete[] data;
        size = stk.size;
        top = stk.top;
        data = new T[size];
        for (int i = 0; i <= top; i++) {
            data[i] = stk.data[i];
        }
    }
    return *this;
}
