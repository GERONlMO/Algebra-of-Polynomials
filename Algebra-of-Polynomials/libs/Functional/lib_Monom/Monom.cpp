#include "../lib_Monom/Monom.h"

Monom::Monom() {
    coeff = 0.0;
    powers = nullptr;
    numVars = 0;
}

Monom::Monom(const Monom& monom) {
    coeff = monom.coeff;
    numVars = monom.numVars;
    powers = new int[numVars];
    for (int i = 0; i < numVars; i++) {
        powers[i] = monom.powers[i];
    }
}

Monom::Monom(double coeff, int numVars, int* powers) {
    this->coeff = coeff;
    this->numVars = numVars;
    this->powers = new int[numVars];
    for (int i = 0; i < numVars; i++) {
        this->powers[i] = powers[i];
    }
}

Monom::~Monom() {
    delete[] powers;
}

double Monom::getCoeff() {
    return coeff;
}

int* Monom::getPowers() {
    return powers;
}

int Monom::getNumVars() {
    return numVars;
}
//COMPLETED
std::string Monom::toString() {
    std::string out;
    if (coeff == 0)
        return "0";
    std::string strCoeff = std::to_string(coeff);
    strCoeff.erase(strCoeff.find_last_not_of('0') + 1, std::string::npos);
    out += strCoeff + printPowers();
    return out;
}

//COMPLETED
std::string Monom::printPowers() {
    std::string out;
    for(int i = 0; i < numVars; i++) {
        if (powers[i] > 1) {
            out += varsName[i] + "^" + std::to_string(powers[i]);
        } else if (powers[i] > 0){
            out += varsName[i];
        }
    }
    return out;
}
//COMPLETED
Monom& Monom::operator=(const Monom& monom) {
    if (this == &monom)
        return *this;
    coeff = monom.coeff;
    numVars = monom.numVars;
    powers = new int[numVars];
    for (int i = 0; i < numVars; i++) {
        powers[i] = monom.powers[i];
    }
    return *this;
}
//COMPLETED
Monom Monom::operator+(const Monom& monom) {
    Monom result;
    if (isEqual(monom)) {
        result.coeff = coeff + monom.coeff;
        result.numVars = numVars;
        result.powers = new int[numVars];
        for (int i = 0; i < numVars; i++) {
            result.powers[i] = powers[i];
        }
    }
    return result;
}
//COMPLETED
Monom Monom::operator+=(const Monom& monom) {
    if (isEqual(monom)) {
        coeff += monom.coeff;
    }
    return *this;
}
//COMPLETED
Monom Monom::operator-() const {
    Monom result(*this);
    result.coeff = -coeff;
    return result;
}
//COMPLETED
Monom Monom::operator-(const Monom& monom) {
    Monom result;

    if (isEqual(monom)) {
        result.coeff = coeff - monom.coeff;
        result.numVars = numVars;
        result.powers = new int[numVars];
        for (int i = 0; i < numVars; i++) {
            result.powers[i] = powers[i];
        }
    }
    return result;
}
//COMPLETED
Monom Monom::operator-=(const Monom& monom) {
    if (isEqual(monom)) {
        coeff -= monom.coeff;
    }
    return *this;
}
//COMPLETED
Monom Monom::operator*(int x) {
    Monom result(*this);
    result.coeff *= x;
    return result;
}
//COMPLETED
Monom Monom::operator*(const Monom& monom) {
    if (numVars != monom.numVars) {
        throw std::invalid_argument("Different number of variables");
    }
    Monom result;
    result.coeff = coeff * monom.coeff;
    result.numVars = numVars;
    result.powers = new int[numVars];
    for (int i = 0; i < numVars; i++) {
        result.powers[i] = powers[i] + monom.powers[i];
    }
    return result;
}
//COMPLETED
Monom Monom::operator*=(int x) {
    *this = *this * x;
    return *this;
}
//COMPLETED
Monom Monom::operator*=(const Monom& monom) {
    *this = *this * monom;
    return *this;
}
//COMPLETED
Monom Monom::operator/(int x) {
    Monom result(*this);
    result.coeff /= x;
    return result;
}
//COMPLETED
Monom Monom::operator/(const Monom& monom) {
    Monom result(*this);
    for (int i = 0; i < numVars; i++) {
        result.powers[i] -= monom.powers[i];
    }
    result.coeff /= monom.coeff;
    return result;
}
//COMPLETED
Monom Monom::operator/=(int x) {
    coeff /= x;
    return *this;
}
//COMPLETED
Monom Monom::operator/=(const Monom& monom) {
    for (int i = 0; i < numVars; i++) {
        powers[i] -= monom.powers[i];
    }
    coeff /= monom.coeff;
    return *this;
}
//COMPLETED
bool Monom::operator==(const Monom& monom) {
    if (coeff != monom.coeff) {
        return false;
    }
    for (int i = 0; i < numVars; i++) {
        if (powers[i] != monom.powers[i]) {
            return false;
        }
    }
    return true;
}
//COMPLETED
bool Monom::operator!=(const Monom& monom) {
    return !(*this == monom);
}
//COMPLETED
bool Monom::operator>(const Monom& monom) {
    for (int i = 0; i < numVars; i++) {
        if (powers[i] > monom.powers[i]) {
            return true;
        }
        else if (powers[i] < monom.powers[i]) {
            return false;
        }
    }
    return coeff > monom.coeff;
}
//COMPLETED
bool Monom::operator<(const Monom& monom) {
    for (int i = 0; i < numVars; i++) {
        if (powers[i] < monom.powers[i]) {
            return true;
        }
        else if (powers[i] > monom.powers[i]) {
            return false;
        }
    }
    return coeff < monom.coeff;
}
//COMPLETED
bool Monom::operator>=(const Monom& monom) {
    return (*this > monom) || (*this == monom);
}
//COMPLETED
bool Monom::operator<=(const Monom& monom) {
    return (*this < monom) || (*this == monom);
}
//COMPLETED
bool Monom::isEqual(Monom monom) {
    for (int i = 0; i < numVars; i++) {
        if (powers[i] != monom.powers[i]) {
            return false;
        }
    }
    return true;
}

void Monom::setCoeff(double coeff) {
    this->coeff = coeff;
}

double Monom::evaluate(double x, double y, double z) {
    return coeff * pow(x, powers[0]) * pow(y, powers[1]) * pow(z, powers[2]);
}

