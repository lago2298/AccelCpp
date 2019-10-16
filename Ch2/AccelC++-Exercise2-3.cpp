// AccelC++.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>  // Add standard library string header file

int main() {

	std::cout << "Please enter your first name: ";
	std::string name;
	std::cin >> name;
	std::cout << "How much spacing would you like between the greeting and the border?: ";
	int pad;
	std::cin >> pad;
	std::cout << std::endl; // Extra line

	// Build out the greeting string
	const std::string greeting = "Hello, " + name + "!";

	// Set variables for row and column size
	const int row = 3 + 2 * pad; // 1 row for greeting string + 2 blank spaces (pad) + 2 stars
	// Use string::size_type when dealing with string sizes- safe practice
	const std::string::size_type column = greeting.size() + 2 * pad + 2; // Size of greeting string + 2 blank spaces (pad) + 2 stars

	// Loop invariant = r is the row number that we are currently writing characters at
	for (int r = 0; r < row; r++)
	{
		std::string::size_type c = 0;
		// Loop invariant = c is the column number that we are currently writing characters at
		while (c != column)
		{
			// If we are at the location to start writing our greeting string, then write it
			if (r == pad + 1 && c == pad + 1)
			{
				std::cout << greeting;
				c += greeting.size();
			}
			else {
				// If the character is on the border, then it should be a "*"
				if (r == 0 || r == row - 1 || c == 0 || c == column - 1) {
					std::cout << "*";
				}
				else {
					// Write blanks
					std::cout << " ";
				}
				c++;
			}
		}
		std::cout << std::endl;
	}
	return 0;
}