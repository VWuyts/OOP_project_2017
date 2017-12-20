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

// includes
#include "accommodation.h"

class Booking
{
	friend std::ostream& operator<<(std::ostream&, const Booking&);

public:
	// default constructor
	Booking(int = -1, bool = false, bool = false, bool = false, bool = false);
	// constructor
	Booking(int, bool, bool, bool, bool, int, Accommodation*[], size_t);
	// destructor
	~Booking(void);

	void setBookingId(const int); // set bookingId
	int getBookingId(void) const; // get bookingId

	int getNoOfAccomm(void) const; // get noOfAccomm

	void setActivityPass(const bool); // set activityPass
	bool getActivityPass(void) const; // get activityPass

	void setSportPass(const bool); // set sportPass
	bool getSportPass(void) const; // get sportPass

	void setBikeRental(const bool); // set bikeRental
	bool getBikeRental(void) const; // get bikeRental

	void setSubtropicPass(const bool); // set subtropicPass
	bool getSubtropicPass(void) const; // get subtropicPass

	void setAccommodations(Accommodation* const); // set Accommodation
	Accommodation* const getAccommodations(size_t) const; // get Accommodation

	int getTotalPrice(void) const; // get total price

	void deleteAccomAt(size_t); // delete the Accommodation at the given index

private:
	// data members
	int bookingId;
	int noOfAccomm;
	bool activityPass;
	bool sportPass;
	bool bikeRental;
	bool subtropicPass;
	Accommodation** accommodations;

	void setNoOfAccomm(const int); // set noOfAccomm
	int calculateTotalPrice(void) const; // calculate total price
}; // end class Booking

