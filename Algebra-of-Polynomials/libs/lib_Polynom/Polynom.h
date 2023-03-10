#ifndef LIB_POLYNOM_POLYNOM_H_
#define LIB_POLYNOM_POLYNOM_H_
#include <string>
#include "..\lib_Monom\Monom.h"

class Polynom {
	std::string polynom;
	Monom* monoms;
public:
	Polynom operator+(const Polynom& polynom);
	Polynom operator-(const Polynom& polynom);
	Polynom operator*(const Polynom& polynom);
	Polynom operator/(const Polynom& polynom);

	std::string getPolynom();
	Monom* getMonoms();


};
//Input -> input - polynom -> split into monoms -> calculate derivative | add/substract/multiply/divide monoms -!
//						   -> convert to postfix -> calculate -!
#endif // !LIB_POLYNOM_POLYNOM_H_ x^3y^2 + .. -> (1), (2) -> 1, [3,2]