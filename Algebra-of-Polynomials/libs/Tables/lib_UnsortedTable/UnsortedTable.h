#ifndef LIB_UNSORTEDTABLE_UNSORTEDTABLE_H_
#define LIB_UNSORTEDTABLE_UNSORTEDTABLE_H_

#include "..\lib_UnorderedTable\UnorderedTable.h"
template <typename TKey, typename TValue>
class UnsortedTable : public UnorderedTable<TKey, TValue> {
public:
    virtual int insert(TKey key, TValue value);
    virtual int remove(TKey key);
    virtual TValue find(TKey key);
    virtual void print();
};

#endif // !LIB_UNSORTEDTABLE_UNSORTEDTABLE_H_