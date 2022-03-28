#ifndef READANDWRITE_H
#define READANDWRITE_H

// readData() function to read in the data from the files
std::vector<std::vector<std::string>> readData(std::string fname);

// printMap() function to print the contents of a map
void printMap(FILE *fp, std::map<std::string, double> myMap, int courseNum=0, bool moreData=false);

#endif