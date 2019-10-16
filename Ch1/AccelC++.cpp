// AccelC++.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>  // Add standard library string header file

int main() {
	std::cout << "Please enter your first name: ";
	std::string name; // Initialize a name variable of type string
	std::cin >> name;

	// Initialize the string variables as constants
	const std::string greeting = "Hello, " + name + "!";
	const std::string greeting_line = "* " + greeting + " *";
	const std::string star_line (greeting_line.size(), '*');  // needs to be a character literal to fill
	const std::string blank (greeting.size(), ' ');
	const std::string blank_line = "* " + blank + " *";

	// Write each line of greeting out manually
	std::cout << std::endl; // Empty line
	std::cout << star_line << std::endl;
	std::cout << blank_line << std::endl;
	std::cout << greeting_line << std::endl;
	std::cout << blank_line << std::endl;
	std::cout << star_line << std::endl;

	return 0;

}