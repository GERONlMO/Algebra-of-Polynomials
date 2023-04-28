#ifndef LIB_TABLE_TTABLERECORD_H_
#define LIB_TABLE_TTABLERECORD_H_

template <typename TKey, typename TValue>
struct TTableRecord
{
    TKey key;
    TValue value;
    bool isEmpty() {
        if (key == NULL) return true;
        else return false;
    }
};

#endif // !LIB_TABLE_TTABLERECORD_H_