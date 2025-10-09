#ifndef DELIMITERPARSER_H_
#define DELIMITERPARSER_H_

#include <string>
#include <vector>

#ifdef __cplusplus
namespace calculator {
#endif

class DelimiterParser {
 public:
  static std::string extractDelimiter(const std::string& numbers, std::string& numStr);
  static std::vector<std::string> split(const std::string& str, const std::string& delimiter);

 private:
  static std::string getToken(const std::string& str, size_t start, size_t pos);
  static void addTokenIfNotEmpty(std::vector<std::string>& tokens, const std::string& token);
};

#ifdef __cplusplus
}  // namespace calculator
#endif

#endif  // DELIMITERPARSER_H_
