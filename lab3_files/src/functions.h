#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include "structures.h"

// createStudent() function to create a student object
student createStudent(std::vector<std::vector<std::string>> myData, int i);

// createStudentGroup() function to create a group of students
std::vector<student> createStudentGroup();

// findPassRatePerInstructor() function to find the number of passes for each instructor
std::map<std::string, double> findPassRatePerInstructor(std::vector<student> studentGroup);

#endif