#include "StringCalculator.h"
#include <regex>


namespace calculator {

int StringCalculator::add(const std::string& numbers) {

  if (numbers.empty()) {
    return 0;
  }
    std::regex number_pattern("\\d+");
    std::sregex_iterator begin(numbers.begin(), numbers.end(), number_pattern);
    std::sregex_iterator end;

    int count = std::distance(begin, end);

    if (count == 1) {
        int number = std::stoi(begin->str());
        return number;
    }
    std::stringstream ss(numbers);
    std::string token;
    int sum = 0;

    while (std::getline(ss, token, ',')) {
        if (!token.empty()) {
            sum += std::stoi(token);
        }
    }

  return sum;
}
}