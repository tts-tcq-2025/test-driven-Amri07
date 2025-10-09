#ifndef STRINGCALCULATOR_H_
#define STRINGCALCULATOR_H_

#include <string>
#include <vector>

#ifdef __cplusplus
namespace calculator {
#endif

class StringCalculator {
 public:
  explicit StringCalculator() = default;
  ~StringCalculator() = default;

  int add(const std::string& numbers);

 private:
  std::vector<int> parseNumbers(const std::string& numbers, const std::string& delimiter);
  void validateNumbers(const std::vector<int>& numbers);
  int sumNumbers(const std::vector<int>& numbers);
  std::string join(const std::vector<int>& numbers, const std::string& delimiter);
};

#ifdef __cplusplus
}  // namespace calculator
#endif

#endif  // STRINGCALCULATOR_H_
