//
//  Ch3-Exercise3-3.cpp
//  
/*  Created by Laura Gong on 10/16/19.
    A program to count how many times each distinct word apppears in the input
 and then print them and their counts
 */

#include <iomanip>  // needed for setprecision
#include<ios>  // needed for streamsize
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    // Ask for words
    cout << "Enter some words: ";
    
    // Vectors to contain the words and their counts
    vector<string> words;
    vector<int> counts;
    
    // Vector size type for string vector
    typedef vector<string>::size_type vec_string_size;
    
    // String variable to save the inputted word
    string s;
    
    // Take in the words
    // Loop invariant: We have saved all words that are inputted into the words vector, and saved their counts into the counts vector
    while(cin >> s)
    {
        // Boolean to check whether string has been found in vector yet
        bool found = false;
        
        // Check if the word has been saved into the words vector already, if yes, then update the count vector for that index

        for (vec_string_size index = 0; index < words.size(); index++)
        {
            if (words[index] == s)
            {
                counts[index]++;
                found = true;  // Found the string in the vector
            }
        }
        
        // If we didn't find the string, the word doesn't exist in the vector yet, push it and update count to 1
        if (found == false)
        {
            words.push_back(s);
            counts.push_back(1);
        }
    }
    
    for (vec_string_size i = 0; i < words.size(); ++i)
        cout << words[i] << " appeared " << counts[i] << " times" << endl;
    
    
    return 0;
}
