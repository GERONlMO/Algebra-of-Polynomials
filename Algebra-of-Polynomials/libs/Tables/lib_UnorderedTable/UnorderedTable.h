#ifndef LIB_UNORDEREDTABLE_UNORDEREDTABLE_H_
#define LIB_UNORDEREDTABLE_UNORDEREDTABLE_H_
#include "..\..\Tables\lib_Table\Table.h"
template <typename T>
class UnorderedTable : public Table<T> {
public:
	virtual int insert(T obj);
	virtual int remove(T obj);
	virtual T find(T key);
	virtual void print();
};

#endif // !LIB_UNORDEREDTABLE_UNORDEREDTABLE_H_