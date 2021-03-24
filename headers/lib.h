#pragma once
#include<vector>

class value;
int check_if_operands_loaded(value opperator_1, value opperator_2);
void input_value(value &input, std::vector<value> &operands_memory);
void switch_to_phasor(value &to_switch);
void switch_to_rectangle(value &to_switch);
void multiply(value multiplicant, value multiplier, value &output);
void divide(value dividend, value divisor, value &output);
void add(value &augend, value &addend, value &output);
void subtract(value &munuend, value &subtrahend, value &output);
void print_value(value &to_print);
void clear_operands(value &operand_to_clear);
void calculator(value &operand_1, value &operand_2, value &ouput, std::vector<value> &history);
void load_value(value &to_load, std::vector <value> memory, int index_of_memory);
void loader(value &operand, value &output, std::vector <value> &memory, std::vector <value> &history);