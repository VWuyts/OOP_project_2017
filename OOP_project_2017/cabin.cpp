/*
 *	Lab assignment for course Object Oriented Programming 2017
 *
 *	Véronique Wuyts
 *	Bachelor Elektronica-ICT option Application Development
 *	Thomas More campus De Nayer
 *
 *	Implementation of class Cabin
 */

// includes
#include <iomanip>
#include "cabin.h"

// constructor
Cabin::Cabin(int id, LuxuryLevel luxuryLevel, int maxPeople, int size, int price,
	int noOfBedrooms, bool bluRaySurround, bool bbq, bool breakfastService, bool laundryService)
	: Accommodation(id, luxuryLevel, maxPeople, size, price)
{
	setNoOfBedrooms(noOfBedrooms);
	this->bluRaySurround = bluRaySurround; // no validation
	this->bbq = bbq; // no validation
	this->breakfastService = breakfastService; // no validation
	this->laundryService = laundryService; // no validation
} // end Cabin constructor

// destructor
Cabin::~Cabin(void){}

// set noOfBedrooms value
// If the given noOfBedrooms value is in [MIN_BEDROOMS, MAX_BEDROOMS], the object noOfBedrooms
// is set to the given noOfBedrooms value, else the object noOfBedrooms is set to MIN_BEDROOMS.
void Cabin::setNoOfBedrooms(const int noOfBedrooms)
{
	this->noOfBedrooms = (noOfBedrooms >= MIN_BEDROOMS && noOfBedrooms <= MAX_BEDROOMS ? noOfBedrooms : MIN_BEDROOMS);
} // end function set NoOfBedrooms

// return noOfBedrooms value
int Cabin::getNoOfBedrooms(void) const
{
	return noOfBedrooms;
} // end function getNoOfBedrooms

// set bluRaySurround value
void Cabin::setBluRaySurround(const bool bluRaySurround)
{
	this->bluRaySurround = bluRaySurround;
} // end function setBluRaySurround

// return bluRaySurround value
bool Cabin::getBluRaySurround(void) const
{
	return bluRaySurround;
} // end function getBluRaySurround

// set bbq value
void Cabin::setBbq(const bool bbq)
{
	this->bbq = bbq;
} // end function setBbq

// return bbq value
bool Cabin::getBbq(void) const
{
	return bbq;
} // end function getBbq

// set breakfastService value
void Cabin::setBreakfastService(const bool breakfastService)
{
	this->breakfastService = breakfastService;
} // end function setBreakfastService

// return breakfastService value
bool Cabin::getBreakfastService(void) const
{
	return breakfastService;
} // end function getBreakfastService

// set laundryService value
void Cabin::setLaundryService(const bool laundryService)
{
	this->laundryService = laundryService;
} // end function setLaundryService

// return laundryService value
bool Cabin::getLaundryService(void) const
{
	return laundryService;
} // end function getLaundryService

// return Accommodation Type
Accommodation::Type Cabin::getType(void) const
{
	return Accommodation::Type::CABIN;
} // end function getType

// overloaded stream insertion operator: non-member function
std::ostream& operator<<(std::ostream& output, Cabin& cabin)
{
	output << "Cabin:\n"
		<< static_cast<Accommodation&>(cabin); // ref: Peter2015
	output << "  " << std::setw(WIDTH_ACCOM) << "number of bedrooms:" << cabin.noOfBedrooms
		<< "\n  " << std::setw(WIDTH_ACCOM) << "blu-Ray surround:" << (cabin.bluRaySurround ? "yes" : "no")
		<< "\n  " << std::setw(WIDTH_ACCOM) << "barbecue:" << (cabin.bbq ? "yes" : "no")
		<< "\n  " << std::setw(WIDTH_ACCOM) << "breakfast service:" << (cabin.breakfastService ? "yes" : "no")
		<< "\n  " << std::setw(WIDTH_ACCOM) << "laundry service:" << (cabin.laundryService ? "yes" : "no")
		<< "\n";

	return output; // enable cascading stream insertion operations
}  // end overloaded operator<<
