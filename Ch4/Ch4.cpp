//
//  Ch4.cpp Separating Functionality into Functions
//

#include <iomanip>  // needed for setprecision
#include <ios>  // needed for streamsize
#include <iostream>
#include <string>
#include <vector>
#include <stdexcept> // needed for exceptions

using namespace std;

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

// Function to read in homework grades
// Need to pass in reference to istream object and also change it (clear input so normal behavior can continue)
// Also need to pass in reference to homework vector because will be pushing elements to the vector
istream& read_hw (istream& in, vector<double>& hw)
{
    // If istream object is ready
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


int main()
{
    // Ask for student name
    cout << "What is your name?: ";
    string name;
    cin >> name;
    
    // Ask for midterm and final grades
    cout << endl;
    double midterm, final;
    cout << "Please enter your midterm and final grades: ";
    cin >> midterm >> final;
    
    cout << "Please enter homework grades: ";
    
    // Read in the homework grades
    vector<double> homework;
    read_hw(cin,homework);

    try {
        double finalgrade = final_grade(midterm,final,homework); // Rule of thumb: only one side effect (exception) per line of code
        streamsize prec = cout.precision(); // Obtain default precision for cout
        cout << "Your final grade is " << setprecision(3) << finalgrade << setprecision(prec) << endl; // With cout you don't know what order code is going to be executed
    } catch (domain_error)
    {
        cout << endl << "You must enter your grades.  Please try again." << endl;
        return 1;
    }
    
    return 0;
}
