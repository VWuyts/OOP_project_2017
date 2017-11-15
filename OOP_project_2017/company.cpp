/*
 *	Lab assignment for course Object Oriented Programming 2017
 *
 *	Véronique Wuyts
 *	Bachelor Elektronica-ICT option Application Development
 *	Thomas More campus De Nayer
 *
 *	Implementation of class Company
 */

// includes
#include <cstring>
#include <iostream>
#include "Company.h"

// default constructor
Company::Company(char name[], char address[])
{
	setName(name);
	setAddress(address);
	for (size_t i{ 0 }; i < MAX_CUSTOMERS; i++)
	{
		customers[i] = nullptr;
	}
	for (size_t i = 0; i < MAX_PARKS; i++)
	{
		parks[i] = nullptr;
	}
} // end Company default constructor

// destructor
Company::~Company(void)
{
	// TO DO: implement destructor
} // end Company destructor

// return constant pointer to constant name
const char* const Company::getName(void) const
{
	return name;
} // end function getName

// return constant pointer to constant address
const char* const Company::getAddress(void) const
{
	return address;
} // end function getAddress

// return constant pointer to constant Customers array
const Customer* const * const Company::getCustomers(void) const
{
	return customers;
} // end function getCustomers

// return constant pointer to constant Park array
const Park* const * const Company::getParks(void) const
{
	return parks;
} // end function getParks

// set name
void Company::setName(const char name[])
{
	size_t length = strlen(name);
	length = (length < CHARS_NAME ? length : CHARS_NAME - 1);
	strncpy_s(this->name, CHARS_NAME, name, length);
} // end function setName

// set address
void Company::setAddress(const char address[])
{
	size_t length = strlen(address);
	length = (length < CHARS_ADDRESS ? length : CHARS_ADDRESS - 1);
	strncpy_s(this->address, CHARS_ADDRESS, address, length);
} // end function setAddress

// set customer
// Stores the pointer to the Customer in the first free index of
// the customers array. If no free index is found, the Customer
// is not stored and a message is shown.
void Company::setCustomers(Customer* const customer)
{
	size_t counter = 0;
	bool isSet = false;

	while (counter < MAX_CUSTOMERS && !isSet)
	{
		if (this->customers[counter] == nullptr)
		{
			this->customers[counter] = customer;
			isSet = true;
		}
		counter++;
	}

	if (!isSet)
	{
		std::cout << "The customer could not be set.\n" << std::endl;
	}
} // end function setCustomers

// set park
// Stores the pointer to the Park in the first free index of
// the parks array. If no free index is found, the Park
// is not stored and a message is shown.
void Company::setParks(Park* const park)
{
	size_t counter = 0;
	bool isSet = false;

	while (counter < MAX_PARKS && !isSet)
	{
		if (this->parks[counter] == nullptr)
		{
			this->parks[counter] = park;
			isSet = true;
		}
		counter++;
	}

	if (!isSet)
	{
		std::cout << "The park could not be set.\n" << std::endl;
	}
}