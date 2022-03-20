#include <iostream>
#include <map>

#include "structures.h"
#include "functions.h"

int main() {

    bool inRepeat = false;
    double x, y;
    double opDouble;
    double result = 0;
    std::map<std::string, double> myMap;

    do {
        // create a Calculator using createCalculator() function
        Calculator myCalculator = createCalculator(inRepeat, result);

        // pass Calculator to calculate()
        myMap = calculate(myCalculator);
        x = myMap.at("x");
        y = myMap.at("y");
        opDouble = myMap.at("opDouble");
        result = myMap.at("result");

        //print result with operands and operator

        // print result to file
        printOutput(x, y, opDouble, result);

        inRepeat = repeat(result);

    } while(inRepeat == true);

    // indicate successful termination
    return 0;
}