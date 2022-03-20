#include "structures.h"

#include <iostream>
#include <map>

// calculate function
std::map<std::string, double> calculate(Calculator myCalculator) {

    // declare double to hold result
    double result;

    double opDouble = 6;

    std::map<std::string, double> myMap;

    // switch on the calculator's operator
    switch(myCalculator.op) {

        // addition
        case Calculator::Calculator::Operators::a:
            result = myCalculator.x + myCalculator.y;
            opDouble = 0;
            break;

        // subtraction
        case Calculator::Operators::s:
            result = myCalculator.x - myCalculator.y;
            opDouble = 1;
            break;

        // multiplication
        case Calculator::Operators::m:
            result = myCalculator.x * myCalculator.y;
            opDouble = 2;
            break;

        // division
        case Calculator::Operators::d:

            if(myCalculator.y == 0) {
                printf("Division by zero is undefined.");
            }
            else {
                result = myCalculator.x / myCalculator.y;
            }

            opDouble = 3;
            break;

        // square root
        case Calculator::Operators::r:

            if(myCalculator.y < 0) {
                printf("Division by zero is undefined.");
            }
            else {
                result = sqrt(myCalculator.x);
            }

            opDouble = 4;
            break;
        
        // negate
        case Calculator::Operators::n:
            result = -1 * myCalculator.x;
            opDouble = 5;
            break;

        // default
        default:
            //result = null;
            printf("error");
    }

    // return x, y, op and result
    myMap.insert(std::pair<std::string, double>("x", myCalculator.x));
    myMap.insert(std::pair<std::string, double>("y", myCalculator.y));
    myMap.insert(std::pair<std::string, double>("operator", opDouble));
    myMap.insert(std::pair<std::string, double>("result", result));
    
    return myMap;
}

// create a Calculator
Calculator createCalculator(bool inRepeat, double result) {

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
    double x = result;
    double y = 0;

    if((inRepeat == false) || 
    (inRepeat == true && o == Calculator::Operators::a) ||
    (inRepeat == true && o == Calculator::Operators::s) ||
    (inRepeat == true && o == Calculator::Operators::m) ||
    (inRepeat == true && o == Calculator::Operators::d)) {
        printf("Please enter an operand: ");

        if(inRepeat == false) {
            std::cin >> x;
        }
        else {
            std::cin >> y;
        }
    }

    if((inRepeat == false && o == Calculator::Operators::a) || 
    (inRepeat == false && o == Calculator::Operators::s) ||
    (inRepeat == false && o == Calculator::Operators::m) ||
    (inRepeat == false && o == Calculator::Operators::d)) {
        printf("Please enter another operand: ");
        std::cin >> y;
    }

    // create instance of Calculator
    Calculator myCalculator(o, x, y);

    return myCalculator;
}

void printOutput(double result) {

    // create file to hold output
    FILE * pFile;
    pFile = fopen("output.txt", "a");

    // display result
    fprintf(pFile, "Your result is: %.2f.\n", result);

    // close the output file
    fclose(pFile);
}

bool repeat(double result) {

    bool inRepeat;
    char repeatVal;

    printf("Would you like to perform another operation (y/n)? ");

    std::cin >> repeatVal;

    while(repeatVal != 'y' && repeatVal != 'n') {
        printf("Please enter y for yes or n for no: ");
        std::cin >> repeatVal;
    }

    if(repeatVal == 'n') {
        inRepeat = false;
        printf("Ok, thank you for using the calculator.\n");
    }
    else {
        inRepeat = true;
    }
    return inRepeat;   
}