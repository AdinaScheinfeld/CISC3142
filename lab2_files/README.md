## Lab 2

### Problem Description

Create a calculator that performs addition, subtraction, multiplication, division, square root, and negation, and allows the user to perform multiple operations. 

### Tech Used

All code compiles in C++14 standard. 

### Articulation of the Solution

- [structures.h](structures.h) is a header file with the struct for a Calculator. 
- [functions.cpp](functions.cpp) contains the `calculate()` function, the `createCalculator()` function, the `convertOpDoubleToChar()` function, the `printOutput()` function, and the `repeat()` function.
    - `calculate()` takes a Calculator object as input, and calculates the sum, difference, product, quotient, square root, or negation of the Calculator's input(s) using the calculator's operator. The function returns a map containing the input(s), the operator, and the result. 
    - `createCalculator()` takes a boolean and a double as input. The boolean indicates whether the program is in repeat mode (i.e. the user has already performed an operation and is now performing another operation), and the double holds the result of the operation performed by the previous use of the calculator if the calculator is in repeat mode. `createCalculator()` prompts the user for an operator and for operator(s) and returns a Calculator object created from that input. 
    - `convertOpDoubleToCharacter()` takes a double value representing an operator as input, converts the double to its corresponding operator as a character, and returns that character. 
    - `printOutput()` takes four doubles as input, and prints the output of the operation performed by the calculator. The doubles represent the operands, the operator, and the result of the calculation. All operands and the result are printed rounded to the nearest hundredth. 
    - `repeat()` takes no input and returns a boolean value indicating whether the user would like to use the calculator to perform another operation. 
- [structures.h](structures.h) is a header file for [functions.cpp](functions.cpp).
- [main.cpp](main.cpp) contains the `main()` function which calls the `createCalculator()` function to create a calculator, calls the `printOutput()` function to print the result from the calculator, and calls the `inRepeat()` function to determine if the user would like to perform another operation. 

### How to use?

All code runs from the project root under the default `main` branch with the command `make lab2`. 

### Testing

- [output.txt](output.txt) contains the output from testing the calculator.
- [outputLog.txt](outputLog.txt) contains the console input and output from when the code was tested. 