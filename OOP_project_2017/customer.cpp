/*
 *	Lab assignment for course Object Oriented Programming 2017
 *
 *	Véronique Wuyts
 *	Bachelor Elektronica-ICT option Application Development
 *	Thomas More campus De Nayer
 *
 *	Implementation of class Customer
 */

// includes
#include <cstring>
#include <iomanip>
#include "customer.h"

// default constructor
Customer::Customer(const char name[], const char address[], const char email[], const char bankAccount[])
{
	setName(name);
	setAddress(address);
	setEmail(email);
	setBankAccount(bankAccount);
	bookings = new Booking*[MAX_BOOKING];
	for (size_t i{ 0 }; i < MAX_BOOKING; i++)
	{
		bookings[i] = nullptr;
	}
} // end default Customer constructor

// constructor
Customer::Customer(const char name[], const char address[], const char email[], const char bankAccount[],
	Booking* bookings[], size_t sizeOfBookings)
{
	sizeOfBookings = (sizeOfBookings < MAX_BOOKING ? sizeOfBookings : MAX_BOOKING);

	setName(name);
	setAddress(address);
	setEmail(email);
	setBankAccount(bankAccount);
	this->bookings = new Booking*[MAX_BOOKING];
	for (size_t i{ 0 }; i < MAX_BOOKING; i++)
	{
		this->bookings[i] = nullptr;
	}
	for (size_t i{ 0 }; i < sizeOfBookings; i++)
	{
		this->bookings[i] = bookings[i];
	}
} // end Customer constructor

// destructor
// If Customer is destructed, also the bookings array and its
// contents is destructed to avoid memory leaks.
Customer::~Customer(void)
{
	for (size_t i{ 0 }; i < MAX_BOOKING; i++)
	{
		delete bookings[i];
	}
	delete[] bookings;
} // end Customer destructor

// set name
void Customer::setName(const char name[])
{
	size_t length{ strlen(name) };
	length = (length < CHARS_NAME ? length : CHARS_NAME - 1);
	strncpy_s(this->name, CHARS_NAME, name, length);
} // end function setName

// return constant pointer to constant name
const char* const Customer::getName(void) const
{
	return name;
} // end function getNane

// set address
void Customer::setAddress(const char address[])
{
	size_t length{ strlen(address) };
	length = (length < CHARS_ADDRESS ? length : CHARS_ADDRESS - 1);
	strncpy_s(this->address, CHARS_ADDRESS, address, length);
} // end function setAddress

// return constant pointer to constant address
const char* const Customer::getAddress(void) const
{
	return address;
} // end function getAddress

// set email
void Customer::setEmail(const char email[])
{
	size_t length{ strlen(email) };
	length = (length < CHARS_EMAIL ? length : CHARS_EMAIL - 1);
	strncpy_s(this->email, CHARS_EMAIL, email, length);
} // end function setEmail

// return constant pointer to constant email
const char* const Customer::getEmail(void) const
{
	return email;
} // end function getEmail

// set bankAccount
void Customer::setBankAccount(const char bankAccount[])
{
	size_t length{ strlen(bankAccount) };
	length = (length < CHARS_BANK_ACCOUNT ? length : CHARS_BANK_ACCOUNT - 1);
	strncpy_s(this->bankAccount, CHARS_BANK_ACCOUNT, bankAccount, length);
} // end function setBankAccount+

// return constant pointer to constant bankAccount
const char* const Customer::getBankAccount(void) const
{
	return bankAccount;
} // end function getBankAccount

// set Booking
// Stores the pointer to the Booking in the first free index of
// the bookings array. If no free index is found, the
// Booking is not stored and a message is printed.
// Setting a nullptr has no effect.
// The Booking object, to which the given pointer points to, may be
// destroyed after running this set function.
void Customer::setBookings(Booking * const booking)
{
	size_t counter{ 0 };
	bool isSet{ false };

	if (booking != nullptr) // cannot call function on nullptr
	{
		while (counter < MAX_BOOKING && !isSet)
		{
			if (this->bookings[counter] == nullptr)
			{
				// Make sure that contents of bookings array is created with 'new'
				this->bookings[counter] = new Booking(booking->getBookingId(), booking->getActivityPass(),
					booking->getSportPass(), booking->getBikeRental(), booking->getSubtropicPass());
				for (size_t i{ 0 }; i < MAX_BOOKING_ACCOM; i++)
				{
					this->bookings[counter]->setAccommodations(booking->getAccommodations(i));
				}
				isSet = true;
			}
			counter++;
		}

		if (!isSet)
		{
			std::cout << "The booking was not set.\n" << std::endl;
		}
	}
} // end function setBooking

// return constant pointer to a Booking at the given index in the
// bookings array
// If the given index is greater than or equal to MAX_BOOKING,
// a null pointer is returned.
Booking* const Customer::getBooking(size_t index) const
{
	if (index < MAX_BOOKING)
	{
		return bookings[index];
	}

	return nullptr;
} // end function getBooking

// return number of Bookings
size_t Customer::getNoOfBookings(void) const
{
	size_t noOfBookings{ 0 };

	for (size_t i{ 0 }; i < MAX_BOOKING; i++)
	{
		if (bookings[i] != nullptr)
		{
			++noOfBookings;
		}
	}

	return noOfBookings;
} // end function getNoOfBookings

// return index of the Booking with the given bookingId
// If the given id is not found, DEFAULT_INDEX is returned.
size_t Customer::getBookingIndexOf(int bookingId) const
{
	size_t index{ DEFAULT_INDEX };
	size_t i{ 0 };

	while (i < MAX_BOOKING && index == DEFAULT_INDEX)
	{
		if (bookings[i] != nullptr && bookings[i]->getBookingId() == bookingId)
		{
			index = i;
		}
		i++;
	}

	return index;
} // end function getBookingIndexOf

// destruct the Booking at the given index in the bookings array
void Customer::destructBookingAt(size_t index)
{
	if (index < MAX_BOOKING)
	{
		delete bookings[index]; // delete on nullptr has no effect
		bookings[index] = nullptr; // set the index as 'free'
	}
} // end function destructBookingAt

// delete the Accommodation with the given id from the bookings
void Customer::deleteAccomFromBooking(int id)
{
	for (size_t i{ 0 }; i < MAX_BOOKING; i++)
	{
		size_t counter{ 0 };
		while (bookings[i] != nullptr && counter < MAX_BOOKING_ACCOM)
		{
			if (bookings[i]->getAccommodations(counter) != nullptr
				&& bookings[i]->getAccommodations(counter)->getId() == id)
			{
				bookings[i]->deleteAccomAt(counter);
				if (bookings[i]->getNoOfAccomm() == 0)
				{
					destructBookingAt(i);
				}
			}
			counter++;
		}
	}
} // end function deleteAccomFromBooking

// overloaded stream insertion operator: non-member function
std::ostream& operator<<(std::ostream& output, const Customer& customer)
{
	output << "Customer: " << customer.name  << std::left
		<< "\n  " << std::setw(WIDTH_CUST) << "address:" << customer.address
		<< "\n  " << std::setw(WIDTH_CUST) << "e-mail:" << customer.email
		<< "\n  " << std::setw(WIDTH_CUST) << "bank account:" << customer.bankAccount
		<< std::endl;

	return output; // enable cascading stream insertion operations
} // end overloaded operator<<
