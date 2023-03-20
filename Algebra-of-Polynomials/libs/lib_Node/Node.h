#ifndef LIB_NODE_NODE_H_
#define LIB_NODE_NODE_H_

#include <string>
template <typename T>
class Node {
	std::string Value;
	std::string Key;
	T* Next;
	T* Previous;
public:
	std::string getValue();
	std::string getKey();
	T* getNext();
	T& operator= (const T& node);
};

#endif // !LIB_NODE_NODE_H_