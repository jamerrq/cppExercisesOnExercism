
#include "bob.h"

namespace bob {

    bool is_yelling(std::string input) {
        bool alpha = false;
        for(int i = 0; i < static_cast<int>(input.length()); i++) {
            alpha = alpha || isalpha(input[i]);
            // if is not alpha, ignore
            if(!isalpha(input[i])) {
                continue;
            }
            if(!isupper(input[i])) {
                return false;
            }
        }
        return alpha;
    }

    std::string upper_string(std::string input) {
        std::string output = "";
        for(int i = 0; i < static_cast<int>(input.length()); i++) {
            if(!isalpha(input[i])) {
                continue;
            }
            output += toupper(input[i]);
        }
        return output;
    }

    std::string hey(std::string input) {

        // If question -> "Sure."
        // If yelling question -> "Calm down, I know what I'm doing!"
        // If yelling -> "Whoa, chill out!"
        // If silence -> "Fine. Be that way!"
        // Else -> "Whatever."

        // Replace tabs, newlines and carriage returns with spaces
        std::regex replace("\t|\n|\r");
        input = std::regex_replace(input, replace, " ");

        // Remove all spaces
        std::regex space(" ");
        input = std::regex_replace(input, space, "");

        // If question
        if(input.back() == '?') {
            // std::cout << "Question: " << input << std::endl;
            // std::cout << "Yelling: " << is_yelling(input) << std::endl;
            // If yelling question
            if(is_yelling(input)) {
                return "Calm down, I know what I'm doing!";
            }
            return "Sure.";
        }

        // std::cout << "Yelling: " << is_yelling(input) << std::endl;

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

// int main(){
//     std::cout << bob::hey("WHAT THE HELL WERE YOU THINKING?") << std::endl;
// }
