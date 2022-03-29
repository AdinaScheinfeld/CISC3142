#include <vector>
#include <iostream>
#include <map>

#include "readAndWrite.h"
#include "structures.h"
#include "aggFunctions.h"

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
std::vector<student> createStudentGroup() {

    // declare a vector to hold the group of students
    std::vector<student> studentGroup;

    // read in 1115 data, 3115 data, and 3130 data
    std::vector<std::vector<std::string>> myData1115 = readData("../data/allFiles/1115.csv");
    std::vector<std::vector<std::string>> myData3115 = readData("../data/allFiles/3115.csv");
    std::vector<std::vector<std::string>> myData3130 = readData("../data/allFiles/3130.csv");

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
std::vector<term> createTermGroup() {

    // declare a vector to hold the group of term objects
    std::vector<term> termGroup;

    // read in 1115 data, 3115 data, and 3130 data
    std::vector<std::vector<std::string>> myData1115 = readData("../data/allFiles/1115.csv");
    std::vector<std::vector<std::string>> myData3115 = readData("../data/allFiles/3115.csv");
    std::vector<std::vector<std::string>> myData3130 = readData("../data/allFiles/3130.csv");

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

// function to find the pass rate for each instructor
std::map<std::string, double> findPassRatePerInstructor(std::vector<student> studentGroup) {

    // initialize a map for the instructors and their total number of students
    std::map<std::string, int> instructorStudentCountMap = countStudentsPerInstructor(studentGroup);

    // create a map for the instructors and their count of passes
    std::map<std::string, int> instructorPassMap;

    // create a map for the instructors and their pass rates
    std::map<std::string, double> instructorPassRateMap;

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
                instructorPassRateMap.insert(std::pair<std::string, double> (x.first, (double)y.second/x.second));
            }
        }
    }

    // return the map of instructors and their pass rate
    return instructorPassRateMap;
}

// function to find the pass rate for each instructor for each course
std::map<std::string, double> findPassRatePerInstructorPerCourse(std::vector<student> studentGroup, int courseNum) {

    // initialize a map for the instructors and their total number of students
    std::map<std::string, int> instructorStudentCountMap = countStudentsPerInstructor(studentGroup, courseNum);
    
    // create a map for the instructors and their count of passes
    std::map<std::string, int> instructorPassMap;

    // create a map for the instructors and their pass rates
    std::map<std::string, double> instructorPassRateMap;

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
                instructorPassRateMap.insert(std::pair<std::string, double> (x.first, (double)y.second/x.second));
            }
        }
    }

    // return the map of instructors and their pass rate
    return instructorPassRateMap;
}

// function to find the W rate for each instructor
std::map<std::string, double> findWRatePerInstructor(std::vector<student> studentGroup) {

    // initialize a map for the instructors and their total number of students
    std::map<std::string, int> instructorStudentCountMap = countStudentsPerInstructor(studentGroup);
    
    // create a map for the instructors and their count of Ws
    std::map<std::string, int> instructorWMap;

    // create a map for the instructors and their W rates
    std::map<std::string, double> instructorWRateMap;

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
                instructorWRateMap.insert(std::pair<std::string, double> (x.first, (double)y.second/x.second));
            }
        }
    }

    // return the map of instructors and their W rate
    return instructorWRateMap;
}

// function to find the W rate for each instructor for each course
std::map<std::string, double> findWRatePerInstructorPerCourse(std::vector<student> studentGroup, int courseNum) {

    // initialize a map for the instructors and their total number of students
    std::map<std::string, int> instructorStudentCountMap = countStudentsPerInstructor(studentGroup, courseNum);
    
    // create a map for the instructors and their count of Ws
    std::map<std::string, int> instructorWMap;

    // create a map for the instructors and their W rates
    std::map<std::string, double> instructorWRateMap;

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
                instructorWRateMap.insert(std::pair<std::string, double> (x.first, (double)y.second/x.second));
            }
        }
    }

    // return the map of instructors and their W rate
    return instructorWRateMap;
}

double passRatePerTerm(std::vector<term> termGroup, std::vector<std::string> termIds) {

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

    std::cout << totalStudents << " " << totalPassingStudents << std::endl;

    // return the pass rate for the passed in term
    return totalPassingStudents / totalStudents;
}

