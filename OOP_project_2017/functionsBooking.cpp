/*
 *	Lab assignment for course Object Oriented Programming 2017
 *
 *	Véronique Wuyts
 *	Bachelor Elektronica-ICT option Application Development
 *	Thomas More campus De Nayer
 *
 *	Implementation of Booking functions
 */

// Includes
#include "cabin.h"
#include "hotelroom.h"
#include "functionsBooking.h"
#include "functionsCustomer.h"
#include "functionsPark.h"
#include "functionsUserInput.h"

// view all Bookings of a specific Customer included in the given Company
void checkBooking(Company* co)
{
	Booking* bookingPtr{ nullptr };
	Customer* custPtr{ nullptr };
	size_t noOfCusts{ co->getNoOfCustomers() };
	size_t custIndex{ 0 };

	std::cout << "\nCheck bookings" << std::endl;
	printLine(15);
	// check if there are customers included in the given Company
	if (noOfCusts == 0)
	{
		std::cout << "Company " << co->getName() << " has no customers and thus no bookings.\n" << std::endl;
	}
	else
	{
		std::cout << "Please check from which customer you want to check the bookings:" << std::endl;
		checkCustomer(co);
		std::cout << noOfCusts + 1 << ". cancel" << std::endl;
		custIndex = requestIndex("customer", noOfCusts + 1);
		if (custIndex != (noOfCusts + 1))
		{
			custIndex = co->getCustIndex(custIndex);
			if (custIndex != DEFAULT_INDEX)
			{
				// check if there are bookings included in the requested customer
				custPtr = co->getCustomers(custIndex);
				if (custPtr->getNoOfBookings() == 0)
				{
					std::cout << "\nCustomer " << custPtr->getName() << " has no bookings\n" << std::endl;
				}
				else
				{
					std::cout << "\nCustomer " << custPtr->getName() << " has following bookings:" << std::endl;
					for (size_t i{ 0 }; i < MAX_BOOKING; i++)
					{
						if ((bookingPtr = custPtr->getBooking(i)) != nullptr)
						{
							std::cout << *bookingPtr << std::endl;
						}
					}
					std::cout << std::endl;
				}
			}
		}
	}
} // end function checkBooking

// create a booking and add it to a customer included in the given Company
void createBooking(Company* co)
{
	size_t custIndex{ 0 };
	size_t parkIndex{ 0 };
	size_t noOfCusts{ co->getNoOfCustomers() };
	size_t noOfParks{ co->getNoOfParks() };
	int noOfAccomm{ 0 };
	int bookingId{ 0 };
	bool services[4];
	bool activityPass{ false };
	bool sportPass{ false };
	bool bikeRental{ false };
	bool subtropicPass{ false };
	Accommodation* accomPtr{ nullptr };
	Booking* bookingPtr{ nullptr };
	Customer* custPtr{ nullptr };
	Park* parkPtr{ nullptr };
	Accommodation* accommodations[MAX_BOOKING_ACCOM];
	for (size_t i{ 0 }; i < MAX_BOOKING_ACCOM; i++)
	{
		accommodations[i] = nullptr;
	}

	std::cout << "\nCreate booking" << std::endl;
	printLine(14);
	// check if there are parks included in the given Company
	if (noOfParks == 0)
	{
		std::cout << "\nCompany " << co->getName() << " has not yet any parks where you can book your holiday.\n" << std::endl;
	}
	else
	{
		// check if there are customers included in the given Company
		if (noOfCusts == 0)
		{
			std::cout << "\nYou first have to create a customer.\n" << std::endl;
		}
		else
		{
			std::cout << "Please check to which customer you want to add a booking:" << std::endl;
			checkCustomer(co);
			std::cout << (noOfCusts + 1) << ". cancel\n" << std::endl;
			custIndex = requestIndex("customer", noOfCusts + 1);
			if (custIndex != (noOfCusts + 1))
			{
				custIndex = co->getCustIndex(custIndex);
				if (custIndex != DEFAULT_INDEX)
				{
					custPtr = co->getCustomers(custIndex);
					// check if a booking can be added
					if (custPtr->getNoOfBookings() == MAX_BOOKING)
					{
						std::cout << "\nCustomer " << custPtr->getName() << " has already reached the maximum number of bookings.\n" << std::endl;
					}
					else
					{
						std::cout << "\nPlease check the park where you want to stay:" << std::endl;
						checkPark(co);
						std::cout << (noOfParks + 1) << ". cancel\n" << std::endl;
						parkIndex = requestIndex("park", noOfParks + 1);
						if (parkIndex != (noOfParks + 1))
						{
							parkIndex = co->getParkIndex(parkIndex);
							if (parkIndex != DEFAULT_INDEX)
							{
								parkPtr = co->getParks(parkIndex);
								// check if the requested park has accommodations
								if (parkPtr->getNoOfAccommodations() == 0)
								{
									std::cout << "\nPark " << parkPtr->getName() << " has no available accommodations." << std::endl;
								}
								else
								{
									do
									{
										std::cout << std::endl;
										// choose accommodations within the requested park
										accomPtr = searchAccommodation(parkPtr);
										if (accomPtr != nullptr)
										{
											accommodations[noOfAccomm] = accomPtr;
											noOfAccomm++;
											std::cout << "\nThe accommodatiom with id " << accomPtr->getId()
												<< " has been added to your booking\n" << std::endl;
										}
									} while (noOfAccomm < MAX_BOOKING_ACCOM
										&& requestBool("", "\nDo you want to add another accommodation to your booking"));
								}
								// a Booking has to have at least 1 Accommodation
								if (noOfAccomm > 0)
								{
									// request an id for the new Booking
									bookingId = requestInt("\nPlease give the bookingId");
									// request if additional services may be booked
									if (requestBool("", "\nDo you want to add services to your booking"))
									{
										bookServices(services, parkPtr);
									}
									// create new Booking and add to requested Customer
									bookingPtr = new Booking(bookingId, services[0], services[1], services[2], services[3], noOfAccomm, accommodations, noOfAccomm);
									custPtr->setBookings(bookingPtr);
									std::cout << "\nThe booking with id " << bookingId
										<< " and total price " << bookingPtr->getTotalPrice()
										<< " euro has been added to customer "
										<< custPtr->getName() << "\n" << std::endl;
									delete bookingPtr;
									bookingPtr = nullptr;
								}
								else
								{
									std::cout << "\nNo booking has been created.\n" << std::endl;
								}
							} // end if parkIndex != DEFAULT_INDEX
						} // end if parkIndex != (noOfParks + 1)
					} // end if-else custPtr->getNoOfBookings() == MAX_BOOKING
				} // end if custIndex != DEFAULT_INDEX
			} // end if custIndex != (noOfCusts + 1)
		} // end if-else noOfCusts == 0
	} // end if-else noOfParks == 0
} // end function createBooking

// change a Booking from a Customer included in the given Company
void changeBooking(Company* co)
{
	int bookingId{ DEFAULT_INT };
	int accomId{ 0 };
	int changedInt{ 0 };
	size_t bookingIndex{ DEFAULT_INDEX };
	size_t custIndex{ 0 };
	size_t changeIndex{ 0 };
	size_t accomIndex{ 0 };
	size_t counter{ 0 };
	size_t serviceIndex{ 0 };
	//size_t parkIndex{ 0 };
	Accommodation* accomPtr{ nullptr };
	Booking* bookingPtr{ nullptr };
	Customer* custPtr{ nullptr };
	Park* parkPtr{ nullptr };
	size_t accomIndexArray[MAX_BOOKING_ACCOM + 1];

	std::cout << "Change booking" << std::endl;
	printLine(14);
	// Check if there are customers included in the given Company
	if (co->getNoOfCustomers() == 0)
	{
		std::cout << "\nCompany " << co->getName() << " has no customers and thus no bookings.\n" << std::endl;
	}
	else
	{
		std::cout << "Please check the booking you want to change:" << std::endl;
		checkBooking(co);
		bookingId = requestInt("Please give the ID of the booking to change\nor -999 to cancel");
		if (bookingId != DEFAULT_INT)
		{
			while (custIndex < MAX_CUSTOMERS && bookingIndex == DEFAULT_INDEX)
			{
				if ((custPtr = co->getCustomers(custIndex)) != nullptr)
				{
					bookingIndex = custPtr->getBookingIndexOf(bookingId);
				}
				custIndex++;
			}
			if (bookingIndex != DEFAULT_INDEX)
			{
				bookingPtr = custPtr->getBooking(bookingIndex); // custPtr is not changed after getting the bookingIndex
				std::cout << "\nWhat do you want to change?"
					<< "\n1. id"
					<< "\n2. services"
					<< "\n3. add accommodation"
					<< "\n4. delete accommodation"
					<< "\n5. cancel\n"
					<< std::endl;
				changeIndex = requestIndex("", 5);
				std::cout << std::endl;
				// change the requested item
				switch (changeIndex)
				{
				case 1: // id
					changedInt = requestInt("new booking id");
					bookingPtr->setBookingId(changedInt);
					std::cout << "\nThe booking now has id:" << bookingPtr->getBookingId() << "\n" << std::endl;
					break;
				case 2: // services
					std::cout << "Please select the service you want to change"
						<< "\n1. activity pass"
						<< "\n2. sport pass"
						<< "\n3. bike rental"
						<< "\n4. subtropic pass"
						<< "\n5. cancel\n"
						<< std::endl;
					serviceIndex = requestIndex("", 5);
					// Search an Accomodation pointer
					while (accomPtr == nullptr && accomIndex < MAX_BOOKING_ACCOM)
					{
						accomPtr = bookingPtr->getAccommodations(accomIndex);
					}
					// search the Park based on the Accommodation id (a booking includes accommodations from 1 park)
					accomId = accomPtr->getId();
					accomIndex = DEFAULT_INDEX;
					while (counter < MAX_PARKS && accomIndex == DEFAULT_INDEX)
					{
						if ((parkPtr = co->getParks(counter)) != nullptr)
						{
							accomIndex = parkPtr->getAccomIndexOf(accomId);
						}
						counter++;
					} // parkPtr does not change after finding a valid accomIndex
					// change the requested service, if available in the park
					switch (serviceIndex)
					{
					case 1: // activity pass
						bookingPtr->setActivityPass(!bookingPtr->getActivityPass());
						std::cout << "\nThe booking now has" << (bookingPtr->getActivityPass() ? " an" : " no")
							<< " activity pass\n" << std::endl;
						break;
					case 2: // sport pass
						if (!bookingPtr->getSportPass() && !parkPtr->getSportsHall())
						{
							std::cout << "\nSport pass cannot be changed,\nbecause park " << parkPtr->getName()
								<< " does not have a sports hall\n" << std::endl;
						}
						else
						{
							bookingPtr->setSportPass(!bookingPtr->getSportPass());
							std::cout << "\nThe booking now has" << (bookingPtr->getActivityPass() ? " a" : " no")
								<< " sports pass\n" << std::endl;
						}
						break;
					case 3: // bike rental
						if (!bookingPtr->getBikeRental() && !parkPtr->getBikeRental())
						{
							std::cout << "\nBike rental cannot be changed,\nbecause park " << parkPtr->getName()
								<< " does not offer bike rental\n" << std::endl;
						}
						else
						{
							bookingPtr->setBikeRental(!bookingPtr->getBikeRental());
							std::cout << "\nThe booking now has" << (bookingPtr->getActivityPass() ? "" : " no")
								<< " bike rental\n" << std::endl;
						}
						break;
					case 4: // subtropic pass
						if (!bookingPtr->getSubtropicPass() && !parkPtr->getSubtropicPar())
						{
							std::cout << "\nSubtropic pass cannot be changed,\nbecause park " << parkPtr->getName()
								<< " does not have a subtropic paradise\n" << std::endl;
						}
						else
						{
							bookingPtr->setSubtropicPass(!bookingPtr->getSubtropicPass());
							std::cout << "\nThe booking now has" << (bookingPtr->getSubtropicPass() ? " a" : " no")
								<< " subtropic pass\n" << std::endl;
						}
						break;
					case 5: // cancel
						break;
					}
					break;
				case 3: // add accommodation
					// check if a booking can be added to the Customer
					if (custPtr->getNoOfBookings() == MAX_BOOKING)
					{
						std::cout << "\nCustomer " << custPtr->getName()
							<< " has already reached the maximum number of bookings\n" << std::endl;
					}
					else
					{
						// Search an Accomodation pointer
						while (accomPtr == nullptr && accomIndex < MAX_BOOKING_ACCOM)
						{
							accomPtr = bookingPtr->getAccommodations(accomIndex);
						}
						// search the Park based on the Accommodation id (a booking includes accommodations from 1 park)
						accomId = accomPtr->getId();
						accomIndex = DEFAULT_INDEX;
						while (counter < MAX_PARKS && accomIndex == DEFAULT_INDEX)
						{
							if ((parkPtr = co->getParks(counter)) != nullptr)
							{
								accomIndex = parkPtr->getAccomIndexOf(accomId);
							}
							counter++;
						} // parkPtr does not change after finding a valid accomIndex
						// choose accommodations within the park
						accomPtr = searchAccommodation(parkPtr);
						if (accomPtr != nullptr)
						{
							bookingPtr->setAccommodations(accomPtr);
							std::cout << "\nThe accommodatiom with id " << accomPtr->getId()
								<< " has been added to your booking.\n" << std::endl;
						}
					}
					break;
				case 4: // delete accommodation
					std::cout << "Please select the accommodation you want to delete from the booking:" << std::endl;
					for (size_t i{ 0 }; i < MAX_BOOKING_ACCOM; i++)
					{
						if ((accomPtr = bookingPtr->getAccommodations(i)) != nullptr)
						{
							switch (accomPtr->getType())
							{
							case Accommodation::Type::CABIN:
								std::cout << ++counter << ". " << *dynamic_cast<Cabin*>(accomPtr) << std::endl;
								accomIndexArray[counter] = i;
								break;
							case Accommodation::Type::HOTEL_ROOM:
								std::cout << ++counter << ". " << *dynamic_cast<Hotelroom*>(accomPtr) << std::endl;
								accomIndexArray[counter] = i;
								break;
							}
						}
						else
						{
							accomIndexArray[i] = DEFAULT_INDEX;
						}
					}
					std::cout << (counter + 1) << ". cancel\n" << std::endl;
					accomIndex = requestIndex("", counter + 1);
					if (accomIndex != (counter + 1))
					{
						accomIndex = accomIndexArray[accomIndex];
						accomId = bookingPtr->getAccommodations(accomIndex)->getId();
						bookingPtr->deleteAccomAt(accomIndex);
						std::cout << "\nThe accommodation with id " << accomId
							<< " has been deleted from the booking" << std::endl;
						if (bookingPtr->getNoOfAccomm() == 0) // a booking has to have at least 1 Accommodation
						{
							custPtr->destructBookingAt(bookingIndex);
							std::cout << "The booking with id " << bookingId << " has been deleted from customer "
								<< custPtr->getName() << ", because there were no accommodations left in the booking"
								<< std::endl;
						}
						std::cout << std::endl;
					}
					break;
				case 5: // cancel
					break;
				}
			}
			else
			{
				std::cout << "\nA booking with id " << bookingId << " could not be found.\n" << std::endl;
			}
		}
	}
} // end function changeBooking

// delete a Booking from a Customer included in the given Company
void deleteBooking(Company* co)
{
	int bookingId{ DEFAULT_INT };
	size_t bookingIndex{ DEFAULT_INDEX };
	size_t custIndex{ 0 };
	Customer* custPtr{ nullptr };

	std::cout << "Delete booking" << std::endl;
	printLine(14);
	// Check if there are customers included in the given Company
	if (co->getNoOfCustomers() == 0)
	{
		std::cout << "\nCompany " << co->getName() << " has no customers and thus no bookings.\n" << std::endl;
	}
	else
	{
		std::cout << "Please check the booking you want to delete:" << std::endl;
		checkBooking(co);
		bookingId = requestInt("Please give the ID of the booking to delete\nor -999 to cancel");
		if (bookingId != DEFAULT_INT)
		{
			while (custIndex < MAX_CUSTOMERS && bookingIndex == DEFAULT_INDEX)
			{
				if ((custPtr = co->getCustomers(custIndex)) != nullptr)
				{
					bookingIndex = custPtr->getBookingIndexOf(bookingId);
				}
				custIndex++;
			}
			if (bookingIndex != DEFAULT_INDEX)
			{
				custPtr->destructBookingAt(bookingIndex);
				std::cout << "\nThe booking with id " << bookingId << " has been deleted\n" << std::endl;
			}
			else
			{
				std::cout << "\nA booking with id " << bookingId << " could not be found.\n" << std::endl;
			}
		}
	}
} // end function deleteBooking

// add additional services to the Booking
// The offered services are dependent on the given Park
// The services array = activityPass, sportPass, bikeRental, subtropicPass
void bookServices(bool services[], Park* parkPtr)
{
	std::cout << "\nPark " << parkPtr->getName()
		<< " offers following services:\n"
		<< "  * actvity pass: " << PRICE_ACTIVITY << " euro" << std::endl; // all parks offer an activity pass
	if (parkPtr->getSportsHall())
	{
		std::cout << "  * sport pass: " << PRICE_SPORT << " euro" << std::endl;
	}
	if (parkPtr->getBikeRental())
	{
		std::cout << "  * bike rental: " << PRICE_BIKE_RENTAL << " euro" << std::endl;
	}
	if (parkPtr->getSubtropicPar())
	{
		std::cout << "  * subtropic pass: " << PRICE_SUB_TROPIC << " euro" << std::endl;
	}
	services[0] = requestBool("", "\nDo you want an activity pass"); 
	services[1] = (parkPtr->getSportsHall() ? 
		requestBool("", "Do you want a sport pass") : false);
	services[2] = (parkPtr->getBikeRental() ? 
		requestBool("", "Do you want bike rental") : false);
	services[3] = (parkPtr->getSubtropicPar() ? 
		requestBool("", "Do you want a subtropic pass") : false);
} // end function bookServices

// Utility functions

// search an Accommodation in the given Park
// The Accommodations may be filtered on type, number of people
// and luxury level. The function returns a pointer to the chosen
// Accommodation or nullptr if no Accommodation is found or chosen.
Accommodation* searchAccommodation(Park* parkPtr)
{
	size_t typeIndex{ 0 };
	size_t luxLevelIndex{ 0 };
	size_t accomIdCounter{ 0 };
	size_t accomIndex{ 0 };
	int noOfPeople{ 0 };
	int accomId{ 0 };
	int accomIdArray[MAX_PARK_ACCOM];
	Accommodation* accomPtr{ nullptr };

	// filter on accommodation type
	std::cout << "Which type of accommodation do you want to book?"
		<< "\n  1. cabin"
		<< "\n  2. hotel room"
		<< "\n  3. no preference"
		<< std::endl;
	typeIndex = requestIndex("type", 3);
	// filter on number of people
	std::cout << "\nHow many people have to stay in the accommodation?"
		<< "\nGive 1 if you do not have a preference" << std::endl;
	noOfPeople = requestInt("number of people");
	while (noOfPeople < 1 || noOfPeople > MAX_PEOPLE)
	{
		std::cout << "Please enter a number between " << 1 << " and " << MAX_PEOPLE << std::endl;
		noOfPeople = requestInt("number of people");
	}
	// filter on luxury level
	std::cout << "\nWhich luxury level do you want?"
		<< "\n  1. comfort"
		<< "\n  2. premium"
		<< "\n  3. VIP"
		<< "\n  4. no preference"
		<< std::endl;
	luxLevelIndex = requestIndex("luxury level", 4);

	// show accommodations which correspond to the given filters
	accomIdCounter = 0;
	for (size_t i{ 0 }; i < MAX_PARK_ACCOM; i++)
	{
		accomPtr = parkPtr->getAccommodations(i);
		if (accomPtr != nullptr
			&& accomPtr->shouldDisplay(Accommodation::RequestType::R_TYPE, typeIndex)
			&& accomPtr->shouldDisplay(Accommodation::RequestType::R_PEOPLE, noOfPeople)
			&& accomPtr->shouldDisplay(Accommodation::RequestType::R_LUXURY_LEVEL, luxLevelIndex))
		{
			if (accomIdCounter == 0)
			{
				std::cout << "\nThe following accommodations correspond to your requirements:" << std::endl;
			}
			switch (accomPtr->getType())
			{
			case Accommodation::Type::CABIN:
				std::cout << *dynamic_cast<Cabin*>(accomPtr) << std::endl;
				break;
			case Accommodation::Type::HOTEL_ROOM:
				std::cout << *dynamic_cast<Hotelroom*>(accomPtr) << std::endl;
				break;
			}
			accomIdArray[accomIdCounter] = accomPtr->getId();
			accomIdCounter++;
		}
	}
	if (accomIdCounter != 0)
	{
		accomId = requestInt("\nPlease give the ID of the accommodation you want to book\nor -999 to cancel");
		if (accomId != DEFAULT_INT)
		{
			if (inArray(accomId, accomIdArray, accomIdCounter))
			{
				// put the accomPtr in the accommodatioms array
				accomIndex = parkPtr->getAccomIndexOf(accomId);
				accomPtr = parkPtr->getAccommodations(accomIndex);
			}
			else
			{
				std::cout << "\nAn accommodatiom with id " << accomId << " could not be found.\n" << std::endl;
			}
		}
	}
	else
	{
		std::cout << "\nPark " << parkPtr->getName()
			<< " has no accommodations\nthat corresponds to your requirements.\n" << std::endl;
	}

	return accomPtr;
} // end function searchAccommodation

// search the given array for the given integer
bool inArray(int needle, int haystack[], size_t haystackSize)
{
	for (size_t i{ 0 }; i < haystackSize; i++)
	{
		if (haystack[i] == needle)
			return true;
	}

	return false;
} // end function inArray

// search the given Accommodation array for the given id
/*bool idInArray(int id, Accommodation* accomArray[], size_t arraySize)
{
	for (size_t i{ 0 }; i < arraySize; i ++)
	{
		if (accomArray[i]->getId() == id)
			return true;
	}

	return false;
}*/ // end function idInArray

