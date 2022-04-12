#ifndef DATE_H
#define DATE_H

#include "structures.h"

// Enrollment class with methods for enrollment operations
class Enrollment {

    public:
    //private:

        // default constructor for an enrollment object
        Enrollment();

        // constructor to define a new enrollment by creating a student object with a new course
        Enrollment(std::string sid, int cn, std::vector<student> &myStudents);

    //public:

        // updateGrade() method to update a student's grade
        void updateGrade(student& myStudent, std::string newGrade);

        // updateInstructor() method to update a student's instructor
        void updateInstructor(student& myStudent, std::string newInstructor);
};

#endif