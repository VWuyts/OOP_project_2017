/*
 *	Lab assignment for course Object Oriented Programming 2017
 *
 *	Véronique Wuyts
 *	Bachelor Elektronica-ICT option Application Development
 *	Thomas More campus De Nayer
 *
 *	Definition of class Accommodation
 */

#pragma once

// includes
#include <iostream>
#include "constants.h"

class Accommodation
{
	friend std::ostream& operator<<(std::ostream&, const Accommodation&);

public:
	// enumerations
	enum class Type : int { CABIN, HOTEL_ROOM };
	enum class LuxuryLevel : int { COMFORT, PREMIUM, VIP };
	enum class RequestType : int { R_TYPE, R_PEOPLE, R_LUXURY_LEVEL };

	// constructor
	Accommodation(int = -1, LuxuryLevel = LuxuryLevel::COMFORT, int = DEFAULT_PEOPLE, int = DEFAULT_SIZE, int = DEFAULT_PRICE);
	// destructor
	virtual ~Accommodation(void);

	void setId(const int); // set id
	int getId(void) const; // get id

	void setLuxuryLevel(const LuxuryLevel); // set luxuryLevel
	LuxuryLevel getLuxuryLevel(void) const; // get luxurylevel

	void setMaxPeople(const int); // set maxPeople
	int getMaxPeople(void) const; // get maxPeople

	void setSize(const int); // set size
	int getSize(void) const; // get size

	void setPrice(const int); // set price
	int getPrice(void) const; // get price

	virtual Type getType(void) const = 0; // get type
	virtual bool shouldDisplay(RequestType, size_t) const; // determine whether to display the Accommodation

private:
	// data members
	int id;
	LuxuryLevel luxuryLevel;
	int maxPeople;
	int size;
	int price;
}; // end class Accommodation
