#include "../lib_Monom/Monom.h"


Monom::Monom() {
    coeff = 0;
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

Monom::Monom(int coeff, int numVars, int* powers) {
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

int Monom::getCoeff() {
    return coeff;
}

int* Monom::getPowers() {
    return powers;
}

void Monom::toString() {
    std::cout << coeff;
    for (int i = 0; i < numVars; i++) {
        if (powers[i] > 0) {
            std::cout << "x" << i << "^" << powers[i];
        }
    }
    std::cout << std::endl;
}

Monom& Monom::operator=(const Monom& monom) {
    coeff = monom.coeff;
    numVars = monom.numVars;
    powers = new int[numVars];
    for (int i = 0; i < numVars; i++) {
        powers[i] = monom.powers[i];
    }
    return *this;
}

Monom Monom::operator+(const Monom& monom) {
    Monom result;
    if (numVars == monom.numVars) {
        bool isEqual = true;
        for (int i = 0; i < numVars; i++) {
            if (powers[i] != monom.powers[i]) {
                isEqual = false;
                break;
            }
        }
        if (isEqual) {
            result.coeff = coeff + monom.coeff;
            result.numVars = numVars;
            result.powers = new int[numVars];
            for (int i = 0; i < numVars; i++) {
                result.powers[i] = powers[i];
            }
        }
    }
    return result;
}

Monom Monom::operator+=(const Monom& monom) {
    if (numVars == monom.numVars) {
        bool isEqual = true;
        for (int i = 0; i < numVars; i++) {
            if (powers[i] != monom.powers[i]) {
                isEqual = false;
                break;
            }
        }
        if (isEqual) {
            coeff += monom.coeff;
        }
    }
    return *this;
}

Monom Monom::operator-() const {
    Monom result(*this);
    result.coeff = -coeff;
    return result;
}

Monom Monom::operator-(const Monom& monom) {
    Monom result;
    if (numVars == monom.numVars) {
        bool isEqual = true;
        for (int i = 0; i < numVars; i++) {
            if (powers[i] != monom.powers[i]) {
                isEqual = false;
                break;
            }
        }
        if (isEqual) {
            result.coeff = coeff - monom.coeff;
            result.numVars = numVars;
            result.powers = new int[numVars];
            for (int i = 0; i < numVars; i++) {
                result.powers[i] = powers[i];
            }
        }
    }
    return result;
}

Monom Monom::operator-=(const Monom& monom) {
    if (numVars == monom.numVars) {
        bool isEqual = true;
        for (int i = 0; i < numVars; i++) {
            if (powers[i] != monom.powers[i]) {
                isEqual = false;
                break;
            }
        }
        if (isEqual) {
            coeff -= monom.coeff;
        }
    }
    return *this;
}

Monom Monom::operator*(int x) {
    Monom result(*this);
    result.coeff *= x;
    return result;
}

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

Monom Monom::operator*=(int x) {
    *this = *this * x;
    return *this;
}

Monom Monom::operator*=(const Monom& monom) {
    *this = *this * monom;
    return *this;
}

Monom Monom::operator/(int x) {
    Monom result(*this);
    result.coeff /= x;
    for (int i = 0; i < numVars; i++) {
        result.powers[i] /= x;
    }
    return result;
}

Monom Monom::operator/(const Monom& monom) {
    Monom result(*this);
    for (int i = 0; i < numVars; i++) {
        result.powers[i] -= monom.powers[i];
    }
    result.coeff /= monom.coeff;
    return result;
}

Monom Monom::operator/=(int x) {
    coeff /= x;
    for (int i = 0; i < numVars; i++) {
        powers[i] /= x;
    }
    return *this;
}

Monom Monom::operator/=(const Monom& monom) {
    for (int i = 0; i < numVars; i++) {
        powers[i] -= monom.powers[i];
    }
    coeff /= monom.coeff;
    return *this;
}

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

bool Monom::operator!=(const Monom& monom) {
    return !(*this == monom);
}

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

bool Monom::operator>=(const Monom& monom) {
    return (*this > monom) || (*this == monom);
}

bool Monom::operator<=(const Monom& monom) {
    return (*this < monom) || (*this == monom);
}