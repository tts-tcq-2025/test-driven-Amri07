#ifndef DELIMITERPARSER_H_
#define DELIMITERPARSER_H_
/* C-compatible declaration */
#ifdef __cplusplus
extern "C" {
#endif
typedef struct DelimiterParser DelimiterParser;
#ifdef __cplusplus
}
#endif
/* End C-compatible declaration */
#ifdef __cplusplus
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
#endif  // __cplusplus
#endif  // DELIMITERPARSER_H_
