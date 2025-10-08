#include <iostream>
#include "StringCalculator.h"

int main() {
    StringCalculator calculator;

    // Sample inputs to demonstrate functionality
    std::string input1 = "";
    std::string input2 = "1";
    std::string input3 = "1,2";
    std::string input4 = "1\n2,3";
    std::string input5 = "//;\n1;2";
    std::string input6 = "//[***]\n1***2***3";
    std::string input7 = "2,1001";
    std::string input8 = "1,-2";
    std::string input9 = "1,-2,-3";

    std::cout << "Input: \"" << input1 << "\" => Output: " << calculator.add(input1) << std::endl;
    std::cout << "Input: \"" << input2 << "\" => Output: " << calculator.add(input2) << std::endl;
    std::cout << "Input: \"" << input3 << "\" => Output: " << calculator.add(input3) << std::endl;
    std::cout << "Input: \"" << input4 << "\" => Output: " << calculator.add(input4) << std::endl;
    std::cout << "Input: \"" << input5 << "\" => Output: " << calculator.add(input5) << std::endl;
    std::cout << "Input: \"" << input6 << "\" => Output: " << calculator.add(input6) << std::endl;
    std::cout << "Input: \"" << input7 << "\" => Output: " << calculator.add(input7) << std::endl;

    try {
        std::cout << "Input: \"" << input8 << "\" => Output: " << calculator.add(input8) << std::endl;
    } catch (const std::invalid_argument& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    try {
        std::cout << "Input: \"" << input9 << "\" => Output: " << calculator.add(input9) << std::endl;
    } catch (const std::invalid_argument& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    return 0;
}