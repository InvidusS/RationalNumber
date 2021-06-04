#include <gtest/gtest.h>
#include "../src/rational.h"

TEST(TS1, testing_normalized) {
    Rational result (-35, 33);
    Rational r = (3 + Rational(2, 11)) * Rational(-1, 3);
    ASSERT_EQ(result, Rational::normalized(r.getNumerator(), r.getDenominator()));
}

TEST(TS2, testing_normalize) {
    Rational result (153, 55);
    Rational r = 3 + Rational(-1, 3) * (Rational(2, 11) + 2) / (Rational(18, 6) - Rational(1, -3));
    ASSERT_EQ(result, Rational::normalize(r));
}

TEST(TS3, testing_equality_operator_class){
    Rational result(1,2), r1;
    ASSERT_EQ(result, r1 = result);
}

TEST(TS4, testing_equality_operator_int){
    Rational result(4,1), r1;
    ASSERT_EQ(result, r1 = 4);
}

TEST(TS5, testing_numerator_getter){
    Rational r(4,1);
    ASSERT_EQ(4, r.getNumerator());
}

TEST(TS6, testing_denominator_getter){
    Rational r(4,1);
    ASSERT_EQ(1, r.getDenominator());
}
