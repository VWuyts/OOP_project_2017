/*
 *	Lab assignment for course Object Oriented Programming 2017
 *
 *	Véronique Wuyts
 *	Bachelor Elektronica-ICT option Application Development
 *	Thomas More campus De Nayer
 *
 *	Definition of class Hotelroom
 */

#pragma once

// includes
#include "accommodation.h"

class Hotelroom :
	public Accommodation
{
	friend std::ostream& operator<<(std::ostream&, Hotelroom&);

public:
	// constructor
	Hotelroom(int = -1, LuxuryLevel = LuxuryLevel::COMFORT, int = DEFAULT_PEOPLE, int = DEFAULT_SIZE, int = DEFAULT_PRICE,
		int = MIN_FLOOR, const char[] = DEFAULT_SIDE, int = DEFAULT_BEDS, bool = false, bool = false);
	// destructor
	~Hotelroom(void);

	void setFloor(const int); // set floor
	int getFloor(void) const; // get floor

	void setSide(const char[]); // set side
	const char* const getSide(void) const; // get side

	void setNoOfBeds(const int); // set noOfBeds
	int getNoOfBeds(void) const; // get noOfBeds

	void setChildrensBed(const bool); // set childrensBed
	bool getChildrensBed(void) const; // get childrensBed

	void setMiniBar(const bool); // set miniBar
	bool getMiniBar(void) const; // get miniBar

	virtual Type getType(void) const override; // get Type

private:
	// data members
	int floor;
	char side[CHARS_SIDE];
	int noOfBeds;
	bool childrensBed;
	bool miniBar;
}; // end class Hotelroom
