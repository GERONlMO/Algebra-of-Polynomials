#ifndef LIB_MONOM_MONOM_H_
#define LIB_MONOM_MONOM_H_

#include <iostream>
#include <string>

class Monom {
	double coeff;
	int* powers;
	int numVars;
    std::string varsName[3] = {"x", "y", "z"};
    std::string printPowers();
    bool isEqual(Monom monom);
public:
	Monom();
	Monom(const Monom& monom);
	Monom(double coeff, int numVars, int* powers);
	~Monom();
	double getCoeff();
	int* getPowers();
	int getNumVars();
	std::string toString();
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