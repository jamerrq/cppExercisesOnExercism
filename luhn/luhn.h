#if !defined(LUHN_H)
#define LUHN_H
#include <string>
#include <iostream>
#include <regex>

namespace luhn {
    bool valid(std::string input);
}  // namespace luhn

#endif // LUHN_H
