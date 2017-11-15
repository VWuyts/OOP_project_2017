/*
 *	Lab assignment for course Object Oriented Programming 2017
 *
 *	Véronique Wuyts
 *	Bachelor Elektronica-ICT option Application Development
 *	Thomas More campus De Nayer
 *
 *	Implementation of class Park
 */

// includes
#include <cstring>
#include <iostream>
#include "park.h"

// default constructor
Park::Park(char name[], char address[], bool subTropicPar,
	bool bikeRental, bool waterBikeRental, bool bowlingAlley, bool kidsParadise)
{
	setName(name);
	setAddress(address);
	setSubTropicPar(subTropicPar);
	setBikeRental(bikeRental);
	setWaterBikeRental(waterBikeRental);
	setBowlingAlley(bowlingAlley);
	setKidsParadise(kidsParadise);
	for (size_t i{ 0 }; i < MAX_ACCOMMODATIONS; i++)
	{
		accommodations[i] = nullptr;
	}
} // end Park default constructor

// destructor
Park::~Park(void)
{
	// TO DO: implement destructor
} // end Park destructor

// return constant pointer to constant name
const char* const Park::getName(void) const
{
	return name;
} // end function getName

// return constant pointer to constant address
const char* const Park::getAddress(void) const
{
	return address;
} // end function getAddress

// return subTropicPar value
bool Park::getSubTropicPar(void) const
{
	return subTropicPar;
} // end function getSubTropicPar

// return bikeRental value
bool Park::getBikeRental(void) const
{
	return bikeRental;
} // end function  getBikeRental

// return waterBikeRental value
bool Park::getWaterBikeRental(void) const
{
	return waterBikeRental;
} // end function getWaterBikeRental

// return bowlingAlley value
bool Park::getBowlingAlley(void) const
{
	return bowlingAlley;
} // end function getBowlingAlley

// return kidsParadise value
bool Park::getKidsParadise(void) const
{
	return kidsParadise;
} // end function getKidsParadise

// return constant pointer to constant accommodations array
const Accommodation* const * const Park::getAccommodations(void) const
{
	return accommodations;
} // end function getAccommodations

// set name
void Park::setName(const char name[])
{
	size_t length = strlen(name);
	length = (length < CHARS_NAME ? length : CHARS_NAME - 1);
	strncpy_s(this->name, CHARS_NAME, name, length);
} // end function setName

// set address
void Park::setAddress(const char address[])
{
	size_t length = strlen(address);
	length = (length < CHARS_ADDRESS ? length : CHARS_ADDRESS - 1);
	strncpy_s(this->address, CHARS_ADDRESS, address, length);
} // end function setAddress

// set subTropicPar value
void Park::setSubTropicPar(const bool subTropicPar)
{
	this->subTropicPar = subTropicPar;
} // end function setSubTropicPar

// set bikeRental value
void Park::setBikeRental(const bool bikeRental)
{
	this->bikeRental = bikeRental;
} // end function setBikeRental

// set waterBikeRental value
void Park::setWaterBikeRental(const bool waterBikeRental)
{
	this->waterBikeRental = waterBikeRental;
} // end function setWaterBikeRental

// set bowlingAlley value
void Park::setBowlingAlley(const bool bowlingAlley)
{
	this->bowlingAlley = bowlingAlley;
} // end function setBowlingAlley

// set kidsParadise value
void Park::setKidsParadise(const bool kidsParadise)
{
	this->kidsParadise = kidsParadise;
} // end function setKidsParadise

// set accommodation
// Stores the pointer to the Accomodation in the first free index of
// the accommodations array. If no free index is found, the Accomodation
// is not stored and a message is shown.
void Park::setAccommodations(Accommodation* const accommodation)
{
	size_t counter = 0;
	bool isSet = false;

	while (counter < MAX_ACCOMMODATIONS && !isSet)
	{
		if (this->accommodations[counter] == nullptr)
		{
			this->accommodations[counter] = accommodation;
			isSet = true;
		}
		counter++;
	}

	if (!isSet)
	{
		std::cout << "The accommodation could not be set.\n" << std::endl;
	}
} // end function setAccommodations