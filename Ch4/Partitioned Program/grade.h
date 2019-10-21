//
//  grade.h
//

//RULE OF THUMB: only put in header files the minimum you asbolutely need- if something is used in the header file's cpp file, #include it in the cpp file only, not here
// Use std::blank here because you don't know if user has the "using namespace std" statement

#ifndef GUARD_grade_h
#define GUARD_grade_h

#include <vector>
#include "student_info.h"

double final_grade (double midterm, double final, const std::vector<double>& hw);

double grade (const student_info& student);

#endif /* GUARD_grade_h */
