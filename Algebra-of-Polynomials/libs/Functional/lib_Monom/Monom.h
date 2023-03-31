#ifndef LIB_MONOM_MONOM_H_
#define LIB_MONOM_MONOM_H_

#include <string>

class Monom {
	int coeff;
	int powers[3];
public:
	Monom();
	Monom(const Monom& monom);
	Monom(int coeff, int index, int* powers);
	int getCoeff();
	int* getPowers();
	void toString();
	Monom& operator=(const Monom& monom);
	Monom operator+(const Monom& monom);
	Monom operator+=(const Monom& monom);
	Monom operator-() const;
	Monom operator-(const Monom& monom);
	Monom operator-=(const Monom& monom);
	Monom operator*(int x);
	Monom operator*(const Monom& monom);
	Monom operator*=(int x);
	Monom operator*=(const Monom& monom);
	Monom operator/(int x);
	Monom operator/(const Monom& monom);
	Monom operator/=(int x);
	Monom operator/=(const Monom& monom);
	bool operator==(const Monom& monom);
	bool operator!=(const Monom& monom);
	bool operator>(const Monom& monom);
	bool operator<(const Monom& monom);
	bool operator>=(const Monom& monom);
	bool operator<=(const Monom& monom);


};

#endif // !LIB_MONOM_MONOM_H_