#ifndef LIB_HASHTABLE_HASHTABLE_H_
#define LIB_HASHTABLE_HASHTABLE_H_
#include "..\lib_OrderedTable\OrderedTable.h"
template <typename T>
class HashTable : public OrderedTable {
public:
	HashTable();
	HashTable(T* source);
	virtual int insert(T obj);
	virtual int remove(T obj);
	virtual T find(std::string key);
	virtual void print();
};
//TODO: What is differents between Hash Tables?
#endif // !LIB_HASHTABLE_HASHTABLE_H_