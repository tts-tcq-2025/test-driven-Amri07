#include <string>
#include <regex>
#include <sstream>
#include <vector>
namespace calculator{
class StringCalculator {
public:
    int add(const std::string& numbers);

private:
    std::vector<int> extractNumbers(const std::string& input);
    int sum(const std::vector<int>& numbers);
};
}
