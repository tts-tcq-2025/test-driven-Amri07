#include <string>

namespace calculator {
class StringCalculator {
 public:
  StringCalculator() = default;
  ~StringCalculator() = default;
  StringCalculator(const StringCalculator&) = delete;
  StringCalculator& operator=(const StringCalculator&) = delete;
  int add(const std::string& numbers);
};
