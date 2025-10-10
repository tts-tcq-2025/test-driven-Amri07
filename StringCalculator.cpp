#include <iostream>
#include <algorithm>
namespace calculator{
std::vector<int> StringCalculator::extractNumbers(const std::string& input) {
    std::vector<int> result;
    if (input.empty()) return result;

    std::stringstream ss(input);
    std::string token;

    while (std::getline(ss, token, ',')) {
        if (!token.empty()) {
            result.push_back(std::stoi(token));
        }
    }
    return result;
}

int StringCalculator::sum(const std::vector<int>& numbers) {
    int total = 0;
    for (int n : numbers) {
        total += n;
    }
    return total;
}

int StringCalculator::add(const std::string& numbers) {
    if (numbers.empty()) {
        return 0;
    }

    auto extracted = extractNumbers(numbers);
    if (extracted.size() == 1) {
        return extracted.front();
    }

    return sum(extracted);
}
}