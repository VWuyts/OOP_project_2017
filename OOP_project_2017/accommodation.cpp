/*
 *	Lab assignment for course Object Oriented Programming 2017
 *
 *	Véronique Wuyts
 *	Bachelor Elektronica-ICT option Application Development
 *	Thomas More campus De Nayer
 *
 *	Implementation of class Accommodation
 */

// includes
#include <cstring>
#include "accommodation.h"

// default constructor
Accommodation::Accommodation(int id, char luxuryLevel[], int maxPeople,	int size, int price, char type)
{
	this->setId(id);
	this->setLuxuryLevel(luxuryLevel);
	this->setMaxPeople(maxPeople);
	this->setSize(size);
	this->setPrice(price);
	this->setType(type);
} // end Accommodation default contructor

// destructor
Accommodation::~Accommodation(void)
{
	// TO DO: implement destructor
} // end Accommodation destructor

// return id value
int Accommodation::getId(void) const
{
	return id;
} // end function getId

// return constant pointer to constant luxurylevel
const char* const Accommodation::getLuxuryLevel(void) const
{
	return luxuryLevel;
} // end function getLuxuryLevel

// return maxPeople value
int Accommodation::getMaxPeople(void) const
{
	return maxPeople;
} // end funtion getMaxPeople

// return size value
int Accommodation::getSize(void) const
{
	return size;
} // end function getSize

// return price value
int Accommodation::getPrice(void) const
{
	return price;
} // end function getPrice

// return type value
char Accommodation::getType(void) const
{
	return type;
} // end function getType

// set id value
void Accommodation::setId(const int id)
{
	this->id = id;
} // end function setId

// set luxuryLevel
// If the given luxuryLevel equals LUX_LEVEL_LOW, LUX_LEVEL_MEDIUM or LUX_LEVEL_HIGH,
// the object luxuryLevel is set to the given luxuryLevel,
// else the object luxuryLevel is set to LUX_LEVEL_LOW.
void Accommodation::setLuxuryLevel(const char luxuryLevel[])
{
	if (strcmp(luxuryLevel, LUX_LEVEL_LOW) == 0 ||
		strcmp(luxuryLevel, LUX_LEVEL_MEDIUM) == 0 ||
		strcmp(luxuryLevel, LUX_LEVEL_HIGH) == 0)
	{
		strcpy_s(this->luxuryLevel, CHARS_LUXURY_LEVEL, luxuryLevel); //strcpy_s is not strictly needed, because size of string to be copied is checked in if statement
	}
	else
	{
		strcpy_s(this->luxuryLevel, CHARS_LUXURY_LEVEL, LUX_LEVEL_LOW); // strcpy_s is not strictly needed, because string to be copied is a known defined string
	}
} // end function setLuxuryLevel

// set maxPeople value
// Valid maxPeople values are integers in [MIN_PEOPLE, MAX_PEOPLE].
// If an invalid maxPeople value is given, the object maxPeople is set to DEFAULT_PEOPLE.
void Accommodation::setMaxPeople(const int maxPeople)
{
	this->maxPeople = (maxPeople >= MIN_PEOPLE && maxPeople <= MAX_PEOPLE ? maxPeople : DEFAULT_PEOPLE);
} // end function setMaxPeople

// set size value
// Valid size values are integers in [MIN_SIZE, MAX_SIZE].
// If an invalid size value is given, the object size is set to DEFAULT_SIZE.
void Accommodation::setSize(const int size)
{
	this->size = (size >= MIN_SIZE && size <= MAX_SIZE ? size : DEFAULT_SIZE);
} // end function setSize

// set price value
// Valid price values are integers in [MIN_PRICE, MAX_SIZE].
// If an invalid price value is given, the object price is set to DEFAULT_PRICE.
void Accommodation::setPrice(const int price)
{
	this->price = (price >= MIN_PRICE && price <= MAX_PRICE ? price : DEFAULT_PRICE);
} // end function setPrice

// set type value
// Valid type values are chars HOTEL_ROOM or CABIN.
// If an invalid type value is given, the object type is set to CABIN.
void Accommodation::setType(const char type)
{
	this->type = (type == HOTEL_ROOM || type == CABIN ? type : CABIN);
} // end function setType