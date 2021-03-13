#include<iostream>
#include<fstream>
#include<vector>
#include<cmath>
#include<cmath>
#include "build/lib.cpp"

// checks what the user wants to do with the values
void calculator(value operand_1, value operand_2, value &ouput) {
    std::string command; // strign to store user command
    std::cout<<std::endl<<"matheater> ";
    std::cin>>command;
    bool running = true;

    do {
        std::cout<<std::endl<<"matheater> ";
        std::cin>>command;
        running = false;
        if (command == "add")
        {
            add(operand_1, operand_2, ouput);
        }
        else if (command == "sub")
        {
            subtract(operand_1, operand_2, ouput);
        }
        else if (command == "mul")
        {
            multiply(operand_1, operand_2, ouput);
        }
        else if (command == "div")
        {
            divide(operand_1, operand_2, ouput);
        }
        else {
            running = true;
        }

    } while (running);
    
}

int main() 
{
    bool running = true;

    // lists the operands
    std::vector <value> operands;
    
    // array to store whatever value wants in memory
    value memory{};
    
    // values on which operations are done
    value operand_1;
    value operand_2;

    // recieves output of functions
    value result;


    do {
        std::string command; // strign to store user command
        // std::cout<<std::endl<<"matheater> ";
        // std::cin>>command;
        input_value(operand_1);
        input_value(operand_2);
        
        calculator(operand_1, operand_2, result);
        print_value(result);
        running =false;
         
    } while (running);
    
    
    return EXIT_SUCCESS;
}