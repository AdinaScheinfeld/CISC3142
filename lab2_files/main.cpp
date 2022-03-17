#include <iostream>

#include "structures.h"
#include "functions.h"

int main() {

    // create file to hold output
    FILE * pFile;
    pFile = fopen("output.txt", "a");

    // create a Calculator using createCalculator() function
    Calculator myCalculator = createCalculator();

    // pass Calculator to calculate()
    double result = calculate(myCalculator);

    // display result
    fprintf(pFile, "Your result is: %.2f.\n", result);

    // close the output file
    fclose(pFile);

    // indicate successful termination
    return 0;
}