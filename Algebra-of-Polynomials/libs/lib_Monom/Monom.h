#ifndef LIB_MONOM_MONOM_H_
#define LIB_MONOM_MONOM_H_

#include <string>

class Monom {
	int coeff;
	int powers[3];
public:
	Monom();
	Monom(int coeff, int index, int* powers);
	int getCoeff();
	int* getPowers();
};

#endif // !LIB_MONOM_MONOM_H_