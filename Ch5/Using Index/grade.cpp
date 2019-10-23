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

// Returns true if student failed (failing grade is < 50)
bool fgrade (const student_info& student)
{
    return (grade(student) < 50);
}

// Extracts the failed students from the main student vector
vector<student_info> extract_fails (vector<student_info>& all_students)
{
    // Create a failed student vector
    vector<student_info> fail;
    // Create an index that will help iterate through vector
    vector<student_info>::size_type i = 0;
    
    // Iterate through the main student vector and push failed students to the fail vector.
    // Erase failed students from main student vector
    // Loop invariant: i is pointing to the current position whose element we are looking at to see if the student stored in that element has a failing grade.  At this point, all failed students that we have encountered have been removed from the main student vector and added to the fail vector
    while (i != all_students.size()) // size of all_students vector will change
    {
        if (fgrade(all_students[i]))
        {
            fail.push_back(all_students[i]);
            all_students.erase(all_students.begin()+i); // erase function uses the position of the element that you want to erase
        } else {
            i++;
        }
    }
    
    return fail;
}
