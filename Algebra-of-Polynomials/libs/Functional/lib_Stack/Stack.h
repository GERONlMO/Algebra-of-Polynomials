#ifndef LIB_STACK_STACK_H_
#define LIB_STACK_STACK_H_

#include <stdio.h>
#include <string>

template <class T>
class Stack {
private:
	T* data;
	int _top;
	int size;
public:
	Stack();
	Stack(int size);
	int push(T value);
	int pop();
	bool isFull();
	bool isEmpty();
	T top();
	Stack<T>& operator=(const Stack<T>& stk);
};

#endif // !LIB_STACK_STACK_H_
