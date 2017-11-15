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
#include <iostream>
#include "Booking.h"


// default constructor
Booking::Booking(int bookingId, Customer* customer, bool activityPass, bool sportPass, bool bikeRental, bool subTropicPass)
{
	setBookingId(bookingId);
	setCustomer(customer);
	setNoOfAccomm(0);
	for (size_t i{ 0 }; i < MAX_BOOKING; i++)
	{
		accommodations[i] = nullptr;
	}
	setActivityPass(activityPass);
	setSportPass(sportPass);
	setBikeRental(bikeRental);
	setSubTropicPass(subTropicPass);
	calculateTotalPrice(&totalPrice);
} // end Booking default constructor

// destructor
Booking::~Booking(void)
{
	// TO DO: implement destructor
} // end Booking destructor

// return bookingId value
int Booking::getBookingId(void) const
{
	return bookingId;
} // end function getBookingId

// return constant pointer to constant customer
const Customer* const Booking::getCustomer(void) const
{
	return customer;
} // end function getCustomer

// return noOfAccomm value
int Booking::getNoOfAccomm(void) const
{
	return noOfAccomm;
} // end function getNoOfAccomm

// return constant pointer to constant accommodations array
const Accommodation* const * const Booking::getAccommodations(void) const
{
	return accommodations;
} // end function getAccommodations

// return activityPass value
bool Booking::getActivityPass(void) const
{
	return activityPass;
} // end function getActivityPass

// return sportPass value
bool Booking::getSportPass(void) const
{
	return sportPass;
} // end function getSportPass

// return bikeRental value
bool Booking::getBikeRental(void) const
{
	return bikeRental;
} // end function getBikeRental

// return subTropicPass value
bool Booking::getSubTropicPass(void) const
{
	return subTropicPass;
} // end function getSubTropicPass

// return totalPrice value
int Booking::getTotalPrice(void)
{
	this->calculateTotalPrice(&totalPrice);

	return totalPrice;
} // end function getTotalPrice

// set bookingId value
void Booking::setBookingId(const int bookingId)
{
	this->bookingId = bookingId;
} // end function setBookingId

// set customer
// If the given customer is not a NULL pointer, the object customer
// is set to the given customer
void Booking::setCustomer(Customer* const customer)
{
	if (customer != nullptr)
	{
		this->customer = customer;
	}
} // end function setCustomer

// set noOfAccomm value
// If the given noOfAccomm value is greater than or equal to 0 and
// less than or equal to MAX_BOOKINGS, the object noOfAccomm is set
// to the given noOfAccomm value, else the object noOfAccomm is set to 0.
void Booking::setNoOfAccomm(const int noOfAccomm)
{
	this->noOfAccomm = (noOfAccomm >= 0 && noOfAccomm <= MAX_BOOKING ? noOfAccomm : 0);
} // end function setNoOfAccomm

// set accommodation
// Stores the pointer to the Accomodation in the first free index of
// the accommodations array. If no free index is found, the Accomodation
// is not stored and a message is shown.
void Booking::setAccommodations(Accommodation* const accommodation)
{
	size_t counter = 0;
	bool isSet = false;

	while (counter < MAX_BOOKING && !isSet)
	{
		if (accommodations[counter] == nullptr)
		{
			accommodations[counter] = accommodation;
			setNoOfAccomm(getNoOfAccomm() + 1);
			isSet = true;
		}
		counter++;
	}

	if (!isSet)
	{
		std::cout << "The accommodation could not be set.\n" << std::endl;
	}
} // end function setAccommodations

// set activityPass value
void Booking::setActivityPass(const bool activityPass)
{
	this->activityPass = activityPass;
} // end function setActivityPass

// set sportPass value
void Booking::setSportPass(const bool sportPass)
{
	this->sportPass = sportPass;
} // end function setSportPass

// set bikeRental value
void Booking::setBikeRental(const bool bikeRental)
{
	this->bikeRental = bikeRental;
}

// set subTropicPass value
void Booking::setSubTropicPass(const bool subTropicPass)
{
	this->subTropicPass = subTropicPass;
}

// calculate totalPrice value
void Booking::calculateTotalPrice(int* totalPrice)
{
	*totalPrice = 0;

	for (size_t i{ 0 }; i < noOfAccomm; i++)
	{
		if (accommodations[i] != nullptr)
		{
			*totalPrice += accommodations[i]->getPrice();
		}
	}
	if (activityPass)
	{
		*totalPrice += ACTIVITY_PRICE;
	}
	if (sportPass)
	{
		*totalPrice += SPORT_PRICE;
	}
	if (bikeRental)
	{
		*totalPrice += BIKE_RENTAL_PRICE;
	}
	if (subTropicPass)
	{
		*totalPrice += SUB_TROPIC_PRICE;
	}
}