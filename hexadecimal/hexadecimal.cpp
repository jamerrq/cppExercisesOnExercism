#include "hexadecimal.h"

/*
INSTRUCTIONS

Convert a hexadecimal number, represented as a string (e.g. "10af8c"), to its decimal equivalent using first principles (i.e. no, you may not use built-in or external libraries to accomplish the conversion).

On the web we use hexadecimal to represent colors, e.g. green: 008000, teal: 008080, navy: 000080).

The program should handle invalid hexadecimal strings.

EXAMPLES:

"c" -> 0xc
"10" -> 0x10
"af" -> 0xaf
"100" -> 0x100
*/


namespace hexadecimal {
    int convert(std::string input){
        int result = 0;
        int power = 0;
        for (int i = input.length() - 1; i >= 0; i--){
            if (input[i] >= '0' && input[i] <= '9'){
                result += (input[i] - '0') * pow(16, power);
            }
            else if (input[i] >= 'a' && input[i] <= 'f'){
                result += (input[i] - 'a' + 10) * pow(16, power);
            }
            else if (input[i] >= 'A' && input[i] <= 'F'){
                result += (input[i] - 'A' + 10) * pow(16, power);
            }
            else{
                return 0;
            }
            power++;
        }
        return result;
    }
}  // namespace hexadecimal
