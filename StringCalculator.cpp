#include "StringCalculator.h"
#include <iostream>
#include <stdexcept>
#include <algorithm>

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
    std::cout << " digit_list size:" << digit_list.size() << std::endl;
    auto findItr = std::find_if(digit_list.begin(), digit_list.end(), [](std::int32_t digit) {
        std::cout << " digit:" << digit << std::endl;
        return digit < 0;
    });

    if (findItr != digit_list.end()) {
        throw std::runtime_error("Negative number found in digit_list");
    }
}
