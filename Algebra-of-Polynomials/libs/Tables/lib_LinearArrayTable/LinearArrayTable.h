#ifndef LIB_LINEARARRAYTABLE_LINEARARRAYTABLE_H_
#define LIB_LINEARARRAYTABLE_LINEARARRAYTABLE_H_

#include "..\lib_UnsortedTable\UnsortedTable.h"
template <typename TKey, typename TValue>
class LinearArrayTable : public UnsortedTable<TKey, TValue> {
	size_t size;
	size_t count;
	TTableRecord<TKey, TValue>* data;
public:
	LinearArrayTable();
	~LinearArrayTable();
	virtual int insert(TKey key, TValue value) override;
	virtual int remove(TKey key) override;
	virtual TValue find(TKey key) override;
	virtual void print() override;
};

#endif // !LIB_LINEARARRAYTABLE_LINEARARRAYTABLE_H_