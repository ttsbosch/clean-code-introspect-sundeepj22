#include "StringCalculator.h"
#include <stdexcept>

int StringCalculator::add(std::string numbers)
{
    std::vector<std::int32_t> digit_list;
    ExtractDigits(numbers, digit_list);
    CheckNumberIsNegative(digit_list);
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

void StringCalculator::CheckNumberIsNegative(const std::vector<std::int32_t>& digit_list)
{
    const auto findItr{find_if(digit_list.begin(), digit_list.end(), [](std::int32_t digit){
        return digit < 0;
    })};
    if (findItr != std::end(digit_list))
    {
        throw std::runtime_error;
    }
}
