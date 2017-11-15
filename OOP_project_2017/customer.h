/*
 *	Lab assignment for course Object Oriented Programming 2017
 *
 *	Véronique Wuyts
 *	Bachelor Elektronica-ICT option Application Development
 *	Thomas More campus De Nayer
 *
 *	Definition of class Customer
 */

#pragma once

// Includes
#include "constants.h"

class Customer
{
public:
	// Constructor and destructor
	Customer(char[] = NAME_REQUIRED, char[] = ADDRESS_REQUIRED, char[] = EMAIL_REQUIRED, char[] = BANK_ACCOUNT_REQUIRED);
	~Customer(void);

	// Get functions
	const char* const getName(void) const;
	const char* const getAddress(void) const;
	const char* const getEmail(void) const;
	const char* const getBankAccount(void) const;

	// Set functions
	void setName(const char[]);
	void setAddress(const char[]);
	void setEmail(const char[]);
	void setBankAccount(const char[]);

private:
	char name[CHARS_NAME];
	char address[CHARS_ADDRESS];
	char email[CHARS_EMAIL];
	char bankAccount[CHARS_BANK_ACCOUNT];
}; // end class Customer