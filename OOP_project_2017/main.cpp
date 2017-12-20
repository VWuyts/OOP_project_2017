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
	int role{ 0 };
	int option{ 0 };
	int suboption{ 0 };
	const char* roles[ROLES]{ "Customer", "Employee", "Owner" };
	const int rolesPn[ROLES]{ PN_CUSTOMER, PN_EMPLOYEE, PN_OWNER };
	const char* menuOptions[CATS]{ "Accommodation", "Booking", "Customer", "Park" };
	const int menuOptionsPn[CATS]{ PN_EMPLOYEE * PN_OWNER, PN_CUSTOMER * PN_EMPLOYEE, PN_CUSTOMER * PN_EMPLOYEE, PN_OWNER };
	const char* subOptions[CATS][FCTNS]
	{
		{ "Check accommodation", "Create accommodation", "Change accommodation", "Delete accommodation" },
		{ "Check booking", "Create booking", "Change booking", "Delete booking" },
		{ "Check customer", "Create customer", "Change customer", "Delete customer" },
		{ "Check park", "Create park", "Change park", "Delete park" }
	};
	const int subOptionsPn[CATS][FCTNS]
	{
		{ PN_EMPLOYEE * PN_OWNER, PN_OWNER, PN_EMPLOYEE * PN_OWNER, PN_OWNER },
		{ PN_CUSTOMER * PN_EMPLOYEE, PN_CUSTOMER * PN_EMPLOYEE, PN_CUSTOMER * PN_EMPLOYEE, PN_EMPLOYEE },
		{ PN_CUSTOMER * PN_EMPLOYEE, PN_CUSTOMER * PN_EMPLOYEE, PN_CUSTOMER * PN_EMPLOYEE, PN_EMPLOYEE },
		{ PN_OWNER, PN_OWNER, PN_OWNER, PN_OWNER }
	};
	void(*fctn[CATS][FCTNS])(Company*)
	{
		{ checkAccommodation, createAccommodation, changeAccommodation, deleteAccommodation },
		{ checkBooking, createBooking, changeBooking, deleteBooking },
		{ checkCustomer, createCustomer, changeCustomer, deleteCustomer },
		{ checkPark,createPark, changePark, deletePark }
	};
	char name[CHARS_NAME]{ "" };
	char address[CHARS_ADDRESS]{ "" };

	// Read company information from file
	Company* co = readFromFile("../company.dat");
	
	// Start application
	if (co == nullptr)
	{
		cout << "\nPlease give the required information for the new Company:" << std::endl;
		requestString("name", name, CHARS_NAME);
		requestString("address", address, CHARS_ADDRESS);
		cout << "\n" << endl;
		co = new Company(name, address);
	}

	// Welcome message
	cout << "Welcome to " << co->getName() << endl;

	// Initial login
	role = login(roles, rolesPn, ROLES);

	// Execute application
	while (role != -1)
	{
		option = menu(role, menuOptions, menuOptionsPn, CATS);
		while (option != -1)
		{
			suboption = submenu(role, option, subOptions, subOptionsPn, FCTNS);
			if (suboption != -1)
			{
				(*fctn[option][suboption])(co); // execute requested function
				printLine(DEFAULT_LINE);
			}
			option = menu(role, menuOptions, menuOptionsPn, CATS);
		}
		role = login(roles, rolesPn, ROLES);
	}

	// role == -1 -> logout message
	cout << "\n" << endl;
	printLine(DEFAULT_LINE);
	cout << "You have been logged out.\nThe application can now be closed.\n" << endl;
	printLine(DEFAULT_LINE);
	cout << "\n" << endl;

	// Save all Company data to file
	saveToFile(co, "../company.dat");
	delete co;
	co = nullptr;
	
	return 0;
} // end main
