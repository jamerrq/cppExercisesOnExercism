#include "trinary.h"

namespace trinary {
    int to_decimal(std::string trinary) {
        int decimal = 0;
        int power = 1;
        int length = trinary.length();
        for (int i = length - 1; i >= 0; i--) {
            if (trinary[i] < '0' || trinary[i] > '2') {
                return 0;
            }
            decimal += (trinary[i] - '0') * power;
            power *= 3;
        }
        return decimal;
    }
}  // namespace trinary
