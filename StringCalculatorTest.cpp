#include "StringCalculator.h"
#include <gtest/gtest.h>
#include <string>

class StringCalculatorTest : public ::testing::Test {
 protected:
  calculator::StringCalculator calc;

  void ExpectNegativesException(const std::string& input, const std::string& expectedMsg) {
    try {
      calc.add(input);
      FAIL() << "Expected exception";
    } catch (const std::invalid_argument& e) {
      EXPECT_TRUE(std::string(e.what()).find(expectedMsg) != std::string::npos);
    }
  }
};

TEST_F(StringCalculatorTest, ReturnZeroForEmptyString) {
  EXPECT_EQ(calc.add(""), 0);
}


TEST_F(StringCalculatorTest, ReturnSingleNumber) {
  EXPECT_EQ(calc.add("1"), 1);
}

TEST_F(StringCalculatorTest, SumTwoCommaSeparatedNumbers) {
  EXPECT_EQ(calc.add("1,2"), 3);
}
/*
TEST_F(StringCalculatorTest, SumUnknownAmountOfNumbers) {
  EXPECT_EQ(calc.add("1,2,3,4,5"), 15);
}

TEST_F(StringCalculatorTest, HandleNewLineAsDelimiter) {
  EXPECT_EQ(calc.add("1\n2,3"), 6);
}

TEST_F(StringCalculatorTest, CustomSingleCharDelimiter) {
  EXPECT_EQ(calc.add("//;\n1;2"), 3);
}

TEST_F(StringCalculatorTest, CustomMultiCharDelimiter) {
  EXPECT_EQ(calc.add("//[***]\n1***2***3"), 6);
}

TEST_F(StringCalculatorTest, IgnoreNumbersGreaterThan1000) {
  EXPECT_EQ(calc.add("2,1001"), 2);
}

TEST_F(StringCalculatorTest, NegativeNumberThrowsException) {
  ExpectNegativesException("1,-2", "negatives not allowed: -2");
}

TEST_F(StringCalculatorTest, MultipleNegativesInException) {
  ExpectNegativesException("1,-2,-3", "negatives not allowed: -2,-3");
}
*/
