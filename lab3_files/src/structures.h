#ifndef STRUCTURES_H
#define STRUCTURES_H

# include <string>

// student struct with EMPLID, course number, instructor ID, and grade
struct student {
    std::string emplid;
    int courseno;
    std::string instructorid;
    std::string grade;

    // student constructor
    student(std::string sid, int cn, std::string iid, std::string g) {
        emplid = sid;
        courseno = cn;
        instructorid = iid;
        grade = g;
    }
};

#endif