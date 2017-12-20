/*
 *	Lab assignment for course Object Oriented Programming 2017
 *
 *	Véronique Wuyts
 *	Bachelor Elektronica-ICT option Application Development
 *	Thomas More campus De Nayer
 *
 *	Implementation of class Company
 */

// includes
#include <cstring>
#include <iostream>
#include "Company.h"

// default constructor
Company::Company(const char name[], const char address[])
{
	setName(name);
	setAddress(address);
	customers = new Customer*[MAX_CUSTOMERS];
	for (size_t i{ 0 }; i < MAX_CUSTOMERS; i++)
	{
		customers[i] = nullptr;
	}
	parks = new Park*[MAX_PARKS];
	for (size_t i{ 0 }; i < MAX_PARKS; i++)
	{
		parks[i] = nullptr;
	}
} // end default Company constructor

// constructor
Company::Company(const char name[], const char address[], Customer* customers[], size_t sizeOfCust, Park* parks[], size_t sizeOfParks)
{
	sizeOfCust = (sizeOfCust < MAX_CUSTOMERS ? sizeOfCust : MAX_CUSTOMERS);
	sizeOfParks = (sizeOfParks < MAX_PARKS ? sizeOfParks : MAX_PARKS);

	setName(name);
	setAddress(address);
	this->customers = new Customer*[MAX_CUSTOMERS];
	for (size_t i{ 0 }; i < MAX_CUSTOMERS; i++)
	{
		this->customers[i] = nullptr;
	}
	for (size_t i{ 0 }; i < sizeOfCust; i++)
	{
		this->customers[i] = customers[i];
	}
	this->parks = new Park*[MAX_PARKS];
	for (size_t i{ 0 }; i < MAX_PARKS; i++)
	{
		this->parks[i] = nullptr;
	}
	for (size_t i{ 0 }; i < sizeOfParks; i++)
	{
		this->parks[i] = parks[i];
	}
} // end Company constructor

// destructor
// Company is a composition of Customers and Parks, so these
// arrays and their contents are also destructed.
Company::~Company(void)
{
	for (size_t i{ 0 }; i < MAX_CUSTOMERS; i++)
	{
		delete customers[i];
	}
	delete[] customers;
	for (size_t i{ 0 }; i < MAX_PARKS; i++)
	{
		delete parks[i];
	}
	delete[] parks;
} // end Company destructor

// set name
void Company::setName(const char name[])
{
	size_t length{ strlen(name) };
	length = { (length < CHARS_NAME ? length : CHARS_NAME - 1) };
	strncpy_s(this->name, CHARS_NAME, name, length);
} // end function setName

// return constant pointer to constant name
const char* const Company::getName(void) const
{
	return name;
} // end function getName

// set address
void Company::setAddress(const char address[])
{
	size_t length{ strlen(address) };
	length = (length < CHARS_ADDRESS ? length : CHARS_ADDRESS - 1);
	strncpy_s(this->address, CHARS_ADDRESS, address, length);
} // end function setAddress

// return constant pointer to constant address
const char* const Company::getAddress(void) const
{
	return address;
} // end function getAddress

// set customer
// Stores a pointer to the Customer in the first free index of
// the customers array. If no free index is found, the Customer
// is not stored and a message is printed.
// Setting a nullptr has no effect.
// The Customer object, to which the given pointer points to, may be
// destroyed after running this set function.
void Company::setCustomers(Customer* const customer)
{
	size_t counter{ 0 };
	bool isSet{ false };

	if (customer != nullptr) // cannot call function on nullptr
	{
		while (counter < MAX_CUSTOMERS && !isSet)
		{
			if (this->customers[counter] == nullptr)
			{
				this->customers[counter] = new Customer(customer->getName(), customer->getAddress(),
					customer->getEmail(), customer->getBankAccount());
				for (size_t i{ 0 }; i < MAX_BOOKING; i++)
				{
					this->customers[counter]->setBookings(customer->getBooking(i));
				}
				isSet = true;
			}
			counter++;
		}

		if (!isSet)
		{
			std::cout << "The customer was not set.\n" << std::endl;
		}
	}
} // end function setCustomers

// return a constant pointer to the Customer at the given index
// in the customers array.
// If the given index is greater than or equal to MAX_CUSTOMERS,
// a null pointer is returned.
Customer* const Company::getCustomers(size_t index) const
{
	if (index < MAX_CUSTOMERS)
	{
		return customers[index];
	}
	return nullptr;
} // end function getCustomers

// set park
// Stores a pointer to the Park in the first free index of
// the parks array. If no free index is found, the Park is
// not stored and a message is printed.
// Setting a nullptr has no effect.
// The Park object, to which the given pointer points to, may be
// destroyed after running this set function.
void Company::setParks(Park* const park)
{
	size_t counter{ 0 };
	bool isSet{ false };

	if (park != nullptr) // cannot call function on nullptr
	{
		while (counter < MAX_PARKS && !isSet)
		{
			if (this->parks[counter] == nullptr)
			{
				this->parks[counter] = new Park(park->getName(), park->getAddress(), park->getSubtropicPar(), park->getBikeRental(),
					park->getWaterBikeRental(), park->getBowlingAlley(), park->getKidsParadise());
				for (size_t i{ 0 }; i < MAX_PARK_ACCOM; i++)
				{
					this->parks[counter]->setAccommodations(park->getAccommodations(i));
				}
				isSet = true;
			}
			counter++;
		}

		if (!isSet)
		{
			std::cout << "The park was not set.\n" << std::endl;
		}
	}
} // end function setParks

// return constant pointer to a Park at the given index in the
// parks array
// If the given index is greater than or equal to MAX_PARKS,
// a null pointer is returned.
Park* const Company::getParks(size_t index) const
{
	if (index < MAX_PARKS)
	{
		return parks[index];
	}
	return nullptr;
} // end function getParks

// return number of Customers
size_t Company::getNoOfCustomers(void) const
{
	size_t noOfCustomers{ 0 };

	for (size_t i{ 0 }; i < MAX_CUSTOMERS; i++)
	{
		if (customers[i] != nullptr)
		{
			++noOfCustomers;
		}
	}

	return noOfCustomers;
} // end function getNoOfCustomers

// return number of Parks
size_t Company::getNoOfParks(void) const
{
	size_t noOfParks{ 0 };

	for (size_t i{ 0 }; i < MAX_PARKS; i++)
	{
		if (parks[i] != nullptr)
		{
			++noOfParks;
		}
	}

	return noOfParks;
} // end function getNoOfParks

// return the index of the chosen Customer
// If the choice is not valid, DEFAULT_INDEX is returned
size_t Company::getCustIndex(size_t choice) const
{
	int counter{ 0 };
	size_t index{ DEFAULT_INDEX };

	for (size_t i{ 0 }; i < MAX_CUSTOMERS; i++)
	{
		if (customers[i] != nullptr && ++counter == choice)
		{
			index = i;
		}
	}

	return index;
} // end function getCustIndex

// return the index of the chosen Park
// If the choice is not valid, DEFAULT_INDEX is returned
size_t Company::getParkIndex(size_t choice) const
{
	int counter{ 0 };
	size_t index{ DEFAULT_INDEX };

	for (size_t i{ 0 }; i < MAX_PARKS; i++)
	{
		if (parks[i] != nullptr && ++counter == choice)
		{
			index = i;
		}
	}
	
	return index;
} // end function getParkIndex

// destruct the Customer at the given index
void Company::destructCustomerAt(size_t index)
{
	if (index < MAX_CUSTOMERS)
	{
		delete customers[index]; // delete on nullptr has no effect
		customers[index] = nullptr; // set the index as 'free'
	}
} // end function destructCustomerAt

// destruct the Park at the given index
void Company::destructParkAt(size_t index)
{
	Accommodation* accomPtr{ nullptr };

	if (index < MAX_PARKS)
	{
		if (parks[index] != nullptr)
		{
			// delete all the accommodations of the park from Customer's Bookings
			for (size_t i{ 0 }; i < MAX_PARK_ACCOM; i++)
			{
				if ((accomPtr = parks[index]->getAccommodations(i)) != nullptr)
				{
					for (size_t j = 0; j < MAX_CUSTOMERS; j++)
					{
						if (customers[j] != nullptr)
						{
							customers[j]->deleteAccomFromBooking(accomPtr->getId());
						}
					}
				}
			}
		}
		delete parks[index]; // delete on nullptr has no effect
		parks[index] = nullptr; // set the index as 'free'
	}
} // end function destructParkAt

// overloaded stream insertion operator: non-member function
std::ostream& operator<<(std::ostream& output, const Company& company)
{
	output << "Company: " << company.name
		<< "\n  address: " << company.address
		<< "\n";

	return output; // enable cascading stream insertion operations
}  // end overloaded operator<<
