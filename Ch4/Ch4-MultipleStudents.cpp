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

using namespace std;

// Data Structure for Student Info
struct student_info {
    string name;
    double midterm, final;
    vector<double> homework;
};

// Function to calculate the median homework grade, returns the median
// Do not want to change homework grades vector during the sort, so copy in homeowork grade values
double median (vector<double> values)
{
    typedef vector<double>::size_type vec_sz;
    vec_sz vector_size = values.size();
    // Check if the vector is empty
    if (vector_size == 0)
    {
        throw domain_error("median of an empty vector");  // A throw will halt execution at this point and pass to other part of program that calls this function
    }
    // Sort the vector in nondecreasing order
    sort(values.begin(), values.end());
    
    // If the number of values are even, take the average of the two middle values
    // If the number of values are odd, take the middle value as the median
    vec_sz mid = vector_size/2;
    return vector_size % 2 == 0? (values[mid]+values[mid-1])/2 : values[mid];
}

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
    
    // TODO: Sort Student Info objects in vector alphabetically by name
    
    
    // Print final grades for each student
    for (vec_stu_info_size index = 0; index < student_vector.size(); index++)
    {
        
        cout << "The final grade for " << student_vector[index].name << " is: ";
        
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
