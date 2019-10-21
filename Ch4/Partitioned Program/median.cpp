//
//  median.cpp
//  
//
//  Created by Laura Gong on 10/21/19.
//

#include "median.h"

#include <algorithm>
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
