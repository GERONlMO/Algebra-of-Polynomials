#ifndef LIB_SORTEDARRAYTABLE_SORTEDARRAYTABLE_H_
#define LIB_SORTEDARRAYTABLE_SORTEDARRAYTABLE_H_

#include "..\lib_SortedTable\SortedTable.h"
#include "..\..\Functional\lib_List\List.h"
template <typename TKey, typename TValue>
class SortedArrayTable : public SortedTable<TKey, TValue> {
	int size;
	int count;
	TTableRecord<TKey, TValue>* data;

	virtual void sort() override;
public:
	SortedArrayTable();
	virtual int insert(TKey key, TValue value) override;
	virtual int remove(TKey key) override;
	virtual TValue find(TKey key) override;
	virtual void print() override;
};

#endif // !LIB_SORTEDARRAYTABLE_SORTEDARRAYTABLE_H_