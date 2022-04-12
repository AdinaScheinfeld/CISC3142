#include <vector>
#include <string>
#include <iostream>

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


// int main(){

//     std::vector<student> myStudents;

//     Enrollment("123456", 1115, myStudents);

//     for(int i=0; i<myStudents.size(); i++) {
//         std::cout << "Here " << myStudents.at(i).emplid << std::endl;
//     }

//     return 0;
