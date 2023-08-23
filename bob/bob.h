#if !defined(BOB_H)
#define BOB_H
#include <string>
#include <cctype>
#include <iostream>
#include <regex>
#include <algorithm>

namespace bob {

    bool is_yelling(std::string input);

    std::string upper_string(std::string input);

    std::string hey(std::string input);

}  // namespace bob

#endif // BOB_H
