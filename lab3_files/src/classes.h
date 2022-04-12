#ifndef DATE_H
#define DATE_H

#include "structures.h"

// Enrollment class with methods for enrollment operations
class Enrollment {

    public:

        // default constructor for an enrollment object
        Enrollment();

        // constructor to define a new enrollment by creating a student object with a new course
        Enrollment(std::string sid, int cn, std::vector<student> &myStudents);

        // updateGrade() method to update a student's grade
        void updateGrade(student& myStudent, std::string newGrade);

        // updateInstructor() method to update a student's instructor
        void updateInstructor(student& myStudent, std::string newInstructor);

        // getID() method to get a student id
        std::string getId();

        // getCourse() method to get a course
        int getCourse();

        // getGrade() method to get a grade
        std::string getGrade();

        // getInstructorId() method to get an instructor id
        std::string getInstructorId();
};

#endif