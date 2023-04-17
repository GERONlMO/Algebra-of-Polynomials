#ifndef LIB_MONOM_MONOM_H_
#define LIB_MONOM_MONOM_H_

#include <iostream>
#include <string>

class Monom {
	int coeff;
	int* powers; // [0] = x; [1] = y; [2] = z
	int numVars;
    std::string varsName[3] = {"x", "y", "z"};
public:
	Monom();
	Monom(const Monom& monom);
	Monom(int coeff, int numVars, int* powers);
	~Monom();
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