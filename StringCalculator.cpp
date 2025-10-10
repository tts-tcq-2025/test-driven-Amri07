#include "StringCalculator.h"
#include <regex>


namespace calculator {

int StringCalculator::add(const std::string& numbers) {

  if (numbers.empty()) {
    return 0;
  }
    std::regex number_pattern("\\d+");
    std::sregex_iterator begin(input.begin(), input.end(), number_pattern);
    std::sregex_iterator end;

    int count = std::distance(begin, end);

    if (count == 1) {
        int number = std::stoi(begin->str());
        return number;
    }
  throw "Not Implemented Exception";
}
}