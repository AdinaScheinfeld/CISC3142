#ifndef functions_h
#define functions_h

// calculate() function
std::map<std::string, double> calculate(Calculator myCalculator);

// createCalculator() function
Calculator createCalculator(bool inRepeat, double result);

// printOutput() function
void printOutput(double result);

bool repeat(double result);

#endif