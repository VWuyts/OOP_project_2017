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
#include <iomanip>
#include <iostream>
#include "cabin.h"
#include "hotelroom.h"
#include "park.h"

// default constructor
Park::Park(const char name[], const char address[], bool subtropicPar,
	bool bikeRental, bool waterBikeRental, bool bowlingAlley, bool kidsParadise, bool sportsHall)
{
	setName(name);
	setAddress(address);
	this->subtropicPar = subtropicPar; // no validation
	this->bikeRental = bikeRental; // no validation
	this->waterBikeRental = waterBikeRental; // no validation
	this->bowlingAlley = bowlingAlley; // no validation
	this->kidsParadise = kidsParadise; // no validation
	this->sportsHall = sportsHall; // no validation
	accommodations = new Accommodation*[MAX_PARK_ACCOM];
	for (size_t i{ 0 }; i < MAX_PARK_ACCOM; i++)
	{
		accommodations[i] = nullptr;
	}
} // end default Park constructor

// constructor
Park::Park(const char name[], const char address[], bool subtropicPar,
	bool bikeRental, bool waterBikeRental, bool bowlingAlley, bool kidsParadise,
	bool sportsHall, Accommodation* accommodations[], size_t sizeOfAccoms)
{
	sizeOfAccoms = (sizeOfAccoms < MAX_PARK_ACCOM ? sizeOfAccoms : MAX_PARK_ACCOM);

	setName(name);
	setAddress(address);
	this->subtropicPar = subtropicPar; // no validation
	this->bikeRental = bikeRental; // no validation
	this->waterBikeRental = waterBikeRental; // no validation
	this->bowlingAlley = bowlingAlley; // no validation
	this->kidsParadise = kidsParadise; // no validation
	this->sportsHall = sportsHall; // no validation
	this->accommodations = new Accommodation*[MAX_PARK_ACCOM];
	for (size_t i{ 0 }; i < MAX_PARK_ACCOM; i++)
	{
		this->accommodations[i] = nullptr;
	}
	for (size_t i{ 0 }; i < sizeOfAccoms; i++)
	{
		this->accommodations[i] = accommodations[i];
	}
} // end Park constructor

// destructor
// If Park is destructed, also the accommodations array and its
// contents is destructed to avoid memory leaks.
Park::~Park(void)
{
	for (size_t i{ 0 }; i < MAX_PARK_ACCOM; i++)
	{
		delete accommodations[i];
	}
	delete[] accommodations;
} // end Park destructor

// set name
void Park::setName(const char name[])
{
	size_t length{ strlen(name) };
	length = (length < CHARS_NAME ? length : CHARS_NAME - 1);
	strncpy_s(this->name, CHARS_NAME, name, length);
} // end function setName

// return constant pointer to constant name
const char* const Park::getName(void) const
{
	return name;
} // end function getName

// set address
void Park::setAddress(const char address[])
{
	size_t length{ strlen(address) };
	length = (length < CHARS_ADDRESS ? length : CHARS_ADDRESS - 1);
	strncpy_s(this->address, CHARS_ADDRESS, address, length);
} // end function setAddress

// return constant pointer to constant address
const char* const Park::getAddress(void) const
{
	return address;
} // end function getAddress

// set subtropicPar value
void Park::setSubtropicPar(const bool subtropicPar)
{
	this->subtropicPar = subtropicPar;
} // end function setSubtropicPar

// return subtropicPar value
bool Park::getSubtropicPar(void) const
{
	return subtropicPar;
} // end function getSubtropicPar

// set bikeRental value
void Park::setBikeRental(const bool bikeRental)
{
	this->bikeRental = bikeRental;
} // end function setBikeRental

// return bikeRental value
bool Park::getBikeRental(void) const
{
	return bikeRental;
} // end function getBikeRental

// set waterBikeRental value
void Park::setWaterBikeRental(const bool waterBikeRental)
{
	this->waterBikeRental = waterBikeRental;
} // end function setWaterBikeRental

// return waterBikeRental value
bool Park::getWaterBikeRental(void) const
{
	return waterBikeRental;
} // end function getWaterBikeRental

// set bowlingAlley value
void Park::setBowlingAlley(const bool bowlingAlley)
{
	this->bowlingAlley = bowlingAlley;
} // end function setBowlingAlley

// return bowlingAlley value
bool Park::getBowlingAlley(void) const
{
	return bowlingAlley;
} // end function getBowlingAlley

// set kidsParadise value
void Park::setKidsParadise(const bool kidsParadise)
{
	this->kidsParadise = kidsParadise;
} // end function setKidsParadise

// return kidsParadise value
bool Park::getKidsParadise(void) const
{
	return kidsParadise;
} // end function getKidsParadise

// set sportsHall value
void Park::setSportsHall(const bool sportsHall)
{
	this->sportsHall = sportsHall;
} // end function setSportsHall

bool Park::getSportsHall(void)
{
	return sportsHall;
} // end function getSportsHall

// set accommodation
// Stores the pointer to the Accomodation in the first free index of
// the accommodations array. A null pointer is not stored. If not a null
// pointer is given and no free index is found, the Accomodation is not
// stored and a message is printed.
// Setting a nullptr has no effect.
// The Cabin or Hotelroom object, to which the given pointer points to,
// may be destroyed after running this set function.
void Park::setAccommodations(Accommodation* const accommodation)
{
	size_t counter{ 0 };
	bool isSet{ false };
	Accommodation::Type type{ Accommodation::Type::CABIN };
	Cabin* cabinPtr{ nullptr };
	Hotelroom* hotelPtr{ nullptr };

	if (accommodation != nullptr) // cannot call function on nullptr
	{
		while (counter < MAX_PARK_ACCOM && !isSet)
		{
			if (this->accommodations[counter] == nullptr)
			{
				type = accommodation->getType();
				if (type == Accommodation::Type::CABIN)
				{
					cabinPtr = dynamic_cast<Cabin*>(accommodation);
					this->accommodations[counter] = new Cabin(cabinPtr->getId(), cabinPtr->getLuxuryLevel(), cabinPtr->getMaxPeople(),
						cabinPtr->getSize(), cabinPtr->getPrice(), cabinPtr->getNoOfBedrooms(), cabinPtr->getBluRaySurround(),
						cabinPtr->getBbq(), cabinPtr->getBreakfastService(), cabinPtr->getLaundryService());
				}
				else
				{
					hotelPtr = dynamic_cast<Hotelroom*>(accommodation);
					this->accommodations[counter] = new Hotelroom(hotelPtr->getId(), hotelPtr->getLuxuryLevel(), hotelPtr->getMaxPeople(),
						hotelPtr->getSize(), hotelPtr->getPrice(), hotelPtr->getFloor(), hotelPtr->getSide(), hotelPtr->getNoOfBeds(),
						hotelPtr->getChildrensBed(), hotelPtr->getMiniBar());
				}
				isSet = true;
			}
			counter++;
		}
		if (!isSet)
		{
			std::cout << "The accommodation was not set.\n" << std::endl;
		}
	}
} // end function setAccommodation

// return a constant pointer to the Accommodation at the given
// index in the accommodations array.
// If the given index is greater than or equal to
// MAX_ACCOMMODATIONS, a null pointer is returned.
Accommodation* const Park::getAccommodations(size_t index) const
{
	if (index < MAX_PARK_ACCOM)
	{
		return accommodations[index];
	}

	return nullptr;
} // end function getAccommodation

// return number of Accommodations
size_t Park::getNoOfAccommodations(void) const
{
	size_t noOfAccom{ 0 };

	for (size_t i{ 0 }; i < MAX_PARK_ACCOM; i++)
	{
		if (accommodations[i] != nullptr)
		{
			++noOfAccom;
		}
	}

	return noOfAccom;
} // end function getNoOfAccommodations

// return index of the Accommodation with the given id
// If the given id is not found, DEFAULT_INDEX is returned.
size_t Park::getAccomIndexOf(int id) const
{
	size_t index{ DEFAULT_INDEX };
	size_t i{ 0 };

	while (i < MAX_PARK_ACCOM && index == DEFAULT_INDEX)
	{
		if (accommodations[i] != nullptr && accommodations[i]->getId() == id)
		{
			index = i;
		}
		i++;
	}

	return index;
}// end function getAccomIndexOf

// destruct the Accommodation at the given index in the accommodations array
void Park::destructAccommodationAt(size_t index)
{
	if (index < MAX_PARK_ACCOM)
	{
		delete accommodations[index]; // delete on nullptr has no effect
		accommodations[index] = nullptr; // set the index as 'free'
	}
} // end function destructAccommodationAt

// overloaded stream insertion operator: non-member function
std::ostream& operator<<(std::ostream& output, const Park& park)
{
	output << "Park: " << park.name
		<< std::left
		<< "\n  " << std::setw(WIDTH_PARK) << "address:" << park.address
		<< "\n  " << std::setw(WIDTH_PARK) << "subtropic paradise:" << (park.subtropicPar ? "yes" : "no")
		<< "\n  " << std::setw(WIDTH_PARK) << "bike rental:" << (park.bikeRental ? "yes" : "no")
		<< "\n  " << std::setw(WIDTH_PARK) << "water bike rental:" << (park.waterBikeRental ? "yes" : "no")
		<< "\n  " << std::setw(WIDTH_PARK) << "bowling alley:" << (park.bowlingAlley ? "yes" : "no")
		<< "\n  " << std::setw(WIDTH_PARK) << "kids paradise:" << (park.kidsParadise ? "yes" : "no")
		<< "\n  " << std::setw(WIDTH_PARK) << "sports hall:" << (park.sportsHall ? "yes" : "no")
		<< "\n";

	return output; // enable cascading stream insertion operations
} // end overloaded operator<<
