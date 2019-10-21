// median.h file

//RULE OF THUMB: only put in header files the minimum you asbolutely need- if something is used in the header file's cpp file, #include it in the cpp file only, not here
// Use std::blank here because you don't know if user has the "using namespace std" statement

#ifndef GUARD_median_h
#define GUARD_median_h

#include <vector> // Needed because vector is declared in the function parameter

double median (std::vector<double> values);  // NOTE: use std::vector here because you don't know if user has the "using namespace std" statement

#endif /* median_h */
