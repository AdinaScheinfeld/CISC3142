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