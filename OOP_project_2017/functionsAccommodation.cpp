/*
 *	Lab assignment for course Object Oriented Programming 2017
 *
 *	Véronique Wuyts
 *	Bachelor Elektronica-ICT option Application Development
 *	Thomas More campus De Nayer
 *
 *	Implementation of Accommodation functions
 */

// Includes
#include <iostream>
#include <cstring>
#include "functionsAccommodation.h"
#include "functionsPark.h"
#include "functionsUserInput.h"

// view all Accommodations of a specific Park included in the given Company
void checkAccommodation(Company* co)
{
	Accommodation* accomPtr{ nullptr };
	Park* parkPtr{ nullptr };
	size_t noOfParks{ co->getNoOfParks() };
	size_t parkIndex{ 0 };

	std::cout << "\nCheck accommodations" << std::endl;
	printLine(20);
	// check if there are parks included in the given Company
	if (noOfParks == 0)
	{
		std::cout << "Company " << co->getName() << " has no parks and thus no accommodations.\n" << std::endl;
	}
	else
	{
		std::cout << "Please check from which park you want to check the accommodations:" << std::endl;
		checkPark(co);
		parkIndex = requestIndex("park", noOfParks);
		if (parkIndex != DEFAULT_INDEX)
		{
			parkIndex = co->getParkIndex(parkIndex);
			if (parkIndex != DEFAULT_INDEX)
			{
				parkPtr = co->getParks(parkIndex);
				// check if there are accommodations included in the requested park
				if (parkPtr->getNoOfAccommodations() == 0)
				{
					std::cout << "\nPark " << parkPtr->getName() << " has no accommodations\n" << std::endl;
				}
				else
				{
					std::cout << "\nPark " << parkPtr->getName() << " has following accommodations:" << std::endl;
					for (size_t i{ 0 }; i < MAX_PARK_ACCOM; i++)
					{
						if ((accomPtr = parkPtr->getAccommodations(i)) != nullptr)
						{
							switch (accomPtr->getType())
							{
							case Accommodation::Type::CABIN:
								std::cout << *dynamic_cast<Cabin*>(accomPtr) << std::endl;
								break;
							case Accommodation::Type::HOTEL_ROOM:
								std::cout << *dynamic_cast<Hotelroom*>(accomPtr) << std::endl;
							}
							
						}
					}
				}
			}
		}
	}
} // end function checkAccommodation

// create an accommodation and add it to a park included in the given Company
void createAccommodation(Company* co)
{
	size_t parkIndex{ 0 };
	size_t noOfParks{ co->getNoOfParks() };
	size_t luxLevelIndex{ 0 };
	size_t typeIndex{ 0 };
	int id{ 0 };
	Accommodation::LuxuryLevel luxuryLevel{ Accommodation::LuxuryLevel::COMFORT };
	int maxPeople{ 0 };
	int size{ 0 };
	int price{ 0 };
	char side[CHARS_SIDE]{ "" };
	int int1{ 0 };
	int int2{ 0 };
	bool bool1{ false };
	bool bool2{ false };
	bool bool3{ false };
	bool bool4{ false };
	Accommodation* accomPtr{ nullptr };
	Park* parkPtr{ nullptr };
	
	std::cout << "\nCreate accommodation" << std::endl;
	printLine(20);
	// check if there are parks included in the given Company
	if (noOfParks == 0)
	{
		std::cout << "\nYou first have to to create a park.\n" << std::endl;
	}
	else
	{
		std::cout << "Please check to which park you want to add an accommodation:" << std::endl;
		checkPark(co);
		std::cout << (noOfParks + 1) << ". cancel\n" << std::endl;
		parkIndex = requestIndex("park", noOfParks + 1);
		if (parkIndex != (noOfParks + 1))
		{
			parkIndex = co->getParkIndex(parkIndex);
			if (parkIndex != DEFAULT_INDEX)
			{
				parkPtr = co->getParks(parkIndex);
				// check if an accommodation can be added
				if (parkPtr->getNoOfAccommodations() == MAX_PARK_ACCOM)
				{
					std::cout << "Park " << parkPtr->getName() << " has already reached the maximum number of accommodations.\n" << std::endl;
				}
				else
				{
					std::cout << "Please give the required information for the new accommodation:" << std::endl;
					id = requestInt("id");
					std::cout << "  luxury level:"
						<< "\n    1. comfort"
						<< "\n    2. premium"
						<< "\n    3. VIP"
						<< std::endl;
					luxLevelIndex = requestIndex("luxury level", 3);
					switch (luxLevelIndex)
					{
					case 1:
						luxuryLevel = Accommodation::LuxuryLevel::COMFORT;
						break;
					case 2:
						luxuryLevel = Accommodation::LuxuryLevel::PREMIUM;
						break;
					case 3:
						luxuryLevel = Accommodation::LuxuryLevel::VIP;
						break;
					}
					maxPeople = requestInt("maximum number of people");
					size = requestInt("size");
					price = requestInt("price");
					std::cout << "  type: "
						<< "\n    1. cabin"
						<< "\n    2. hotel room"
						<< std::endl;
					typeIndex = requestIndex("type", 2);
					// create new cabin or hotel room
					switch (typeIndex)
					{
					case 1:
						int1 = requestInt("number of bedrooms");
						bool1 = requestBool("cabin", "blu-ray surround system");
						bool2 = requestBool("cabin", "barbecue");
						bool3 = requestBool("cabin", "breakfast service");
						bool4 = requestBool("cabin", "laundry service");
						accomPtr = new Cabin(id, luxuryLevel, maxPeople, size, price, int1, bool1, bool2, bool3, bool4);
						break;
					case 2:
						int1 = requestInt("floor");
						requestString("side", side, CHARS_SIDE);
						int2 = requestInt("number of beds");
						bool1 = requestBool("hotel room", "childrens bed");
						bool2 = requestBool("hotel room", "mini bar");
						accomPtr = new Hotelroom(id, luxuryLevel, maxPeople, size, price, int1, side, int2, bool1, bool2);
						break;
					}
					parkPtr->setAccommodations(accomPtr);
					delete accomPtr;
					accomPtr = nullptr;
					std::cout << "\nThe " << (typeIndex == 1 ? "cabin" : "hotel room") << " has been added to park "
						<< parkPtr->getName() << "\n"
						<< std::endl;
				}
			}
		}
	}
} // end function createAccommodation

// change an Accommodation from a Park included in the given Company
void changeAccommodation(Company* co)
{
	size_t parkIndex{ 0 };
	int accomId{ DEFAULT_INT };
	size_t accomIndex{ DEFAULT_INDEX };
	size_t changeIndex{ 0 };
	Accommodation::Type type{Accommodation::Type::CABIN};
	int changedInt{ 0 };
	Accommodation::LuxuryLevel changedLuxLevel{ Accommodation::LuxuryLevel::COMFORT };
	size_t luxLevelIndex{ 0 };
	int changedBool{ false };
	char changedSide[CHARS_SIDE]{ "" };
	Accommodation* accomPtr{ nullptr };
	Park* parkPtr{ nullptr };

	std::cout << "\nChange accommodation" << std::endl;
	printLine(20);
	// check if there are parks included in the given Company
	if (co->getNoOfParks() == 0)
	{
		std::cout << "\nCompany " << co->getName() << " has no parks and thus no accommodations.\n" << std::endl;
	}
	else
	{
		// request which accommodation has to be changed
		std::cout << "Please check the accommodation you want to change:" << std::endl;
		checkAccommodation(co);
		accomId = requestInt("Please give the ID of the accommodation to change\nor -999 to cancel");
		if (accomId != DEFAULT_INT)
		{
			while (parkIndex < MAX_PARKS && accomIndex == DEFAULT_INDEX)
			{
				if ((parkPtr = co->getParks(parkIndex)) != nullptr)
				{
					accomIndex = parkPtr->getAccomIndexOf(accomId);
				}
				parkIndex++;
			}
			if (accomIndex != DEFAULT_INDEX)
			{
				accomPtr = parkPtr->getAccommodations(accomIndex); // parkPtr is not changed after getting the accomIndex
				type = accomPtr->getType();
				std::cout << "\nWhat do you want to change?"
					<< "\n1. id"
					<< "\n2. luxury level"
					<< "\n3. maximum number of people"
					<< "\n4. size"
					<< "\n5. price"
					<< std::endl;
				switch (type)
				{
				case Accommodation::Type::CABIN:
					std::cout << "6. number of bedrooms"
						<< "\n7. blu-ray surround system"
						<< "\n8. barbecue"
						<< "\n9. breakfast service"
						<< "\n10. laundry service"
						<< std::endl;
					break;
				case Accommodation::Type::HOTEL_ROOM:
					std::cout << "6. floor"
						<< "\n7. side"
						<< "\n8. number of beds"
						<< "\n9. childrens bed"
						<< "\n10. mini bar"
						<< std::endl;
					break;
				}
				std::cout << "11. cancel\n" << std::endl;
				changeIndex = requestIndex("", 11);
				std::cout << std::endl;
				// change the requested item
				switch (changeIndex)
				{
				case 1:
					changedInt = requestInt("new id");
					accomPtr->setId(changedInt);
					std::cout << "\nThe accommodation now has id: "
						<< accomPtr->getId() << "\n" << std::endl;
					break;
				case 2:
					std::cout << "\nSelect the new luxury level:"
						<< "\n  1. comfort"
						<< "\n  2. premium"
						<< "\n  3. VIP"
						<< std::endl;
					luxLevelIndex = requestIndex("", 3);
					switch (luxLevelIndex)
					{
					case 1:
						accomPtr->setLuxuryLevel(Accommodation::LuxuryLevel::COMFORT);
						break;
					case 2:
						accomPtr->setLuxuryLevel(Accommodation::LuxuryLevel::PREMIUM);
						break;
					case 3:
						accomPtr->setLuxuryLevel(Accommodation::LuxuryLevel::VIP);
						break;
					}
					std::cout << "\nThe accommodation now has luxury level: ";
					switch (accomPtr->getLuxuryLevel())
					{
					case Accommodation::LuxuryLevel::COMFORT:
						std::cout << "comfort" << "\n" << std::endl;
						break;
					case Accommodation::LuxuryLevel::PREMIUM:
						std::cout << "premium" << "\n" << std::endl;
						break;
					case Accommodation::LuxuryLevel::VIP:
						std::cout << "VIP" << "\n" << std::endl;
						break;
					}
					break;
				case 3:
					changedInt = requestInt("new maximum number of people");
					accomPtr->setMaxPeople(changedInt);
					std::cout << "\nThe accommodation now has maximum "
						<< accomPtr->getMaxPeople()
						<< " people" << "\n" << std::endl;
					break;
				case 4:
					changedInt = requestInt("new size");
					accomPtr->setSize(changedInt);
					std::cout << "\nThe accommodation now has size: "
						<< accomPtr->getSize() << "\n" << std::endl;
					break;
				case 5:
					changedInt = requestInt("new price");
					accomPtr->setPrice(changedInt);
					std::cout << "\nThe accommodation now has price: "
						<< accomPtr->getPrice() << "\n" << std::endl;
					break;
				case 6:
					switch (type)
					{
					case Accommodation::Type::CABIN:
						changedInt = requestInt("new number of bedrooms");
						dynamic_cast<Cabin*>(accomPtr)->setNoOfBedrooms(changedInt);
						std::cout << "\nThe accommodation now has "
							<< dynamic_cast<Cabin*>(accomPtr)->getNoOfBedrooms()
							<< " bedrooms" << "\n" << std::endl;
						break;
					case Accommodation::Type::HOTEL_ROOM:
						changedInt = requestInt("new floor");
						dynamic_cast<Hotelroom*>(accomPtr)->setFloor(changedInt);
						std::cout << "\nThe accommodation now has floor: "
							<< dynamic_cast<Hotelroom*>(accomPtr)->getFloor()
							<< "\n" << std::endl;
						break;
					}
					break;
				case 7:
					switch (type)
					{
					case Accommodation::Type::CABIN:
						dynamic_cast<Cabin*>(accomPtr)->setBluRaySurround(
							!dynamic_cast<Cabin*>(accomPtr)->getBluRaySurround());
						std::cout << "\nThe accommodation now has"
							<< (dynamic_cast<Cabin*>(accomPtr)->getBluRaySurround() ? " a" : " no")
							<< " blu-ray surround system" << "\n" << std::endl;
						break;
					case Accommodation::Type::HOTEL_ROOM:
						requestString("new side", changedSide, CHARS_SIDE);
						dynamic_cast<Hotelroom*>(accomPtr)->setSide(changedSide);
						std::cout << "\nThe accommodation now has side: "
							<< dynamic_cast<Hotelroom*>(accomPtr)->getSide()
							<< "\n" << std::endl;
						break;
					}
					break;
				case 8:
					switch (type)
					{
					case Accommodation::Type::CABIN:
						dynamic_cast<Cabin*>(accomPtr)->setBbq(
							!dynamic_cast<Cabin*>(accomPtr)->getBbq());
						std::cout << "\nThe accommodation now has"
							<< (dynamic_cast<Cabin*>(accomPtr)->getBbq() ? " a" : " no")
							<< " barbecue" << "\n" << std::endl;
						break;
					case Accommodation::Type::HOTEL_ROOM:
						changedInt = requestInt("new number of beds");
						dynamic_cast<Hotelroom*>(accomPtr)->setNoOfBeds(changedInt);
						std::cout << "\nThe accommodation now has "
							<< dynamic_cast<Hotelroom*>(accomPtr)->getNoOfBeds()
							<< " beds" << "\n" << std::endl;
						break;
					}
					break;
				case 9:
					switch (type)
					{
					case Accommodation::Type::CABIN:
						dynamic_cast<Cabin*>(accomPtr)->setBreakfastService(
							!dynamic_cast<Cabin*>(accomPtr)->getBreakfastService());
						std::cout << "\nThe accommodation now has"
							<< (dynamic_cast<Cabin*>(accomPtr)->getBluRaySurround() ? "" : " no")
							<< " breakfast service" << "\n" << std::endl;
						break;
					case Accommodation::Type::HOTEL_ROOM:
						dynamic_cast<Hotelroom*>(accomPtr)->setChildrensBed(
							!dynamic_cast<Hotelroom*>(accomPtr)->getChildrensBed());
						std::cout << "\nThe accommodation now has"
							<< (dynamic_cast<Hotelroom*>(accomPtr)->getChildrensBed() ? " a" : " no")
							<< " childrens bed" << "\n" << std::endl;
						break;
					}
					break;
				case 10:
					switch (type)
					{
					case Accommodation::Type::CABIN:
						dynamic_cast<Cabin*>(accomPtr)->setLaundryService(
							!dynamic_cast<Cabin*>(accomPtr)->getLaundryService());
						std::cout << "\nThe accommodation now has"
							<< (dynamic_cast<Cabin*>(accomPtr)->getLaundryService() ? " a" : " no")
							<< " laundry service" << "\n" << std::endl;
						break;
					case Accommodation::Type::HOTEL_ROOM:
						dynamic_cast<Hotelroom*>(accomPtr)->setMiniBar(
							!dynamic_cast<Hotelroom*>(accomPtr)->getMiniBar());
						std::cout << "\nThe accommodation now has"
							<< (dynamic_cast<Hotelroom*>(accomPtr)->getMiniBar() ? " a" : " no")
							<< " mini bar" << "\n" << std::endl;
						break;
					}
					break;
				case 11:
					break;
				}
			}
			else
			{
				std::cout << "\nAn accommodatiom with id " << accomId << " could not be found.\n" << std::endl;
			}
		}
	}
} // end function changeAccommodation

// delete an Accommodation from a Park included in the given Company
void deleteAccommodation(Company* co)
{
	int accomId{ DEFAULT_INT };
	size_t parkIndex{ 0 };
	size_t accomIndex{ DEFAULT_INDEX };
	Park* parkPtr{ nullptr };

	std::cout << "Delete accommodation" << std::endl;
	printLine(20);
	// check if there are parks included in the given Company
	if (co->getNoOfParks() == 0)
	{
		std::cout << "\nCompany " << co->getName() << " has no parks and thus no accommodations.\n" << std::endl;
	}
	else
	{
		std::cout << "Please check the accommodation you want to delete:" << std::endl;
		checkAccommodation(co);
		accomId = requestInt("Please give the ID of the accommodation to delete\nor -999 to cancel");
		if (accomId != DEFAULT_INT)
		{
			while (parkIndex < MAX_PARKS && accomIndex == DEFAULT_INDEX)
			{
				if ((parkPtr = co->getParks(parkIndex)) != nullptr)
				{
					accomIndex = parkPtr->getAccomIndexOf(accomId);
				}
				parkIndex++;
			}
			if (accomIndex != DEFAULT_INDEX)
			{
				// delete the accommodations from bookings
				for (size_t i{ 0 }; i < MAX_CUSTOMERS; i++)
				{
					if (co->getCustomers(i) != nullptr)
					{
						co->getCustomers(i)->deleteAccomFromBooking(accomId);
					}	
				}
				// delete the accommodation
				parkPtr->destructAccommodationAt(accomIndex);
				std::cout << "\nThe accommodation with id " << accomId
					<< " has been deleted\n" << std::endl;
			}
			else
			{
				std::cout << "\nAn accommodatiom with id " << accomId << " could not be found.\n" << std::endl;
			}
		}
	}
} // end function deleteAccommodation
