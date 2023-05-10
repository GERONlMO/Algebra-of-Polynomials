#ifndef LIB_PARSER_PARSER_H_
#define LIB_PARSER_PARSER_H_

#include <map>
#include <stack>
#include <iostream>
#include "../lib_Stack/Stack.h"
#include "../lib_Monom/Monom.h"
#include "../lib_SyntaxTree/SyntaxTree.h"
#include "../lib_List/List.h"

class Parser {
	std::string targetExpression;
    List<Monom> list;
    void removeSpaces();
public:
    Parser();
	Parser(std::string expression);
	List<Monom> parse();
	void parseMonom(std::string monom);
    void removeSpaces(std::string& expression);

};

#endif // !LIB_PARSER_PARSER_H_