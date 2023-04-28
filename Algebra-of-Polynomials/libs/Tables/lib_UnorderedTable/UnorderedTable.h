#ifndef LIB_UNORDEREDTABLE_UNORDEREDTABLE_H_
#define LIB_UNORDEREDTABLE_UNORDEREDTABLE_H_

#include "..\..\Tables\lib_Table\Table.h"
template <typename TKey, typename TValue>
class UnorderedTable : public Table<TKey, TValue> {
public:
    virtual int insert(TKey key, TValue value);
    virtual int remove(TKey key);
    virtual TValue find(TKey key);
    virtual void print();
};

#endif // !LIB_UNORDEREDTABLE_UNORDEREDTABLE_H_