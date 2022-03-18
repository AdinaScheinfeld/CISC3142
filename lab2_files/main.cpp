#include <iostream>

#include "structures.h"
#include "functions.h"

int main() {

    bool inRepeat = false;
    double result = 0;

    do {
        // create a Calculator using createCalculator() function
        Calculator myCalculator = createCalculator(inRepeat, result);

        // pass Calculator to calculate()
        result = calculate(myCalculator);

        // print result to file
        printOutput(result);

        inRepeat = repeat(result);

    } while(inRepeat == true);

    // indicate successful termination
    return 0;
}