#include<iostream>
#include<fstream>
#include<vector>
#include<cmath>
#include<cmath>
#include "build/lib.cpp"


int main() 
{
    bool running = true;

    // lists the operands
    std::vector <value> operands;
    
    // array to store whatever value wants in memory
    std::vector <value> memory;
    // values on which operations are done
    value operand_1;
    value operand_2;

    // recieves output of functions
    value result;
    
    // load inisital values
    input_value(operand_1, operands);
    input_value(operand_2, operands);

    do {
        std::string command; // strign to store user command
        // std::cout<<std::endl<<"matheater> ";
        // std::cin>>command;
        
        calculator(operand_1, operand_2, result, memory);
        print_value(result);
        running =false;
         
    } while (running);
    
    
    return EXIT_SUCCESS;
}