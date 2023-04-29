#ifndef LIB_ORDEREDTABLE_ORDEREDTABLE_H_
#define LIB_ORDEREDTABLE_ORDEREDTABLE_H_

#include "..\lib_Table\Table.h"
template <typename TKey, typename TValue>
class OrderedTable : public Table<TKey, TValue> {
public:
    virtual int insert(TKey key, TValue value) = 0;
    virtual int remove(TKey key) = 0;
    virtual TValue find(TKey key) = 0;
    virtual void print() = 0;
};

#endif // !LIB_ORDEREDTABLE_ORDEREDTABLE_H_