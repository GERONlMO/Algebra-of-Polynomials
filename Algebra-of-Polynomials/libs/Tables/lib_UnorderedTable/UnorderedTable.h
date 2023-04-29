#ifndef LIB_UNORDEREDTABLE_UNORDEREDTABLE_H_
#define LIB_UNORDEREDTABLE_UNORDEREDTABLE_H_

#include "..\..\Tables\lib_Table\Table.h"
template <typename TKey, typename TValue>
class UnorderedTable : public Table<TKey, TValue> {
public:
    virtual int insert(TKey key, TValue value) = 0;
    virtual int remove(TKey key) = 0;
    virtual TValue find(TKey key) = 0;
    virtual void print() = 0;
};

#endif // !LIB_UNORDEREDTABLE_UNORDEREDTABLE_H_