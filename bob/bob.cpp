
#include "bob.h"
#include <string>
#include <cctype>

namespace bob {

    bool is_yelling(std::string input) {
        bool alpha = false;
        // std::cout << static_cast<int>(input.length()) << std::endl;
        for(int i = 0; i < static_cast<int>(input.length()); i++) {
            alpha = alpha || isalpha(input[i]);
            if(!isupper(input[i])) {
                return false;
            }
        }
        std::cout << "Alpha: " << alpha << std::endl;
        return alpha;
    }

    std::string upper_string(std::string input) {
        std::string output = "";
        for(int i = 0; i < static_cast<int>(input.length()); i++) {
            output += toupper(input[i]);
        }
        return output;
    }

    std::string hey(std::string input) {

        // Print input
        std::cout << input << std::endl;
        std::cout << "Yelling: " << is_yelling(input) << std::endl;

        // If question -> "Sure."
        // If yelling question -> "Calm down, I know what I'm doing!"
        // If yelling -> "Whoa, chill out!"
        // If silence -> "Fine. Be that way!"
        // Else -> "Whatever."

        // If question
        if(input.back() == '?') {
            // If yelling question
            if(input == upper_string(input)) {
                return "Calm down, I know what I'm doing!";
            }
            return "Sure.";
        }

        // If yelling
        if(is_yelling(input)) {
            return "Whoa, chill out!";
        }

        // If silence
        if(input.find_first_not_of(' ') == std::string::npos) {
            return "Fine. Be that way!";
        }

        return "Whatever.";
    }
}  // namespace bob
