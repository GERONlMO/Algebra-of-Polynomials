#ifndef LIB_TABLE_TABLE_H_
#define LIB_TABLE_TABLE_H_

#include <iostream>
template <typename T>
class Table {
	int size;
public:
	virtual Table();
	virtual int insert(T obj);
	virtual int remove(T obj);
	virtual int size();
	virtual T find(std::string key);
	virtual void print();
};

#endif // !LIB_TABLE_TABLE_H_