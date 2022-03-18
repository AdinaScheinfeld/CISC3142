#ifndef structures_h
#define structures_h

#include <cmath>

// Calculator data structure
struct Calculator {

    // enum of operators
    // a: addition
    // s: subtraction
    // m: multiplication
    // d: division
    // r: square root
    // n: negate
    enum class Operators {a, s, m, d, r, n};

    // Calculator member variables
    Operators op;
    double x;
    double y;
    double result;

    // Calculator constructor
    Calculator(Operators op0, double x0, double y0) {
        op = op0;
        x = x0;
        y = y0;
    }
};

#endif