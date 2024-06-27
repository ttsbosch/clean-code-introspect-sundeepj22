#include <string>
#include <vector>
#include <cctype>
#include <numeric> // for std::accumulate

class StringCalculator
{
public:
int add(std::string numbers);
private:
void ExtractDigits(const std::string& input, std::vector<std::int32_t>& digit_list);
};
