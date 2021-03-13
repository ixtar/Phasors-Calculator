# include <iostream>
# include <cmath>

class value {
    public:
        double head; // magnitude of phasor or real of rectangle
        double tail; // angle of phasor or imaginary of rectangle
        bool type; // true for phasor and false for rectangle
};


// user inputs a value
void input_value(value &input) {
    std::cout<<"type > ";
    
    // user will enter 1 to create a phasor and 0 for a rectangle
    std::cin>>input.type;
    if (input.type)
    {
        std::cout<<"Magnitude = "<<std::endl;
        std::cin>>input.head;
        std::cout<<"Angle = "<<std::endl;
        std::cin>>input.tail;
    }
    
    if (!input.type)
    {
        std::cout<<"Real = "<<std::endl;
        std::cin>>input.head;
        std::cout<<"Imaginary = "<<std::endl;
        std::cin>>input.tail;
    }
}

void switch_to_phasor(value &to_switch) {
    
    // transition varriables
    double magnitude, angle;
    
    magnitude = sqrt(pow(to_switch.head, 2)+ pow(to_switch.tail, 2));

    // if the value is purely imaginary the math will breakdown... my code will not :)
    // it will break down because we would be dividing by 0 when taking the tangent
    if (to_switch.head==0){ 
        if (to_switch.tail<0) {
            angle = -90;
        }
        else {
            angle = 90;
        }
    }
    else {
        angle = tan(to_switch.tail/to_switch.head);
    }
    
    to_switch.head = magnitude;
    to_switch.tail = angle;
    to_switch.type = true;
}

void switch_to_rectangle(value &to_switch) {
    double real, imaginary;
    real = to_switch.head * cos(to_switch.tail);
    imaginary = to_switch.head * sin(to_switch.tail);
    to_switch.head = real;
    to_switch.tail = imaginary;
    to_switch.type = false;
}

// multiplication function
void multiply(value multiplicant, value multiplier, value &output) { 
    // switch values to phasor to do multiplication;
    if (!multiplicant.type) {
        switch_to_phasor(multiplicant);
    }
    if (!multiplier.type) {
        switch_to_phasor(multiplicant);
    }
    // do calculations and return output
    output.head = multiplicant.head * multiplier.head;
    output.tail = multiplicant.tail + multiplier.tail;
}

// division function
void divide(value dividend, value divisor, value &output) {
    // switch values to phasor to do division;
    if (!dividend.type) {
        switch_to_phasor(dividend);
    }
    if (!divisor.type) {
        switch_to_phasor(divisor);
    }
    // do calculations and return output
    output.head = dividend.head / divisor.head;
    output.tail = dividend.tail - divisor.tail;
}

void add(value augend, value addend, value &output) {
    // switch values to phasor to do division;
    if (augend.type) {
        switch_to_rectangle(augend);
    }
    if (addend.type) {
        switch_to_rectangle(addend);
    }
    // do calculations and return output
    output.head = augend.head + addend.head;
    output.tail = augend.tail + addend.tail;
}

void subtract(value munuend, value subtrahend, value &output) {
    // switch values to phasor to do division;
    if (munuend.type=true) {
        switch_to_rectangle(munuend);
    }
    if (subtrahend.type=true) {
        switch_to_rectangle(subtrahend);
    }
    // do calculations and return output
    output.head = munuend.head - subtrahend.head;
    output.tail = munuend.tail - subtrahend.tail;
}

// prints a value to the screen
void print_value(value to_print) {
    
    // checks if the value is in phasor form or rectangle form
    if (to_print.type=true) {
        std::cout<<"Magnitude: "<<to_print.head<<std::endl;
        std::cout<<"Angle: "<<to_print.tail<<std::endl;
    }
    else if (to_print.type=false) {
        switch_to_rectangle(to_print);
        std::cout<<"Real: "<<to_print.head<<std::endl;
        std::cout<<"Imaginary: "<<to_print.tail<<std::endl;
    }
}
