#include <iostream>
#include <map>
#include <string>
#include <vector>

#include "aggFunctions.h"
#include "classes.h"
#include "readAndWrite.h"
#include "structures.h"

// main function
int main(int argc, char** argv) {

    // get input file names from command line args
    std::string inputFile1 = argv[1];
    std::string inputFile2 = argv[2];
    std::string inputFile3 = argv[3];

    // get current date to use in output file names
    time_t t;
    struct tm *tmp;
    char MY_TIME[50];
    time(&t);
    tmp = localtime(&t);

    // convert the date to mm-dd-yyyy format
    strftime(MY_TIME, sizeof(MY_TIME), "%m-%d-%Y", tmp);
    std::string dateString(MY_TIME);

    // create and open a file for each instructor and their pass rate
    // the naming convention for output files is output<#>-<mm>-<dd>-<yyyy>.csv
    FILE *fp1;
    std::string filename1 = ("lab3_files/output/output1-" + dateString + ".csv");
    fp1 = fopen(filename1.c_str(), "w");

    // create and open a file for each instructor and their pass rate per course
    // the naming convention for output files is output<#>-<mm>-<dd>-<yyyy>.csv
    FILE *fp2;
    std::string filename2 = ("lab3_files/output/output2-" + dateString + ".csv");
    fp2 = fopen(filename2.c_str(), "w");

    // create and open a file for each instructor and their W rate
    // the naming convention for output files is output<#>-<mm>-<dd>-<yyyy>.csv
    FILE *fp3;
    std::string filename3 = ("lab3_files/output/output3-" + dateString + ".csv");
    fp3 = fopen(filename3.c_str(), "w");

    // create and open a file for each instructor and their W rate per coures
    // the naming convention for output files is output<#>-<mm>-<dd>-<yyyy>.csv
    FILE *fp4;
    std::string filename4 = ("lab3_files/output/output4-" + dateString + ".csv");
    fp4 = fopen(filename4.c_str(), "w");

    // create and open a file for the Fall vs Spring pass rate for each course
    // the naming convention for output files is output<#>-<mm>-<dd>-<yyyy>.csv
    FILE *fp5;
    std::string filename5 = ("lab3_files/output/output5-" + dateString + ".csv");
    fp5 = fopen(filename5.c_str(), "w");

    // create and open a file to demonstrate the Enrollment class operations
    // the naming convention for output files is output<#>-<mm>-<dd>-<yyyy>.csv
    FILE *fp6;
    std::string filename6 = ("lab3_files/output/output6-" + dateString + ".csv");
    fp6 = fopen(filename6.c_str(), "w");

    // use the createStudentGroup() function to create a group of students
    std::vector<student> myStudents = createStudentGroup(inputFile1, inputFile2, inputFile3);

    // use the createTermGroup() function to creat a group of terms
    std::vector<term> myTerms = createTermGroup(inputFile1, inputFile2, inputFile3);

    // create a vector of Fall term numbers
    std::vector<std::string> fallTerm{"T04", "T08", "T12", "T16", "T20", "T23"};

    // create a vector of Spring term numbers
    std::vector<std::string> springTerm{"T02", "T06", "T10", "T14", "T18", "T21"};

    // calculate the pass rate for each instructor using the findNumPassesPerInstructor() function
    std::map<std::string, std::string> instructorPassRateMap = findPassRatePerInstructor(myStudents);

    // use the printPassMap() function to print each instructor and their pass rate to a file
    printPassMap(fp1, instructorPassRateMap);

    // calculate the pass rate for each instructor for each course using the findNumPassesPerInstructorPerCourse() function
    std::map<std::string, std::string> instructorPassRateMap1115 = findPassRatePerInstructorPerCourse(myStudents, 1115);
    std::map<std::string, std::string> instructorPassRateMap3115 = findPassRatePerInstructorPerCourse(myStudents, 3115);
    std::map<std::string, std::string> instructorPassRateMap3130 = findPassRatePerInstructorPerCourse(myStudents, 3130);

    // use the printPassMap() function to print each instructor and their pass rate per course to a file
    printPassMap(fp2, instructorPassRateMap1115, 1115);
    printPassMap(fp2, instructorPassRateMap3115, 3115, true);
    printPassMap(fp2, instructorPassRateMap3130, 3130, true);

    // calculte the W rate for each instructor using the findWRatePerInstructor() function
    std::map<std::string, std::string> instructorWRateMap = findWRatePerInstructor(myStudents);

    // use the printWMap() function to print each instructor and their W rate to a file
    printWMap(fp3, instructorWRateMap);

    // calculate the W rate for each instructor  for each course using the findWRatePerInstructorPerCourse() function
    std::map<std::string, std::string> instructorWRateMap1115 = findWRatePerInstructorPerCourse(myStudents, 1115);
    std::map<std::string, std::string> instructorWRateMap3115 = findWRatePerInstructorPerCourse(myStudents, 3115);
    std::map<std::string, std::string> instructorWRateMap3130 = findWRatePerInstructorPerCourse(myStudents, 3130);

    // use the printWMap() function to print each instructor and their pass rate per course to a file
    printWMap(fp4, instructorPassRateMap1115, 1115);
    printWMap(fp4, instructorPassRateMap3115, 3115, true);
    printWMap(fp4, instructorPassRateMap3130, 3130, true);

    // calculate the pass rate for the fall term and spring term
    std::string passRateFall = passRatePerTerm(myTerms, fallTerm);
    std::string passRateSpring = passRatePerTerm(myTerms, springTerm);
    
    // print header to file
    printHeader(fp5, 2, "Term", "Pass Rate");
   
    // print fall and spring pass rates to file
    printStringAndDouble(fp5, "Fall", passRateFall);
    printStringAndDouble(fp5, "Spring", passRateSpring);

    // create an enrollment object to use for enrolling a new student and updating their grade and instructor
    Enrollment e;

    // use the getID() method to get an ID for a new student
    std::string newID = e.getId();

    // use the getCourse() method to get a course for a new student
    int newCourse = e.getCourse();

    // create a new student using the Enrollment class and the newID and newCourse that were passed in by the user
    Enrollment(newID, newCourse, myStudents);

    // print the added student's information to a file
    printHeader(fp6, 4, "EMPLID", "Course Number", "Instructor ID", "Grade");
    printAddedStudent(fp6, myStudents);

    // use the getGrade() method to get a grade
    std::string newGrade = e.getGrade();

    // update the new student's grade
    e.updateGrade(myStudents.at(myStudents.size()-1), newGrade);

    // print the new student's updated information to the file
    printAddedStudent(fp6, myStudents);

    // user the getInstructorId() method to get an instructor id
    std::string newInstructorID = e.getInstructorId();

    // update the new student's instructor
    e.updateInstructor(myStudents.at(myStudents.size()-1), newInstructorID);

    // print the new student's updated information to the file
    printAddedStudent(fp6, myStudents);

    // close the output files
    fclose(fp1);
    fclose(fp2);
    fclose(fp3);
    fclose(fp4);
    fclose(fp5);
    fclose(fp6);

    // return 0 to indicate successful termination
    return 0;
}