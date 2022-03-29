#include <string>
#include <vector>
#include <iostream>
#include <map>

#include "readAndWrite.h"
#include "functions.h"
#include "structures.h"

// main function
int main() {

    // create and open a file for each instructor and their pass rate
    FILE *fp1;
    fp1 = fopen("../output/output1.csv", "w");

    // create and open a file for each instructor and their pass rate per course
    FILE *fp2;
    fp2 = fopen("../output/output2.csv", "w");

    // create and open a file for each instructor and their W rate
    FILE *fp3;
    fp3 = fopen("../output/output3.csv", "w");

    // create and open a file for each instructor and their W rate per coures
    FILE *fp4;
    fp4 = fopen("../output/output4.csv", "w");

    // use the createStudentGroup() function to create a group of students
    std::vector<student> myStudents = createStudentGroup();

    // use the createTermGroup() function to creat a group of terms
    std::vector<term> myTerms = createTermGroup();

    // create a vector of Fall term numbers
    std::vector<std::string> fallTerm{"T04", "T08", "T12", "T16", "T20", "T23"};

    // create a vector of Spring term numbers
    std::vector<std::string> springTerm{"T02", "T06", "T10", "T14", "T18", "T21"};

    // calculate the pass rate for each instructor using the findNumPassesPerInstructor() function
    std::map<std::string, double> instructorPassRateMap = findPassRatePerInstructor(myStudents);

    // use the printPassMap() function to print each instructor and their pass rate to a file
    printPassMap(fp1, instructorPassRateMap);

    // calculate the pass rate for each instructor for each course using the findNumPassesPerInstructorPerCourse() function
    std::map<std::string, double> instructorPassRateMap1115 = findPassRatePerInstructorPerCourse(myStudents, 1115);
    std::map<std::string, double> instructorPassRateMap3115 = findPassRatePerInstructorPerCourse(myStudents, 3115);
    std::map<std::string, double> instructorPassRateMap3130 = findPassRatePerInstructorPerCourse(myStudents, 3130);

    // use the printPassMap() function to print each instructor and their pass rate per course to a file
    printPassMap(fp2, instructorPassRateMap1115, 1115);
    printPassMap(fp2, instructorPassRateMap3115, 3115, true);
    printPassMap(fp2, instructorPassRateMap3130, 3130, true);

    // calculte the W rate for each instructor using the findWRatePerInstructor() function
    std::map<std::string, double> instructorWRateMap = findWRatePerInstructor(myStudents);

    // use the printWMap() function to print each instructor and their W rate to a file
    printWMap(fp3, instructorWRateMap);

    // calculate the W rate for each instructor  for each course using the findWRatePerInstructorPerCourse() function
    std::map<std::string, double> instructorWRateMap1115 = findWRatePerInstructorPerCourse(myStudents, 1115);
    std::map<std::string, double> instructorWRateMap3115 = findWRatePerInstructorPerCourse(myStudents, 3115);
    std::map<std::string, double> instructorWRateMap3130 = findWRatePerInstructorPerCourse(myStudents, 3130);

    // use the printWMap() function to print each instructor and their pass rate per course to a file
    printWMap(fp4, instructorPassRateMap1115, 1115);
    printWMap(fp4, instructorPassRateMap3115, 3115, true);
    printWMap(fp4, instructorPassRateMap3130, 3130, true);

    // calculate the pass rate for the fall term
    double passRateFall = passRatePerTerm(myTerms, fallTerm);
    std::cout << passRateFall << std::endl;
    // UP TO HERE - add comments and properly format pass rate for fall and spring

    // close the files
    fclose(fp1);
    fclose(fp2);
    fclose(fp3);

    // return 0 to indicate successful termination
    return 0;
}