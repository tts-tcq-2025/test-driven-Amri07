#include "StringCalculator.h"
#include <sstream>
#include <stdexcept>
#include <vector>
#include <algorithm>

int StringCalculator::add(const std::string& input) {
    if (input.empty()) {
        return 0;
    }

    std::string delimiter = ",";
    std::string numbers = input;

    if (input.find("//") == 0) {
        size_t pos = input.find('\n');
        delimiter = input.substr(2, pos - 2);
        numbers = input.substr(pos + 1);
    }

    std::vector<int> parsedNumbers = parseNumbers(numbers, delimiter);
    validateNumbers(parsedNumbers);

    return sumNumbers(parsedNumbers);
}

std::vector<int> StringCalculator::parseNumbers(const std::string& numbers, const std::string& delimiter) {
    std::vector<int> result;
    std::string token;
    std::istringstream tokenStream(numbers);
    
    while (std::getline(tokenStream, token, ',')) {
        std::istringstream subStream(token);
        while (std::getline(subStream, token, '\n')) {
            if (!token.empty()) {
                result.push_back(std::stoi(token));
            }
        }
    }

    return result;
}

void StringCalculator::validateNumbers(const std::vector<int>& numbers) {
    std::vector<int> negatives;
    for (int number : numbers) {
        if (number < 0) {
            negatives.push_back(number);
        }
    }

    if (!negatives.empty()) {
        throw std::invalid_argument("negatives not allowed: " + join(negatives, ","));
    }
}

int StringCalculator::sumNumbers(const std::vector<int>& numbers) {
    int sum = 0;
    for (int number : numbers) {
        if (number <= 1000) {
            sum += number;
        }
    }
    return sum;
}

std::string StringCalculator::join(const std::vector<int>& numbers, const std::string& delimiter) {
    std::ostringstream oss;
    for (size_t i = 0; i < numbers.size(); ++i) {
        oss << numbers[i];
        if (i != numbers.size() - 1) {
            oss << delimiter;
        }
    }
    return oss.str();
}