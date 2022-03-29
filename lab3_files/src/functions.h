#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include "structures.h"

// createStudent() function to create a student object
student createStudent(std::vector<std::vector<std::string>> myData, int i);

// createTerm() function to create a term object
term createTerm(std::vector<std::vector<std::string>> myData, int i);

// createStudentGroup() function to create a group of students
std::vector<student> createStudentGroup();

// createTermGroup() function to create a group of terms
std::vector<term> createTermGroup();

// findPassRatePerInstructor() function to find the pass rate for each instructor
std::map<std::string, double> findPassRatePerInstructor(std::vector<student> studentGroup);

// findPassRatePerInstructorPerCourse to find the pass rate for each instructor for each course
std::map<std::string, double> findPassRatePerInstructorPerCourse(std::vector<student> studentGroup, int courseNum);

// findWRatePerInstructor to find the W rate for each instructor
std::map<std::string, double> findWRatePerInstructor(std::vector<student> studentGroup);

// findWRatePerInstructorPerCourse to find the W rate for each instructor for each course
std::map<std::string, double> findWRatePerInstructorPerCourse(std::vector<student> studentGroup, int courseNum);

// passRatePerTerm() function to calculate the pass rate for each term
double passRatePerTerm(std::vector<term> termGroup, std::vector<std::string> termIds);

#endif