#include <iostream>
#include <map>

#include "structures.h"
#include "functions.h"

int main() {

    // initialize boolean to indicate whether in repeat mode
    bool inRepeat = false;

    // declare variables to hold operands
    double x, y;

    // declare variable to hold operator
    double opDouble;

    // initialize variable to hold result
    double result = 0;

    // declare map to hold operands, operator, and result
    std::map<std::string, double> myMap;

    do {
        // create a Calculator using createCalculator() function
        Calculator myCalculator = createCalculator(inRepeat, result);

        // pass Calculator to calculate()
        myMap = calculate(myCalculator);

        // extract operands, operator, and result from myMap
        x = myMap.at("x");
        y = myMap.at("y");
        opDouble = myMap.at("opDouble");
        result = myMap.at("result");

        // print result to file
        printOutput(x, y, opDouble, result);

        // call repeat() function to determine whether user would like to perform another operation
        inRepeat = repeat(result);

    } while(inRepeat == true);

    // indicate successful termination
    return 0;
}