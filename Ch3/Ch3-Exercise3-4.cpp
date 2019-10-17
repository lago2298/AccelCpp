//
//  Ch3-Exercise3-4.cpp
//  
/*  Created by Laura Gong on 10/16/19.
	A program to report the length of the longest and shortest strings in the input
 */

#include <iomanip>  // needed for setprecision
#include <ios>  // needed for streamsize
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
	// Ask for words
	cout << "Enter some words: ";

	// Save the longest and shortest lengths and respective strings
	typedef string::size_type string_length;
	string_length longest = 0;
	string longest_string;
	string_length shortest = 0;
	string shortest_string;
	bool first_element = true;

	string x;

	// Loop invariant: Each string that has successfully come through input has had the length compared
	// to the longest and shortest lengths so far, and the longest and shortest lengths and and their
	// respective strings have been updated accordingly
	while (cin >> x)
	{
		if (first_element) {
			shortest = longest = x.size();
			shortest_string = longest_string = x;
			first_element = false;
		}
		else {
			if (x.size() > longest)
			{
				longest = x.size();
				longest_string = x;
			}
			if (x.size() < shortest) {
				shortest = x.size();
				shortest_string = x;
			}
		}
	}

	cout << "The longest word is: " << longest_string << " with length: " << longest << endl;
	cout << "The shortest word is: " << shortest_string << " with length: " << shortest << endl;


	return 0;
}
