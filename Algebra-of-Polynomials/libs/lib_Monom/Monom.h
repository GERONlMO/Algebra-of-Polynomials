#ifndef LIB_MONOM_MONOM_H_
#define

#include <string>

class Monom {
public:
	int coeff;
	int index;
	int* powers;

	Monom();
	Monom(int coeff, int index, int* powers);
};

#endif // !LIB_MONOM_MONOM_H_