#include <iostream>
#include <string>
#include <vector>

#include "classes.h"
#include "structures.h"

// function implementations for Enrollment class

// default constructor for an enrollment object
Enrollment::Enrollment(){};

// constructor to define a new enrollment by creating a student object with a new course
Enrollment::Enrollment(std::string sid, int cn, std::vector<student> &myStudents) {
    
    // create a new student using the constructor in the student struct
    student newStudent (sid, cn);

    // add the new student to the myStudents group of students
    myStudents.push_back(newStudent);
}

// method to update a student's grade
void Enrollment::updateGrade(student& myStudent, std::string newGrade) {

    // set the grade of the student who was passed in to the value of the new grade
    myStudent.grade = newGrade;
}

// method to update a student's instructor
void Enrollment::updateInstructor(student& myStudent, std::string newInstructor) {

    // set the grade of the student who was passed in to the value of the new grade
    myStudent.instructorid = newInstructor;
}

// method to get a student id
std::string Enrollment::getId() {

    // declare variable to hold the new student's ID
    std::string newID;

    // prompt the user to enter the new student's id
    printf("Please enter the student's ID: ");

    // save the ID that the user input to newID
    std::cin >> newID;

    // check to ensure that the ID that the user entered is a string
    while(std::cin.fail()) {
        std::cin.clear();
        std::cin.ignore();
        printf("Please enter a valid EMPLID: ");
        std::cin >> newID; 
    }

    // check to ensure that the length of the ID that was entered is 5 and the ID begins with the letter E
    while(newID.length() != 5 || newID[0] != 'E') {
        printf("Please enter a valid EMPLID: ");
        std::cin >> newID;
    }

    // return the ID that was entered
    return newID;
}

// method to get a course number
int Enrollment::getCourse() {

    // declare variable to hold the new course
    int newCourse;

    // prompt the user to enter the new course
    printf("Please enter the course number: ");

    // save the course that the user entered to newCourse;
    std::cin >> newCourse;

    // check to ensure that the course that the user entered is an int
    while(std::cin.fail()) {
        std::cin.clear();
        std::cin.ignore();
        printf("Please enter a valid course number: ");
        std::cin >> newCourse; 
    }

    // return the course number that was entered
    return newCourse;
}

// method to get a grade
std::string Enrollment::getGrade() {

    // declare variable to hold the new grade
    std::string newGrade;

    // prompt the user to enter the grade
    printf("Please enter the grade: ");

    // save the grade that the user entered to newGrade
    std::cin >> newGrade;

    // check to ensure that the grade taht the user entered is a string
    while(std::cin.fail()) {
        std::cin.clear();
        std::cin.ignore();
        printf("Please enter a valid grade: ");
        std::cin >> newGrade; 
    }

    // return the grade that was entered
    return newGrade;
}

// method to get an instructor id
std::string Enrollment::getInstructorId() {

    // declare variable to hold the instructor id
    std::string newInstructorID;

    // prompt the user to enter the instructor id
    printf("Please enter the instructor ID: ");

    // save the id that the user entered to newInstructorID
    std::cin >> newInstructorID;

    // check to ensure that the instructor ID that the user entered is a string
    while(std::cin.fail()) {
        std::cin.clear();
        std::cin.ignore();
        printf("Please enter a valid Instructor ID: ");
        std::cin >> newInstructorID; 
    }

    // check to ensure that the length of the instructor ID that was entered is 3 and the ID begins with the letter I
    while(newInstructorID.length() != 3 || newInstructorID[0] != 'I') {
        printf("Please enter a valid Instructor ID: ");
        std::cin >> newInstructorID;
    }

    // return the instructor ID that was entered
    return newInstructorID;
}

