#ifndef LIB_TABLE_TABLE_H_
#define

#include <iostream>
template <typename T>
class Table {
public:
	virtual Table();

	virtual int insert(T obj) {};
	virtual int remove(T obj) {};
	virtual T find(std::string key) {};
};

#endif // !LIB_TABLE_TABLE_H_