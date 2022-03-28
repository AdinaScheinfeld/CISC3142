#include <string>
#include <vector>
#include <iostream>
#include <map>

#include "readAndWrite.h"
#include "functions.h"
#include "structures.h"

int main() {

    // create and open a file for each instructor and their pass rate
    FILE *fp1;
    fp1 = fopen("../output/output1.csv", "w");

    // create and open a file for each instructor rand their pass rate per course
    FILE *fp2;
    fp2 = fopen("../output/output2.csv", "w");

    // create and open a file for each instructor and their W rate
    FILE *fp3;
    fp3 = fopen("../output/output3.csv", "w");

    // use the createStudentGroup() function to create a group of students
    std::vector<student> myStudents = createStudentGroup();

    // calculate the number of passes for each instructor using the findNumPassesPerInstructor() function
    std::map<std::string, double> instructorPassRateMap = findPassRatePerInstructor(myStudents);

    // use the printPassMap() function to print each instructor and their pass rate to a file
    printPassMap(fp1, instructorPassRateMap);

    // calculate the number of passes for each instructor for each course using the findNumPassesPerInstructorPerCourse() function
    std::map<std::string, double> instructorPassRateMap1115 = findPassRatePerInstructorPerCourse(myStudents, 1115);
    std::map<std::string, double> instructorPassRateMap3115 = findPassRatePerInstructorPerCourse(myStudents, 3115);
    std::map<std::string, double> instructorPassRateMap3130 = findPassRatePerInstructorPerCourse(myStudents, 3130);

    // use the printPassMap() function to print each instructor and their number of passes per course to a file
    printPassMap(fp2, instructorPassRateMap1115, 1115);
    printPassMap(fp2, instructorPassRateMap3115, 3115, true);
    printPassMap(fp2, instructorPassRateMap3130, 3130, true);

    std::map<std::string, double> instructorWRateMap = findWRatePerInstructor(myStudents);

    // use the printWMap() function to print each instructor and their W rate to a file
    printWMap(fp3, instructorWRateMap);

    // close the files
    fclose(fp1);
    fclose(fp2);
    fclose(fp3);

    // return 0 to indicate successful termination
    return 0;
}