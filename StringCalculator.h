#ifndef STRINGCALCULATOR_H
#define STRINGCALCULATOR_H

#include <string>
#include <vector>
#include <stdexcept>

class StringCalculator {
public:
    int add(const std::string& input);

private:
    std::vector<int> parseInput(const std::string& input);
    void validateNumbers(const std::vector<int>& numbers);
    std::vector<std::string> split(const std::string& input, const std::string& delimiter);
    std::string extractDelimiter(const std::string& input);
};

#endif // STRINGCALCULATOR_H