/*
 *	Lab assignment for course Object Oriented Programming 2017
 *
 *	Véronique Wuyts
 *	Bachelor Elektronica-ICT option Application Development
 *	Thomas More campus De Nayer
 *
 * Implementation of class Hotelroom
 */

// includes
#include <cstring>
#include <iomanip>
#include "hotelroom.h"

// constructor
Hotelroom::Hotelroom(int id, LuxuryLevel luxuryLevel, int maxPeople, int size, int price,
	int floor, const char side[], int noOfBeds, bool childrensBed, bool miniBar)
	: Accommodation(id, luxuryLevel, maxPeople, size, price)
{
	setFloor(floor);
	setSide(side);
	setNoOfBeds(noOfBeds);
	this->childrensBed = childrensBed; // no validation
	this->miniBar = miniBar; // no validation
} // end Hotelroom constructor

// destructor
Hotelroom::~Hotelroom(void){}

// set floor value
// If the given floor value is in [MIN_FLOOR, MAX_FLOOR], the object floor
// is set to the given floor value, else the object floor is set to MIN_FLOOR.
void Hotelroom::setFloor(const int floor)
{
	this->floor = (floor >= MIN_FLOOR && floor <= MAX_FLOOR ? floor : MIN_FLOOR);
} // end function setFloor

// return floor value
int Hotelroom::getFloor(void) const
{
	return floor;
} // end function getFloor

// set side
void Hotelroom::setSide(const char side[])
{
	size_t length{ strlen(side) };
	length = (length < CHARS_SIDE ? length : CHARS_SIDE - 1);
	strncpy_s(this->side, CHARS_SIDE, side, length);
} // end function setSide

// return constant pointer to constant side
const char* const Hotelroom::getSide(void) const
{
	return side;
} // end function getSide

// set noOfBeds value
// If the given noOfBeds value is in [MIN_BEDS, MAX_BEDS] and is greater than or
// equal to (maxPeople - 1), the object noOfBeds is set to the given noOfBeds value,
// else the object noOfBeds is set to the object maxPeople.
void Hotelroom::setNoOfBeds(const int noOfBeds)
{
	this->noOfBeds = (noOfBeds >= MIN_BEDS && noOfBeds <= MAX_BEDS && noOfBeds >= (getMaxPeople() - 1) ?
		noOfBeds : getMaxPeople()); // getMaxPeople - 1, since 1 double bed possible
} // end function setNoOfBeds

// return noOfBeds value
int Hotelroom::getNoOfBeds(void) const
{
	return noOfBeds;
} // end function getNoOfBeds

// set childrensBed value
void Hotelroom::setChildrensBed(const bool childrensBed)
{
	this->childrensBed = childrensBed;
} // end function setChildrensBed

// return childrensBed value
bool Hotelroom::getChildrensBed(void) const
{
	return childrensBed;
} // end function getChildrensBed

// set minibar value
void Hotelroom::setMiniBar(const bool miniBar)
{
	this->miniBar = miniBar;
} // end function setMiniBar

// return miniBar value
bool Hotelroom::getMiniBar(void) const
{
	return miniBar;
} // end function getMiniBar

// return Accommodation Type
Accommodation::Type Hotelroom::getType(void) const
{
	return Accommodation::Type::HOTEL_ROOM;
} // end function getType

// overloaded stream insertion operator: non-member function
std::ostream& operator<<(std::ostream& output, Hotelroom& hotelroom)
{
	output << "Hotelroom:\n"
		<< static_cast<Accommodation&>(hotelroom); // ref: Peter2015
	output << "  " << std::setw(WIDTH_ACCOM) << "floor:" << hotelroom.floor
		<< "\n  " << std::setw(WIDTH_ACCOM) << "side:" << hotelroom.side
		<< "\n  " << std::setw(WIDTH_ACCOM) << "number of beds:" << hotelroom.noOfBeds
		<< "\n  " << std::setw(WIDTH_ACCOM) << "childrens bed:" << (hotelroom.childrensBed ? "yes" : "no")
		<< "\n  " << std::setw(WIDTH_ACCOM) << "mini bar:" << (hotelroom.miniBar ? "yes" : "no")
		<< "\n";

	return output; // enable cascading stream insertion operations
} // end overloaded operator<<
