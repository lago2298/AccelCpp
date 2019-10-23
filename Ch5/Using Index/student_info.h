//
//  student_info.h
//

//RULE OF THUMB: only put in header files the minimum you asbolutely need- if something is used in the header file's cpp file, #include it in the cpp file only, not here
// Use std::blank here because you don't know if user has the "using namespace std" statement

#ifndef GUARD_student_info_h
#define GUARD_student_info_h

#include <iostream>
#include <vector>
#include <string>

// Data Structure for Student Info
struct student_info {
    std::string name;
    double midterm, final;
    std::vector<double> homework;
};

bool compare (const student_info& x, const student_info& y);

std::istream& read_hw (std::istream& in, std::vector<double>& hw);

std::istream& read_info (std::istream& in, student_info& student);

#endif /* GUARD_student_info_h */
