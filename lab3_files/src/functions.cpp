#include <vector>
#include <iostream>
#include <map>

#include "readAndWrite.h"
#include "structures.h"

// createStudent() function
student createStudent(std::vector<std::vector<std::string>> myData, int i) {

    // use the student struct's constructor to create a student
    student myStudent (myData[i][0], std::stoi(myData[i][1]), myData[i][3], myData[i][5]);

    // return the created student
    return myStudent;

}

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

// findNumPassesPerInstructor() function
std::map<std::string, int> findNumPassesPerInstructor(std::vector<student> studentGroup) {

    // create a map for the instructors
    std::map<std::string, int> instructorMap;

    // insert each instructor into the map
    for(int i=0; i<studentGroup.size(); i++) {
        instructorMap.insert(std::pair<std::string, int> (studentGroup[i].instructorid, 0));
    }

    // loop throught the students and increment the value associated with each instructor of a student who passed
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
            instructorMap[studentGroup[i].instructorid]++;
    }

    // return the map of instructors and their count of passes
    return instructorMap;
}