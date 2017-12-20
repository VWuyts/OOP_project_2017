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

// includes
#include "accommodation.h"

class Park
{
	friend std::ostream& operator<<(std::ostream&, const Park&);

public:
	// default constructor
	Park(const char[] = DEFAULT_PARK_NAME, const char[] = DEFAULT_PARK_ADDRESS,
		bool = false, bool = false, bool = false, bool = false, bool = false, bool = false);
	// constructor
	Park(const char[], const char[],bool, bool, bool, bool, bool, bool, Accommodation*[], size_t);
	// destructor
	~Park(void);

	void setName(const char[]); // set name
	const char* const getName(void) const; // get name

	void setAddress(const char[]); // set address
	const char* const getAddress(void) const; // get address

	void setSubtropicPar(const bool); // set subtropicPar
	bool getSubtropicPar(void) const; // get subtropicPar

	void setBikeRental(const bool); // set bikeRental
	bool getBikeRental(void) const; // get bikeRental

	void setWaterBikeRental(const bool); // set waterBikeRental
	bool getWaterBikeRental(void) const; // get waterBikeRental

	void setBowlingAlley(const bool); // set bowlingAlley
	bool getBowlingAlley(void) const; // get bowlingAlley

	void setKidsParadise(const bool); // set kidsParadise
	bool getKidsParadise(void) const; // get kidsParadise

	void setSportsHall(const bool); // set sportsHall
	bool getSportsHall(void); // get sportsHall

	void setAccommodations(Accommodation* const); // set Accomodation
	Accommodation* const getAccommodations(size_t index) const; // get Accommodation

	size_t getNoOfAccommodations(void) const; // get number of Accommodations
	size_t getAccomIndexOf(int) const; // get index of Accomodation

	void destructAccommodationAt(size_t); // delete the Accommodation at the given index

private:
	// Data members
	char name[CHARS_NAME];
	char address[CHARS_ADDRESS];
	bool subtropicPar;
	bool bikeRental;
	bool waterBikeRental;
	bool bowlingAlley;
	bool kidsParadise;
	bool sportsHall;
	Accommodation** accommodations;
}; // end class Parc