#ifndef LIB_SORTEDTABLE_SORTEDTABLE_H_
#define LIB_SORTEDTABLE_SORTEDTABLE_H_

#include "..\lib_UnorderedTable\UnorderedTable.h"
template <typename T>
class SortedTable : public UnorderedTable<T> {
public:
	virtual int insert(T obj);
	virtual int remove(T obj);
	virtual T find(T key);
	virtual void sort();
	virtual void print();
};
#endif // !LIB_SORTEDTABLE_SORTEDTABLE_H_