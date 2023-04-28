#ifndef LIB_LINEARLISTTABLE_LINEARLISTTABLE_H_
#define LIB_LINEARLISTTABLE_LINEARLISTTABLE_H_

#include "..\lib_UnsortedTable\UnsortedTable.h"
#include "..\..\Functional\lib_List\List.h"
template <typename TKey, typename TValue>
class LinearListTable : public UnsortedTable<TKey, TValue> {
	List<TTableRecord<TKey, TValue>> data;
public:
	LinearListTable();
	virtual int insert(TKey key, TValue value) override;
	virtual int remove(TKey key) override;
	virtual TValue find(TKey key) override;
	virtual void print() override;
};

#endif // !LIB_LINEARLISTTABLE_LINEARLISTTABLE_H_