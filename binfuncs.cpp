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
std::string get_characters(const char c, const size_t amount) noexcept { // gives space at the end
    std::string output {};
    for (size_t i = 0; i < amount; ++i) {
        output += c;
        output += ' ';
    }
    return output;
}

std::string bin_move(const std::string &reg, const std::string &value) {
    std::stoll(value, nullptr, 10); // hidden check for overflow

    if (reg == "rax") {
        return "72 184 " + remove_overflow(value + " ") + get_characters('0', 8 - round(static_cast<double>(value.length()) / 2 ));
    }
    else if (reg == "rcx") {
        return "72 185 " + remove_overflow(value + " ") + get_characters('0', 8 - round(static_cast<double>(value.length()) / 2 ));
    }
    else if (reg == "rdx") {
        return "72 186 " + remove_overflow(value + " ") + get_characters('0', 8 - round(static_cast<double>(value.length()) / 2 ));
    }
    else if (reg == "rsi") {
        return "72 190 " + remove_overflow(value + " ") + get_characters('0', 8 - round(static_cast<double>(value.length()) / 2 ));
    }
    else if (reg == "rdi") {
        return "72 191 " + remove_overflow(value + " ") + get_characters('0', 8 - round(static_cast<double>(value.length()) / 2 ));
    }
    else if (reg == "r8") {
        return "73 184 " + remove_overflow(value + " ") + get_characters('0', 8 - round(static_cast<double>(value.length()) / 2 ));
    }
    else if (reg == "r9") {
        return "73 185 " + remove_overflow(value + " ") + get_characters('0', 8 - round(static_cast<double>(value.length()) / 2 ));
    }
    else if (reg == "r10") {
        return "73 186 " + remove_overflow(value + " ") + get_characters('0', 8 - round(static_cast<double>(value.length()) / 2 ));
    }
    else if (reg == "r11") {
        return "73 187 " + remove_overflow(value + " ") + get_characters('0', 8 - round(static_cast<double>(value.length()) / 2 ));
    }
    throw std::runtime_error("Parsing error, register given is not supported");
    return "";
}
std::string bin_addition(const std::string &reg, const std::string &value) {
    std::stoll(value, nullptr, 10); // hidden check for overflow

    if (reg == "rax") {
        return "72 5 " + remove_overflow(value + " ") + get_characters('0', 4 - round(static_cast<double>(value.length()) / 2 ));
    }
    else if (reg == "rcx") {
        return "72 129 193 " + remove_overflow(value + " ") + get_characters('0', 4 - round(static_cast<double>(value.length()) / 2 ));
    }
    else if (reg == "rdx") {
        return "72 129 194 " + remove_overflow(value + " ") + get_characters('0', 4 - round(static_cast<double>(value.length()) / 2 ));
    }
    else if (reg == "rsi") {
        return "72 129 198 " + remove_overflow(value + " ") + get_characters('0', 4 - round(static_cast<double>(value.length()) / 2 ));
    }
    else if (reg == "rdi") {
        return "72 129 199 " + remove_overflow(value + " ") + get_characters('0', 4 - round(static_cast<double>(value.length()) / 2 ));
    }
    else if (reg == "r8") {
        return "73 129 192 " + remove_overflow(value + " ") + get_characters('0', 4 - round(static_cast<double>(value.length()) / 2 ));
    }
    else if (reg == "r9") {
        return "73 129 193 " + remove_overflow(value + " ") + get_characters('0', 4 - round(static_cast<double>(value.length()) / 2 ));
    }
    else if (reg == "r10") {
        return "73 129 194 " + remove_overflow(value + " ") + get_characters('0', 4 - round(static_cast<double>(value.length()) / 2 ));
    }
    else if (reg == "r11") {
        return "73 129 195 " + remove_overflow(value + " ") + get_characters('0', 4 - round(static_cast<double>(value.length()) / 2 ));
    }
    throw std::runtime_error("Parsing error, register given is not supported");
    return "";
}
std::string bin_subtraction(const std::string &reg, const std::string &value) {
     std::stoll(value, nullptr, 10); // hidden check for overflow

    if (reg == "rax") {
        return "72 45 " + remove_overflow(value + " ") + get_characters('0', 4 - round(static_cast<double>(value.length()) / 2 ));
    }
    else if (reg == "rcx") {
        return "72 129 233 " + remove_overflow(value + " ") + get_characters('0', 4 - round(static_cast<double>(value.length()) / 2 ));
    }
    else if (reg == "rdx") {
        return "72 129 234 " + remove_overflow(value + " ") + get_characters('0', 4 - round(static_cast<double>(value.length()) / 2 ));
    }
    else if (reg == "rsi") {
        return "72 129 238 " + remove_overflow(value + " ") + get_characters('0', 4 - round(static_cast<double>(value.length()) / 2 ));
    }
    else if (reg == "rdi") {
        return "72 129 239 " + remove_overflow(value + " ") + get_characters('0', 4 - round(static_cast<double>(value.length()) / 2 ));
    }
    else if (reg == "r8") {
        return "73 129 232 " + remove_overflow(value + " ") + get_characters('0', 4 - round(static_cast<double>(value.length()) / 2 ));
    }
    else if (reg == "r9") {
        return "73 129 233 " + remove_overflow(value + " ") + get_characters('0', 4 - round(static_cast<double>(value.length()) / 2 ));
    }
    else if (reg == "r10") {
        return "73 129 234 " + remove_overflow(value + " ") + get_characters('0', 4 - round(static_cast<double>(value.length()) / 2 ));
    }
    else if (reg == "r11") {
        return "73 129 235 " + remove_overflow(value + " ") + get_characters('0', 4 - round(static_cast<double>(value.length()) / 2 ));
    }
    throw std::runtime_error("Parsing error, register given is not supported");
    return "";
}
std::string bin_rshift(const std::string &reg, const std::string &value) {
    long long temp_val = std::stoll(value, nullptr, 10);
    
    if (temp_val < 0 || temp_val > 255) {
        throw std::logic_error("Logic error, shift supports only values from 0 to 255");
    }

    if (reg == "rax") {
        return "72 193 232 " + value + " ";
    }
    else if (reg == "rcx") {
        return "72 193 233 " + value + " ";
    }
    else if (reg == "rdx") {
        return "72 193 234 " + value + " ";
    }
    else if (reg == "rsi") {
        return "72 193 238 " + value + " ";
    }
    else if (reg == "rdi") {
        return "72 193 239 " + value + " ";
    }
    else if (reg == "r8") {
        return "73 193 232 " + value + " ";
    }
    else if (reg == "r9") {
        return "73 193 233 " + value + " ";
    }
    else if (reg == "r10") {
        return "73 193 234 " + value + " ";
    }
    else if (reg == "r11") {
        return "73 193 235 " + value + " ";
    }
    throw std::runtime_error("Parsing error, register given is not supported");
    return "";
}
std::string bin_lshift(const std::string &reg, const std::string &value) {
    long long temp_val = std::stoll(value, nullptr, 10);
    
    if (temp_val < 0 || temp_val > 255) {
        throw std::logic_error("Logic error, shift supports only values from 0 to 255");
    }

    if (reg == "rax") {
        return "72 193 224 " + value + " ";
    }
    else if (reg == "rcx") {
        return "72 193 225 " + value + " ";
    }
    else if (reg == "rdx") {
        return "72 193 226 " + value + " ";
    }
    else if (reg == "rsi") {
        return "72 193 230 " + value + " ";
    }
    else if (reg == "rdi") {
        return "72 193 231 " + value + " ";
    }
    else if (reg == "r8") {
        return "73 193 224 " + value + " ";
    }
    else if (reg == "r9") {
        return "73 193 225 " + value + " ";
    }
    else if (reg == "r10") {
        return "73 193 226 " + value + " ";
    }
    else if (reg == "r11") {
        return "73 193 227 " + value + " ";
    }
    throw std::runtime_error("Parsing error, register given is not supported");
    return "";
}
std::string bin_and(const std::string &reg, const std::string &value) {
    std::stoll(value, nullptr, 10); // hidden check for overflow

    if (reg == "rax") {
        return "72 37 " + remove_overflow(value + " ") + get_characters('0', 4 - round(static_cast<double>(value.length()) / 2 ));
    }
    else if (reg == "rcx") {
        return "72 129 225 " + remove_overflow(value + " ") + get_characters('0', 4 - round(static_cast<double>(value.length()) / 2 ));
    }
    else if (reg == "rdx") {
        return "72 129 226 " + remove_overflow(value + " ") + get_characters('0', 4 - round(static_cast<double>(value.length()) / 2 ));
    }
    else if (reg == "rsi") {
        return "72 129 230 " + remove_overflow(value + " ") + get_characters('0', 4 - round(static_cast<double>(value.length()) / 2 ));
    }
    else if (reg == "rdi") {
        return "72 129 231 " + remove_overflow(value + " ") + get_characters('0', 4 - round(static_cast<double>(value.length()) / 2 ));
    }
    else if (reg == "r8") {
        return "73 129 224 " + remove_overflow(value + " ") + get_characters('0', 4 - round(static_cast<double>(value.length()) / 2 ));
    }
    else if (reg == "r9") {
        return "73 129 225 " + remove_overflow(value + " ") + get_characters('0', 4 - round(static_cast<double>(value.length()) / 2 ));
    }
    else if (reg == "r10") {
        return "73 129 226 " + remove_overflow(value + " ") + get_characters('0', 4 - round(static_cast<double>(value.length()) / 2 ));
    }
    else if (reg == "r11") {
        return "73 129 227 " + remove_overflow(value + " ") + get_characters('0', 4 - round(static_cast<double>(value.length()) / 2 ));
    }
    throw std::runtime_error("Parsing error, register given is not supported");
    return "";
}
std::string bin_or(const std::string &reg, const std::string &value) {
    std::stoll(value, nullptr, 10); // hidden check for overflow

    if (reg == "rax") {
        return "72 13 " + remove_overflow(value + " ") + get_characters('0', 4 - round(static_cast<double>(value.length()) / 2 ));
    }
    else if (reg == "rcx") {
        return "72 129 201 " + remove_overflow(value + " ") + get_characters('0', 4 - round(static_cast<double>(value.length()) / 2 ));
    }
    else if (reg == "rdx") {
        return "72 129 202 " + remove_overflow(value + " ") + get_characters('0', 4 - round(static_cast<double>(value.length()) / 2 ));
    }
    else if (reg == "rsi") {
        return "72 129 206 " + remove_overflow(value + " ") + get_characters('0', 4 - round(static_cast<double>(value.length()) / 2 ));
    }
    else if (reg == "rdi") {
        return "72 129 207 " + remove_overflow(value + " ") + get_characters('0', 4 - round(static_cast<double>(value.length()) / 2 ));
    }
    else if (reg == "r8") {
        return "73 129 200 " + remove_overflow(value + " ") + get_characters('0', 4 - round(static_cast<double>(value.length()) / 2 ));
    }
    else if (reg == "r9") {
        return "73 129 201 " + remove_overflow(value + " ") + get_characters('0', 4 - round(static_cast<double>(value.length()) / 2 ));
    }
    else if (reg == "r10") {
        return "73 129 202 " + remove_overflow(value + " ") + get_characters('0', 4 - round(static_cast<double>(value.length()) / 2 ));
    }
    else if (reg == "r11") {
        return "73 129 203 " + remove_overflow(value + " ") + get_characters('0', 4 - round(static_cast<double>(value.length()) / 2 ));
    }
    throw std::runtime_error("Parsing error, register given is not supported");
    return "";
}
std::string bin_xor(const std::string &reg, const std::string &value) {
    std::stoll(value, nullptr, 10); // hidden check for overflow

    if (reg == "rax") {
        return "72 53 " + remove_overflow(value + " ") + get_characters('0', 4 - round(static_cast<double>(value.length()) / 2 ));
    }
    else if (reg == "rcx") {
        return "72 129 241 " + remove_overflow(value + " ") + get_characters('0', 4 - round(static_cast<double>(value.length()) / 2 ));
    }
    else if (reg == "rdx") {
        return "72 129 242 " + remove_overflow(value + " ") + get_characters('0', 4 - round(static_cast<double>(value.length()) / 2 ));
    }
    else if (reg == "rsi") {
        return "72 129 246 " + remove_overflow(value + " ") + get_characters('0', 4 - round(static_cast<double>(value.length()) / 2 ));
    }
    else if (reg == "rdi") {
        return "72 129 247 " + remove_overflow(value + " ") + get_characters('0', 4 - round(static_cast<double>(value.length()) / 2 ));
    }
    else if (reg == "r8") {
        return "73 129 240 " + remove_overflow(value + " ") + get_characters('0', 4 - round(static_cast<double>(value.length()) / 2 ));
    }
    else if (reg == "r9") {
        return "73 129 241 " + remove_overflow(value + " ") + get_characters('0', 4 - round(static_cast<double>(value.length()) / 2 ));
    }
    else if (reg == "r10") {
        return "73 129 242 " + remove_overflow(value + " ") + get_characters('0', 4 - round(static_cast<double>(value.length()) / 2 ));
    }
    else if (reg == "r11") {
        return "73 129 243 " + remove_overflow(value + " ") + get_characters('0', 4 - round(static_cast<double>(value.length()) / 2 ));
    }
    throw std::runtime_error("Parsing error, register given is not supported");
    return "";
}
