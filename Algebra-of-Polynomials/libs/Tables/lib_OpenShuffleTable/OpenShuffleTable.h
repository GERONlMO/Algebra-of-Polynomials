#ifndef LIB_OPENSHUFFLETABLE_OPENSHUFFLETABLE_H_
#define LIB_OPENSHUFFLETABLE_OPENSHUFFLETABLE_H_

#include "..\lib_HashTable\HashTable.h"
template <typename TKey, typename TValue>
class OpenShuffleTable : public HashTable<TKey, TValue> {
    int count;
    int size;
    double loadFactor;
    int findFreeIndex(TKey key);
    virtual int hash(TKey key);
    virtual void resize(int newSize);
    TTableRecord<TKey, TValue>* table;
public:
    OpenShuffleTable();
    ~OpenShuffleTable();
    virtual int insert(TKey key, TValue value);
    virtual int remove(TKey key);
    virtual TValue find(TKey key);
    virtual void print();
};

template <typename TKey, typename TValue>
OpenShuffleTable<TKey, TValue>::OpenShuffleTable() {
    size = 100; // начальный размер таблицы
    count = 0; // количество элементов в таблице
    loadFactor = 0.7; // максимальная загрузка таблицы
    table = new TTableRecord<TKey, TValue>[size];
}

template <typename TKey, typename TValue>
OpenShuffleTable<TKey, TValue>::~OpenShuffleTable() {
    delete[] table;
}

template <typename TKey, typename TValue>
int OpenShuffleTable<TKey, TValue>::insert(TKey key, TValue value) {
    if (count >= size * loadFactor) {
        // Если достигнута максимальная загрузка таблицы, то увеличиваем ее размер
        resize(size * 2);
    }

    int index = findFreeIndex(key);
    if (index != -1) {
        // Если нашли свободный индекс, то вставляем элемент
        TTableRecord<TKey, TValue> record = { key, value };
        table[index] = record;
        count++;
    }

    return 0;
}

template <typename TKey, typename TValue>
int OpenShuffleTable<TKey, TValue>::remove(TKey key) {
    int index = findFreeIndex(key);
    if (index != -1) {
        // Если нашли элемент с таким же ключом, то удаляем его
        table[index] = TTableRecord<TKey, TValue>(TKey(), TValue());
        count--;
        return 0;
    }

    throw "Object not found";
}

template <typename TKey, typename TValue>
TValue OpenShuffleTable<TKey, TValue>::find(TKey key) {
    int index = findFreeIndex(key);
    if (index != -1) {
        // Если нашли элемент с таким же ключом, то возвращаем его значение
        return table[index].value;
    }
    // Если элемент не найден, то возвращаем ошибку
    throw "Object not found";
}

template <typename TKey, typename TValue>
void OpenShuffleTable<TKey, TValue>::print() {
    std::cout << "{ ";
    for (int i = 0; i < size; i++) {
        if (table[i].key != TKey()) {
            
            std::cout << "(" << table[i].key << ", " << table[i].value << ") ";
        }
    }
    std::cout << "}" << std::endl;
}

template <typename TKey, typename TValue>
int OpenShuffleTable<TKey, TValue>::hash(TKey key) {
    return std::hash<TKey>()(key) % size;
}

template <typename TKey, typename TValue>
int OpenShuffleTable<TKey, TValue>::findFreeIndex(TKey key) {
    int index = hash(key);
    int startIndex = index;
    do {
        if (table[index].key == key || table[index].key == TKey()) {
            // Если нашли элемент с таким же ключом или элемент без ключа,
            // то возвращаем индекс
            return index;
        }
        index = (index + 1) % size; // двигаемся по таблице
    } while (index != startIndex);
    // Если прошли всю таблицу и не нашли свободный индекс, то возвращаем -1
    return -1;
}

template <typename TKey, typename TValue>
void OpenShuffleTable<TKey, TValue>::resize(int newSize) {
    TTableRecord<TKey, TValue>* newTable = new TTableRecord<TKey, TValue>[newSize];
    for (int i = 0; i < newSize; i++) {
        newTable[i].key = TKey();
        newTable[i].value = TValue();
    }
    int newCount = 0;
    for (int i = 0; i < size; i++) {
        if (table[i].key != TKey()) {
            int newIndex = findFreeIndex(table[i].key);
            newTable[newIndex].key = table[i].key;
            newTable[newIndex].value = table[i].value;
            ++newCount;
        }
    }
    delete[] table;
    table = newTable;
    size = newSize;
    count = newCount;
}

#endif // !LIB_OPENSHUFFLETABLE_OPENSHUFFLETABLE_H_