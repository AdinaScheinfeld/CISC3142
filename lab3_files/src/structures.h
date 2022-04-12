#ifndef STRUCTURES_H
#define STRUCTURES_H

# include <string>

// student struct with EMPLID, course number, instructor ID, and grade
struct student {
    std::string emplid;
    int courseno;
    std::string instructorid;
    std::string grade;

    // student constructor when provided an emplid, course number, instructor id, and grade
    student(std::string sid, int cn, std::string iid, std::string g) {
        emplid = sid;
        courseno = cn;
        instructorid = iid;
        grade = g;
    }

    // student constructor when provided only an emplid and course number
    student(std::string sid, int cn) {
        emplid = sid;
        courseno = cn; 
        instructorid = "Unknown";
        grade = "Unknown";
    }

};

// term struct with EMPLID, termid, grade
struct term {
    std::string emplid;
    std::string termid;
    std::string grade;

    // term constructor
    term(std::string sid, std::string tid, std::string g) {
        emplid = sid;
        termid = tid;
        grade = g;
    }
};

#endif