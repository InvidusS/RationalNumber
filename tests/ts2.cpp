#include <gtest/gtest.h>
#include "../src/rational.h"

TEST(TS7, testing_addition){
    Rational result(15,18), r1(3,6), r2(1,3);
    ASSERT_EQ(result, r1 + r2);
}

TEST(TS8, testing_subtraction){
    Rational result(3,18), r1(3,6), r2(1,3);
    ASSERT_EQ(result, r1 - r2);
}

TEST(TS9, testing_multiplication){
    Rational result(3,18), r1(3,6), r2(1,3);
    ASSERT_EQ(result, r1 * r2);
}

TEST(TS10, testing_division){
    Rational result(9,6), r1(3,6), r2(1,3);
    ASSERT_EQ(result, r1 / r2);
}

TEST(TS11, testing_inverse){
    Rational result(-3,6), r1(3,6);
    ASSERT_EQ(result, -r1);
}

TEST(TS12, testing_inverse_2){
    Rational result(-3,-6), r1(3,6);
    ASSERT_EQ(result, +r1);
}
