#include "StringCalculator.h"
#include "DelimiterParser.h"
#include <sstream>
#include <stdexcept>
#include <algorithm>
#include <numeric>
#include <string>
#include <vector>

namespace {

int parseInt(const std::string& token) {
  int num = 0;
  std::stringstream ss(token);
  ss >> num;
  if (ss.fail()) {
    throw std::invalid_argument("Invalid number: " + token);
  }
  return num;
}

std::vector<int> findNegatives(const std::vector<int>& numbers) {
  std::vector<int> negatives;
  std::copy_if(numbers.begin(), numbers.end(),
               std::back_inserter(negatives),
               [](int n) { return n < 0; });
  return negatives;
}

}  // namespace

int StringCalculator::add(const std::string& numbers) {
  if (numbers.empty()) {
    return 0;
  }
  std::string numStr = numbers;
  std::string delimiter = DelimiterParser::extractDelimiter(numbers, numStr);
  std::vector<int> parsedNumbers = parseNumbers(numStr, delimiter);
  validateNumbers(parsedNumbers);
  return sumNumbers(parsedNumbers);
}

std::vector<int> StringCalculator::parseNumbers(const std::string& numbers,
    const std::string& delimiter) {
  std::string str = numbers;
  std::replace(str.begin(), str.end(), '\n', ',');
  std::vector<std::string> tokens = DelimiterParser::split(str, delimiter);
  std::vector<int> result;
  std::transform(tokens.begin(), tokens.end(),
                std::back_inserter(result),
                parseInt);
  return result;
}

void StringCalculator::validateNumbers(const std::vector<int>& numbers) {
  std::vector<int> negatives = findNegatives(numbers);
  if (!negatives.empty()) {
    throw std::invalid_argument("negatives not allowed: " + join(negatives, ","));
  }
}

int StringCalculator::sumNumbers(const std::vector<int>& numbers) {
  return std::accumulate(numbers.begin(), numbers.end(), 0,
    [](int sum, int n) { return n <= 1000 ? sum + n : sum; });
}

std::string StringCalculator::join(const std::vector<int>& numbers,
    const std::string& delimiter) {
  std::ostringstream oss;
  for (size_t i = 0; i < numbers.size(); ++i) {
    if (i > 0) {
      oss << delimiter;
    }
    oss << numbers[i];
  }
  return oss.str();
}
