/*
 *	Lab assignment for course Object Oriented Programming 2017
 *
 *	Véronique Wuyts
 *	Bachelor Elektronica-ICT option Application Development
 *	Thomas More campus De Nayer
 *
 *	Function main
 */

// includes
#include "main.h"

int main(void)
{
	int user { 0 };
	int option{ 0 };

	user = login();

	option = menu(user);

	return 0;
} // end main


// Utility functions

// Function login returns the user as an integer in [1, 3] or 4 to quit.
int login(void)
{
	int user{ 0 };

	cout << "Please login to continue:\n"
		 << "1 = Customer\n"
		 << "2 = Employee\n"
		 << "3 = Owner\n"
		 << "4 = Close application\n" << endl;
	cin >> user;
	cin.clear(); // clear error flag; ref: Stack Overflow
	cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // ignore rest of input buffer or rest of line; ref: Stack Overflow

	while (0 < user || user > 4)
	{
		cout << "Please enter a number between 1 and 4" << endl;
		cin >> user;
		cin.clear(); // clear error flag; ref: Stack Overflow
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // ignore rest of input buffer or rest of line; ref: Stack Overflow
	}

	return user;
}

// Function menu 
int menu(int user)
{
	int option{ 0 };

	return option;
}