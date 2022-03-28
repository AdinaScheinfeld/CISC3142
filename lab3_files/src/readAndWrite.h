#ifndef READANDWRITE_H
#define READANDWRITE_H

// readData() function to read in the data from the files
std::vector<std::vector<std::string>> readData(std::string fname);

// printPassMap() function to print the contents of a pass map
void printPassMap(FILE *fp, std::map<std::string, double> myMap, int courseNum=0, bool moreData=false);

// printWMap() function to print the contents of a W map
void printWMap(FILE *fp, std::map<std::string, double> myMap, int courseNum=0, bool moreData=false);

#endif