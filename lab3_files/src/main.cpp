#include <string>
#include <vector>
#include <iostream>
#include <map>

#include "readAndWrite.h"
#include "functions.h"
#include "structures.h"

// main function
int main() {

    // get current date to use in filenames
    time_t t;
    struct tm *tmp;
    char MY_TIME[50];
    time(&t);
    tmp = localtime(&t);

    // convert the date to mm-dd-yyyy format
    strftime(MY_TIME, sizeof(MY_TIME), "%m-%d-%Y", tmp);
    std::string dateString(MY_TIME);

    // create and open a file for each instructor and their pass rate
    // the naming convention for files is output<#>-<mm>-<dd>-<yyyy>.csv
    FILE *fp1;
    std::string filename1 = ("../output/output1-" + dateString + ".csv");
    fp1 = fopen(filename1.c_str(), "w");

    // create and open a file for each instructor and their pass rate per course
    // the naming convention for files is output<#>-<mm>-<dd>-<yyyy>.csv
    FILE *fp2;
    std::string filename2 = ("../output/output2-" + dateString + ".csv");
    fp2 = fopen(filename2.c_str(), "w");

    // create and open a file for each instructor and their W rate
    // the naming convention for files is output<#>-<mm>-<dd>-<yyyy>.csv
    FILE *fp3;
    std::string filename3 = ("../output/output3-" + dateString + ".csv");
    fp3 = fopen(filename3.c_str(), "w");

    // create and open a file for each instructor and their W rate per coures
    // the naming convention for files is output<#>-<mm>-<dd>-<yyyy>.csv
    FILE *fp4;
    std::string filename4 = ("../output/output4-" + dateString + ".csv");
    fp4 = fopen(filename4.c_str(), "w");

    // create and open a file for the Fall vs Spring pass rate for each course
    // the naming convention for files is output<#>-<mm>-<dd>-<yyyy>.csv
    FILE *fp5;
    std::string filename5 = ("../output/output5-" + dateString + ".csv");
    fp5 = fopen(filename5.c_str(), "w");

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

    // calculate the pass rate for the fall term and spring term
    double passRateFall = passRatePerTerm(myTerms, fallTerm);
    double passRateSpring = passRatePerTerm(myTerms, springTerm);
    std::cout << passRateSpring << std::endl;
    
    // print header to file
    printHeader(fp5, "Term", "Pass Rate");
   
    // print fall and spring pass rates to file
    printStringAndDouble(fp5, "Fall", passRateFall);
    printStringAndDouble(fp5, "Spring", passRateSpring);

    // close the files
    fclose(fp1);
    fclose(fp2);
    fclose(fp3);

    // UP TO HERE



    // return 0 to indicate successful termination
    return 0;
}