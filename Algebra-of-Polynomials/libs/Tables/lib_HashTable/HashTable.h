#ifndef LIB_HASHTABLE_HASHTABLE_H_
#define LIB_HASHTABLE_HASHTABLE_H_

#include "..\lib_OrderedTable\OrderedTable.h"
template <typename TKey, typename TValue>
class HashTable : public OrderedTable<TKey, TValue> {
    int count = 0;
    int size = 0;
    double loadFactor = 0;
    virtual int hash(TKey key) = 0;
    virtual void resize(int newSize) = 0;
public:
    virtual int insert(TKey key, TValue value) = 0;
    virtual int remove(TKey key) = 0;
    virtual TValue find(TKey key) = 0;
    virtual void print() = 0;
};

#endif // !LIB_HASHTABLE_HASHTABLE_H_