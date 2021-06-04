#pragma once

#include <iostream>

class Rational {
private:
    int numer;
    int denom;

    void initialize(int numerator, int denominator);

    friend std::ostream& operator << (std::ostream&, const Rational&);
    friend std::istream& operator >> (std::istream&, Rational&);

public:
    Rational() = default;
    Rational(int, int);
    Rational(const Rational&);
    ~Rational() = default;

    Rational& operator = (const Rational&);
    Rational& operator = (int);

    int getNumerator() const ;
    int getDenominator() const ;

    static Rational normalize(const Rational&);
    static Rational normalized(int, int);

    Rational operator + (const Rational&) const;
    Rational operator - (const Rational&) const;
    Rational operator * (const Rational&) const;
    Rational operator / (const Rational&) const;

    Rational operator + () const;
    Rational operator - () const;

    bool operator == (const Rational&) const;
    bool operator <= (const Rational&) const;
    bool operator >= (const Rational&) const;
    bool operator < (const Rational&) const;
    bool operator > (const Rational&) const;
};

Rational operator + (const Rational&, int);
Rational operator + (int, const Rational&);

Rational operator - (const Rational&, int);
Rational operator - (int, const Rational&);

Rational operator * (const Rational&, int);
Rational operator * (int, const Rational&);

Rational operator / (const Rational&, int);
Rational operator / (int, const Rational&);
