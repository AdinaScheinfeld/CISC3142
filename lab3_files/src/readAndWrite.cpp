#include <fstream>
#include <iostream>
#include <map>
#include <sstream>
#include <vector>

#include "structures.h"

// function to read in data
std::vector<std::vector<std::string>> readData(std::string fname) {

    // declare variables
    std::vector<std::vector<std::string>> content;
    std::vector<std::string> row;
    std::string line, word;

    // read in file
    std::fstream file(fname, std::ios::in);

    // if the file opened successfully
    if(file.is_open()) {

        // skip header row
        getline(file, line);

        // while there is still data to be read in
        while(getline(file, line)) {

            // clear the row vector
            row.clear();

            // read in a line
            std::stringstream str(line);

            // parse the line
            while(getline(str, word, ',')) {
                row.push_back(word);
            }
            // add the data to the vector
            content.push_back(row);
        }
    }

    // print an error message if the file could not be opened
    else {
        printf("Could not open file\n");
    }

    // return the content that has been read in
    return content;
}

// function to print the keys and values in a pass map
void printPassMap(FILE *fp, std::map<std::string, std::string> myMap, int courseNum, bool moreData) {

    // print each key and value in the map if no course number is passed in
    if(courseNum == 0) {

        // if this is the first time the file is being used, print a header
        if(!moreData) {
            fprintf(fp, "Instructor ID,Pass Rate\n");
        }

        // print the data to the map
        for(auto x:myMap) {
            fprintf(fp, "%s,%s\n", x.first.c_str(), x.second.c_str());

        }
    }

    // print each key and value in the map with a course number, if a course number was passed in
    else {

        // if this is the first time the file is being used, print a header
        if(!moreData) {
            fprintf(fp, "Instructor ID,Course Number,Pass Rate\n");  
        }

        // print the data to the map
        for (auto x: myMap) {
            fprintf(fp, "%s,%i,%s\n", x.first.c_str(), courseNum, x.second.c_str());

        }
    }
}

// function to print the keys and values in a pass map
void printWMap(FILE *fp, std::map<std::string, std::string> myMap, int courseNum, bool moreData) {

    // print each key and value in the map if no course number is passed in
    if(courseNum == 0) {

        // if this is the first time the file is being used, print a header
        if(!moreData) {
            fprintf(fp, "Instructor ID,W Rate\n");
        }

        // print the data to the map
        for(auto x:myMap) {
            fprintf(fp, "%s,%s\n", x.first.c_str(), x.second.c_str());
        }
    }

    // print each key and value in the map with a course number, if a course number was passed in
    else {

        // if this is the first time the file is being used, print a header
        if(!moreData) {
            fprintf(fp, "Instructor ID,Course Number,W Rate\n");  
        }

        // print the data to the map
        for (auto x: myMap) {
            fprintf(fp, "%s,%i,%s\n", x.first.c_str(), courseNum, x.second.c_str());
        }
    }
}

// function to print a header to a file
void printHeader(FILE *fp, int numColumns, std::string firstColumn, std::string secondColumn, std::string thirdColumn, std::string fourthColumn) {

    if(numColumns == 2) {
        // print the headers that were passed in to the file that was passed in
        fprintf(fp, "%s,%s\n", firstColumn.c_str(), secondColumn.c_str());
    }

    else if(numColumns == 4) {
        // print the headers that were passed in to the file that was passed in
        fprintf(fp, "%s,%s,%s,%s\n", firstColumn.c_str(), secondColumn.c_str(), thirdColumn.c_str(), fourthColumn.c_str());
    }
}

// function to print a string and a double stored as a stringto a file
void printStringAndDouble(FILE *fp, std::string s, std::string d) {

    // print the string and the double to the file that was passed in
    fprintf(fp, "%s,%s\n", s.c_str(), d.c_str());
}

// function to print the student that was added using the Enrollment class operations
void printAddedStudent(FILE *fp, std::vector<student> myStudents) {

    // print the new student's information to the file
    fprintf(fp, "%s,%i,%s,%s\n", myStudents.at(myStudents.size()-1).emplid.c_str(), myStudents.at(myStudents.size()-1).courseno, myStudents.at(myStudents.size()-1).instructorid.c_str(), myStudents.at(myStudents.size()-1).grade.c_str());

}

