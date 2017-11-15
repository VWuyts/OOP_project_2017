/*
 *	Lab assignment for course Object Oriented Programming 2017
 *
 *	Véronique Wuyts
 *	Bachelor Elektronica-ICT option Application Development
 *	Thomas More campus De Nayer
 *
 *	Definition of class Park
 */

#pragma once

// Includes
#include "accommodation.h"
#include "constants.h"

class Park
{
public:
	// Constructor and destructor
	Park(char[] = NAME_REQUIRED, char[] = ADDRESS_REQUIRED,
		bool = false, bool = false, bool = false, bool = false, bool = false);
	~Park(void);

	// Get functions
	const char* const getName(void) const;
	const char* const getAddress(void) const;
	bool getSubTropicPar(void) const;
	bool getBikeRental(void) const;
	bool getWaterBikeRental(void) const;
	bool getBowlingAlley(void) const;
	bool getKidsParadise(void) const;
	const Accommodation* const * const getAccommodations(void) const;

	// Set functions
	void setName(const char[]);
	void setAddress(const char[]);
	void setSubTropicPar(const bool);
	void setBikeRental(const bool);
	void setWaterBikeRental(const bool);
	void setBowlingAlley(const bool);
	void setKidsParadise(const bool);
	void setAccommodations(Accommodation* const);

private:
	char name[CHARS_NAME];
	char address[CHARS_ADDRESS];
	bool subTropicPar;
	bool bikeRental;
	bool waterBikeRental;
	bool bowlingAlley;
	bool kidsParadise;
	Accommodation* accommodations[MAX_ACCOMMODATIONS];
}; // end class Parc