#ifndef functions_h
#define functions_h

// calculate() function
std::map<std::string, double> calculate(Calculator myCalculator);

// createCalculator() function
Calculator createCalculator(bool inRepeat, double result);

// printOutput() function
void printOutput(double x, double y, double opDouble, double result);

bool repeat(double result);

char convertOpDoubleToChar(double opDouble);

#endif