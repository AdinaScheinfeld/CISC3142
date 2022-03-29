#ifndef AGGFUNCTIONS_H
#define AGGFUNCTIONS_H

// countStudentsPerInstructor() function to count the number of students for each instructor
std::map<std::string, int> countStudentsPerInstructor(std::vector<student> studentGroup, int courseNum=0);

#endif