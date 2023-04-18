#include "Polynom.h"
#include <sstream>
#include <iomanip>

Polynom::Polynom(std::string str) {
    std::string delimiter = "+-";

    size_t start = 0, end = 0;
    while ((end = str.find_first_of(delimiter, start)) != std::string::npos) {
        std::string token = str.substr(start, end - start);
        stringInMonom(token);
        signs += str.substr(end, 1);
        start = end + 1;
    }
    stringInMonom(str.substr(start));
    signs += " ";
}

Polynom::Polynom(const Polynom& polynom) {
    monoms = polynom.monoms;
    signs = polynom.signs;
}

Polynom::~Polynom() {
    monoms.resetList();
}





Polynom& Polynom::operator=(const Polynom& polynom) {
    monoms = polynom.monoms;
    signs = polynom.signs;
    return *this;
}

bool Polynom::operator==(const Polynom& polynom) {
    List<Monom> tmp = polynom.monoms;
    if (monoms.size() == tmp.size()) {
        return false;
    }
}

bool Polynom::operator!=(const Polynom& polynom) {

}

bool Polynom::operator>(const Polynom& polynom) {

}

bool Polynom::operator<(const Polynom& polynom) {

}

bool Polynom::operator>=(const Polynom& polynom) {

}

bool Polynom::operator<=(const Polynom& polynom) {

}

void Polynom::stringInMonom(std::string strMonom) {
    double coeff = 1;
    int numVars = 3;
    int powers[] = { 0, 0, 0};
    std::string varsName = "xyz";
    for (int i = 0; i < strMonom.size(); i++) {
        if (strMonom[i] >= '0' && strMonom[i] <= '9') {
            coeff = std::stod(strMonom);
        }
        if (strMonom[i] == 'x' || strMonom[i] == 'y' || strMonom[i] == 'z') {
            for (int j = 0; j < 3; j++) {
                if (strMonom[i] == varsName[j]) {
                    if (strMonom[i + 1] == '^') {
                        powers[j] = std::stoi(strMonom.substr(i + 2));
                    }
                    else {
                        powers[j] = 1;
                    }
                }
            }
        }
    }
    Monom monom(coeff, numVars, powers);
    monoms.push_back(monom);
}

void Polynom::toString() {
    if (monoms.size() == 0) {
        std::cout << "0";
        return;
    }
    for (int i = 0; i < monoms.size(); i++) {
        Monom monom = monoms.get(i);

        monom.toString();
        std::cout << " " << signs[i] << " ";
    }
}