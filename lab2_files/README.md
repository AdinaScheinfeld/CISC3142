## Lab 2

### Problem Description

Create a calculator that performs addition, subtraction, multiplication, division, square root, and negation, and allows the user to perform multiple operations. Use object-oriented techniques for data abstraction. 

### Problem Solving Techniques

1. When the user enters an operator and one or more operands, the input is passed to the `createCalculator()` function which uses the Calculator struct's constructor to create and return a Calculator object. 
2. The Calculator object is passed to the `calculate()` function which performs the operation selcted by the user and passes back the operands, the operator, and the result in a map. 
3. The output from `calculate()` is passed to the `printOutput()` function which prints the output of the operation to a file. 
4. Finally, the `repeat()` function prompts the user to determine whether they would like to perform another operation. 
    - If the user chooses to perform another operation, they are prompted for a new operator and operand, and step 1 repeats using the new operator and operand. 
    - If the user chooses not to perform another operation, the program terminates. 

### Articulation of the Solution

- [structures.h](structures.h) is a header file with the struct for a Calculator. 
- [functions.cpp](functions.cpp) contains the `calculate()` function, the `createCalculator()` function, the `convertOpDoubleToChar()` function, the `printOutput()` function, and the `repeat()` function.
    - `calculate()` takes a Calculator object as input, and calculates the sum, difference, product, quotient, square root, or negation of the Calculator's input(s) using the calculator's operator. The function returns a map containing the input(s), the operator, and the result. 
    - `createCalculator()` takes a boolean and a double as input. The boolean indicates whether the program is in repeat mode (i.e. the user has already performed an operation and is now performing another operation), and the double holds the result of the operation performed by the previous use of the calculator if the calculator is in repeat mode. `createCalculator()` prompts the user for an operator and for operator(s) and returns a Calculator object created from that input. 
    - `convertOpDoubleToCharacter()` takes a double value representing an operator as input, converts the double to its corresponding operator as a character, and returns that character. 
    - `printOutput()` takes four doubles as input, and prints the output of the operation performed by the calculator. The doubles represent the operands, the operator, and the result of the calculation. All operands and the result are printed rounded to the nearest hundredth. 
    - `repeat()` takes no input and returns a boolean value indicating whether the user would like to use the calculator to perform another operation. 
- [functions.h](functions.h) is a header file for [functions.cpp](functions.cpp).
- [main.cpp](main.cpp) contains the `main()` function which calls the `createCalculator()` function to create a calculator, calls the `printOutput()` function to print the result from the calculator, and calls the `inRepeat()` function to determine if the user would like to perform another operation. 

### Tech Used

All code compiles in C++14 standard.

### How to use?

All code runs from the project root under the default `main` branch with the command `make lab2`. After that target is run, the user is promped to enter an operator and one or more operands depending on the requirements of the selected operator. After that operation is executed, the user is prompted to determine whether they want to execute another operation on the calculator or whether they want to terminate the program. Error checking ensures that the user only enters valid operators (+ for addition, - for subtraction, * for multiplication, / for division, s for square root, or n for negation). Error checking also ensures that the user enters valid operands (positive or negative integer or floating point values). Further error checking ensures that the user-entered operands are appropriate for the user-selected operation (i.e. An error message will be printed and the program will terminate if the user attempts to divide by 0 or if the user attempts to calculate the square root of a negative number). The output of each calculation gets appended to [output.txt](output.txt) if the file exists. If [output.txt](output.txt) does not exist, the file is created, and the results of all future operations are saved in the file. 

### Testing

- [output.txt](output.txt) contains the output from testing the calculator. Testing was performed using both correct data (to ensure that the program runs correctly) and incorrect data (to ensure that error checking works correctly).
- [outputLog.txt](outputLog.txt) contains the console input and output from when the code was tested. 