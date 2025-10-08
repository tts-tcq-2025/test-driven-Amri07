#ifndef STRING_SPLITTER_H_
#define STRING_SPLITTER_H_

#include <string>
#include <vector>

class StringSplitter {
 public:
  static std::string extractDelimiter(const std::string& numbers, std::string& numStr);
  static std::vector<std::string> split(const std::string& str, const std::string& delimiter);
};

#endif  // STRING_SPLITTER_H_
