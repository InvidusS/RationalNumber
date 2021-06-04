#include <gtest/gtest.h>
#include "../src/rational.h"

TEST(TS13, testing_operator_equal){
    Rational r1(3,6), r2(3,6);
    ASSERT_TRUE(r1 == r2);
}

TEST(TS14, testing_operator_less_or_equal){
    Rational r1(3,6), r2(3,6), r3(3,5);
    ASSERT_TRUE(r1 <= r2);
    ASSERT_TRUE(r1 <= r3);
}

TEST(TS15, testing_operator_greater_or_equal){
    Rational r1(3,6), r2(3,6), r3(3,7);
    ASSERT_TRUE(r1 >= r2);
    ASSERT_TRUE(r1 >= r3);
}

TEST(TS16, testing_operator_less){
    Rational r1(3,6), r2(3,5);
    ASSERT_TRUE(r1 < r2);
}

TEST(TS17, testing_operator_greater){
    Rational r1(3,6), r2(3,7);
    ASSERT_TRUE(r1 > r2);
}
