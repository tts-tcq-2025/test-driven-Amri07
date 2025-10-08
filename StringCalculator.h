#ifndef STRINGCALCULATOR_H_
#define STRINGCALCULATOR_H_

#include <string>
#include <vector>

class StringCalculator {
 public:
  int add(const std::string& numbers);

 private:
  std::vector<int> parseNumbers(const std::string& numbers, std::string& delimiter);
  void validateNumbers(const std::vector<int>& numbers);
  int sumNumbers(const std::vector<int>& numbers);
  std::string join(const std::vector<int>& numbers, const std::string& delimiter);
};

#endif  // STRINGCALCULATOR_H_
