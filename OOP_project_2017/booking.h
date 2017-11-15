/*
 *	Lab assignment for course Object Oriented Programming 2017
 *
 *	Véronique Wuyts
 *	Bachelor Elektronica-ICT option Application Development
 *	Thomas More campus De Nayer
 *
 *	Definition of class Booking
 */

#pragma once

// Includes
#include "accommodation.h"
#include "constants.h"
#include "customer.h"

class Booking
{
public:
	// Constructor and destructor
	Booking(int = 0, Customer* = nullptr, bool = false, bool = false, bool = false, bool = false);
	~Booking(void);

	// Get functions
	int getBookingId(void) const;
	const Customer* const getCustomer(void) const;
	int getNoOfAccomm(void) const;
	const Accommodation* const * const getAccommodations(void) const;
	bool getActivityPass(void) const;
	bool getSportPass(void) const;
	bool getBikeRental(void) const;
	bool getSubTropicPass(void) const;
	int getTotalPrice(void);

	// Set functions
	void setBookingId(const int);
	void setCustomer(Customer* const);
	void setNoOfAccomm(const int);
	void setAccommodations(Accommodation* const);
	void setActivityPass(const bool);
	void setSportPass(const bool);
	void setBikeRental(const bool);
	void setSubTropicPass(const bool);

private:
	int bookingId;
	Customer* customer;
	int noOfAccomm;
	Accommodation* accommodations[MAX_BOOKING];
	bool activityPass;
	bool sportPass;
	bool bikeRental;
	bool subTropicPass;
	int totalPrice;
	void calculateTotalPrice(int*);
}; // end class Booking

