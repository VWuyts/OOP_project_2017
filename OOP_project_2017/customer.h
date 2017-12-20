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

// includes
#include <iostream>
#include "booking.h"

class Customer
{
	friend std::ostream& operator<<(std::ostream&, const Customer&);

public:
	// default constructor
	Customer(const char[] = NAME_REQUIRED, const char[] = ADDRESS_REQUIRED,
		const char[] = EMAIL_REQUIRED, const char[] = BANK_ACCOUNT_REQUIRED);
	// constructor
	Customer(const char[], const char[], const char[], const char[], Booking*[], size_t);
	// destructor
	~Customer(void);

	void setName(const char[]); // set name
	const char* const getName(void) const; // get name

	void setAddress(const char[]); // set address
	const char* const getAddress(void) const; // get address

	void setEmail(const char[]); // set email
	const char* const getEmail(void) const; // get email

	void setBankAccount(const char[]); // set bankAccount
	const char* const getBankAccount(void) const; // get bankAccount
	
	void setBookings(Booking * const); // set Booking
	Booking* const getBooking(size_t) const; // get Booking

	size_t getNoOfBookings(void) const; // get number of Bookings
	size_t getBookingIndexOf(int) const; // get index of Booking

	void destructBookingAt(size_t); // delete the Booking at the given index
	void deleteAccomFromBooking(int); // delete an Accommodation from a Booking

private:
	// data members
	char name[CHARS_NAME];
	char address[CHARS_ADDRESS];
	char email[CHARS_EMAIL];
	char bankAccount[CHARS_BANK_ACCOUNT];
	Booking** bookings;
}; // end class Customer