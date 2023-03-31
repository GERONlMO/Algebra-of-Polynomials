#ifndef LIB_PARSER_PARSER_H_
#define LIB_PARSER_PARSER_H_

#include <map>
#include <stack>
#include <iostream>
#include "../lib_Stack/Stack.h"
#include "../lib_Monom/Monom.h"
#include "../lib_SyntaxTree/SyntaxTree.h"

class Parser {
	std::string infixExpression;
	std::string postfixExpression;
	SyntaxTree<std::string> tree;
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

	/// <summary>
	/// Parsing string polynom into postfix expression
	/// </summary>
	/// <returns>String postfix expression</returns>
	std::string parse();
	double calculate();
	std::string getPostfix();
	std::string* split(std::string polynom);
	Monom getMonom(std::string monom);

	/// <summary>
	/// Uniting array of monoms into string polynom
	/// </summary>
	/// <param name="Array of Monoms"></param>
	/// <returns></returns>
	std::string unite(Monom* monoms);
};

#endif // !LIB_PARSER_PARSER_H_