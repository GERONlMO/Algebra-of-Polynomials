#ifndef LIB_SORTEDTABLE_SORTEDTABLE_H_
#define LIB_SORTEDTABLE_SORTEDTABLE_H_

#include "..\lib_UnorderedTable\UnorderedTable.h"
template <typename TKey, typename TValue>
class SortedTable : public UnorderedTable<TKey, TValue> {
	virtual void sort();
public:
	virtual int insert(TKey key, TValue value);
	virtual int remove(TKey key);
	virtual TValue find(TKey key);
	virtual void print();
};
#endif // !LIB_SORTEDTABLE_SORTEDTABLE_H_