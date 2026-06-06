#include <string>
#include <cmath>
#include <cctype>
#include <iostream>

std::string remove_overflow(std::string data, const size_t &&group_size) {
    long long digit_temp = std::stoll(data, nullptr, 10);
    data.assign('\0', data.size());
    data.clear();
    if (digit_temp < 0) {
        unsigned long long neg_digit_temp = 0ull + digit_temp;
        for (size_t j = 0, i = 0; j < group_size; ++j, i += 8) {
            data += std::to_string((neg_digit_temp >> i) & 0xff) + " ";
        }
    }
    else {
        for (size_t j = 0, i = 0; j < group_size; ++j, i += 8) {
            data += std::to_string((digit_temp >> i) & 0xff) + " ";
        }
    }
    return data;
}

/*
std::string get_characters(const char c, const size_t amount) noexcept { // gives space at the end
    std::string output {};
    for (size_t i = 0; i < amount; ++i) {
        output += c;
        output += ' ';
    }
    return output;
}
*/

// r12-r15 REGISTERS ARE RESERVED FOR FUNCTION ARGUMENTS

std::string bin_move(const std::string &reg, const std::string &value) {
    std::stoll(value, nullptr, 10); // hidden check for overflow

    if (reg == "rax") {
        return "72 184 " + remove_overflow(value, 8);
    }
    else if (reg == "rcx") {
        return "72 185 " + remove_overflow(value, 8);
    }
    else if (reg == "rdx") {
        return "72 186 " + remove_overflow(value, 8);
    }
    else if (reg == "rsi") {
        return "72 190 " + remove_overflow(value, 8);
    }
    else if (reg == "rdi") {
        return "72 191 " + remove_overflow(value, 8);
    }
    else if (reg == "r8") {
        return "73 184 " + remove_overflow(value, 8);
    }
    else if (reg == "r9") {
        return "73 185 " + remove_overflow(value, 8);
    }
    else if (reg == "r10") {
        return "73 186 " + remove_overflow(value, 8);
    }
    else if (reg == "r11") {
        return "73 187 " + remove_overflow(value, 8);
    }
    else if (reg == "r12") {
        return "73 188 " + remove_overflow(value, 8);
    }
    else if (reg == "r13") {
        return "73 189 " + remove_overflow(value, 8);
    }
    else if (reg == "r14") {
        return "73 190 " + remove_overflow(value, 8);
    }
    else if (reg == "r15") {
        return "73 191 " + remove_overflow(value, 8);
    }
    throw std::runtime_error("Parsing error, register given is not supported");
    return "";
}
std::string bin_move_register(const std::string &reg1, const std::string &reg2) {
    if (reg1 == "rax") {
        if (reg2 == "rax") {
            return "72 137 192 ";
        }
        else if (reg2 == "rcx") {
            return "72 137 200 ";
        }
        else if (reg2 == "rdx") {
            return "72 137 208 ";
        }
        else if (reg2 == "rsi") {
            return "72 137 240 ";
        }
        else if (reg2 == "rdi") {
            return "72 137 248 ";
        }
        else if (reg2 == "r8") {
            return "76 137 192 ";
        }
        else if (reg2 == "r9") {
            return "76 137 200 ";
        }
        else if (reg2 == "r10") {
            return "76 137 208 ";
        }
        else if (reg2 == "r11") {
            return "76 137 216 ";
        }
        else if (reg2 == "r12") {
            return "76 137 224 ";
        }
        else if (reg2 == "r13") {
            return "76 137 232 ";
        }
        else if (reg2 == "r14") {
            return "76 137 240 ";
        }
        else if (reg2 == "r15") {
            return "76 137 248 ";
        }
        throw std::runtime_error("Parsing error, register given is not supported");
    }
    else if (reg1 == "rcx") {
        if (reg2 == "rax") {
            return "72 137 193 ";
        }
        else if (reg2 == "rcx") {
            return "72 137 201 ";
        }
        else if (reg2 == "rdx") {
            return "72 137 209 ";
        }
        else if (reg2 == "rsi") {
            return "72 137 241 ";
        }
        else if (reg2 == "rdi") {
            return "72 137 249 ";
        }
        else if (reg2 == "r8") {
            return "76 137 193 ";
        }
        else if (reg2 == "r9") {
            return "76 137 201 ";
        }
        else if (reg2 == "r10") {
            return "76 137 209 ";
        }
        else if (reg2 == "r11") {
            return "76 137 217 ";
        }
        else if (reg2 == "r12") {
            return "76 137 225 ";
        }
        else if (reg2 == "r13") {
            return "76 137 233 ";
        }
        else if (reg2 == "r14") {
            return "76 137 241 ";
        }
        else if (reg2 == "r15") {
            return "76 137 249 ";
        }
        throw std::runtime_error("Parsing error, register given is not supported");   
    }
    else if (reg1 == "rdx") {
        if (reg2 == "rax") {
            return "72 137 194 ";
        }
        else if (reg2 == "rcx") {
            return "72 137 202 ";
        }
        else if (reg2 == "rdx") {
            return "72 137 210 ";
        }
        else if (reg2 == "rsi") {
            return "72 137 242 ";
        }
        else if (reg2 == "rdi") {
            return "72 137 250 ";
        }
        else if (reg2 == "r8") {
            return "76 137 194 ";
        }
        else if (reg2 == "r9") {
            return "76 137 202 ";
        }
        else if (reg2 == "r10") {
            return "76 137 210 ";
        }
        else if (reg2 == "r11") {
            return "76 137 218 ";
        }
        else if (reg2 == "r12") {
            return "76 137 226 ";
        }
        else if (reg2 == "r13") {
            return "76 137 234 ";
        }
        else if (reg2 == "r14") {
            return "76 137 242 ";
        }
        else if (reg2 == "r15") {
            return "76 137 250 ";
        }
        throw std::runtime_error("Parsing error, register given is not supported");   
    }
    else if (reg1 == "rsi") {
        if (reg2 == "rax") {
            return "72 137 198 ";
        }
        else if (reg2 == "rcx") {
            return "72 137 206 ";
        }
        else if (reg2 == "rdx") {
            return "72 137 214 ";
        }
        else if (reg2 == "rsi") {
            return "72 137 246 ";
        }
        else if (reg2 == "rdi") {
            return "72 137 254 ";
        }
        else if (reg2 == "r8") {
            return "76 137 198 ";
        }
        else if (reg2 == "r9") {
            return "76 137 206 ";
        }
        else if (reg2 == "r10") {
            return "76 137 214 ";
        }
        else if (reg2 == "r11") {
            return "76 137 222 ";
        }
        else if (reg2 == "r12") {
            return "76 137 230 ";
        }
        else if (reg2 == "r13") {
            return "76 137 238 ";
        }
        else if (reg2 == "r14") {
            return "76 137 246 ";
        }
        else if (reg2 == "r15") {
            return "76 137 254 ";
        }
        throw std::runtime_error("Parsing error, register given is not supported");   
    }
    else if (reg1 == "rdi") {
        if (reg2 == "rax") {
            return "72 137 199 ";
        }
        else if (reg2 == "rcx") {
            return "72 137 207 ";
        }
        else if (reg2 == "rdx") {
            return "72 137 215 ";
        }
        else if (reg2 == "rsi") {
            return "72 137 247 ";
        }
        else if (reg2 == "rdi") {
            return "72 137 255 ";
        }
        else if (reg2 == "r8") {
            return "76 137 199 ";
        }
        else if (reg2 == "r9") {
            return "76 137 207 ";
        }
        else if (reg2 == "r10") {
            return "76 137 215 ";
        }
        else if (reg2 == "r11") {
            return "76 137 223 ";
        }
        else if (reg2 == "r12") {
            return "76 137 231 ";
        }
        else if (reg2 == "r13") {
            return "76 137 239 ";
        }
        else if (reg2 == "r14") {
            return "76 137 247 ";
        }
        else if (reg2 == "r15") {
            return "76 137 255 ";
        }
        throw std::runtime_error("Parsing error, register given is not supported");   
    }
    else if (reg1 == "r8") {
        if (reg2 == "rax") {
            return "73 137 192 ";
        }
        else if (reg2 == "rcx") {
            return "73 137 200 ";
        }
        else if (reg2 == "rdx") {
            return "73 137 208 ";
        }
        else if (reg2 == "rsi") {
            return "73 137 240 ";
        }
        else if (reg2 == "rdi") {
            return "73 137 248 ";
        }
        else if (reg2 == "r8") {
            return "77 137 192 ";
        }
        else if (reg2 == "r9") {
            return "77 137 200 ";
        }
        else if (reg2 == "r10") {
            return "77 137 208 ";
        }
        else if (reg2 == "r11") {
            return "77 137 216 ";
        }
        else if (reg2 == "r12") {
            return "77 137 224 ";
        }
        else if (reg2 == "r13") {
            return "77 137 232 ";
        }
        else if (reg2 == "r14") {
            return "77 137 240 ";
        }
        else if (reg2 == "r15") {
            return "77 137 248 ";
        }
        throw std::runtime_error("Parsing error, register given is not supported");   
    }
    else if (reg1 == "r9") {
        if (reg2 == "rax") {
            return "73 137 191 ";
        }
        else if (reg2 == "rcx") {
            return "73 137 201 ";
        }
        else if (reg2 == "rdx") {
            return "73 137 209 ";
        }
        else if (reg2 == "rsi") {
            return "73 137 241 ";
        }
        else if (reg2 == "rdi") {
            return "73 137 249 ";
        }
        else if (reg2 == "r8") {
            return "77 137 193 ";
        }
        else if (reg2 == "r9") {
            return "77 137 201 ";
        }
        else if (reg2 == "r10") {
            return "77 137 209 ";
        }
        else if (reg2 == "r11") {
            return "77 137 217 ";
        }
        else if (reg2 == "r12") {
            return "77 137 225 ";
        }
        else if (reg2 == "r13") {
            return "77 137 233 ";
        }
        else if (reg2 == "r14") {
            return "77 137 241 ";
        }
        else if (reg2 == "r15") {
            return "77 137 249 ";
        }
        throw std::runtime_error("Parsing error, register given is not supported");   
    }
    else if (reg1 == "r10") {
        if (reg2 == "rax") {
            return "73 137 194 ";
        }
        else if (reg2 == "rcx") {
            return "73 137 202 ";
        }
        else if (reg2 == "rdx") {
            return "73 137 210 ";
        }
        else if (reg2 == "rsi") {
            return "73 137 242 ";
        }
        else if (reg2 == "rdi") {
            return "73 137 250 ";
        }
        else if (reg2 == "r8") {
            return "77 137 194 ";
        }
        else if (reg2 == "r9") {
            return "77 137 202 ";
        }
        else if (reg2 == "r10") {
            return "77 137 210 ";
        }
        else if (reg2 == "r11") {
            return "77 137 218 ";
        }
        else if (reg2 == "r12") {
            return "77 137 226 ";
        }
        else if (reg2 == "r13") {
            return "77 137 234 ";
        }
        else if (reg2 == "r14") {
            return "77 137 242 ";
        }
        else if (reg2 == "r15") {
            return "77 137 250 ";
        }
        throw std::runtime_error("Parsing error, register given is not supported");   
    }
    else if (reg1 == "r11") {
        if (reg2 == "rax") {
            return "73 137 195 ";
        }
        else if (reg2 == "rcx") {
            return "73 137 203 ";
        }
        else if (reg2 == "rdx") {
            return "73 137 211 ";
        }
        else if (reg2 == "rsi") {
            return "73 137 243 ";
        }
        else if (reg2 == "rdi") {
            return "73 137 251 ";
        }
        else if (reg2 == "r8") {
            return "77 137 195 ";
        }
        else if (reg2 == "r9") {
            return "77 137 203 ";
        }
        else if (reg2 == "r10") {
            return "77 137 211 ";
        }
        else if (reg2 == "r11") {
            return "77 137 219 ";
        }
        else if (reg2 == "r12") {
            return "77 137 227 ";
        }
        else if (reg2 == "r13") {
            return "77 137 235 ";
        }
        else if (reg2 == "r14") {
            return "77 137 243 ";
        }
        else if (reg2 == "r15") {
            return "77 137 251 ";
        }
        throw std::runtime_error("Parsing error, register given is not supported");   
    }
    else if (reg1 == "r12") {
        if (reg2 == "rax") {
            return "73 137 196 ";
        }
        else if (reg2 == "rcx") {
            return "73 137 204 ";
        }
        else if (reg2 == "rdx") {
            return "73 137 212 ";
        }
        else if (reg2 == "rsi") {
            return "73 137 244 ";
        }
        else if (reg2 == "rdi") {
            return "73 137 252 ";
        }
        else if (reg2 == "r8") {
            return "77 137 196 ";
        }
        else if (reg2 == "r9") {
            return "77 137 204 ";
        }
        else if (reg2 == "r10") {
            return "77 137 212 ";
        }
        else if (reg2 == "r11") {
            return "77 137 220 ";
        }
        else if (reg2 == "r12") {
            return "77 137 228 ";
        }
        else if (reg2 == "r13") {
            return "77 137 236 ";
        }
        else if (reg2 == "r14") {
            return "77 137 244 ";
        }
        else if (reg2 == "r15") {
            return "77 137 252 ";
        }
        throw std::runtime_error("Parsing error, register given is not supported");
    }
    else if (reg1 == "r13") {
        if (reg2 == "rax") {
            return "73 137 197 ";
        }
        else if (reg2 == "rcx") {
            return "73 137 205 ";
        }
        else if (reg2 == "rdx") {
            return "73 137 213 ";
        }
        else if (reg2 == "rsi") {
            return "73 137 245 ";
        }
        else if (reg2 == "rdi") {
            return "73 137 253 ";
        }
        else if (reg2 == "r8") {
            return "77 137 197 ";
        }
        else if (reg2 == "r9") {
            return "77 137 205 ";
        }
        else if (reg2 == "r10") {
            return "77 137 213 ";
        }
        else if (reg2 == "r11") {
            return "77 137 221 ";
        }
        else if (reg2 == "r12") {
            return "77 137 229 ";
        }
        else if (reg2 == "r13") {
            return "77 137 237 ";
        }
        else if (reg2 == "r14") {
            return "77 137 245 ";
        }
        else if (reg2 == "r15") {
            return "77 137 253 ";
        }
        throw std::runtime_error("Parsing error, register given is not supported");
    }
    else if (reg1 == "r14") {
        if (reg2 == "rax") {
            return "73 137 198 ";
        }
        else if (reg2 == "rcx") {
            return "73 137 206 ";
        }
        else if (reg2 == "rdx") {
            return "73 137 214 ";
        }
        else if (reg2 == "rsi") {
            return "73 137 246 ";
        }
        else if (reg2 == "rdi") {
            return "73 137 254 ";
        }
        else if (reg2 == "r8") {
            return "77 137 198 ";
        }
        else if (reg2 == "r9") {
            return "77 137 206 ";
        }
        else if (reg2 == "r10") {
            return "77 137 214 ";
        }
        else if (reg2 == "r11") {
            return "77 137 222 ";
        }
        else if (reg2 == "r12") {
            return "77 137 230 ";
        }
        else if (reg2 == "r13") {
            return "77 137 238 ";
        }
        else if (reg2 == "r14") {
            return "77 137 246 ";
        }
        else if (reg2 == "r15") {
            return "77 137 254 ";
        }
        throw std::runtime_error("Parsing error, register given is not supported");
    }
    else if (reg1 == "r15") {
        if (reg2 == "rax") {
            return "73 137 199 ";
        }
        else if (reg2 == "rcx") {
            return "73 137 207 ";
        }
        else if (reg2 == "rdx") {
            return "73 137 215 ";
        }
        else if (reg2 == "rsi") {
            return "73 137 247 ";
        }
        else if (reg2 == "rdi") {
            return "73 137 255 ";
        }
        else if (reg2 == "r8") {
            return "77 137 199 ";
        }
        else if (reg2 == "r9") {
            return "77 137 207 ";
        }
        else if (reg2 == "r10") {
            return "77 137 215 ";
        }
        else if (reg2 == "r11") {
            return "77 137 223 ";
        }
        else if (reg2 == "r12") {
            return "77 137 231 ";
        }
        else if (reg2 == "r13") {
            return "77 137 239 ";
        }
        else if (reg2 == "r14") {
            return "77 137 247 ";
        }
        else if (reg2 == "r15") {
            return "77 137 255 ";
        }
        throw std::runtime_error("Parsing error, register given is not supported");
    }
    throw std::runtime_error("Parsing error, register given is not supported");
    return "";
}


std::string bin_addition(const std::string &reg, const std::string &value) {
    std::stoll(value, nullptr, 10); // hidden check for overflow

    if (reg == "rax") {
        return "72 5 " + remove_overflow(value, 4);
    }
    else if (reg == "rcx") {
        return "72 129 193 " + remove_overflow(value, 4);
    }
    else if (reg == "rdx") {
        return "72 129 194 " + remove_overflow(value, 4);
    }
    else if (reg == "rsi") {
        return "72 129 198 " + remove_overflow(value, 4);
    }
    else if (reg == "rdi") {
        return "72 129 199 " + remove_overflow(value, 4);
    }
    else if (reg == "r8") {
        return "73 129 192 " + remove_overflow(value, 4);
    }
    else if (reg == "r9") {
        return "73 129 193 " + remove_overflow(value, 4);
    }
    else if (reg == "r10") {
        return "73 129 194 " + remove_overflow(value, 4);
    }
    else if (reg == "r11") {
        return "73 129 195 " + remove_overflow(value, 4);
    }
    throw std::runtime_error("Parsing error, register given is not supported");
    return "";
}
std::string bin_subtraction(const std::string &reg, const std::string &value) {
     std::stoll(value, nullptr, 10); // hidden check for overflow

    if (reg == "rax") {
        return "72 45 " + remove_overflow(value, 4);
    }
    else if (reg == "rcx") {
        return "72 129 233 " + remove_overflow(value, 4);
    }
    else if (reg == "rdx") {
        return "72 129 234 " + remove_overflow(value, 4);
    }
    else if (reg == "rsi") {
        return "72 129 238 " + remove_overflow(value, 4);
    }
    else if (reg == "rdi") {
        return "72 129 239 " + remove_overflow(value, 4);
    }
    else if (reg == "r8") {
        return "73 129 232 " + remove_overflow(value, 4);
    }
    else if (reg == "r9") {
        return "73 129 233 " + remove_overflow(value, 4);
    }
    else if (reg == "r10") {
        return "73 129 234 " + remove_overflow(value, 4);
    }
    else if (reg == "r11") {
        return "73 129 235 " + remove_overflow(value, 4);
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
        return "72 37 " + remove_overflow(value, 4);
    }
    else if (reg == "rcx") {
        return "72 129 225 " + remove_overflow(value, 4);
    }
    else if (reg == "rdx") {
        return "72 129 226 " + remove_overflow(value, 4);
    }
    else if (reg == "rsi") {
        return "72 129 230 " + remove_overflow(value, 4);
    }
    else if (reg == "rdi") {
        return "72 129 231 " + remove_overflow(value, 4);
    }
    else if (reg == "r8") {
        return "73 129 224 " + remove_overflow(value, 4);
    }
    else if (reg == "r9") {
        return "73 129 225 " + remove_overflow(value, 4);
    }
    else if (reg == "r10") {
        return "73 129 226 " + remove_overflow(value, 4);
    }
    else if (reg == "r11") {
        return "73 129 227 " + remove_overflow(value, 4);
    }
    throw std::runtime_error("Parsing error, register given is not supported");
    return "";
}
std::string bin_or(const std::string &reg, const std::string &value) {
    std::stoll(value, nullptr, 10); // hidden check for overflow

    if (reg == "rax") {
        return "72 13 " + remove_overflow(value, 4);
    }
    else if (reg == "rcx") {
        return "72 129 201 " + remove_overflow(value, 4);
    }
    else if (reg == "rdx") {
        return "72 129 202 " + remove_overflow(value, 4);
    }
    else if (reg == "rsi") {
        return "72 129 206 " + remove_overflow(value, 4);
    }
    else if (reg == "rdi") {
        return "72 129 207 " + remove_overflow(value, 4);
    }
    else if (reg == "r8") {
        return "73 129 200 " + remove_overflow(value, 4);
    }
    else if (reg == "r9") {
        return "73 129 201 " + remove_overflow(value, 4);
    }
    else if (reg == "r10") {
        return "73 129 202 " + remove_overflow(value, 4);
    }
    else if (reg == "r11") {
        return "73 129 203 " + remove_overflow(value, 4);
    }
    throw std::runtime_error("Parsing error, register given is not supported");
    return "";
}
std::string bin_xor(const std::string &reg, const std::string &value) {
    std::stoll(value, nullptr, 10); // hidden check for overflow

    if (reg == "rax") {
        return "72 53 " + remove_overflow(value, 4);
    }
    else if (reg == "rcx") {
        return "72 129 241 " + remove_overflow(value, 4);
    }
    else if (reg == "rdx") {
        return "72 129 242 " + remove_overflow(value, 4);
    }
    else if (reg == "rsi") {
        return "72 129 246 " + remove_overflow(value, 4);
    }
    else if (reg == "rdi") {
        return "72 129 247 " + remove_overflow(value, 4);
    }
    else if (reg == "r8") {
        return "73 129 240 " + remove_overflow(value, 4);
    }
    else if (reg == "r9") {
        return "73 129 241 " + remove_overflow(value, 4);
    }
    else if (reg == "r10") {
        return "73 129 242 " + remove_overflow(value, 4);
    }
    else if (reg == "r11") {
        return "73 129 243 " + remove_overflow(value, 4);
    }
    throw std::runtime_error("Parsing error, register given is not supported");
    return "";
}
std::string bin_multiply(const std::string &reg, const std::string &value) {
    std::stoll(value, nullptr, 10); // hidden check for overflow

    if (reg == "rax") {
        return "72 105 192 " + remove_overflow(value, 4);
    }
    else if (reg == "rcx") {
        return "72 105 201 " + remove_overflow(value, 4);
    }
    else if (reg == "rdx") {
        return "72 105 210 " + remove_overflow(value, 4);
    }
    else if (reg == "rsi") {
        return "72 105 246 " + remove_overflow(value, 4);
    }
    else if (reg == "rdi") {
        return "72 105 255 " + remove_overflow(value, 4);
    }
    else if (reg == "r8") {
        return "77 105 192 " + remove_overflow(value, 4);
    }
    else if (reg == "r9") {
        return "77 105 201 " + remove_overflow(value, 4);
    }
    else if (reg == "r10") {
        return "77 105 210 " + remove_overflow(value, 4);
    }
    else if (reg == "r11") {
        return "77 105 219 " + remove_overflow(value, 4);
    }
    throw std::runtime_error("Parsing error, register given is not supported");
    return "";
}
std::string bin_divide() {
    return "80 82 76 137 240 72 49 210 73 247 255 73 137 198 73 137 215 90 88 ";
}
std::string bin_print() {
    return "80 87 86 82 65 190 10 0 0 0 77 49 237 77 49 228 76 137 248 72 49 210 73 247 246 72 133 192 116 5 73 255 197 235 240 76 137 248 77 57 236 119 16 72 49 210 73 247 246 73 255 196 72 131 194 48 82 235 235 77 133 228 116 27 184 1 0 0 0 191 1 0 0 0 72 137 230 186 1 0 0 0 15 5 73 255 204 65 94 235 224 90 94 95 88 ";
}
