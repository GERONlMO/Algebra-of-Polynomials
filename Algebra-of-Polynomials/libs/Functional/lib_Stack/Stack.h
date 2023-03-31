#ifndef LIB_STACK_STACK_H_
#define LIB_STACK_STACK_H_

#include <stdio.h>
#include <string>

template <class T>
class stack {
private:
	T* data;
	int Top;
	int size;
public:
	stack();
	stack(int size);
	int push(T value);
	int pop();
	bool isFull();
	bool isEmpty();
	T top();
	stack<T>& operator=(const stack<T>& stk);
};

#endif // !LIB_STACK_STACK_H_
