//
//  grade.cpp
//  
//
//  Created by Laura Gong on 10/21/19.
//

#include <stdexcept> // needed for exceptions
#include "grade.h"
#include "median.h"  // Needed to use median function

using namespace std;

// Function to calculate the final grade.  Parameter is const reference to hw vector- Don't need
// to worry about anything changing the homework grade vector- Also can save time by passing
// in the reference and not copying it in
double final_grade (double midterm, double final, const vector<double>& hw)
{
    // Check if hw vector is empty
    if (hw.size() == 0)
    {
        throw domain_error("No homework grades were entered. Student has done no homework.");
    }
    return (0.2*midterm + 0.4*final + 0.4*median(hw));
}

// Will not change student_info object that is passed in
// Does not need throw domain_error because the domain_error from final_grade will get passed through here and go up to the higher function
double grade (const student_info& student)
{
    return final_grade(student.midterm,student.final,student.homework);
}
