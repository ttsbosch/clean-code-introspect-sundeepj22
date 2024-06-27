#include "StringCalculator.h"
#include <vector>
#include <cctype>
#include <numeric> // for std::accumulate

int StringCalculator::add(std::string numbers)
{
    std::vector<std::int32_t> digit_list;
    ExtractDigits(numbers, digit_list);
    std::int32_t sumOfDigitList{std::accumulate(digit_list.begin(), digit_list.end(), 0)};
    return sumOfDigitList;
}

void StringCalculator::ExtractDigits(const std::string& input, std::vector<std::int32_t>& digit_list)
{
      digit_list.clear();
      for (char c : input)
      {
          if (std::isdigit(c))
          {
              digit_list.push_back(c - '0');  // Convert char to integer and add to digit_list
          }
      }
}
