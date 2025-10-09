#ifndef DELIMITERPARSER_H_
#define DELIMITERPARSER_H_
#if defined(__cplusplus)
#include <string>
#include <vector>
namespace calculator {
class DelimiterParser {
 public:
  static std::string extractDelimiter(const std::string& numbers, std::string& numStr);
  static std::vector<std::string> split(const std::string& str, const std::string& delimiter);
 private:
  DelimiterParser() = delete;
  static std::string getToken(const std::string& str, size_t start, size_t pos);
  static void addTokenIfNotEmpty(std::vector<std::string>& tokens, const std::string& token);
};
}  // namespace calculator
#else
typedef struct DelimiterParser DelimiterParser;
#endif
#endif  // DELIMITERPARSER_H_
