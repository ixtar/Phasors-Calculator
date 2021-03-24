#include"headers/lib.h"
#include"build/lib.cpp"
#include<iostream>
#include<fstream>
#include<vector>
#include<cmath>


int main() 
{
    bool running = true;

    // lists the operands
    std::vector <value> history;
    // array to store whatever value wants in memory
    std::vector <value> memory;
    // values on which operations are done
    value operand_1;
    value operand_2;
    // recieves output of functions
    value result;

    // load inisital values
    input_value(operand_1,memory, history);
    input_value(operand_2,memory, history);

    do {
        command(operand_1,operand_2,result,memory,history);
        // calculator(operand_1, operand_2, result, memory);
        print_value(result);
    } while (running);
    
    
    return EXIT_SUCCESS;
}