#pragma once
#include <string>
std::string bin_move(const std::string &reg, const std::string &value);
std::string bin_move_register(const std::string &reg1, const std::string &reg2);
std::string bin_addition(const std::string &reg, const std::string &value);
std::string bin_subtraction(const std::string &reg, const std::string &value);
std::string bin_rshift(const std::string &reg, const std::string &value);
std::string bin_lshift(const std::string &reg, const std::string &value);
std::string bin_and(const std::string &reg, const std::string &value);
std::string bin_or(const std::string &reg, const std::string &value);
std::string bin_xor(const std::string &reg, const std::string &value);
std::string bin_multiply(const std::string &reg, const std::string &value);
std::string bin_divide();
std::string bin_print();
