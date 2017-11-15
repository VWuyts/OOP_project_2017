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
#include "constants.h"

class Accommodation
{
public:
	// Constructor and destructor
	Accommodation(int = -1, char[] = LUX_LEVEL_LOW, int = DEFAULT_PEOPLE, int = DEFAULT_SIZE, int = DEFAULT_PRICE, char = CABIN);
	~Accommodation(void);

	// Get functions
	int getId(void) const;
	const char* const getLuxuryLevel(void) const;
	int getMaxPeople(void) const;
	int getSize(void) const;
	int getPrice(void) const;
	char getType(void) const;

	// Set functions
	void setId(const int);
	void setLuxuryLevel(const char[]);
	void setMaxPeople(const int);
	void setSize(const int);
	void setPrice(const int);
	void setType(const char);

private:
	int id;
	char luxuryLevel[CHARS_LUXURY_LEVEL];
	int maxPeople;
	int size;
	int price;
	char type;
}; // end class Accommodation
