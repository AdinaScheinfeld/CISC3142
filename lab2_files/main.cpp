#include <iostream>

#include "structures.h"
#include "functions.h"

int main() {

    // create file to hold output
    FILE * pFile;
    pFile = fopen("output.txt", "a");

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

    // create instance of Calculator
    Calculator myCalculator(o, 6.1, 2);

    // pass Calculator to calculate()
    double result = calculate(myCalculator);

    // display result
    fprintf(pFile, "Your result is: %.2f.\n", result);

    // close the output file
    fclose(pFile);

    // indicate successful termination
    return 0;
}