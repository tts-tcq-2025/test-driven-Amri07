#include "StringCalculator.h"
#include <gtest/gtest.h>

class StringCalculatorTest : public ::testing::Test {
protected:
    StringCalculator calculator;
};

TEST_F(StringCalculatorTest, ReturnZeroForEmptyString) {
    EXPECT_EQ(calculator.add(""), 0);
}

TEST_F(StringCalculatorTest, ReturnSingleNumber) {
    EXPECT_EQ(calculator.add("1"), 1);
}

TEST_F(StringCalculatorTest, SumTwoCommaSeparatedNumbers) {
    EXPECT_EQ(calculator.add("1,2"), 3);
}

TEST_F(StringCalculatorTest, SumUnknownAmountOfNumbers) {
    EXPECT_EQ(calculator.add("1,2,3,4,5"), 15);
}

TEST_F(StringCalculatorTest, HandleNewLineAsDelimiter) {
    EXPECT_EQ(calculator.add("1\n2,3"), 6);
}

TEST_F(StringCalculatorTest, CustomSingleCharDelimiter) {
    EXPECT_EQ(calculator.add("//;\n1;2"), 3);
}

TEST_F(StringCalculatorTest, CustomMultiCharDelimiter) {
    EXPECT_EQ(calculator.add("//[***]\n1***2***3"), 6);
}

TEST_F(StringCalculatorTest, IgnoreNumbersGreaterThan1000) {
    EXPECT_EQ(calculator.add("2,1001"), 2);
}

TEST_F(StringCalculatorTest, NegativeNumberThrowsException) {
    std::string input = "1,-2";
    std::string expectedMessage = "negatives not allowed: -2";
    auto exception = testing::AssertionFailure();
    EXPECT_THROW({
        try {
            calculator.add(input);
        } catch (const std::invalid_argument& e) {
            exception = testing::AssertionFailure() << e.what();
            throw;
        }
    }, std::invalid_argument);
    EXPECT_TRUE(exception << expectedMessage);
}

TEST_F(StringCalculatorTest, MultipleNegativesInException) {
    std::string input = "1,-2,-3";
    std::string expectedMessage = "negatives not allowed: -2,-3";
    auto exception = testing::AssertionFailure();
    EXPECT_THROW({
        try {
            calculator.add(input);
        } catch (const std::invalid_argument& e) {
            exception = testing::AssertionFailure() << e.what();
            throw;
        }
    }, std::invalid_argument);
    EXPECT_TRUE(exception << expectedMessage);
}