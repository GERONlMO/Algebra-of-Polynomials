#ifndef LIB_POLYNOM_POLYNOM_H_
#define LIB_POLYNOM_POLYNOM_H_
#include <string>
#include "..\lib_Monom\Monom.h"
#include "..\lib_List\List.h"
#include "../lib_SyntaxTree/SyntaxTree.h"

class Polynom {
	std::string strPolynom;
	List<Monom> monoms;
    SyntaxTree<std::string, Monom> tree;
    std::string toPostfix();
    void parseMonoms();
public:
	Polynom(std::string);
	Polynom operator=(const Polynom& polynom);
	Polynom operator+(const Monom& monom);
	Polynom operator+(const Polynom& polynom);
	Polynom operator-(const Monom& monom);
	Polynom operator-(const Polynom& polynom);
	Polynom operator*(const int* x);
	Polynom operator*(const Polynom& polynom);
	Polynom operator/(const int* x);
	Polynom operator/(const Polynom& polynom);
	bool operator==(const Polynom& polynom);
	bool operator!=(const Polynom& polynom);
	bool operator>(const Polynom& polynom);
	bool operator<(const Polynom& polynom);
	bool operator>=(const Polynom& polynom);
	bool operator<=(const Polynom& polynom);

	int at(int x);
	Polynom derivative();
	Polynom integral();
	std::string toString();
	Monom* getMonoms();


};
//Input -> input - polynom -> split into monoms -> calculate derivative | add/substract/multiply/divide monoms -!
//						   -> convert to postfix -> calculate -!
#endif // !LIB_POLYNOM_POLYNOM_H_ x^3y^2 + .. -> (1), (2) -> 1, [3,2]