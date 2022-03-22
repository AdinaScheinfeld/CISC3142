#include <iostream>
#include <map>

#include "structures.h"

// calculate function
std::map<std::string, double> calculate(Calculator myCalculator) {

    // declare double to hold result
    double result;

    // declare double to hold operator as a double
    double opDouble;

    // declare map to hold operand(s), operator, and result
    std::map<std::string, double> myMap;

    // switch on the calculator's operator
    switch(myCalculator.op) {

        // addition
        case Calculator::Calculator::Operators::a:

            // calculate the sum of x and y
            result = myCalculator.x + myCalculator.y;

            // set opDouble to 0 to indicate addition
            opDouble = 0;

            break;

        // subtraction
        case Calculator::Operators::s:

            // calculate the difference of x and y
            result = myCalculator.x - myCalculator.y;

            // set opDouble to 1 to indicate subtraction
            opDouble = 1;
            break;

        // multiplication
        case Calculator::Operators::m:

            // calculate the product of x and y
            result = myCalculator.x * myCalculator.y;

            // set opDouble to 2 to indicate multiplication
            opDouble = 2;

            break;

        // division
        case Calculator::Operators::d:

            // check if denominator is zero
            if(myCalculator.y == 0) {
                printf("Division by zero is undefined.\n");
                std::exit(EXIT_FAILURE);
            }
            else {
                // calculate the quotient of x and y
                result = myCalculator.x / myCalculator.y;
            }

            // set opDouble to 3 to indicate division
            opDouble = 3;

            break;

        // square root
        case Calculator::Operators::r:

            // check if operand is less than 0
            if(myCalculator.x < 0) {
                printf("Square root of a negative number is undefined.\n");
                std::exit(EXIT_FAILURE);
            }
            else {
                // calculate the square root of x
                result = sqrt(myCalculator.x);
            }

            // set opDouble to 4 to indicate square root
            opDouble = 4;

            break;
        
        // negate
        case Calculator::Operators::n:

            // negate x
            result = -1 * myCalculator.x;

            // set opDouble to 5 to indicate negation
            opDouble = 5;

            break;

        // default
        default:

            // if an invalid operator has been used, indicate an error, and exit
            printf("error");
            std::exit(EXIT_FAILURE);
    }

    // add x, y, opDouble, and result to myMap
    myMap.insert(std::pair<std::string, double>("x", myCalculator.x));
    myMap.insert(std::pair<std::string, double>("y", myCalculator.y));
    myMap.insert(std::pair<std::string, double>("opDouble", opDouble));
    myMap.insert(std::pair<std::string, double>("result", result));
    
    // return myMap
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

    // if not in repeat mode, or if the user has selected a binary operator, prompt the user for an operand
    if((inRepeat == false) || 
    (inRepeat == true && o == Calculator::Operators::a) ||
    (inRepeat == true && o == Calculator::Operators::s) ||
    (inRepeat == true && o == Calculator::Operators::m) ||
    (inRepeat == true && o == Calculator::Operators::d)) {
        printf("Please enter an operand: ");

        // if not in repeat mode, assign the user's input to x
        if(inRepeat == false) {
            std::cin >> x;

            // check to ensure that the operand that the user entered is valid
            while(std::cin.fail()) {
                std::cin.clear();
                std::cin.ignore();
                printf("Please enter a valid operand: ");
                std::cin >> x;
            }
        }

        // if in repeat mode, assign the user's input to y
        // (the result of the previous operation has been assigned to x)
        else {
            std::cin >> y;

            // check to ensure that the operand that the user entered is valid
            while(std::cin.fail()) {
                std::cin.clear();
                std::cin.ignore();
                printf("Please enter a valid operand: ");
                std::cin >> y;
            }
        }
    }

    // if not in repeat mode, and the user has selected a binary operator, prompt the user for another operand
    if((inRepeat == false && o == Calculator::Operators::a) || 
    (inRepeat == false && o == Calculator::Operators::s) ||
    (inRepeat == false && o == Calculator::Operators::m) ||
    (inRepeat == false && o == Calculator::Operators::d)) {
        printf("Please enter another operand: ");

        // store the second operand in y
        std::cin >> y;

        // ensure that the user has entered a valid operand
        while(std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore();
            printf("Please enter a valid operand: ");
            std::cin >> y;
        }
    }

    // create instance of Calculator
    Calculator myCalculator(o, x, y);

    // return the calculator that has been created
    return myCalculator;
}

// convert opDouble to a character
char convertOpDoubleToChar(double opDouble) {

    // addition
    if(opDouble == 0) {
        return '+';
    }

    // subtraction
    else if(opDouble == 1) {
        return '-';
    }

    // multiplication
    else if(opDouble == 2) {
        return '*';
    }

    // division
    else if(opDouble == 3) {
        return '/';
    }

    // square root
    else if(opDouble == 4) {
        return 's';
    }

    // negation
    else if(opDouble == 5) {
        return 'n';
    }

    // error
    else{
        return 'e';
    }
}

// print output
void printOutput(double x, double y, double opDouble, double result) {

    // declare a character to hold the operator
    char op;

    // create file to hold output
    FILE * pFile;
    pFile = fopen("lab2_files/output.txt", "a");

    // use convertOpDoubleToChar to convert opDouble to a character and store the result in op
    op = convertOpDoubleToChar(opDouble);

    // if opDouble causes an error, indicate that the operator is invalid, and exit
    if(opDouble == 'e') {
        printf("Invalid operator.");
        std::exit(EXIT_FAILURE);
    }

    // if square root or negation were performed, print the output with 1 operand
    if(opDouble == 4 || opDouble == 5) {
        fprintf(pFile, "Operand(s): %.2f; Operator: %c; Result: %.2f.\n", x, op, result);
    }

    // if addition, subtract, multiplication, or division were performed, print the output with 2 operands
    else {
        fprintf(pFile, "Operand(s): %.2f, %.2f; Operator: %c; Result: %.2f.\n", x, y, op, result);
    }

    // close the output file
    fclose(pFile);
}

// function check if user would like to perform another operation
bool repeat() {

    // declare variables
    bool inRepeat;
    char repeatVal;

    // prompt user to determine whether they would like to perform another operation
    printf("Would you like to perform another operation (y/n)? ");
    std::cin >> repeatVal;

    // check to ensure that the user has entered a valid input
    while(repeatVal != 'y' && repeatVal != 'n') {
        printf("Please enter y for yes or n for no: ");
        std::cin >> repeatVal;
    }

    // if the user does not want to perform another operation, indicate that the program will exit
    if(repeatVal == 'n') {
        inRepeat = false;
        printf("Ok, thank you for using the calculator.\n");
    }

    // if the user wants to perform another operation, store the user's decision
    else {
        inRepeat = true;
    }

    // return boolean indicating whether the user would like to perform another operation
    return inRepeat;   
}