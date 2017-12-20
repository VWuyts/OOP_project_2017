/*
 *	Lab assignment for course Object Oriented Programming 2017
 *
 *	Véronique Wuyts
 *	Bachelor Elektronica-ICT option Application Development
 *	Thomas More campus De Nayer
 *
 *	Implementation of class Booking
 */

// includes
#include <iomanip>
#include "booking.h"

// default constructor
Booking::Booking(int bookingId, bool activityPass, bool sportPass, bool bikeRental, bool subtropicPass)
{
	this->bookingId = bookingId; // no validation
	noOfAccomm = 0; // no validation required
	this->activityPass = activityPass; // no validation
	this->sportPass = sportPass; // no validation
	this->bikeRental = bikeRental; // no validation
	this->subtropicPass = subtropicPass; // no validation
	accommodations = new Accommodation*[MAX_BOOKING_ACCOM];
	for (size_t i{ 0 }; i < MAX_BOOKING_ACCOM; i++)
	{
		accommodations[i] = nullptr;
	}
} // end default Booking constructor

// contructor
Booking::Booking(int bookingId, bool activityPass, bool sportPass, bool bikeRental, bool subtropicPass,
	int noOfAccomm, Accommodation* accommodations[], size_t sizeOfAccoms)
{
	sizeOfAccoms = (sizeOfAccoms < MAX_BOOKING_ACCOM ? sizeOfAccoms : MAX_BOOKING_ACCOM);

	this->bookingId = bookingId; // no validation
	setNoOfAccomm(noOfAccomm);
	this->activityPass = activityPass; // no validation
	this->sportPass = sportPass; // no validation
	this->bikeRental = bikeRental; // no validation
	this->subtropicPass = subtropicPass; // no validation
	this->accommodations = new Accommodation*[MAX_BOOKING_ACCOM];
	for (size_t i{ 0 }; i < MAX_BOOKING_ACCOM; i++)
	{
		this->accommodations[i] = nullptr;
	}
	for (size_t i{ 0 }; i < sizeOfAccoms; i++)
	{
		this->accommodations[i] = accommodations[i];
	}
}

// destructor
// If Booking is destructed, also the accommodations array is destructed
// to avoid memory leaks.
// The content of the accommodations array is not destructed, as the
// Accommodations still exist in the Park.
Booking::~Booking(void)
{
	delete[] accommodations;
} // end Booking destructor

// set bookingId value
void Booking::setBookingId(const int bookingId)
{
	this->bookingId = bookingId;
} // end function setBookingId

// return bookingId value
int Booking::getBookingId(void) const
{
	return bookingId;
} // end function getBookingId

// set noOfAccomm value
// If the given noOfAccomm value is greater than or equal to 1 and
// less than or equal to MAX_BOOKING_ACCOM, the object noOfAccomm is set
// to the given noOfAccomm value, else the object noOfAccomm is set to 1.
void Booking::setNoOfAccomm(const int noOfAccomm)
{
	this->noOfAccomm = (noOfAccomm >= 1 && noOfAccomm <= MAX_BOOKING_ACCOM ? noOfAccomm : 1);
} // end function setNoOfAccom

// return noOfAccomm value
int Booking::getNoOfAccomm(void) const
{
	return noOfAccomm;
} // end function getNoOfAccomm

// set activityPass value
void Booking::setActivityPass(const bool activityPass)
{
	this->activityPass = activityPass;
} // end function setActivityPass

// return activityPass value
bool Booking::getActivityPass(void) const
{
	return activityPass;
} // end function getActivityPass

// set sportPass value
void Booking::setSportPass(const bool sportPass)
{
	this->sportPass = sportPass;
} // end function setSportPass

// return sportPass value
bool Booking::getSportPass(void) const
{
	return sportPass;
} // end function getSportPass

// set bikeRental value
void Booking::setBikeRental(const bool bikeRental)
{
	this->bikeRental = bikeRental;
} // end function setBikeRental

// return bikeRental value
bool Booking::getBikeRental(void) const
{
	return bikeRental;
} // end function getBikeRental

// set subtropicPass value
void Booking::setSubtropicPass(const bool subtropicPass)
{
	this->subtropicPass = subtropicPass;
} // end function setsubtropicPass

// return subtropicPass value
bool Booking::getSubtropicPass(void) const
{
	return subtropicPass;
} // end function getsubtropicPass

  // set accommodation
  // Stores the pointer to the Accomodation in the first free index of
  // the accommodations array. If no free index is found, the
  // Accommodation is not stored and a message is printed.
  // Setting a nullptr has no effect.
  // The given Accommodation pointer has to be a pointer from the accommodations
  // array of a Park object.
void Booking::setAccommodations(Accommodation* const accommodation)
{
	size_t counter{ 0 };
	bool isSet{ false };

	if (accommodation != nullptr)
	{
		while (counter < MAX_BOOKING_ACCOM && !isSet)
		{
			if (accommodations[counter] == nullptr)
			{
				accommodations[counter] = accommodation; // pointer from accommodations array from a Park object, dus already created with 'new'
				noOfAccomm++;
				isSet = true;
			}
			counter++;
		}

		if (!isSet)
		{
			std::cout << "The accommodation was not set.\n" << std::endl;
		}
	}
} // end function setAccommodations

  // return constant pointer to the Accommodation at the given index
  // in the accommodations array.
  // If the given index is greater than or equal to MAX_BOOKING_ACCOM,
  // a null pointer is returned.
Accommodation* const Booking::getAccommodations(size_t index) const
{
	if (index < MAX_BOOKING_ACCOM)
	{
		return accommodations[index];
	}

	return nullptr;
} // end function getAccommodations

// return totalPrice value
int Booking::getTotalPrice(void) const
{
	return calculateTotalPrice();

} // end function getTotalPrice

// calculate totalPrice value
int Booking::calculateTotalPrice(void) const
{
	int totalPrice{ 0 };

	for (size_t i{ 0 }; i < noOfAccomm; i++)
	{
		if (accommodations[i] != nullptr)
		{
			totalPrice += accommodations[i]->getPrice();
		}
	}
	if (activityPass)
	{
		totalPrice += PRICE_ACTIVITY;
	}
	if (sportPass)
	{
		totalPrice += PRICE_SPORT;
	}
	if (bikeRental)
	{
		totalPrice += PRICE_BIKE_RENTAL;
	}
	if (subtropicPass)
	{
		totalPrice += PRICE_SUB_TROPIC;
	}

	return totalPrice;
} // end function calculateTotalPrice

// delete the Accommodation with the given index
void Booking::deleteAccomAt(size_t index)
{
	if (index < MAX_BOOKING_ACCOM)
	{
		accommodations[index] = nullptr;
		noOfAccomm--;
	}
} // end function deleteAccomAt

// overloaded stream insertion operator: non-member function
std::ostream& operator<<(std::ostream& output, const Booking& booking)
{
	Accommodation* accomPtr{ nullptr };
	
	output << "Booking:"
		<< std::left
		<< "\n  " << std::setw(WIDTH_BOOKING) << "ID:" << booking.bookingId
		<< "\n  " << std::setw(WIDTH_BOOKING) << "number of Accommodations:" << booking.noOfAccomm;
	if (booking.noOfAccomm > 0)
	{
		output << "\n  accommodations:";
		for (size_t i{ 0 }; i < MAX_BOOKING_ACCOM; i++)
		{
			if ((accomPtr = booking.accommodations[i]) != nullptr)
			{
				output << "\n    " << (i + 1) << ". "
					<< (accomPtr->getType() == Accommodation::Type::CABIN ? "Cabin" : "Hotelroom")
					<< " with id " << accomPtr->getId()
					<< " for maximum " << accomPtr->getMaxPeople() << " people";
			}
		}
	}
	output << "\n  " << std::setw(WIDTH_BOOKING) << "activity pass:" << (booking.activityPass ? "yes" : "no")
		<< "\n  " << std::setw(WIDTH_BOOKING) << "sport pass:" << (booking.sportPass ? "yes" : "no")
		<< "\n  " << std::setw(WIDTH_BOOKING) << "bike rental:" << (booking.bikeRental ? "yes" : "no")
		<< "\n  " << std::setw(WIDTH_BOOKING) << "subtropic pass:" << (booking.subtropicPass ? "yes" : "no")
		<< "\n  " << std::setw(WIDTH_BOOKING) << "total price:" << booking.getTotalPrice() << " euro";

	return output; // enable cascading stream insertion operations
} // end overloaded operator<<
