#include "rational.h"
#include <iostream>

Rational::Rational(int numerator, int denominator = 1) : numer{numerator}, denom{denominator} {}

Rational::Rational(const Rational& copy) : Rational {copy.numer, copy.denom} {}

Rational& Rational::operator = (const Rational& other) {
    this->numer = other.numer;
    this->denom = other.denom;
    return *this;
}

Rational& Rational::operator = (int rationalNumber) {
    this->numer = rationalNumber;
    this->denom = 1;
    return *this;
}

int Rational::getNumerator() const {
    return numer;
}

int Rational::getDenominator() const {
    return denom;
}

Rational Rational::normalize(const Rational& r){
    int n = std::abs(r.numer);
    int d = std::abs(r.denom);

    while(n != d){
        if(n > d)
            n -= d;
        else
            d -= n;
    }

    if(r.denom < 0)
        return +Rational {r.numer / n, r.denom / n};
    return Rational{r.numer / n, r.denom / n};
}

Rational Rational::normalized(int numerator, int denominator){
    int n = std::abs(numerator);
    int d = std::abs(denominator);

    while(n != d){
        if(n > d)
            n -= d;
        else
            d -= n;
    }

    numerator /= n;
    denominator /= n;

    if(denominator < 0)
        return +Rational {numerator, denominator};
    return Rational{numerator, denominator};
}

Rational Rational::operator + (const Rational& other) const {
    return Rational {this->numer * other.denom + this->denom * other.numer, this->denom * other.denom};
}

Rational Rational::operator - (const Rational& other) const {
    return Rational {this->numer * other.denom - this->denom * other.numer, this->denom * other.denom};
}

Rational Rational::operator * (const Rational& other) const {
    return Rational {this->numer * other.numer, this->denom * other.denom};
}

Rational Rational::operator / (const Rational& other) const {
    return Rational {this->numer * other.denom, this->denom * other.numer};
}

Rational Rational::operator + ()const {
    return Rational {this->numer * -1, this->denom * -1};
}

Rational Rational::operator - ()const {
    return Rational {this->numer * -1, this->denom};
}

bool Rational::operator == (const Rational& other) const {
    return (this->numer * other.denom == this->denom * other.numer) ? true : false;
}

bool Rational::operator >= (const Rational& other) const {
    return (this->numer * other.denom >= this->denom * other.numer) ? true : false;
}

bool Rational::operator <= (const Rational& other) const {
    return (this->numer * other.denom <= this->denom * other.numer) ? true : false;
}

bool Rational::operator > (const Rational& other) const {
    return (this->numer * other.denom > this->denom * other.numer) ? true : false;
}

bool Rational::operator < (const Rational& other) const {
    return (this->numer * other.denom < this->denom * other.numer) ? true : false;
}

Rational operator + (const Rational& r, int i) {
    return Rational {r.getNumerator() + r.getDenominator() * i, r.getDenominator()};
}

Rational operator + (int i, const Rational& r) {
    return Rational {r.getNumerator() + r.getDenominator() * i, r.getDenominator()};
}

Rational operator - (const Rational& r, int i) {
    return Rational {r.getNumerator() - r.getDenominator() * i, r.getDenominator()};
}

Rational operator - (int i, const Rational& r) {
    return Rational {r.getNumerator() - r.getDenominator() * i, r.getDenominator()};
}

Rational operator * (const Rational& r, int i) {
    return Rational {r.getNumerator() * i, r.getDenominator()};
}

Rational operator * (int i, const Rational& r) {
    return Rational {r.getNumerator() * i, r.getDenominator()};
}

Rational operator / (const Rational& r, int i) {
    return Rational {r.getNumerator(), r.getDenominator() * i};
}

Rational operator / (int i, const Rational& r) {
    return Rational {r.getNumerator(), r.getDenominator() * i};
}

std::ostream& operator << (std::ostream& os, const Rational& other) {
    os << '(' << other.numer << '/' << other.denom << ')' << '\n';
    return os;
}

std::istream& operator >> (std::istream& is, Rational& other){
    std::cout << "Enter numerator: ";
    is >> other.numer;

    std::cout << "Enter Denominator: ";
    is >> other.denom;

    return is;
}
