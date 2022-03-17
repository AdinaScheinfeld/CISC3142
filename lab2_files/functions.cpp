#include "structures.h"

#include <iostream>

double calculate(Calculator myCalculator) {

    // declare double to hold result
    double result;

    // switch on the calculator's operator
    switch(myCalculator.op) {

        // addition
        case Calculator::Calculator::Operators::a:
            result = myCalculator.x + myCalculator.y;
            break;

        // subtraction
        case Calculator::Operators::s:
            result = myCalculator.x - myCalculator.y;
            break;

        // multiplication
        case Calculator::Operators::m:
            result = myCalculator.x * myCalculator.y;
            break;

        // division
        case Calculator::Operators::d:

            if(myCalculator.y == 0) {
                printf("Division by zero is undefined.");
            }
            else {
                result = myCalculator.x / myCalculator.y;
            }
            break;

        // square root
        case Calculator::Operators::r:

            if(myCalculator.y < 0) {
                printf("Division by zero is undefined.");
            }
            else {
                result = sqrt(myCalculator.x);
            }
            break;
        
        // negate
        case Calculator::Operators::n:
            result = -1 * myCalculator.x;
            break;

        // default
        default:
            //result = null;
            printf("error");
    }
    
    // return the result
    return result;
}

Calculator createCalculator() {

    // declare variable to hold the operator
    Calculator::Operators o;

    // get operator from user
    char operatorInput;
    printf("Please enter an operator "
            "(use + for addition, - for subtraction, * for multiplication, / for division, "
            "s for square root, or n for negation): ");
    std::cin >> operatorInput;

    // check to make sure that entered operator is valid
    while(operatorInput != '+' && operatorInput != '-' && operatorInput != '*' && operatorInput != '/' 
            && operatorInput != 's' && operatorInput != 'n') {
        printf("Please enter a valid operator "
                "(use + for addition, - for subtraction, * for multiplication, / for division, "
                "s for square root, or n for negation): ");
        std::cin >> operatorInput;
    }

    // assign the Calculator operation to the operation selected by the user
    if(operatorInput == '+') {o = Calculator::Operators::a;}
    else if(operatorInput == '-') {o = Calculator::Operators::s;}
    else if(operatorInput == '*') {o = Calculator::Operators::m;}
    else if(operatorInput == '/') {o = Calculator::Operators::d;}
    else if(operatorInput == 's') {o = Calculator::Operators::r;}
    else {o = Calculator::Operators::n;}

    // get operand(s) from user
    double x = 0;
    double y = 0;

    printf("Please enter an operand: ");
    std::cin >> x;

    if(o != Calculator::Operators::s && o != Calculator::Operators::n) {
        printf("Please enter another operand: ");
        std::cin >> y;
    }

    // create instance of Calculator
    Calculator myCalculator(o, x, y);

    return myCalculator;
}