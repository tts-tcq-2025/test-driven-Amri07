#include "StringCalculator.h"
#include <sstream>
#include <stdexcept>
#include <algorithm>
#include <cctype>

int StringCalculator::add(const std::string& numbers) {
  if (numbers.empty()) return 0;
  std::string delimiter = ",";
  std::string numStr = numbers;
  if (numbers.substr(0, 2) == "//") {
    size_t delimEnd = numbers.find('\n');
    if (numbers[2] == '[') {
      size_t close = numbers.find(']', 3);
      delimiter = numbers.substr(3, close - 3);
    } else {
      delimiter = std::string(1, numbers[2]);
    }
    numStr = numbers.substr(delimEnd + 1);
  }
  std::vector<int> parsedNumbers = parseNumbers(numStr, delimiter);
  validateNumbers(parsedNumbers);
  return sumNumbers(parsedNumbers);
}

std::vector<int> StringCalculator::parseNumbers(const std::string& numbers, std::string& delimiter) {
  std::vector<int> result;
  std::string del = delimiter;
  std::string str = numbers;
  std::replace(str.begin(), str.end(), '\n', ',');
  size_t pos = 0, start = 0;
  while (start < str.size()) {
    pos = str.find(del, start);
    std::string token = (pos == std::string::npos) ? str.substr(start) : str.substr(start, pos - start);
    if (!token.empty()) {
      int num = 0;
      std::stringstream ss(token);
      ss >> num;
      if (ss.fail()) throw std::invalid_argument("Invalid number: " + token);
      result.push_back(num);
    }
    if (pos == std::string::npos) break;
    start = pos + del.length();
  }
  return result;
}

void StringCalculator::validateNumbers(const std::vector<int>& numbers) {
  std::vector<int> negatives;
  for (int n : numbers) {
    if (n < 0) negatives.push_back(n);
  }
  if (!negatives.empty()) {
    throw std::invalid_argument("negatives not allowed: " + join(negatives, ","));
  }
}

int StringCalculator::sumNumbers(const std::vector<int>& numbers) {
  int sum = 0;
  for (int n : numbers) {
    if (n <= 1000) sum += n;
  }
  return sum;
}

std::string StringCalculator::join(const std::vector<int>& numbers, const std::string& delimiter) {
  std::ostringstream oss;
  for (size_t i = 0; i < numbers.size(); ++i) {
    if (i > 0) oss << delimiter;
    oss << numbers[i];
  }
  return oss.str();
}
