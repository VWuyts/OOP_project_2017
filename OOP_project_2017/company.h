/*
 *	Lab assignment for course Object Oriented Programming 2017
 *
 *	Véronique Wuyts
 *	Bachelor Elektronica-ICT option Application Development
 *	Thomas More campus De Nayer
 *
 *	Definition of class Company
 */

#pragma once

#include "Customer.h"
#include "Park.h"

class Company
{
public:
	// Constructor and destructor
	Company(char[] = NAME_REQUIRED, char[] = ADDRESS_REQUIRED);
	~Company(void);

	// Get functions
	const char* const getName(void) const;
	const char* const getAddress(void) const;
	const Customer* const * const getCustomers(void) const;
	const Park* const * const getParks(void) const;

	// Set functions
	void setName(const char[]);
	void setAddress(const char[]);
	void setCustomers(Customer * const);
	void setParks(Park * const);

private:
	char name[CHARS_NAME];
	char address[CHARS_ADDRESS];
	Customer* customers[MAX_CUSTOMERS];
	Park* parks[MAX_PARKS];
}; // end class Company

