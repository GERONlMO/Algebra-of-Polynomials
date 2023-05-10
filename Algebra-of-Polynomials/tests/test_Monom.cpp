#include "../gtest/gtest.h"
#include "Monom.h"
TEST(Monom_comparisons, Monom_less){};
TEST(Monom_comparisons, Monom_greater) {};
TEST(Monom_comparisons, Monom_less_or_equal) {};
TEST(Monom_comparisons, Monom_greater_or_equal) {};
TEST(Monom_comparisons, Monom_equal) {};
TEST(Monom_comparisons, Monom_not_equal) {};

TEST(Monom_operations, Monom_plus) {
    // Test adding two monomials with the same variables and powers
    Monom m1(2, 3, { 1, 2 });
    Monom m2(4, 3, { 1, 2 });
    Monom result = m1 + m2;
    EXPECT_EQ(result.getCoeff(), 6);
    EXPECT_EQ(result.getNumVars(), 2);
    EXPECT_EQ(result.getPowers()[0], 1);
    EXPECT_EQ(result.getPowers()[1], 2);
};
TEST(Monom_operations, Monom_minus) {};
TEST(Monom_operations, Monom_unar_minus) {};
TEST(Monom_operations, Monom_mult) {};
TEST(Monom_operations, Monom_mult_on_number) {};
TEST(Monom_operations, Monom_div) {};
TEST(Monom_operations, Monom_div_on_number) {};
TEST(Monom_operations, Monom_assignment) {};

TEST(Monom_methods, Monom_get_coefficient) {};
TEST(Monom_methods, Monom_get_powers) {};

