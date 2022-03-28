#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include "structures.h"

// createStudent() function to create a student object
student createStudent(std::vector<std::vector<std::string>> myData, int i);

// createStudentGroup() function to create a group of students
std::vector<student> createStudentGroup();

// findPassRatePerInstructor() function to find the pass rate for each instructor
std::map<std::string, double> findPassRatePerInstructor(std::vector<student> studentGroup);

// findPassRatePerInstructorPerCourse to find the pass rate for each instructor for each course
std::map<std::string, double> findPassRatePerInstructorPerCourse(std::vector<student> studentGroup, int courseNum);

#endif