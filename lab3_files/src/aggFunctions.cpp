#include <cmath>
#include <iostream>
#include <map>
#include <vector>

#include "aggFunctions.h"
#include "readAndWrite.h"
#include "structures.h"

// function to create a student object
student createStudent(std::vector<std::vector<std::string>> myData, int i) {

    // use the student struct's constructor to create a student
    student myStudent (myData[i][0], std::stoi(myData[i][1]), myData[i][3], myData[i][5]);

    // return the created student
    return myStudent;
}

// function to create a term object
term createTerm(std::vector<std::vector<std::string>> myData, int i) {

    // use the term's constructor to create a term object
    term myTerm (myData[i][0], myData[i][3], myData[i][5]);

    // return the create term object
    return myTerm;
}

// function to create a group of students
std::vector<student> createStudentGroup(std::string inputFile1, std::string inputFile2, std::string inputFile3) {

    // declare a vector to hold the group of students
    std::vector<student> studentGroup;

    // read in 1115 data, 3115 data, and 3130 data
    std::vector<std::vector<std::string>> myData1115 = readData(inputFile1);
    std::vector<std::vector<std::string>> myData3115 = readData(inputFile2);
    std::vector<std::vector<std::string>> myData3130 = readData(inputFile3);

    // add 1115 students to studentGroup
    for(int i=0; i<myData1115.size(); i++) {

        // create a student from the 1115 data
        student myStudent = createStudent(myData1115, i);

        // add the student to the studentGroup
        studentGroup.push_back(myStudent);
    }

    // add 3115 students to studentGroup
    for(int i=0; i<myData3115.size(); i++) {

        // create a student from the 3115 data
        student myStudent = createStudent(myData3115, i);

        // add the student to the studentGroup
        studentGroup.push_back(myStudent);
    }

    // add 3130 students to studentGroup
    for(int i=0; i<myData3130.size(); i++) {

        // create a student from the 3130 data
        student myStudent = createStudent(myData3130, i);

        // add the student to the studentGroup
        studentGroup.push_back(myStudent);
    }

    // return the student group
    return studentGroup;
}

// function to create a group of term object
std::vector<term> createTermGroup(std::string inputFile1, std::string inputFile2, std::string inputFile3) {

    // declare a vector to hold the group of term objects
    std::vector<term> termGroup;

    // read in 1115 data, 3115 data, and 3130 data
    std::vector<std::vector<std::string>> myData1115 = readData(inputFile1);
    std::vector<std::vector<std::string>> myData3115 = readData(inputFile2);
    std::vector<std::vector<std::string>> myData3130 = readData(inputFile3);

    // add 1115 terms to termGroup
    for(int i=0; i<myData1115.size(); i++) {

        // create a term from the 1115 data
        term myTerm = createTerm(myData1115, i);

        // add the term to the termGroup
        termGroup.push_back(myTerm);
    }

    // add 3115 terms to termGroup
    for(int i=0; i<myData3115.size(); i++) {

        // create a term from the 3115 data
        term myTerm = createTerm(myData3115, i);

        // add the term to the termGroup
        termGroup.push_back(myTerm);
    }

    // add 3130 terms to termGroup
    for(int i=0; i<myData3130.size(); i++) {

        // create a term from the 3130 data
        term myTerm = createTerm(myData3130, i);

        // add the term to the termGroup
        termGroup.push_back(myTerm);
    }

    // return the term group
    return termGroup;
}

// function to format decimals to 3 decimal places
std::string formatThreeDecimalPlaces(double d) {

    // format the double that was passed in to 3 decimal places
    char buffer[50];
    sprintf(buffer, "%.3f", d);

    // return the formatted string
    return buffer;
}

// function to find the number of students for each instructor
std::map<std::string, int> countStudentsPerInstructor(std::vector<student> studentGroup, int courseNum) {

    // declare a map to hold the count of students per instructor
    std::map<std::string, int> instructorStudentCountMap;

    // loop through the students and increment the value associated with each instructor of a student
    if(courseNum == 0) {
        for(int i=0; i<studentGroup.size(); i++) {
            instructorStudentCountMap[studentGroup[i].instructorid]++;
        }
    }

    // loop through the students and increment the value associated with each instructor of a student for the course passed in
    else {
        for(int i=0; i<studentGroup.size(); i++) {
            if(studentGroup[i].courseno == courseNum) {
                instructorStudentCountMap[studentGroup[i].instructorid]++;
            }
        }
    }

    // return a map with each instructor and their count of students
    return instructorStudentCountMap;
}

// function to find the pass rate for each instructor
std::map<std::string, std::string> findPassRatePerInstructor(std::vector<student> studentGroup) {

    // initialize a map for the instructors and their total number of students
    std::map<std::string, int> instructorStudentCountMap = countStudentsPerInstructor(studentGroup);

    // create a map for the instructors and their count of passes
    std::map<std::string, int> instructorPassMap;

    // create a map for the instructors and their pass rates
    std::map<std::string, std::string> instructorPassRateMap;

    // loop through the students and increment the value associated with each instructor of a student who passed
    // all grades besides F, W, WD, WU, WN, AUD, NC, and FIN are considered to have passed
    for(int i=0; i<studentGroup.size(); i++) {
        if(studentGroup[i].grade != "F" && 
        studentGroup[i].grade != "W" && 
        studentGroup[i].grade != "WD" && 
        studentGroup[i].grade != "WU" && 
        studentGroup[i].grade != "WN" &&
        studentGroup[i].grade != "AUD" &&
        studentGroup[i].grade != "NC" &&
        studentGroup[i].grade != "FIN")
            instructorPassMap[studentGroup[i].instructorid]++;
    }

    // calculate the pass rate of each instructor and add the pass rates to the instructorPassRateMap
    for(auto x: instructorStudentCountMap) {
        for(auto y: instructorPassMap) {
            if(x.first == y.first) {

                //instructorPassRateMap.insert(std::pair<std::string, double> (x.first, (double)y.second/x.second));
                instructorPassRateMap.insert(std::pair<std::string, std::string> (x.first, formatThreeDecimalPlaces((double)y.second/x.second)));
            }
        }
    }

    // return the map of instructors and their pass rate
    return instructorPassRateMap;
}

// function to find the pass rate for each instructor for each course
std::map<std::string, std::string> findPassRatePerInstructorPerCourse(std::vector<student> studentGroup, int courseNum) {

    // initialize a map for the instructors and their total number of students
    std::map<std::string, int> instructorStudentCountMap = countStudentsPerInstructor(studentGroup, courseNum);
    
    // create a map for the instructors and their count of passes
    std::map<std::string, int> instructorPassMap;

    // create a map for the instructors and their pass rates
    std::map<std::string, std::string> instructorPassRateMap;

    // loop through the students and increment the value associated with each instructor of a student who passed
    // in the course number that was passed to the function
    // all grades besides F, W, WD, WU, WN, AUD, NC, and FIN are considered to have passed
    for(int i=0; i<studentGroup.size(); i++) {
        if(studentGroup[i].grade != "F" && 
        studentGroup[i].grade != "W" && 
        studentGroup[i].grade != "WD" && 
        studentGroup[i].grade != "WU" && 
        studentGroup[i].grade != "WN" &&
        studentGroup[i].grade != "AUD" &&
        studentGroup[i].grade != "NC" &&
        studentGroup[i].grade != "FIN" &&
        studentGroup[i].courseno == courseNum)
            instructorPassMap[studentGroup[i].instructorid]++;
    }

    // calculate the pass rate of each instructor and add the pass rates to the instructorPassRateMap
    for(auto x: instructorStudentCountMap) {
        for(auto y: instructorPassMap) {
            if(x.first == y.first) {
                instructorPassRateMap.insert(std::pair<std::string, std::string> (x.first, formatThreeDecimalPlaces((double)y.second/x.second)));
            }
        }
    }

    // return the map of instructors and their pass rate
    return instructorPassRateMap;
}

// function to find the W rate for each instructor
std::map<std::string, std::string> findWRatePerInstructor(std::vector<student> studentGroup) {

    // initialize a map for the instructors and their total number of students
    std::map<std::string, int> instructorStudentCountMap = countStudentsPerInstructor(studentGroup);
    
    // create a map for the instructors and their count of Ws
    std::map<std::string, int> instructorWMap;

    // create a map for the instructors and their W rates
    std::map<std::string, std::string> instructorWRateMap;

    // loop through the students and increment the value associated with each instructor of a student who received a W
    // W, WD, WU, and WN are considered Ws
    for(int i=0; i<studentGroup.size(); i++) {
        if(studentGroup[i].grade == "W" || 
        studentGroup[i].grade == "WD" || 
        studentGroup[i].grade == "WU" || 
        studentGroup[i].grade == "WN")
            instructorWMap[studentGroup[i].instructorid]++;
    }

    // calculate the W rate of each instructor and add the W rates to the instructorWRateMap
    for(auto x: instructorStudentCountMap) {
        for(auto y: instructorWMap) {
            if(x.first == y.first) {
                instructorWRateMap.insert(std::pair<std::string, std::string> (x.first, formatThreeDecimalPlaces((double)y.second/x.second)));
            }
        }
    }

    // return the map of instructors and their W rate
    return instructorWRateMap;
}

// function to find the W rate for each instructor for each course
std::map<std::string, std::string> findWRatePerInstructorPerCourse(std::vector<student> studentGroup, int courseNum) {

    // initialize a map for the instructors and their total number of students
    std::map<std::string, int> instructorStudentCountMap = countStudentsPerInstructor(studentGroup, courseNum);
    
    // create a map for the instructors and their count of Ws
    std::map<std::string, int> instructorWMap;

    // create a map for the instructors and their W rates
    std::map<std::string, std::string> instructorWRateMap;

    // loop through the students and increment the value associated with each instructor of a student who received a W
    // in the course number that was passed to the function
    // W, WD, WU, and WN are considered Ws
    for(int i=0; i<studentGroup.size(); i++) {
        if(studentGroup[i].grade == "W" && 
        studentGroup[i].grade == "WD" && 
        studentGroup[i].grade == "WU" && 
        studentGroup[i].grade == "WN" &&
        studentGroup[i].courseno == courseNum)
            instructorWMap[studentGroup[i].instructorid]++;
    }

    // calculate the W rate of each instructor and add the W rates to the instructorWRateMap
    for(auto x: instructorStudentCountMap) {
        for(auto y: instructorWMap) {
            if(x.first == y.first) {
                instructorWRateMap.insert(std::pair<std::string, std::string> (x.first, formatThreeDecimalPlaces((double)y.second/x.second)));
            }
        }
    }

    // return the map of instructors and their W rate
    return instructorWRateMap;
}

std::string passRatePerTerm(std::vector<term> termGroup, std::vector<std::string> termIds) {

    // declare variables
    double totalStudents = 0;
    double totalPassingStudents = 0;

    // loop through the term objects and if a student was matriculated during the passed in term, increment totalStudents
    // if the student passed during that term, increment totalPassingStudents
    for(int i=0; i<termGroup.size(); i++) {
        for(int j=0; j<termIds.size(); j++) {

            // increment totalStudents for each student
            if(termGroup[i].termid == termIds[j]) {
                totalStudents++;

                // increment totalPassingStudents for each student who passed
                if(termGroup[i].grade != "F" && 
                termGroup[i].grade != "W" && 
                termGroup[i].grade != "WD" && 
                termGroup[i].grade != "WU" && 
                termGroup[i].grade != "WN" &&
                termGroup[i].grade != "AUD" &&
                termGroup[i].grade != "NC" &&
                termGroup[i].grade != "FIN") {
                    totalPassingStudents++;
                }
            }
        }
    }

    // calculate the pass rate per term
    double passRatePerTermValue = totalPassingStudents / totalStudents;

    // check to ensure that the passRatePerTermValue has a value
    // if passRatePerTermValue does not have a value, set passRatePerTermValue to -1
    if(isnan(passRatePerTermValue)) {
        passRatePerTermValue = -1;
    }

    // return the value of the pass rate per term
    return formatThreeDecimalPlaces(passRatePerTermValue);
}

