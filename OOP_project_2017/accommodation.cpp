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
#include <iomanip>
#include "accommodation.h"

// constructor
Accommodation::Accommodation(int id, LuxuryLevel luxuryLevel, int maxPeople, int size, int price)
{
	setId(id);
	this->luxuryLevel = luxuryLevel; // no validation
	setMaxPeople(maxPeople);
	setSize(size);
	setPrice(price);
} // end Accommodation contructor

// destructor
Accommodation::~Accommodation(void) {}

// set id value
// The given id value should be unique within a Company
// If the given id equals DEFAULT_INT, the id is set to -1
void Accommodation::setId(const int id)
{
	if (id == DEFAULT_INT)
	{
		this->id = -1;
	}
	else
	{
		this->id = id;
	}
} // end function setId

// return id value
int Accommodation::getId(void) const
{
	return id;
} // end function getId

// set luxuryLevel
void Accommodation::setLuxuryLevel(const LuxuryLevel luxuryLevel)
{
	this->luxuryLevel = luxuryLevel;
} // end function setLuxurylevel

// return luxurylevel
Accommodation::LuxuryLevel Accommodation::getLuxuryLevel(void) const
{
	return luxuryLevel;
} // end function getLuxuryLevel

// set maxPeople value
// Valid maxPeople values are integers in [MIN_PEOPLE, MAX_PEOPLE].
// If an invalid maxPeople value is given, the object maxPeople is set to DEFAULT_PEOPLE.
void Accommodation::setMaxPeople(const int maxPeople)
{
	this->maxPeople = (maxPeople >= MIN_PEOPLE && maxPeople <= MAX_PEOPLE ? maxPeople : DEFAULT_PEOPLE);
} // end function setMaxPeople

// return maxPeople value
int Accommodation::getMaxPeople(void) const
{
	return maxPeople;
} // end function getMaxPeople

// set size value
// Valid size values are integers in [MIN_SIZE, MAX_SIZE].
// If an invalid size value is given, the object size is set to DEFAULT_SIZE.
void Accommodation::setSize(const int size)
{
	this->size = (size >= MIN_SIZE && size <= MAX_SIZE ? size : DEFAULT_SIZE);

} // end function setSize

// return size value
int Accommodation::getSize(void) const
{
	return size;
} // end function getSize

// set price value
// Valid price values are integers in [MIN_PRICE, MAX_SIZE].
// If an invalid price value is given, the object price is set to DEFAULT_PRICE.
void Accommodation::setPrice(const int price)
{
	this->price = (price >= MIN_PRICE && price <= MAX_PRICE ? price : DEFAULT_PRICE);
} // end function setPrice

// return price value
int Accommodation::getPrice(void) const
{
	return price;
} // end function getPrice

  // utility function
  // determine whether to display the Accommodation
bool Accommodation::shouldDisplay(RequestType rType, size_t request) const
{
	bool display{ false };

	switch (rType)
	{
	case RequestType::R_TYPE:
		switch (request)
		{
		case 1:
			if (getType() == Accommodation::Type::CABIN)
				display = true;
			break;
		case 2:
			if (getType() == Accommodation::Type::HOTEL_ROOM)
				display = true;
			break;
		case 3:
			display = true;
			break;
		}
		break;
	case RequestType::R_PEOPLE:
		if (maxPeople >= request)
			display = true;
		break;
	case RequestType::R_LUXURY_LEVEL:
		switch (request)
		{
		case 1:
			if (luxuryLevel == Accommodation::LuxuryLevel::COMFORT)
				display = true;
			break;
		case 2:
			if (luxuryLevel == Accommodation::LuxuryLevel::PREMIUM)
				display = true;
			break;
		case 3:
			if (luxuryLevel == Accommodation::LuxuryLevel::VIP)
				display = true;
			break;
		case 4:
			display = true;
			break;
		}
		break;
	}

	return display;
} // end function shouldDisplay


// overloaded stream insertion operator: non-member function
std::ostream& operator<<(std::ostream& output, const Accommodation& accommodation)
{
	output << std::left << "  " << std::setw(WIDTH_ACCOM) << "ID: " << accommodation.id
		<< "\n  " << std::setw(WIDTH_ACCOM) << "luxury level: ";
	switch (accommodation.luxuryLevel)
	{
	case Accommodation::LuxuryLevel::COMFORT:
		output << "comfort";
		break;
	case Accommodation::LuxuryLevel::PREMIUM:
		output << "premium";
		break;
	case Accommodation::LuxuryLevel::VIP:
		output << "VIP";
		break;
	}
	output << "\n  " << std::setw(WIDTH_ACCOM) << "maximum people:" << accommodation.maxPeople
		<< "\n  " << std::setw(WIDTH_ACCOM)  << "size:" << accommodation.size << " m^2"
		<< "\n  " << std::setw(WIDTH_ACCOM) << "price:" << accommodation.price << " euro"
		<< "\n";

	return output; // enable cascading stream insertion operations
}  // end overloaded operator<<
