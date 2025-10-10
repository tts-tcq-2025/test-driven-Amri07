#include "DelimiterParser.h"
#include <string>
#include <vector>

namespace calculator {

std::string DelimiterParser::extractDelimiter(const std::string& numbers, std::string& numStr) {
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

std::string DelimiterParser::getToken(const std::string& str, size_t start, size_t pos) {
    return (pos == std::string::npos) ? str.substr(start) : str.substr(start, pos - start);
}

void DelimiterParser::addTokenIfNotEmpty(std::vector<std::string>& tokens,
    const std::string& token) {
    if (!token.empty()) {
        tokens.push_back(token);
    }
}

std::vector<std::string> DelimiterParser::split(const std::string& str,
    const std::string& delimiter) {
    std::vector<std::string> tokens;
    size_t start = 0;
    while (start < str.size()) {
        size_t pos = str.find(delimiter, start);
        std::string token = getToken(str, start, pos);
        addTokenIfNotEmpty(tokens, token);
        if (pos == std::string::npos) break;
        start = pos + delimiter.length();
    }
    return tokens;
}

}  // namespace calculator
