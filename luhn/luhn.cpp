#include "luhn.h"

namespace luhn {
    bool valid(std::string input) {
        int sum = 0;
        // Remove all spaces
        std::regex r("\\s+");
        input = std::regex_replace(input, r, "");
        int nDigits = input.length();
        // Strings of length 1 or less are not valid.
        if (nDigits <= 1) {
            return false;
        }
        // std::cout << "input: " << input << "\n";
        int parity = nDigits % 2;
        for (int i = nDigits; i > 0; i--) {
            // std::cout << "i: " << i << " input[i]: " << input[i - 1] << "\n";
            // If is a space, ignore it
            if (input[i - 1] == ' ') {
                continue;
            }
            // If is not a digit, return false
            if (!isdigit(input[i - 1])) {
                return false;
            }
            int digit = input[i - 1] - '0';
            if (i % 2 != parity) {
                digit = digit * 2;
            }
            if (digit > 9) {
                digit = digit - 9;
            }
            sum = sum + digit;
        }
        // std::cout << "sum: " << sum << "\n";
        return sum % 10 == 0;
    }
}  // namespace luhn
