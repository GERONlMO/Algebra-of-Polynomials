#ifndef LIB_PARSER_PARSER_H_
#define

#include <map>
#include <stack>
#include <iostream>
#include "Stack.h"

class Parser {

private:
	std::string infixExpression;
	std::string postfixExpression;
	std::map<char, int> operationsPriority = {
		{'(', 0},
		{'+', 1},
		{'-', 1},
		{'*', 2},
		{'/', 2},
		{'^', 3},
		{'~', 4}
	};

	bool isDigit(char c);
	bool containsKey(char c);
	std::string parseNumber(std::string expression, int* position);
	double execute(char operation, double first, double second);
	int getOperationPriority(char operation);
	bool isCorrect();

public:
	Parser(std::string expression);
	std::string toPostfix();
	double calculate();
	std::string getPostfix();
};

#endif // !LIB_PARSER_PARSER_H_