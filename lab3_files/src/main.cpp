#include <string>
#include <vector>
#include <iostream>
#include <map>

#include "readAndWrite.h"
#include "functions.h"
#include "structures.h"

int main() {

    // create and open a file for each instructor and their number of passes
    FILE *fp;
    fp = fopen("../output/output1.csv", "w");

    // use the createStudentGroup() function to create a group of students
    std::vector<student> myStudents = createStudentGroup();

    // calculate the number of passes for each instructor using the findNumPassesPerInstructor() function
    std::map<std::string, int> instructorMap = findNumPassesPerInstructor(myStudents);

    // use the printMap() function to print each instructor and their number of passes to a file
    printMap(fp, instructorMap);


    // close the files
    fclose(fp);

    // return 0 to indicate successful termination
    return 0;
}