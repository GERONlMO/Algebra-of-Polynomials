#ifndef LIB_UNORDEREDTABLE_UNORDEREDTABLE_H_
#define LIB_UNORDEREDTABLE_UNORDEREDTABLE_H_

template <typename T>
class UnorderedTable : public Table {
public:
	virtual int insert(T obj);
	virtual int remove(T obj);
	virtual T find(std::string key);
	virtual void print();
};

#endif // !LIB_UNORDEREDTABLE_UNORDEREDTABLE_H_