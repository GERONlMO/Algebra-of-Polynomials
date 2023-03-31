#ifndef LIB_SORTEDTABLE_SORTEDTABLE_H_
#define LIB_SORTEDTABLE_SORTEDTABLE_H_

#include "..\lib_UnorderedTable\UnorderedTable.h"
template <typename T>
class SortedTable : public UnorderedTable {
public:
	virtual int insert(T obj);
	virtual int remove(T obj);
	virtual T find(std::string key);
	virtual void sort();
	virtual void print();
};
#endif // !LIB_SORTEDTABLE_SORTEDTABLE_H_