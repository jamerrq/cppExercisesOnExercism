#include <string>

namespace log_line {
    std::string message(std::string logged_report){
        int double_colon_index = logged_report.find(":");
        return logged_report.substr(double_colon_index + 2);
    }

    std::string log_level(std::string logged_report){
        int right_bracket_index = logged_report.find("]");
        return logged_report.substr(1, right_bracket_index - 1);
    }

    std::string reformat(std::string logged_report){
        return message(logged_report) + " (" + log_level(logged_report) + ")";
    }
} // namespace log_line
