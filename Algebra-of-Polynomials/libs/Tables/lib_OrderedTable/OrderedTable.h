#ifndef LIB_ORDEREDTABLE_ORDEREDTABLE_H_
#define LIB_ORDEREDTABLE_ORDEREDTABLE_H_

#include "..\lib_Table\Table.h"
template <typename T>
class OrderedTable : public Table<T> {
public:
	virtual int insert(T obj);
	virtual int remove(T obj);
	virtual T find(std::string key);
	virtual void print();
};

#endif // !LIB_ORDEREDTABLE_ORDEREDTABLE_H_