#ifndef LIB_CHAINMETHODTABLE_CHAINMETHODTABLE_H_
#define LIB_CHAINMETHODTABLE_CHAINMETHODTABLE_H_

#include <vector>
#include "..\lib_HashTable\HashTable.h"
template <typename TKey, typename TValue>
class ChainMethodTable : public HashTable<TKey, TValue> {
    int count;
    int size;
    int threshold;
    double loadFactor;
    int hash(TKey key);
    int hash(TKey key, int newSize);
    void resize(int newSize);
    std::vector<std::vector<TTableRecord<TKey, TValue>>> table;
public:
    ChainMethodTable();
    ~ChainMethodTable();
    virtual int insert(TKey key, TValue value);
    virtual int remove(TKey key);
    virtual TValue find(TKey key);
    virtual void print();
};

template <typename TKey, typename TValue>
ChainMethodTable<TKey, TValue>::ChainMethodTable()
{
    size = 100;
    count = 0;
    loadFactor = 0.7;
    threshold = size * loadFactor;
    table.resize(size);
}

template <typename TKey, typename TValue>
ChainMethodTable<TKey, TValue>::~ChainMethodTable()
{
    table.clear();
}

template <typename TKey, typename TValue>
int ChainMethodTable<TKey, TValue>::insert(TKey key, TValue value) {
    if (count > threshold) resize(size * 2);

    TTableRecord<TKey, TValue> record = { key, value };
    int index = hash(record.key);
    table[index].push_back(record);
    count++;

    return 0;
}

template <typename TKey, typename TValue>
int ChainMethodTable<TKey, TValue>::remove(TKey key)
{
    int index = hash(key);
    std::vector<TTableRecord<TKey, TValue>>& chain = table[index];

    for (auto it = chain.begin(); it != chain.end(); ++it) {
        if (it->key == key) {
            chain.erase(it);
            --count;
            return 0;
        }
    }

    throw "Object not found";
}

template <typename TKey, typename TValue>
TValue ChainMethodTable<TKey, TValue>::find(TKey key)
{
    TValue result;
    int index = hash(key);
    std::vector<TTableRecord<TKey, TValue>>& chain = table[index];

    for (auto it = chain.begin(); it != chain.end(); ++it) {
        if (it->key == key) {
            result = it->value;
            return result;
        }
    }

    throw "Object not found";
}

template <typename TKey, typename TValue>
void ChainMethodTable<TKey, TValue>::print()
{
    for (int i = 0; i < size; ++i) {
        std::vector<TTableRecord<TKey, TValue>>& chain = table[i];

        if (!chain.empty()) {
            std::cout << "Chain " << i << ": ";
            for (auto it = chain.begin(); it != chain.end(); ++it) {
                std::cout << "{" << it->key << ": " << it->value << "} ";
            }
            std::cout << std::endl;
        }
    }
}

template <typename TKey, typename TValue>
int ChainMethodTable<TKey, TValue>::hash(TKey key)
{
    return key % size;
}

template <typename TKey, typename TValue>
int ChainMethodTable<TKey, TValue>::hash(TKey key, int newSize)
{
    return key % newSize;
}

template <typename TKey, typename TValue>
void ChainMethodTable<TKey, TValue>::resize(int newSize)
{
    std::vector<std::vector<TTableRecord<TKey, TValue>>> newTable(newSize);

    for (int i = 0; i < size; ++i) {
        std::vector<TTableRecord<TKey, TValue>>& chain = table[i];

        for (auto it = chain.begin(); it != chain.end(); ++it) {
            int newIndex = hash(it->key, newSize);
            newTable[newIndex].push_back(*it);
        }
    }

    table.swap(newTable);
    size = newSize;
    threshold = size * loadFactor;
}

#endif // !LIB_CHAINMETHODTABLE_CHAINMETHODTABLE_H_