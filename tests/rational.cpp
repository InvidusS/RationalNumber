#include <gtest/gtest.h>
#include "../src/rational.h"

class RationalTest : public ::testing::Test{
protected:
    Rational r2 {2,11}, r3 {1,-3}, r5 {18,6}, r7 {}, r9 {4,1};

    Rational res1 = 3 + r2 * r3;
    Rational res2 = (3 + r2) * r3;
    Rational res3 = 3 + r3 * (r2 + 2) / (r5 - r3);

    void SetUp() override {

    }

    void TearDown() override {

    }
};

TEST_F(RationalTest, normalizedTest){
    EXPECT_EQ(Rational(97, 33), Rational::normalized(res1.getNumerator(), res1.getDenominator()));
    EXPECT_EQ(Rational(-35, 33), Rational::normalized(res2.getNumerator(), res2.getDenominator()));
    EXPECT_EQ(Rational(153, 55), Rational::normalized(res3.getNumerator(), res3.getDenominator()));
}

TEST_F(RationalTest, normaliseTest){
    EXPECT_EQ(Rational(97, 33), Rational::normalize(res1));
    EXPECT_EQ(Rational(-35, 33), Rational::normalize(res2));
    EXPECT_EQ(Rational(153, 55), Rational::normalize(res3));
}

TEST_F(RationalTest, equalityOperatorTest){
    EXPECT_EQ(r5, r7 = r5);
}

TEST_F(RationalTest, equalityOperatorIntTest){
    EXPECT_EQ(r9, r7 = 4);
}

TEST_F(RationalTest, getNominatorTest){
    EXPECT_EQ(2, r2.getNumerator());
    EXPECT_EQ(4, r9.getNumerator());
}

TEST_F(RationalTest, getDenominatorTest){
    EXPECT_EQ(11, r2.getDenominator());
    EXPECT_EQ(-3, r3.getDenominator());
}

TEST_F(RationalTest, additionTest){
    EXPECT_EQ(Rational(15,18), Rational(3,6) + Rational(1,3));
}

TEST_F(RationalTest, subtractionTest){
    EXPECT_EQ(Rational(3,18), Rational(3,6) - Rational(1,3));
}

TEST_F(RationalTest, multiplicationTest){
    EXPECT_EQ(Rational(3,18), Rational(3,6) * Rational(1,3));
}

TEST_F(RationalTest, divisionTest){
    EXPECT_EQ(Rational(9,6), Rational(3,6) / Rational(1,3));
}

TEST_F(RationalTest, equalOperatorTest){
    EXPECT_TRUE(Rational(3,6) == Rational(3,6));
}

TEST_F(RationalTest, lessOrEqualOperatorTest){
    EXPECT_TRUE(Rational(3,6) <= Rational(3,6));
    EXPECT_TRUE(Rational(3,6) <= Rational(3,5));
}

TEST_F(RationalTest, greaterOrEqualOperatorTest){
    EXPECT_TRUE(Rational(3,6) >= Rational(3,6));
    EXPECT_TRUE(Rational(3,6) >= Rational(3,7));
}

TEST_F(RationalTest, lessOperatorTest){
    EXPECT_TRUE(Rational(3,6) < Rational(3,5));
}

TEST_F(RationalTest, greaterOperatorTest){
    EXPECT_TRUE(Rational(3,6) > Rational(3,7));
}
