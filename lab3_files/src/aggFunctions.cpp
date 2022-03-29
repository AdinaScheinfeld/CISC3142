#include <vector>
#include <map>

#include "structures.h"

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

