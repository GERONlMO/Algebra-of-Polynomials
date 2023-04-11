#ifndef LIB_LINEARARRAYTABLE_LINEARARRAYTABLE_H_
#define LIB_LINEARARRAYTABLE_LINEARARRAYTABLE_H_
#include "..\lib_UnsortedTable\UnsortedTable.h"
template <typename T>
class LinearArrayTable : public UnsortedTable<T> {
	T* keys;
	T* values;
public:
	LinearArrayTable();
	LinearArrayTable(T* source);
	~LinearArrayTable();
	//LinearArrayTable(const LinearArrayTable& table);
	int insert(T obj);
	int remove(T obj);
	T find(std::string key);
	void print();
};

#endif // !LIB_LINEARARRAYTABLE_LINEARARRAYTABLE_H_