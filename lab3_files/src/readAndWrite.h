#ifndef READANDWRITE_H
#define READANDWRITE_H

#include "structures.h"

// readData() function to read in the data from the files
std::vector<std::vector<std::string>> readData(std::string fname);

// printPassMap() function to print the contents of a pass map
void printPassMap(FILE *fp, std::map<std::string, std::string> myMap, int courseNum=0, bool moreData=false);

// printWMap() function to print the contents of a W map
void printWMap(FILE *fp, std::map<std::string, std::string> myMap, int courseNum=0, bool moreData=false);

// printHeader() function to print a header to a file
void printHeader(FILE *fp, int numColumns, std::string firstColumn, std::string secondColumn, std::string thirdColumn="", std::string fourthColumn="");

// printStringAndDouble() function to print a string and a double stored as a string to a file
void printStringAndDouble(FILE *fp, std::string s, std::string d);

// printAddedStudent function to print the student that was added using the Enrollment class operations
void printAddedStudent(FILE *fp, std::vector<student> myStudents);

#endif