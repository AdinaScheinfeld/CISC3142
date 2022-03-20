#ifndef functions_h
#define functions_h

// calculate() function
std::map<std::string, double> calculate(Calculator myCalculator);

// createCalculator() function
Calculator createCalculator(bool inRepeat, double result);

// convertOpDoubleToChar() function
char convertOpDoubleToChar(double opDouble);

// printOutput() function
void printOutput(double x, double y, double opDouble, double result);

// repeat() function
bool repeat(double result);

#endif