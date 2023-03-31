#ifndef LIB_TABLE_TABLE_H_
#define LIB_TABLE_TABLE_H_

#include <iostream>
template <typename T>
class Table {
public:
	virtual int insert(T obj);
	virtual int remove(T obj);
	virtual T find(std::string key);
	virtual void print();
};

#endif // !LIB_TABLE_TABLE_H_