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
    TTableRecord<TKey, TValue>* data;
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
    data = new TTableRecord<TKey, TValue>[size];
}

template <typename TKey, typename TValue>
OpenShuffleTable<TKey, TValue>::~OpenShuffleTable() {
    delete[] data;
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
        data[index] = record;
        count++;
    }

    return 0;
}

template <typename TKey, typename TValue>
int OpenShuffleTable<TKey, TValue>::remove(TKey key) {
    try {
        int index = findFreeIndex(key);
        if (index != -1) {
            // Если нашли элемент с таким же ключом, то удаляем его
            data[index] = TTableRecord<TKey, TValue>(TKey(), TValue());
            count--;
            return 0;
        }
        throw std::runtime_error("This object not found");
    }
    catch (const std::exception& ex) {
        std::cerr << "Error:" << ex.what() << std::endl;
    }
}

template <typename TKey, typename TValue>
TValue OpenShuffleTable<TKey, TValue>::find(TKey key) {
    try {
        int index = findFreeIndex(key);
        if (index != -1) {
            // Если нашли элемент с таким же ключом, то возвращаем его значение
            return data[index].value;
        }
        // Если элемент не найден, то возвращаем ошибку
        throw std::runtime_error("This object not found");
    }
    catch (const std::exception& ex) {
        std::cerr << "Error:" << ex.what() << std::endl;
    }
}

template <typename TKey, typename TValue>
void OpenShuffleTable<TKey, TValue>::print() {
    std::cout << "{ ";
    for (int i = 0; i < size; i++) {
        if (data[i].key != TKey()) {
            
            std::cout << "(" << data[i].key << ", " << data[i].value << ") ";
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
        if (data[index].key == key || data[index].key == TKey()) {
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
    TTableRecord<TKey, TValue>* newData = new TTableRecord<TKey, TValue>[newSize];
    for (int i = 0; i < newSize; i++) {
        newData[i].key = TKey();
        newData[i].value = TValue();
    }
    int newCount = 0;
    for (int i = 0; i < size; i++) {
        if (data[i].key != TKey()) {
            int newIndex = findFreeIndex(data[i].key);
            newData[newIndex].key = data[i].key;
            newData[newIndex].value = data[i].value;
            ++newCount;
        }
    }
    delete[] data;
    data = newData;
    size = newSize;
    count = newCount;
}

#endif // !LIB_OPENSHUFFLETABLE_OPENSHUFFLETABLE_H_