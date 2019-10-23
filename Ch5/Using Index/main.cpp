//
/*  Ch4.cpp Obtaining Final Grades for Many Students
    Objective: Create a program that takes in multiple student's information:
        1. Name
        2. Midterm Grade
        3. Final Grade
        4. Homework Grades vector
 The program should calculate the final grade for each student and print the names and final grades on the output with final grades left adjusted to match up to the line, and also sorted alphabetically according to name.
*/

#include <iomanip>  // needed for setprecision
#include <ios>  // needed for streamsize
#include <iostream>
#include <string>
#include <vector>
#include <stdexcept> // needed for exceptions
#include <algorithm>

// User defined header files
#include "student_info.h"
#include "grade.h"

using namespace std;

int main()
{
    // Ask for student names and information
    cout << "Please enter each student name, followed by the midterm grade, final grade, and their homework grades: ";
    
    // Declare vector of student_info elements
    vector<student_info> student_vector;
    typedef vector<student_info>::size_type vec_stu_info_size;
    // Declare a student_info object
    student_info student;
    // Declare variable to hold the size of the name with the maximum length (for report printing purposes)
    typedef string::size_type string_size;
    string_size maxlength_name= 0;
    
    // Read in the student_info
    while (read_info(cin, student))
    {
        // If student_info was written in correctly (all elements- name/midterm/final/homework), then push to student_vector
        student_vector.push_back(student);
        // Obtain current maximum length for student names
        if (student.name.size() > maxlength_name)
        {
            maxlength_name = student.name.size();
        }
    }
    
    // Sort Student Info objects in vector alphabetically by name
    sort(student_vector.begin(), student_vector.end(), compare);
    
    // Print final grades for each student
    for (vec_stu_info_size index = 0; index < student_vector.size(); index++)
    {
        
        try {
            extract_fails(student_vector);
        } catch (domain_error e)
        {
            cout << e.what() << endl;
            return 1;
        }
        
        cout << student_vector[index].name << string(maxlength_name + 1 - student_vector[index].name.size(), ' ');
        
        try {
            double finalgrade = grade(student_vector[index]); // Rule of thumb: only one side effect (exception) per line of code
            streamsize prec = cout.precision(); // Obtain default precision for cout
            cout << setprecision(3) << finalgrade << setprecision(prec) << endl; // With cout you don't know what order code is going to be executed
        } catch (domain_error e)
        {
            cout << e.what() << endl;
            return 1;
        }
    }
    
    return 0;
}
