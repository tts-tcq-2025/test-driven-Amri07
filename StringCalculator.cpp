#include "StringCalculator.h"
#include <sstream>
#include <stdexcept>
#include <algorithm>
#include <string>
#include <vector>

namespace {

std::string extractDelimiter(const std::string& numbers, std::string& numStr) {
  std::string delimiter = ",";
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
  return delimiter;
}

std::vector<std::string> splitOnce(const std::string& str, const std::string& delimiter, size_t start) {
  std::vector<std::string> tokens;
  size_t pos = str.find(delimiter, start);
  if (pos == std::string::npos) {
    tokens.push_back(str.substr(start));
  } else {
    tokens.push_back(str.substr(start, pos - start));
    tokens.push_back(str.substr(pos + delimiter.length()));
  }
  return tokens;
}

void splitRecursive(const std::string& str, const std::string& delimiter, size_t start, std::vector<std::string>& tokens) {
  size_t pos = str.find(delimiter, start);
  if (pos == std::string::npos) {
    std::string token = str.substr(start);
    if (!token.empty()) tokens.push_back(token);
    return;
  }
  std::string token = str.substr(start, pos - start);
  if (!token.empty()) tokens.push_back(token);
  splitRecursive(str, delimiter, pos + delimiter.length(), tokens);
}

std::vector<std::string> split(const std::string& str, const std::string& delimiter) {
  std::vector<std::string> tokens;
  splitRecursive(str, delimiter, 0, tokens);
  return tokens;
}

int parseInt(const std::string& token) {
  int num = 0;
  std::stringstream ss(token);
  ss >> num;
  if (ss.fail()) throw std::invalid_argument("Invalid number: " + token);
  return num;
}

std::vector<int> findNegatives(const std::vector<int>& numbers) {
  std::vector<int> negatives;
  for (int n : numbers) {
    if (n < 0) negatives.push_back(n);
  }
  return negatives;
}

} // namespace

int StringCalculator::add(const std::string& numbers) {
  if (numbers.empty()) return 0;
  std::string numStr = numbers;
  std::string delimiter = extractDelimiter(numbers, numStr);
  std::vector<int> parsedNumbers = parseNumbers(numStr, delimiter);
  validateNumbers(parsedNumbers);
  return sumNumbers(parsedNumbers);
}

std::vector<int> StringCalculator::parseNumbers(const std::string& numbers,
                                                std::string& delimiter) {
  std::string str = numbers;
  std::replace(str.begin(), str.end(), '\n', ',');
  std::vector<std::string> tokens = split(str, delimiter);
  std::vector<int> result;
  for (const auto& token : tokens) {
    result.push_back(parseInt(token));
  }
  return result;
}

void StringCalculator::validateNumbers(const std::vector<int>& numbers) {
  std::vector<int> negatives = findNegatives(numbers);
  if (!negatives.empty()) {
    throw std::invalid_argument("negatives not allowed: " +
                                join(negatives, ","));
  }
}

int StringCalculator::sumNumbers(const std::vector<int>& numbers) {
  int sum = 0;
  for (int n : numbers) {
    if (n <= 1000) sum += n;
  }
  return sum;
}

std::string StringCalculator::join(const std::vector<int>& numbers,
                                   const std::string& delimiter) {
  std::ostringstream oss;
  for (size_t i = 0; i < numbers.size(); ++i) {
    if (i > 0) oss << delimiter;
    oss << numbers[i];
  }
  return oss.str();
}
