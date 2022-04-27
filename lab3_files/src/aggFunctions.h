#ifndef AGGFUNCTIONS_H
#define AGGFUNCTIONS_H

#include "structures.h"

// createStudent() function to create a student object
student createStudent(std::vector<std::vector<std::string>> myData, int i);

// createTerm() function to create a term object
term createTerm(std::vector<std::vector<std::string>> myData, int i);

// createStudentGroup() function to create a group of students
std::vector<student> createStudentGroup(std::string inputFile1, std::string inputFile2, std::string inputFile3);

// createTermGroup() function to create a group of terms
std::vector<term> createTermGroup(std::string inputFile1, std::string inputFile2, std::string inputFile3);

// formatThreeDecimalPlaces to convert a double to a string rounded to three decimal places
std::string formatThreeDecimalPlaces(double d);

// countStudentsPerInstructor() function to count the number of students for each instructor
std::map<std::string, int> countStudentsPerInstructor(std::vector<student> studentGroup, int courseNum=0);

// findPassRatePerInstructor() function to find the pass rate for each instructor
std::map<std::string, std::string> findPassRatePerInstructor(std::vector<student> studentGroup);

// findPassRatePerInstructorPerCourse to find the pass rate for each instructor for each course
std::map<std::string, std::string> findPassRatePerInstructorPerCourse(std::vector<student> studentGroup, int courseNum);

// findWRatePerInstructor to find the W rate for each instructor
std::map<std::string, std::string> findWRatePerInstructor(std::vector<student> studentGroup);

// findWRatePerInstructorPerCourse to find the W rate for each instructor for each course
std::map<std::string, std::string> findWRatePerInstructorPerCourse(std::vector<student> studentGroup, int courseNum);

// passRatePerTerm() function to calculate the pass rate for each term
std::string passRatePerTerm(std::vector<term> termGroup, std::vector<std::string> termIds);

#endif