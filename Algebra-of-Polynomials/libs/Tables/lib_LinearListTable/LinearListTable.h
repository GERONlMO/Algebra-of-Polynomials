#ifndef LIB_LINEARLISTTABLE_LINEARLISTTABLE_H_
#define LIB_LINEARLISTTABLE_LINEARLISTTABLE_H_

#include "..\lib_UnsortedTable\UnsortedTable.h"
#include "..\..\Functional\lib_List\List.h"
template <typename TKey, typename TValue>
class LinearListTable : public UnsortedTable<TKey, TValue> {
	List<TTableRecord<TKey, TValue>> data;
public:
    LinearListTable() {};
    ~LinearListTable() {};
	virtual int insert(TKey key, TValue value) override;
	virtual int remove(TKey key) override;
	virtual TValue find(TKey key) override;
	virtual void print() override;
};

template <typename TKey, typename TValue>
int LinearListTable<TKey, TValue>::insert(TKey key, TValue value) {
    TTableRecord<TKey, TValue> newRecord = { key, value };
    data.push_back(newRecord);
    return 0;
}

template <typename TKey, typename TValue>
int LinearListTable<TKey, TValue>::remove(TKey key) {
    for (int i = 0; i < data.size(); i++) {
        if (data.get(i).key == key) {
            data.remove(data.get(i));
            return 0;
        }
    }

    throw "Object not found";
}

template <typename TKey, typename TValue>
TValue LinearListTable<TKey, TValue>::find(TKey key) {
    for (int i = 0; i < data.size(); i++) {
        if (data.get(i).key == key) {
            return data.get(i).value;
        }
    }

    throw "Object not found";
}

template <typename TKey, typename TValue>
void LinearListTable<TKey, TValue>::print() {
    for (int i = 0; i < data.size(); i++) {
        std::cout << "Key: " << data.get(i).key << ", Value: " << data.get(i).value << std::endl;
    }
}

#endif // !LIB_LINEARLISTTABLE_LINEARLISTTABLE_H_