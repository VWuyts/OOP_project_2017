/*
 *	Lab assignment for course Object Oriented Programming 2017
 *
 *	Véronique Wuyts
 *	Bachelor Elektronica-ICT option Application Development
 *	Thomas More campus De Nayer
 *
 *	Implementation of Park functions
 */

// Includes
#include <cstring>
#include <iostream>
#include "functionsPark.h"
#include "functionsUserInput.h"

// view all Parks included in the given Company
void checkPark(Company* co)
{
	Park* parkPtr{ nullptr };
	size_t counter{ 0 };

	std::cout << "\nCheck parks" << std::endl;
	printLine(11);
	// check if there are parks included in the given Company
	if (co->getNoOfParks() == 0)
	{
		std::cout << "\nCompany " << co->getName() << " has no parks.\n" << std::endl;
	}
	else
	{
		// show parks
		for (size_t i{ 0 }; i < MAX_PARKS; i++)
		{
			if ((parkPtr = co->getParks(i)) != nullptr)
			{
				std::cout << ++counter << ". " << *parkPtr << std::endl;
			}
		}
	}
} // end function checkPark

// create a Park and add it to the given Company
void createPark(Company* co)
{
	char name[CHARS_NAME]{ "" };
	char address[CHARS_ADDRESS]{ "" };
	bool subtropicPar{ false };
	bool bikeRental{ false };
	bool waterBikeRental{ false };
	bool bowlingAlley{ false };
	bool kidsParadise{ false };
	bool sportsHall{ false };
	Park* parkPtr{ nullptr };

	std::cout << "\nCreate park" << std::endl;
	printLine(11);
	// check if a park can be added
	if (co->getNoOfParks() == MAX_PARKS)
	{
		std::cout << "\nCompany " << co->getName() << " has already reached the maximum number of parks.\n" << std::endl;
	}
	else
	{
		std::cout << "Please give the required information for the new park:" << std::endl;
		requestString("name", name, CHARS_NAME);
		requestString("address", address, CHARS_ADDRESS);
		subtropicPar = requestBool("park", "a subtropic paradise");
		bikeRental = requestBool("park", "bike rental");
		waterBikeRental = requestBool("park", "water bike rental");
		bowlingAlley = requestBool("park", "a bowling alley");
		kidsParadise = requestBool("park", "a kids paradise");
		sportsHall = requestBool("park", "a sportshall");
		// create new park
		parkPtr = new Park(name, address, subtropicPar, bikeRental, waterBikeRental, bowlingAlley, kidsParadise, sportsHall);
		co->setParks(parkPtr);
		delete parkPtr;
		parkPtr = nullptr;
		std::cout << "\nPark " << name << " has been added to company " << co->getName() << "\n" << std::endl;
	}
} // end function createPark

// change a Park included in the given Company
void changePark(Company* co)
{
	size_t parkIndex{ 0 };
	size_t changeIndex{ 0 };
	size_t noOfParks{ co->getNoOfParks() };
	char changedName[CHARS_NAME]{ "" };
	char changedAddress[CHARS_ADDRESS]{ "" };
	Park* parkPtr{ nullptr };

	std::cout << "\nChange park" << std::endl;
	printLine(11);
	// check if there are parks included in the given Company
	if (noOfParks == 0)
	{
		std::cout << "\nCompany " << co->getName() << " has no parks.\n" << std::endl;
	}
	else
	{
		// request which park has to be changed
		std::cout << "\nPlease check which park you want to change:" << std::endl;
		checkPark(co);
		std::cout << (noOfParks + 1) << ". cancel\n" << std::endl;
		parkIndex = requestIndex("park", noOfParks + 1);
		if (parkIndex != (noOfParks + 1))
		{
			parkIndex = co->getParkIndex(parkIndex);
			if (parkIndex != DEFAULT_INDEX)
			{
				parkPtr = co->getParks(parkIndex);
				std::cout << "\nWhat do you want to change?"
					<< "\n1. name"
					<< "\n2. address"
					<< "\n3. subtropic paradise"
					<< "\n4. bike rental"
					<< "\n5. water bike rental"
					<< "\n6. bowling alley"
					<< "\n7. kids paradise"
					<< "\n8. sports hall"
					<< "\n9. cancel\n"
					<< std::endl;
				changeIndex = requestIndex("", 9);
				// change the requested item
				switch (changeIndex)
				{
				case 1:
					requestString("new name", changedName, CHARS_NAME);
					parkPtr->setName(changedName);
					std::cout << "\nThe park now has name: " << parkPtr->getName() << "\n" << std::endl;
					break;
				case 2:
					requestString("new address", changedAddress, CHARS_ADDRESS);
					parkPtr->setAddress(changedAddress);
					std::cout << "\nThe park now has address: " << parkPtr->getAddress() << "\n" << std::endl;
					break;
				case 3:
					parkPtr->setSubtropicPar(!parkPtr->getSubtropicPar());
					std::cout << "\nThe park now has" << (parkPtr->getSubtropicPar() ? " a" : " no")
						<< " subtropic paradise" << "\n" << std::endl;
					break;
				case 4:
					parkPtr->setBikeRental(!parkPtr->getBikeRental());
					std::cout << "\nThe park now has" << (parkPtr->getBikeRental() ? "" : " no")
						<< " bike rental" << "\n" << std::endl;
					break;
				case 5:
					parkPtr->setWaterBikeRental(!parkPtr->getWaterBikeRental());
					std::cout << "\nThe park now has" << (parkPtr->getWaterBikeRental() ? "" : " no")
						<< " water bike rental" << "\n" << std::endl;
					break;
				case 6:
					parkPtr->setBowlingAlley(!parkPtr->getBowlingAlley());
					std::cout << "\nThe park now has" << (parkPtr->getBowlingAlley() ? " a" : " no")
						<< " bowling alley" << "\n" << std::endl;
					break;
				case 7:
					parkPtr->setKidsParadise(!parkPtr->getKidsParadise());
					std::cout << "\nThe park now has" << (parkPtr->getKidsParadise() ? " a" : " no")
						<< " kids paradise" << "\n" << std::endl;
					break;
				case 8:
					parkPtr->setSportsHall(!parkPtr->getSportsHall());
					std::cout << "\nThe park now has" << (parkPtr->getSportsHall() ? " a" : " no")
						<< " sports hall" << "\n" << std::endl;
					break;
				case 9:
					break;
				}
			}
		}
	}
} // end function changePark

// delete a Park from the given Company
void deletePark(Company* co)
{
	size_t parkIndex{ 0 };
	size_t noOfParks{ co->getNoOfParks() };
	char parkName[CHARS_NAME]{ "" };
	Customer* custPtr{ nullptr };
	Accommodation* accomPtr{ nullptr };
	Park* parkPtr{ nullptr };

	std::cout << "\nDelete park" << std::endl;
	printLine(11);
	// check if there are parks included in the given Company
	if (noOfParks == 0)
	{
		std::cout << "\nCompany " << co->getName() << " has no parks.\n" << std::endl;
	}
	else
	{
		std::cout << "\nPlease check which park you want to delete:" << std::endl;
		checkPark(co);
		std::cout << (noOfParks + 1) << ". cancel\n" << std::endl;
		parkIndex = requestIndex("park", noOfParks + 1);
		if (parkIndex != (noOfParks + 1))
		{
			parkIndex = co->getParkIndex(parkIndex);
			if (parkIndex != DEFAULT_INDEX)
			{
				parkPtr = co->getParks(parkIndex);
				// delete the park
				strcpy_s(parkName, CHARS_NAME, parkPtr->getName());
				co->destructParkAt(parkIndex);
				std::cout << "\nPark " << parkName << " has been deleted from company " << co->getName()
					<< "\n" << std::endl;
			}
		}
	}
} // end function deletePark
