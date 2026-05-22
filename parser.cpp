#include <iostream>
#include <fstream>
#include <vector>
#include <utility>
#include <tuple>
#include <cctype>
#include <cstdlib>
#include "binfuncs.hpp"

std::string map_to_register() noexcept {
    static size_t index = 0;
    switch (index) {
        case 0: {
            index++;
            return "rax";
        }
        case 1: {
            index++;
            return "rcx";
        }
        case 2: {
            index++;
            return "rdx";
        }
        case 3: {
            index++;
            return "rsi";
        }
        case 4: {
            index++;
            return "rdi";
        }
        case 5: {
            index++;
            return "r8";
        }
        case 6: {
            index++;
            return "r9";
        }
        case 7: {
            index++;
            return "r10";
        }
        case 8: {
            index++;
            return "r11";
        }

        default: {
            break;
        }
            
    }
    return "";
}

std::string get_val_from_range(const std::vector<std::tuple<const size_t, const std::string>> &vals, const size_t &range_start, const size_t &range_end, const bool &&side) noexcept {
    std::string output {};
    size_t current_most_closest = range_start;
    if (side == true) {
        current_most_closest = range_end;
    }

    for (size_t i = 0; i < vals.size(); ++i) {
        
        if (side == true) { // left
            if ((std::get<0>(vals[i]) >= range_start) && (std::get<0>(vals[i]) <= range_end) && (std::get<0>(vals[i]) < current_most_closest)) {
                current_most_closest = std::get<0>(vals[i]);
                output = std::get<1>(vals[i]);
            }
        }
        else { // right
            if ((std::get<0>(vals[i]) >= range_start) && (std::get<0>(vals[i]) <= range_end) && (std::get<0>(vals[i]) > current_most_closest)) {
                current_most_closest = std::get<0>(vals[i]);
                output = std::get<1>(vals[i]);
            }
        }
        
    }
    
    
    if (output.empty()) {
        std::cerr << "Error: Syntax error, nothing is retreived from the expression\n";
    }

    return output;
}
bool typeof_variable_name(const std::string &instr, const size_t &range_start, const size_t &range_end) noexcept {
     for (size_t i = range_start; i < range_end; ++i) {
        if (instr[i] == 'v' && instr[i+1] == 'a' && instr[i+2] == 'r' && instr[i+3] == ' ' && ((i+3) < range_end)) {
            return true;
        }
    }
    return false;
}

std::string variable_declaration_name(const std::string &instr, const size_t &range_start, const size_t &range_end) { // range_end is '=' pos so dont worry, it will not work on functions
    std::string output {};
    for (size_t i = range_start; i < range_end; ++i) {
        if (instr[i] == 'v' && instr[i+1] == 'a' && instr[i+2] == 'r' && instr[i+3] == ' ' && ((i+4) < range_end)) {
            i += 4;
            for (; i < range_end; ++i) {
                if (isalpha(instr[i])) {
                    output += instr[i];
                }
                else if (instr[i] == ' ') {
                    if (i+1 < range_end) {
                        std::cerr << "Error: Syntax error, only one space is allowed\n";
                        return "";
                    }
                    break;
                }
                else {
                    std::cerr << "Error: Syntax error, unexpected character found: " << instr[i] << '\n';
                    return "";
                }
            }
            break;
        }
    }
    if (output.empty()) {
        std::cerr << "Error: Syntax error, variable name not specified\n";
    }
    return output;
}

std::string get_variable_name(const std::string &instr, const size_t &range_start, const size_t &range_end, 
    std::vector< std::tuple <const size_t, const size_t, const std::string, const std::string> > &vars) { // range_end is '=' pos so dont worry, it will not work on functions
    
    std::string output {};
    for (size_t i = range_start; i < range_end; ++i) {
        if (isalpha(instr[i])) {
            for (; i < range_end; ++i) {
                if (isalpha(instr[i])) {
                    output += instr[i];
                }
                else if (instr[i] == ' ') {
                    if (i+1 < range_end) {
                        std::cerr << "Error: Syntax error, only one space is allowed\n";
                        return "";
                    }
                    break;
                }
                else {
                    std::cerr << "Error: Syntax error, unexpected character found: " << instr[i] << '\n';
                    return "";
                }
            }
        }
    }
    for (size_t i = 0; i < vars.size(); ++i) {
        if (std::get<2>(vars[i]) == output) {
            return output;
        }
    }
    
    if (output.empty()) {
        std::cerr << "Error: Syntax error, variable name not specified\n";
        return "";
    }
    std::cerr << "Error: Syntax error, variable is not declared\n";
    return "";
}

std::string dec_to_str(const std::string &decstr) {
    std::string output {};
    std::string temp {};
    for (size_t i = 0; i < decstr.length(); ++i) {
        if (decstr[i] == ' ') {
            output += static_cast<char>(std::stoi(temp, nullptr, 10));
            temp.assign(temp.length(), '\0');
            temp.clear();
        }
        else if (!isdigit(decstr[i])) {
            throw std::runtime_error("Parsing error, Unsupported character: " + decstr[i]);
        }
        else {
            temp += decstr[i];
        }
    }
    return output;
}

template <typename T>
size_t find_varname_index(const std::string &var_name, const std::vector <T> &arr) {
    for (size_t i = 0; i < arr.size(); ++i) {
        if (var_name == std::get<2>(arr[i])) {
            return i;
        }
    }
    throw std::runtime_error("Parsing error, variable doesnt exists");
    return 0;
}

template <typename T>
bool arguments_calculated(const std::vector <T> &arr) {
    bool counted = false;
    for (size_t i = 0; i < arr.size(); ++i) {
        if (std::get<2>(arr[i]) == true) {
            counted = true;
            break;
        }
    }
    if (counted == false) {
        return false;
    }
    return true;
}
template <typename T>
void arguments_reset(std::vector <T> &arr) {
    for (size_t i = 0; i < arr.size(); ++i) {
        std::get<2>(arr[i]) = false;
    }
}

bool compile(const std::string &output_file, const std::string &code, const bool &raw_bin, const bool &raw_object) noexcept {
    std::ofstream Writer(output_file + ".bin");
    if (!Writer) {
        std::cerr << "Error: Failed to open output file for writing\n";
        return false;
    }
    Writer.write(code.c_str(), code.size());
    Writer.close();
    if (raw_bin) {
        return true;
    }
    system(std::string("objcopy -I binary -O elf64-x86-64 --rename-section .data=.text " + output_file + ".bin " + output_file + ".o").c_str());
    remove(std::string(output_file + ".bin").c_str());
    if (raw_object) {
        return true;
    }
    system(std::string("ld -e 0x401000 " + output_file + ".o -o " + output_file).c_str());
    remove(std::string(output_file + ".o").c_str());
    return true;

}

bool parse(const std::string &input_file, const std::string &output_file, const bool &raw_bin, const bool &raw_object) noexcept {
    std::ifstream Reader(input_file);
    if (!Reader) {
        std::cerr << "Error: Failed to open input file\n";
        return false;
    }
    //                          position     character  counted 
    std::vector <std::tuple<const size_t,   const char,   bool>> special_chars {};
    //                          position         number
    std::vector <std::tuple<const size_t,   const std::string>> special_digits {};
    //                      start_position  end_position        name          register_mapped_to_var
    std::vector <std::tuple<const size_t,    const size_t,  const std::string, const std::string>> variables {};
    
    std::string bin_code = "";
    std::string file_insiders {};
    char c;
    while (Reader.get(c)) {
        file_insiders += c;
    }
    
    Reader.close();

    if (file_insiders.find("start:\n") != std::string::npos) {
        file_insiders.erase(0, file_insiders.find("start:\n") + 7);
    }
    else {
        std::cerr << "Error: Start of the program not found\n";
        return false;
    }
    
    std::string temp_digit {};
    size_t temp_pos {};
    for (size_t i = 0; i < file_insiders.size(); ++i) {
        if (ispunct(file_insiders[i])) {
            special_chars.push_back(std::make_tuple(i, file_insiders[i], false));
            
            if (!temp_digit.empty()) {
                special_digits.push_back(std::make_tuple(temp_pos, temp_digit));
                temp_digit.assign('\0', temp_digit.size());
                temp_digit.clear();
            }
        }
        else if (isdigit(file_insiders[i])) {
            if (temp_digit.empty()) {
                temp_pos = i;
            }
            temp_digit += file_insiders[i];
        }
        else {
            if (!temp_digit.empty()) {
                special_digits.push_back(std::make_tuple(temp_pos, temp_digit));
                temp_digit.assign('\0', temp_digit.size());
                temp_digit.clear();
            }

        }
    }

    for (size_t j = 0; j < special_chars.size(); ++j) {
        switch(std::get<1>(special_chars[j])) {
            case '=': {
                std::string var_name {};
                size_t range_start = std::get<0>(special_chars[j]);
                size_t range_end = std::get<0>(special_chars[j]);
                
                while (file_insiders[range_start] != '\n' && range_start > 0) {
                    range_start--;
                }
                while (file_insiders[range_end] != '\n' && range_end < file_insiders.size()) {
                    range_end++;
                }
                
                if (typeof_variable_name(file_insiders, range_start, std::get<0>(special_chars[j])) == true) {
                    if (variables.size() >= 9) {
                        std::cerr << "Error: Syntax error, assembly on Linux can only use 9 registers so you only have 9 variables at maximum\n";
                        return false;
                    }
                    var_name = variable_declaration_name(file_insiders, range_start, std::get<0>(special_chars[j]));
                    if (var_name.empty()) {
                        return false;
                    }
                    else {
                        variables.push_back(std::make_tuple(range_start, range_end, var_name, map_to_register()));   
                    }
                }
                else { // case where only name is defined
                    var_name = get_variable_name(file_insiders, range_start, std::get<0>(special_chars[j]), variables);
                    if (var_name.empty()) { // for now we quit if we encounter not a variable usage, can change later to search for functions name if it is failed 
                        return false;   
                    }

                }
                
                for (size_t z = j + 1; z < special_chars.size(); ++z) {
                    if ((std::get<0>(special_chars[z]) > range_start) && (std::get<0>(special_chars[z]) < range_end)) {
                        switch (std::get<1>(special_chars[z])) {
                            case '+': {
                                std::string val1 {};
                                std::string val2 {};
                                
                                size_t val_range_start = std::get<0>(special_chars[z])-1;
                                size_t val_range_end = std::get<0>(special_chars[z])+1;
                                
                                while (!ispunct(file_insiders[val_range_start]) && val_range_start > range_start) {
                                    val_range_start--;
                                }
                                val_range_start++;
                                while (!ispunct(file_insiders[val_range_end]) && val_range_end < range_end) {
                                    val_range_end++;
                                }
                                if (std::get<2>(special_chars[z-1]) == true) {
                                    val2 = get_val_from_range(special_digits, std::get<0>(special_chars[z]), val_range_end, false);
                                    if (val2.empty()) {
                                        return false;
                                    }
                                    std::get<2>(special_chars[z]) = true;
                                    
                                    bin_code += bin_addition(std::get<3>(variables[find_varname_index(var_name, variables)]), val2);
                                }
                                else {
                                    val1 = get_val_from_range(special_digits, val_range_start, std::get<0>(special_chars[z]), true);
                                    if (val1.empty()) {
                                        return false;
                                    }
                                    val2 = get_val_from_range(special_digits, std::get<0>(special_chars[z]), val_range_end, false);
                                    if (val2.empty()) {
                                        return false;
                                    }
                                    std::get<2>(special_chars[z]) = true;
                                    bin_code += bin_move(std::get<3>(variables[find_varname_index(var_name, variables)]), val1);
                                    bin_code += bin_addition(std::get<3>(variables[find_varname_index(var_name, variables)]), val2);
                                }
                                break;
                            }
                            case '-': {
                                std::string val1 {};
                                std::string val2 {};
                                
                                size_t val_range_start = std::get<0>(special_chars[z])-1;
                                size_t val_range_end = std::get<0>(special_chars[z])+1;
                                
                                while (!ispunct(file_insiders[val_range_start]) && val_range_start > range_start) {
                                    val_range_start--;
                                }
                                val_range_start++;
                                while (!ispunct(file_insiders[val_range_end]) && val_range_end < range_end) {
                                    val_range_end++;
                                }
                                if (std::get<2>(special_chars[z-1]) == true) {
                                    val2 = get_val_from_range(special_digits, std::get<0>(special_chars[z]), val_range_end, false);
                                    if (val2.empty()) {
                                        return false;
                                    }
                                    std::get<2>(special_chars[z]) = true;
                                    
                                    bin_code += bin_subtraction(std::get<3>(variables[find_varname_index(var_name, variables)]), val2);
                                }
                                else {
                                    val1 = get_val_from_range(special_digits, val_range_start, std::get<0>(special_chars[z]), true);
                                    if (val1.empty()) {
                                        return false;
                                    }
                                    val2 = get_val_from_range(special_digits, std::get<0>(special_chars[z]), val_range_end, false);
                                    if (val2.empty()) {
                                        return false;
                                    }
                                    std::get<2>(special_chars[z]) = true;
                                    bin_code += bin_move(std::get<3>(variables[find_varname_index(var_name, variables)]), val1);
                                    bin_code += bin_subtraction(std::get<3>(variables[find_varname_index(var_name, variables)]), val2);
                                }

                                break;
                            }
                            case '>': {
                                std::string val1 {};
                                std::string val2 {};
                                
                                size_t val_range_start = std::get<0>(special_chars[z])-1;
                                size_t val_range_end = std::get<0>(special_chars[z])+1;
                                
                                while (!ispunct(file_insiders[val_range_start]) && val_range_start > range_start) {
                                    val_range_start--;
                                }
                                val_range_start++;
                                while (!ispunct(file_insiders[val_range_end]) && val_range_end < range_end) {
                                    val_range_end++;
                                }
                                if (std::get<2>(special_chars[z-1]) == true) {
                                    val2 = get_val_from_range(special_digits, std::get<0>(special_chars[z]), val_range_end, false);
                                    if (val2.empty()) {
                                        return false;
                                    }
                                    std::get<2>(special_chars[z]) = true;
                                    
                                    bin_code += bin_rshift(std::get<3>(variables[find_varname_index(var_name, variables)]), val2);
                                }
                                else {
                                    val1 = get_val_from_range(special_digits, val_range_start, std::get<0>(special_chars[z]), true);
                                    if (val1.empty()) {
                                        return false;
                                    }
                                    val2 = get_val_from_range(special_digits, std::get<0>(special_chars[z]), val_range_end, false);
                                    if (val2.empty()) {
                                        return false;
                                    }
                                    std::get<2>(special_chars[z]) = true;
                                    bin_code += bin_move(std::get<3>(variables[find_varname_index(var_name, variables)]), val1);
                                    bin_code += bin_rshift(std::get<3>(variables[find_varname_index(var_name, variables)]), val2);
                                }

                                break;
                            }
                            case '<': {
                                std::string val1 {};
                                std::string val2 {};
                                
                                size_t val_range_start = std::get<0>(special_chars[z])-1;
                                size_t val_range_end = std::get<0>(special_chars[z])+1;
                                
                                while (!ispunct(file_insiders[val_range_start]) && val_range_start > range_start) {
                                    val_range_start--;
                                }
                                val_range_start++;
                                while (!ispunct(file_insiders[val_range_end]) && val_range_end < range_end) {
                                    val_range_end++;
                                }
                                if (std::get<2>(special_chars[z-1]) == true) {
                                    val2 = get_val_from_range(special_digits, std::get<0>(special_chars[z]), val_range_end, false);
                                    if (val2.empty()) {
                                        return false;
                                    }
                                    std::get<2>(special_chars[z]) = true;
                                    
                                    bin_code += bin_lshift(std::get<3>(variables[find_varname_index(var_name, variables)]), val2);
                                }
                                else {
                                    val1 = get_val_from_range(special_digits, val_range_start, std::get<0>(special_chars[z]), true);
                                    if (val1.empty()) {
                                        return false;
                                    }
                                    val2 = get_val_from_range(special_digits, std::get<0>(special_chars[z]), val_range_end, false);
                                    if (val2.empty()) {
                                        return false;
                                    }
                                    std::get<2>(special_chars[z]) = true;
                                    bin_code += bin_move(std::get<3>(variables[find_varname_index(var_name, variables)]), val1);
                                    bin_code += bin_lshift(std::get<3>(variables[find_varname_index(var_name, variables)]), val2);
                                }

                                break;
                            }
                            case '&': {
                                std::string val1 {};
                                std::string val2 {};
                                
                                size_t val_range_start = std::get<0>(special_chars[z])-1;
                                size_t val_range_end = std::get<0>(special_chars[z])+1;
                                
                                while (!ispunct(file_insiders[val_range_start]) && val_range_start > range_start) {
                                    val_range_start--;
                                }
                                val_range_start++;
                                while (!ispunct(file_insiders[val_range_end]) && val_range_end < range_end) {
                                    val_range_end++;
                                }
                                if (std::get<2>(special_chars[z-1]) == true) {
                                    val2 = get_val_from_range(special_digits, std::get<0>(special_chars[z]), val_range_end, false);
                                    if (val2.empty()) {
                                        return false;
                                    }
                                    std::get<2>(special_chars[z]) = true;
                                    
                                    bin_code += bin_and(std::get<3>(variables[find_varname_index(var_name, variables)]), val2);
                                }
                                else {
                                    val1 = get_val_from_range(special_digits, val_range_start, std::get<0>(special_chars[z]), true);
                                    if (val1.empty()) {
                                        return false;
                                    }
                                    val2 = get_val_from_range(special_digits, std::get<0>(special_chars[z]), val_range_end, false);
                                    if (val2.empty()) {
                                        return false;
                                    }
                                    std::get<2>(special_chars[z]) = true;
                                    bin_code += bin_move(std::get<3>(variables[find_varname_index(var_name, variables)]), val1);
                                    bin_code += bin_and(std::get<3>(variables[find_varname_index(var_name, variables)]), val2);
                                }

                                break;
                            }
                            case '|': {
                                std::string val1 {};
                                std::string val2 {};
                                
                                size_t val_range_start = std::get<0>(special_chars[z])-1;
                                size_t val_range_end = std::get<0>(special_chars[z])+1;
                                
                                while (!ispunct(file_insiders[val_range_start]) && val_range_start > range_start) {
                                    val_range_start--;
                                }
                                val_range_start++;
                                while (!ispunct(file_insiders[val_range_end]) && val_range_end < range_end) {
                                    val_range_end++;
                                }
                                if (std::get<2>(special_chars[z-1]) == true) {
                                    val2 = get_val_from_range(special_digits, std::get<0>(special_chars[z]), val_range_end, false);
                                    if (val2.empty()) {
                                        return false;
                                    }
                                    std::get<2>(special_chars[z]) = true;
                                    
                                    bin_code += bin_or(std::get<3>(variables[find_varname_index(var_name, variables)]), val2);
                                }
                                else {
                                    val1 = get_val_from_range(special_digits, val_range_start, std::get<0>(special_chars[z]), true);
                                    if (val1.empty()) {
                                        return false;
                                    }
                                    val2 = get_val_from_range(special_digits, std::get<0>(special_chars[z]), val_range_end, false);
                                    if (val2.empty()) {
                                        return false;
                                    }
                                    std::get<2>(special_chars[z]) = true;
                                    bin_code += bin_move(std::get<3>(variables[find_varname_index(var_name, variables)]), val1);
                                    bin_code += bin_or(std::get<3>(variables[find_varname_index(var_name, variables)]), val2);
                                }

                                break;
                            }
                            case '^': {
                                std::string val1 {};
                                std::string val2 {};
                                
                                size_t val_range_start = std::get<0>(special_chars[z])-1;
                                size_t val_range_end = std::get<0>(special_chars[z])+1;
                                
                                while (!ispunct(file_insiders[val_range_start]) && val_range_start > range_start) {
                                    val_range_start--;
                                }
                                val_range_start++;
                                while (!ispunct(file_insiders[val_range_end]) && val_range_end < range_end) {
                                    val_range_end++;
                                }
                                if (std::get<2>(special_chars[z-1]) == true) {
                                    val2 = get_val_from_range(special_digits, std::get<0>(special_chars[z]), val_range_end, false);
                                    if (val2.empty()) {
                                        return false;
                                    }
                                    std::get<2>(special_chars[z]) = true;
                                    
                                    bin_code += bin_xor(std::get<3>(variables[find_varname_index(var_name, variables)]), val2);
                                }
                                else {
                                    val1 = get_val_from_range(special_digits, val_range_start, std::get<0>(special_chars[z]), true);
                                    if (val1.empty()) {
                                        return false;
                                    }
                                    val2 = get_val_from_range(special_digits, std::get<0>(special_chars[z]), val_range_end, false);
                                    if (val2.empty()) {
                                        return false;
                                    }
                                    std::get<2>(special_chars[z]) = true;
                                    bin_code += bin_move(std::get<3>(variables[find_varname_index(var_name, variables)]), val1);
                                    bin_code += bin_xor(std::get<3>(variables[find_varname_index(var_name, variables)]), val2);
                                }

                                break;
                            }
                            default: {
                                std::cerr << "Error: Syntax error, unsupported operation: " << std::get<1>(special_chars[z]) << '\n';
                                return false;
                            }
                        }
                    }
                }

                if (arguments_calculated(special_chars) == false) {
                    std::cerr << "Error: Syntax error, arguments are required to initilize variable\n";
                    return false;
                }

                arguments_reset(special_chars);

                break;
            }
            default: {
                break;
            }
        }
    }
        
    std::string dec_output = dec_to_str(bin_code);
    if (dec_output.empty() || bin_code.empty()) {
        std::cerr << "Error: Code cannot be empty\n";
        return false;
    }
    
    if (compile(output_file, dec_output, raw_bin, raw_object) == false) {
        std::cerr << "Error: Compilation error\n";
        return false;
    }

    return true;
}
