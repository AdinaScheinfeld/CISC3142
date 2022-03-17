#include <iostream>

#include "structures.h"
#include "functions.h"

int main() {

    // create a Calculator using createCalculator() function
    Calculator myCalculator = createCalculator();

    // pass Calculator to calculate()
    double result = calculate(myCalculator);

    // print result to file
    printOutput(result);

    // indicate successful termination
    return 0;
}