#ifndef LIB_LINEARLISTTABLE_LINEARLISTTABLE_H_
#define LIB_LINEARLISTTABLE_LINEARLISTTABLE_H_
#include "..\lib_UnsortedTable\UnsortedTable.h"
#include "..\..\Functional\lib_List\List.h"
template <typename T>
class LinearListTable : public UnsortedTable<T> {
	List<T> keys;
	List<T> values;
public:
	LinearListTable();
	LinearListTable(T* source);
	int insert(T obj);
	int remove(T obj);
	T find(std::string key);
	void print();
};

#endif // !LIB_LINEARLISTTABLE_LINEARLISTTABLE_H_