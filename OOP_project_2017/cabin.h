/*
 *	Lab assignment for course Object Oriented Programming 2017
 *
 *	Véronique Wuyts
 *	Bachelor Elektronica-ICT option Application Development
 *	Thomas More campus De Nayer
 *
 *	Definition of class Cabin
 */

#pragma once

// includes
#include "accommodation.h"

class Cabin :
	public Accommodation
{
	friend std::ostream& operator<<(std::ostream&, Cabin&);

public:
	// constructor
	Cabin(int = -1, LuxuryLevel = LuxuryLevel::COMFORT, int = DEFAULT_PEOPLE, int = DEFAULT_SIZE, int = DEFAULT_PRICE,
		int = MIN_BEDROOMS, bool = false, bool = false, bool = false, bool = false);
	// destructor
	~Cabin(void);

	void setNoOfBedrooms(const int); // set noOfBedRooms
	int getNoOfBedrooms(void) const; // get noOfBedRooms

	void setBluRaySurround(const bool); // set bluRaySurround
	bool getBluRaySurround(void) const; // get bluRaySurround

	void setBbq(const bool); // set bbq
	bool getBbq(void) const; // get bbq

	void setBreakfastService(const bool); // set breakfastService
	bool getBreakfastService(void) const; // get breakfastService

	void setLaundryService(const bool); // set laundryService
	bool getLaundryService(void) const; // get laundryService

	virtual Accommodation::Type getType(void) const override; // get Type

private:
	// data members
	int noOfBedrooms;
	bool bluRaySurround;
	bool bbq;
	bool breakfastService;
	bool laundryService;
}; // end class Cabin
