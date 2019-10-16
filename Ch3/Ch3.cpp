//
//  Ch3.cpp
//  
/*  Created by Laura Gong on 10/16/19.
    Program obtains midterm and final grades and then computes final grade from midterm, final, and median of homework grades.
 */

#include <iomanip>  // needed for setprecision
#include<ios>  // needed for streamsize
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    // Ask for student name
    cout << "Please enter your first name: ";
    string name;
    cin >> name;
    cout << "Hello, " << name << "!" << endl;
    
    // Ask for midterm and final grades
    cout << "Please enter your midterm and final exam grades: ";
    double midterm, final; // Always use double for floating point numbers
    cin >> midterm >> final;
    
    // Ask for homework grades
    cout << "Enter all your homework grades, "
    "followed by end-of-file: ";
    
    // A variable into which to read
    // Don't need to initialize x since the first thing we do is read into it and overwrite it
    double x;
    
    // Initialize vector to store homework grades
    vector<double> homework;
    
    // Loop invariant: We have put all grades that have been read in into homework vector
    while (cin >> x) {
        homework.push_back(x);
    }
    
    // Obtain the size of homework vector
    typedef vector<double>::size_type vec_sz;  // vec_sz is a synonym for vector<double>::size_type
    vec_sz size = homework.size();  // size (type of vec_sz) is the size of homework vector
    
    // Check if no homework grades have been inputted
    if (size == 0)
    {
        cout << "Please enter some homework grades!" << endl;
        return 1;  // Exit with error
    }
    
    // Sort the vector nondecreasing
    sort(homework.begin(), homework.end());  // homework.end() is the element past the last element of homework- [)
    
    // Find or calculate the median
    double median;
    
    // Check if homework vector has even number of elements
    vec_sz mid = size/2;
    median = size % 2 == 0? (homework[mid-1]+homework[mid])/2 : homework[mid];
    
    // Write the result:
    streamsize prec = cout.precision();  // cout's precision for floating point
    cout << "Your final grade is " << setprecision(3) << 0.2 * midterm + 0.4 * final + 0.4 * median
    << setprecision(prec) << endl;
    
    return 0;
}
