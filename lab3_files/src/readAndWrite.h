#ifndef READANDWRITE_H
#define READANDWRITE_H

// readData() function to read in the data from the files
std::vector<std::vector<std::string>> readData(std::string fname);

// printPassMap() function to print the contents of a pass map
void printPassMap(FILE *fp, std::map<std::string, std::string> myMap, int courseNum=0, bool moreData=false);

// printWMap() function to print the contents of a W map
void printWMap(FILE *fp, std::map<std::string, std::string> myMap, int courseNum=0, bool moreData=false);

// printHeader() function to print a header to a file
void printHeader(FILE *fp, std::string firstColumn, std::string secondColumn);

// printStringAndDouble() function to print a string and a double stored as a string to a file
void printStringAndDouble(FILE *fp, std::string s, std::string d);

#endif