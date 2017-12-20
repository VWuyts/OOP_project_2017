/*
 *	Lab assignment for course Object Oriented Programming 2017
 *
 *	Véronique Wuyts
 *	Bachelor Elektronica-ICT option Application Development
 *	Thomas More campus De Nayer
 *
 * Implementation of functions that request user input for Use Case functions
 */

// includes
#include <iomanip>
#include <iostream>
#include "functionsUserInput.h"

// print a line of the given length
void printLine(size_t length)
{
	for (size_t i{ 0 }; i < length; i++)
	{
		std::cout << "-";
	}
	std::cout << std::endl;
} // end function printLine

// request boolean input
bool requestBool(char category[], char info[])
{
	char boolStr[CHARS_BOOL]{ "" };

	if (strcmp(category, "") != 0)
	{
		std::cout << "  Has the " << category << " ";
	}
	std::cout << info << "? (yes/no): ";
	std::cin.getline(boolStr, CHARS_BOOL, '\n');
	if (std::cin.fail())
	{
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}
	while (boolStr[0] != 'y' && boolStr[0] != 'Y' && boolStr[0] != 'n' && boolStr[0] != 'N')
	{
		std::cout << "    Please give 'yes' or 'no': ";
		std::cin.getline(boolStr, CHARS_BOOL, '\n');
		if (std::cin.fail())
		{
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}
	}

	if (boolStr[0] == 'y' || boolStr[0] == 'Y') return true;
	return false;
} // end function requestBool

// request index input
size_t requestIndex(char category[], size_t noOptions)
{
	size_t index{ 0 };

	std::cout << "Your"<< (strcmp(category, "") == 0 ? "" : " ") << category << " choice: ";
	std::cin >> index;
	while (std::cin.fail() || index < 1 || index >noOptions)
	{
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cout << "  Please enter a number between 1 and " << noOptions << ": ";
		std::cin >> index;
	}
	std::cin.clear();
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	
	return index;
} // end function requestIndex

// request integer input
int requestInt(char info[])
{
	int number{ 0 };

	std::cout << "  " << info << ": ";
	std::cin >> number;
	while (std::cin.fail())
	{
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cout << "    Please enter an integer: ";
		std::cin >> number;
	}
	std::cin.clear();
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');;

	return number;
} // end function requestIndex

// request string input
void requestString(char info[], char input[], size_t size)
{
	std::cout << "  " << info << ": ";
	std::cin.getline(input, size, '\n');
	if (std::cin.fail())
	{
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}
	while (strcmp(input, "") == 0)
	{
		std::cout << "    Please give the " << info << ": ";
		std::cin.getline(input, size, '\n');
		if (std::cin.fail())
		{
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}
	}
} // end function requestString
