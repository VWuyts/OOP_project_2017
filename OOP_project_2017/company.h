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

// includes
#include <iostream>
#include "customer.h"
#include "park.h"

class Company
{
	friend std::ostream& operator<<(std::ostream&, const Company&);

public:
	// default constructor
	Company(const char[] = DEFAULT_CO_NAME, const char[] = DEFAULT_CO_ADDRESS);
	// constructor
	// Empty indexes in the Customer* or Park* arrays have to be filled with a nullptr.
	Company(const char[], const char[], Customer*[], size_t, Park*[], size_t);
	// destructor
	~Company(void);

	void setName(const char[]); // set name
	const char* const getName(void) const; // get name

	void setAddress(const char[]); // set address
	const char* const getAddress(void) const; // get address

	void setCustomers(Customer* const); // set a Customer
	Customer* const getCustomers(size_t) const; // get a Customer

	void setParks(Park * const); // set a Park
	Park* const getParks(size_t) const; // get a Park

	size_t getNoOfCustomers(void) const; // get number of Customers
	size_t getNoOfParks(void) const; // get number of Parks

	size_t getCustIndex(size_t) const; // get the index of the chosen Customer
	size_t getParkIndex(size_t) const; // get the index of the chosen Park
	
	void destructCustomerAt(size_t); // delete the Customer at the given index
	void destructParkAt(size_t); // delete the park at the given index

private:
	// data members
	char name[CHARS_NAME];
	char address[CHARS_ADDRESS];
	Customer** customers;
	Park** parks;
	
}; // end class Company
