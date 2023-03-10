#ifndef LIB_NODE_NODE_H_
#define LIB_NODE_NODE_H_

#include <string>

class Node {
	std::string Value;
	std::string Key;
	Node* Next;
	Node* Previous;
public:
	std::string getValue();
	std::string getKey();
	Node* getNext();
	Node& operator= (const Node& node);
};

#endif // !LIB_NODE_NODE_H_