#ifndef LIB_POLYNOM_POLYNOM_H_
#define LIB_POLYNOM_POLYNOM_H_

#include "..\lib_Monom\Monom.h"
#include "..\lib_List\List.h"

class Polynom {
    List<Monom> monoms;
    std::string signs;

    void stringInMonom(std::string strMonom);
public:
    Polynom(std::string);
    Polynom(const Polynom& polynom);
    ~Polynom();

    Polynom& operator=(const Polynom& polynom);
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

    void toString();

    int at(int x);
    Polynom derivative();
    Polynom integral();
};
#endif // !LIB_POLYNOM_POLYNOM_H_