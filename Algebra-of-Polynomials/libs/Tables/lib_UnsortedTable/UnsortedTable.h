#ifndef LIB_UNSORTEDTABLE_UNSORTEDTABLE_H_
#define LIB_UNSORTEDTABLE_UNSORTEDTABLE_H_
#include "..\lib_UnorderedTable\UnorderedTable.h"
template <typename T>
class UnsortedTable : public UnorderedTable {
public:
	virtual int insert(T obj);
	virtual int remove(T obj);
	virtual T find(std::string key);
	virtual void print();
};

#endif // !LIB_UNSORTEDTABLE_UNSORTEDTABLE_H_