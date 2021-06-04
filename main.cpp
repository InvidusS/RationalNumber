#include <iostream>
#include "rational.h"

int main() {
    Rational r2 {2,11}, r3 {1,-3}, r5 {18,6};

    Rational res1 = 3 + r2 * r3;
    Rational res2 = (3 + r2) * r3;
    Rational res3 = 3 + r3 * (r2 + 2) / (r5 - r3);

    std::cout << Rational::normalize(res1) << '\n';
    std::cout << Rational::normalize(res2) << '\n';
    std::cout << Rational::normalize(res3) << '\n';
    return 0;
}
