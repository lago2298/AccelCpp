//
//  student_info.cpp
//  
//
//  Created by Laura Gong on 10/21/19.
//

#include "student_info.h"

using namespace std;

// Function to pass into the sort function to compare elements based on student name alphabetical order
bool compare (const student_info& x, const student_info& y)
{
    return x.name < y.name;
}

// Function to read in homework grades
// Need to pass in reference to istream object and also change it (clear input so normal behavior can continue)
// Also need to pass in reference to homework vector because will be pushing elements to the vector
istream& read_hw (istream& in, vector<double>& hw)
{
    // If istream object is ready- keeps istream object in state it was in (error or no error)
    if (in)
    {
        // Clear the homework vector of any old elements
        hw.clear();
        double x;
        // Loop invariant: All successfully inputted elements have been pushed to homework vector
        while(in >> x)
        {
            hw.push_back(x);
        }
        // Clear the stream so input will work for next student
        in.clear();
    }
    return in;
}

// Read in student information into student_info object
istream& read_info (istream& in, student_info& student)
{
    in >> student.name >> student.midterm >> student.final;
    // Assuming that the following called function makes sure that istream object "in" state is preserved
    read_hw(in, student.homework);  // Read and store all homework grades
    return in;
}
