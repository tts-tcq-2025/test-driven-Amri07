#ifndef STRINGCALCULATOR_H_
#define STRINGCALCULATOR_H_
#if defined(__cplusplus)
#include <string>
#include <vector>
namespace calculator {
class StringCalculator {
 public:
  StringCalculator() = default;
  ~StringCalculator() = default;
  StringCalculator(const StringCalculator&) = delete;
  StringCalculator& operator=(const StringCalculator&) = delete;
  int add(const std::string& numbers);
 private:
  std::vector<int> parseNumbers(const std::string& numbers, const std::string& delimiter);
  void validateNumbers(const std::vector<int>& numbers);
  int sumNumbers(const std::vector<int>& numbers);
  std::string join(const std::vector<int>& numbers, const std::string& delimiter);
};
}  // namespace calculator
#else
typedef struct StringCalculator StringCalculator;
#endif
#endif  // STRINGCALCULATOR_H_
