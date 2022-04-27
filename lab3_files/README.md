## Lab 3

### Problem Description

This code performs data analysis on a provided data file containing rosters showing students' enrollment in courses at Brooklyn College. Each file contains a list of student IDs, course numbers, instructor IDs, section IDs, and grades. All data has been anonymized. 

### Problem Solving Techniques

This code calculates the pass rate for each instructor, the pass rate for each instructor for each course, the W (withdraw) rate for each instructor, the W rate for each instructor for each course, and the pass rate for each term (Fall vs. Spring). The code also provides functionality to enroll a new student and update a student's grade or instructor. 

- The technique used to calculate the pass rate for each instructor was to create a group of student objects count the number of students for each instructor, count the number of passing students for each instructor, and divide the number of each instructor's passing students by that instructor's total number of students. Each student object is an instance of the student struct which contains a student's EMPLID, the course number that the student was enrolled in, the instructor ID of the course's instructor, and the student's grade. A student is considered to have passed a course if they did _not_ receive the grade F, W, WD, WU, WN, AUD, NC, or FIN. 

- The technique used to calculate the pass rate for each instructor for each course was create a group of student objects, count the number of students for each instructor for each course, count the number of passing students for each instructor for each course, and divide the number of each instructor's passing students for each course by that instructor's total number of students for that course. Each student object is an instance of the student struct which contains a student's EMPLID, the course number that the student was enrolled in, the instructor ID of the course's instructor, and the student's grade. A student is considered to have passed a course if they did _not_ receive the grade F, W, WD, WU, WN, AUD, NC, or FIN. 

- The technique used to calculate the W rate for each instructor was to create a group of student objects, count the number of students for each instructor, count the number of students who withdrew from each instructor's courses, and divide the number of each instructor's withdrawal students by that instructor's total number of students. Each student object is an instance of the student struct which contains a student's EMPLID, the course number that the student was enrolled in, the instructor ID of the course's instructor, and the student's grade. A student is considered to have withdrawn from a course if they received a W, WD, WU, or WN. 

- The technique used to calculate the W rate for each instructor for each course was to create a group of student objects, count the number of students for each instructor, count the number of students who withdrew from each instructor's courses, and divide the number of each instructor's withdrawal students for each course by that instructor's total number of students for that course. Each student object is an instance of the student struct which contains a student's EMPLID, the course number that the student was enrolled in, the instructor ID of the course's instructor, and the student's grade. A student is considered to have withdrawn from a course if they received a W, WD, WU, or WN. 

- The technique used to calculate the pass rate for each term (Fall vs. Spring) was to create a group of term objects, count the number of students each term, count the number of students who passed each term, and divide the number of students who passed each term by the total number of students each term. Each term object is an instance of the term struct which contains a student's EMPLID, a term ID, and a grade). A student is considered to have passed a course if they did _not_ receive the grade F, W, WD, WU, WN, AUD, NC, or FIN.

- The technique used to enroll a new student was to create an Enrollment class with a constructor that creates a new student, and methods to get a student ID, course number, grade, and instructor ID from the user. 

### Articulation of the Solution

All source code is stored in the [src](src) folder, all input data is stored in the [data](data) folder, and all output is stored in the [output](output) folder.

- [structures.h](src/structures.h) is a header file with a struct for a student object and a struct for a term object. Each student object consists of an EMPLID, a course number, an instructor ID, and a grade. Each Term object consists of an EMPLID, a term ID, and a grade. 

- [readAndWrite.cpp](src/readAndWrite.cpp) is a file dedicated to functions for file reading and writing. The file contains the `readData()` function, the `printPassMap()` function, the `printWMap()` function, the `printHeader()` function, the `printStringAndDouble()` function, and the `printAddedStudent()` function. 
    - `readData()` takes a string, the filename of a .csv file, as input and returns a vector of vector of strings containing holding the data in the file.
    - `printPassMap()` takes a pointer to an output file, a map containing pass rates, an int holding a course number, and a boolean indicating whether there is more data, as input, and prints each key and value from the map to the provided output file. 
    - `printWMap()` takes a pointer to an output file, a map containing W rates, an int holding a course number, and a boolean indicating whether there is more data, as input, and prints each key and value from the map to the provided output file. 
    - `printHeader()` takes a pointer to an output file, an int indicating the number of headers to print, and that number of strings containing the names of the headers, as input, and prints the headers to the provided file. 
    - `printStringAndDouble()` takes a pointer to an output file, a string, and a double stored as a string, as input, and prints the two strings to the provided output file. 
    - `printAddedStudent()` takes a pointer to an output file and a vector of students as input, and prints the information associated with the last student in the vector to the output file. 

- [readAndWrite.h](src/readAndWrite.h) is a header file with function declarations for the functions in [readAndWrite.cpp](src/readAndWrite.cpp).

- [aggFunctions.cpp](src/aggFunctions.cpp) is a file dedicated to aggregation fucntions. The file contains the `createStudent()` function, the `createTerm()` function, the `createStudentGroup()` function, the `createTermGroup()` function, the `formatThreeDecimalPlaces()` function, the `countStudentsPerInstructor()` function, the `findPassRatePerInstructor()` function, the `findPassRatePerInstructorPerCourse()` function, the `findWRatePerInstructor()` function, the `findWRatePerInstructorPerCourse()` function, and the `passRatePerTerm()` function. 
    - `createStudent()` takes a vector of vectors of strings containing data read in from the input file and an int indicating which number student to create. The function uses the student struct's constructor to create a student object and returns the student object that was created. 
    - `createTerm()` takes a vector of vectors of strings containing data read in from the input file and an int indicating which number term to create. The function uses the term struct's constructor to create a term object and returns the term object that was created. 
    - `createStudentGroup()` takes 3 strings with input file names, uses the `readData()` function to read in the data, uses the `createStudent()` function to create student objects using the data, adds all the students to a vector, and returns the group of students stored as a vector.  
    - `createTermGroup()` takes 3 strings with input file names, uses the `readData()` function to read in the data, uses the `createTerm()` function to create term objects using the data, adds all the terms to a vector, and returns the group of terms stored as a vector.  
    - `formatThreeDecimalPlaces()` is a helper function that takes a double as input and returns that double rounded to the thousandths place, stored as a string. 
    - `countStudentsPerInstructor()` takes a group of students stored as a vector and a course number as input, and returns a map containing instructors as keys and each instructor's number of students as values.
    -  `findPassRatePerInstructor()` takes a group of students stored as a vector as input, and returns a map containing instructors as keys and each instructor's pass rate as values. A student is considered to have passed a course if they did _not_ receive the grade F, W, WD, WU, WN, AUD, NC, or FIN. 
    - `findPassRatePerInstructorPerCourse()` takes a group of students stored as a vector and an int containing a course number as input and returns a map containing instructors as keys and each instructor's pass rate for the provided course, as values. A student is considered to have passed a course if they did _not_ receive the grade F, W, WD, WU, WN, AUD, NC, or FIN. 
    - `findWRatePerInstructor()` takes a group of students stored as a vector as input and returns a map containing instructors as keys and each instructor's W (withdrawal) rate as values. A student is considered to have withdrawn from a course if they received a W, WD, WU, or WN.
    - `findWRatePerInstructorPerCourse()` takes a group of students stored as a vector and an int containing a course number as input and returns a map containing instructors as keys and each instructor's W (withdrawal) rate for the provided course, as values. A student is considered to have withdrawn from a course if they received a W, WD, WU, or WN.
    - `passRatePerTerm()` takes a group of term objects stored as a vector and a list of terms IDs stored as a vector of strings as input and returns the pass rate for each term (Fall and Spring) formatted to 3 decimal places and stored as a string. If there is no data provided for a specific term, the function returns -1. 

- [aggFunctions.h](src/aggFunctions.h) is a header file with function declarations for the functions in [aggFunctions.cpp](src/aggFunctions.cpp).

- [classes.cpp](src/classes.cpp) contains the function definitions for the Enrollment class. The Enrollment class has 2 constructors, an `updateGrade()` function, a `getID()` function, a `getCourse()` function, a `getGrade()` function, and a `getInstructorId()` function.
    - One of the Enrollment class's constructor takes a student ID, a course number, and a reference to a group of students stored as a vector. The other constructor is a default constructor which takes no parameters. 
    - `updateGrade()` takes a reference to a student object and a string containing a new grade, as input, and updates the student's grade to the grade that was passed in.
    - `updateInstructor()` takes a reference to an instructor object and a string containing a new instructor ID, as input, and updates the student's instructor to the instructor ID that was passed in.
    - `getID()` takes no parameters but prompts the user for a student ID. The function performs error checking to ensure that the ID that was passed in is 5 characters long and begins with the letter E, and returns the ID that was passed in.
    - `getCourse()` takes no parameters but prompts the user for a course number. The function performs error checking to ensure that the course number that was passed in is an integer, and returns the course number that was passed in.
    - `getInstructorId()` takes no parameters but prompts the user for an instructor ID. The function performs error checking to ensure that the instructor ID that was passed in is 3 characters long and begins with the letter I, and returns the instructor ID that was passed in.

- [classes.h](src/classes.h) is a header file with the class definition for the Enrollment class. The member functions of the Enrollment class are public to ensure their accessibility from the `main()` function in [main.cpp](src/main.cpp).

- [main.cpp](src/main.cpp) takes an int containing the number of parameters provided and a vector of characters containing the command line arguments as input, and uses the functions in [readAndWrite.cpp](src/readAndWrite.cpp) and [aggFunctions.cpp](src/aggFunctions.cpp) to perform the data analysis described [above](#problem-description). 

### Tech Used

All code compiles in C++14 standard. All code is formatted using the [Google C++ Style Guide](https://google.github.io/styleguide/cppguide.html). 

### How to use?

All code runs from the project root under the default `main` branch with the command `make lab3`. (The command line arguments are stored in the [Makefile](../Makefile) as well. After that target is run, the user is prompted to enter a student ID, a course number, a grade, and an instructor ID. 

### Testing

All output files are stored in the [output](output) folder and are named using the convention `output<#>-<mm>-<dd><yyyy>.csv`.

- `output1.csv` contains a list of instructor IDs with their pass rates, rounded to 3 decimal places.
- `output2.csv` contains a list of instructors and their pass rates per course, rounded to 3 decimal places.
- `output3.csv` contains a list of instructor IDs with their W rates, rounded to 3 decimal places.
- `output4.csv` contains a list of instructors and their W rates per course, rounded to 3 decimal places.
- `output5.csv` contains the Fall and Spring pass rates for each course, rounded to 3 decimal places. 
- `output6.csv` contains output from testing the methods in the Enrollment class. 

