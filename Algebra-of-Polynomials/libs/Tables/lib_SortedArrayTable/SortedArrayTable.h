#ifndef LIB_SORTEDARRAYTABLE_SORTEDARRAYTABLE_H_
#define LIB_SORTEDARRAYTABLE_SORTEDARRAYTABLE_H_
#include "..\lib_SortedTable\SortedTable.h"
#include "..\..\Functional\lib_List\List.h"
template <typename T>
class SortedArrayTable : public SortedTable<T> {
	List<T> keys;
	List<T> values;
public:
	SortedArrayTable();
	SortedArrayTable(T* source);
	int insert(T obj);
	int remove(T obj);
	T find(std::string key);
	void print();
};

#endif // !LIB_SORTEDARRAYTABLE_SORTEDARRAYTABLE_H_