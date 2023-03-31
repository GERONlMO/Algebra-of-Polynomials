#ifndef LIB_NODE_NODE_H_
#define LIB_NODE_NODE_H_

#include <string>
template <typename T>
class Node {
	std::string value;
	std::string key;
	T* next;
	T* top;
	
public:
	std::string getValue();
	std::string getKey();
	T* getNext();
	T* getTop();
	T& operator= (const T& node);
};

#endif // !LIB_NODE_NODE_H_