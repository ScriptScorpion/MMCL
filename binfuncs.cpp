#include <string>
#include <cmath>
#include <cctype>
#include <iostream>

std::string remove_overflow(std::string data) { // needed space at the end to work properly
    std::string temp {};
    for (size_t i = 0; i < data.length(); ++i) {
        if (isdigit(data[i])) {
            temp += data[i];
        }
        else {
            if (temp.empty()) {
                continue;
            }
            long long digit_temp = std::stoll(temp, nullptr, 10);
            if ((digit_temp / 256) != 0) {
                data.replace(i-temp.length(), temp.length(), std::string(std::to_string(digit_temp % 256) + " " + std::to_string(digit_temp / 256)));
            }
            temp.assign(temp.length(), '\0');
            temp.clear();
        }
    }
    return data;
}
std::string get_characters(const char c, const size_t amount) {
    std::string output {};
    for (size_t i = 0; i < amount; ++i) {
        output += c;
        output += ' ';
    }
    return output;
}

std::string bin_addition(const std::string &reg, const std::string &value) {
    if (reg == "rax") {
        return "72 5 " + remove_overflow(value + " ") + get_characters('0', 4 - round(static_cast<double>(value.length()) / 2 ));
    }
    return "";
}
