/*
*	Lab assignment for course Object Oriented Programming 2017
*
*	Véronique Wuyts
*	Bachelor Elektronica-ICT option Application Development
*	Thomas More campus De Nayer
*
*	Implementation of utility functions
*/

// Includes
#include <cstdlib>
#include <iostream>
#include <fstream>
#include "cabin.h"
#include "constants.h"
#include "hotelroom.h"
#include "utilityFunctions.h"

// Function login returns the user as prime number of pnRoles or -1 to quit.
int login(const char* roles[], const int rolesPn[], size_t noRoles)
{
	int user{ 0 };

	std::cout << "\nPlease login to continue:" << std::endl;
	for (size_t i{ 0 }; i < noRoles; i++)
	{
		std::cout << "  " << (i + 1) << ". " << roles[i] << std::endl;
	}
	std::cout << "  " <<(noRoles + 1) << ". Logout and close application\n" << std::endl;
	std::cout << "Your login choice: ";
	std::cin >> user;
	while (std::cin.fail() || user < 1 || user >(noRoles + 1)) // check for invalid user input, ref: Towsend2010
	{
		std::cin.clear(); // clear error flag; ref: Towsend2010
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // ignore rest of input buffer or rest of line; ref: Towsend2010
		std::cout << "Please enter a number between 1 and " << (noRoles + 1) << ": ";
		std::cin >> user;
	}
	std::cin.clear();
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

	if (user == (noRoles + 1)) return -1;
	return rolesPn[user - 1];
} // end function login

// Function menu returns the menu option as an index of the menuOptions array
// or -1 to quit.
int menu(int role, const char* menuOptions[], const int menuOptionsPn[], size_t noCats)
{
	int option{ 0 };
	int noOptions{ 0 };
	int index{ 0 };
	
	std::cout << "\nPlease choose a menu option:" << std::endl;
	for (size_t i{ 0 }; i < noCats; i++)
	{
		if (menuOptionsPn[i] % role == 0) // Property of Gödel Prime Product, ref: VandenBulcke2010
		{
			std::cout << "  " << ++noOptions << ". " << menuOptions[i] << std::endl;
		}
	}
	std::cout << "  " << ++noOptions << ". Quit\n" << std::endl;
	std::cout << "Your menu choice: ";
	std::cin >> option;
	while (std::cin.fail() || option < 1 || option > noOptions)
	{
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cout << "Please enter a number between 1 and " << noOptions << ": ";
		std::cin >> option;
	}
	std::cin.clear();
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

	if (option == noOptions) index = -1; // quit
	else
	{
		noOptions = 0;
		for (int i{ 0 }; i < noCats; i++)
		{
			if (menuOptionsPn[i] % role == 0)
			{
				if (++noOptions == option) index = i;
			}
		}
	}
	
	return index;
} // end function menu

// Function submenu returns the sub-option as a column index of the subOptions array
// or -1 to quit.
int submenu(int role, int option, const char* subOptions[][FCTNS], const int subOptionsPn[][FCTNS], size_t noFctns)
{
	int suboption{ 0 };
	int noOptions{ 0 };
	int index{ 0 };

	std::cout << "\nPlease choose a submenu option:" << std::endl;
	for (size_t i{ 0 }; i < noFctns; i++)
	{
		if (subOptionsPn[option][i] % role == 0)
		{
			std::cout << "  " << ++noOptions << ". " << subOptions[option][i] << std::endl;
		}
	}
	std::cout << "  " << ++noOptions << ". Cancel\n" << std::endl;
	std::cout << "Your submenu choice: ";
	std::cin >> suboption;
	while (std::cin.fail() || suboption < 1 || suboption > noOptions)
	{
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cout << "Please enter a number between 1 and " << noOptions << ": ";
		std::cin >> suboption;
	}
	std::cin.clear();
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

	if (suboption == noOptions) index = -1; // quit
	else
	{
		noOptions = 0;
		for (int i{ 0 }; i < FCTNS; i++)
		{
			if (subOptionsPn[option][i] % role == 0)
			{
				if (++noOptions == suboption) index = i;
			}
		}
	}
	
	return index;
} // end function submenu

// save the contents of the given Company to the given file
void saveToFile(Company* const co, const char* const file)
{
	bool boolVar{ false };
	const char empty[CHARS_NAME]{ "empty" };
	char typeCabin{ 'c' };
	char typeHotelroon{ 'h' };
	char typeEmpty{ 'e' };
	int intVar{ 0 };
	int intEmpty{ DEFAULT_INT };
	Accommodation* accomPtr{ nullptr };
	Park* parkPtr{ nullptr };
	Customer* custPtr{ nullptr };
	Booking* bookingPtr{ nullptr };

	std::ofstream outFile{ file, std::ios::out | std::ios::binary };

	if (!outFile) // overloaded operator! returns true if either the failbit or the badbit is set for the stream
	{
		std::cerr << "File " << file << " could not be opened for writing." << std::endl;
		exit(EXIT_FAILURE);
	}

	// write parks array of Company to file
	for (size_t i{ 0 }; i < MAX_PARKS; i++)
	{
		if ((parkPtr = co->getParks(i)) != nullptr)
		{
			// write Park info to file
			outFile.write(parkPtr->getName(), CHARS_NAME * sizeof(char));
			outFile.write(parkPtr->getAddress(), CHARS_ADDRESS * sizeof(char));
			boolVar = parkPtr->getSubtropicPar();
			outFile.write(reinterpret_cast<const char*>(&boolVar), sizeof(bool));
			boolVar = parkPtr->getBikeRental();
			outFile.write(reinterpret_cast<const char*>(&boolVar), sizeof(bool));
			boolVar = parkPtr->getWaterBikeRental();
			outFile.write(reinterpret_cast<const char*>(&boolVar), sizeof(bool));
			boolVar = parkPtr->getBowlingAlley();
			outFile.write(reinterpret_cast<const char*>(&boolVar), sizeof(bool));
			boolVar = parkPtr->getKidsParadise();
			outFile.write(reinterpret_cast<const char*>(&boolVar), sizeof(bool));
			boolVar = parkPtr->getSportsHall();
			outFile.write(reinterpret_cast<const char*>(&boolVar), sizeof(bool));

			// write accommodations array of Park to file
			for (size_t i{ 0 }; i < MAX_PARK_ACCOM; i++)
			{
				if ((accomPtr = parkPtr->getAccommodations(i)) != nullptr)
				{
					// write Cabin or Hotelroom to file
					switch (accomPtr->getType())
					{
					case Accommodation::Type::CABIN:
						outFile.write(reinterpret_cast<char*>(&typeCabin), sizeof(char));
						outFile.write(reinterpret_cast<char*>(accomPtr), sizeof(Cabin));
						break;
					case Accommodation::Type::HOTEL_ROOM:
						outFile.write(reinterpret_cast<char*>(&typeHotelroon), sizeof(char));
						outFile.write(reinterpret_cast<char*>(accomPtr), sizeof(Hotelroom));
						break;
					}
				}
				else
				{
					outFile.write(reinterpret_cast<char*>(&typeEmpty), sizeof(char)); // accommodations[j] == nullptr
				}
			} // end for accommodations array
		}
		else
		{
			outFile.write(empty, CHARS_NAME * sizeof(char)); // parks[i] == nullptr
		}
	} // end for parks array

	// write customers array of Company to file
	for (size_t i{ 0 }; i < MAX_CUSTOMERS; i++)
	{
		if ((custPtr = co->getCustomers(i)) != nullptr)
		{
			// write Customer info to file
			outFile.write(custPtr->getName(), CHARS_NAME * sizeof(char));
			outFile.write(custPtr->getAddress(), CHARS_ADDRESS * sizeof(char));
			outFile.write(custPtr->getEmail(), CHARS_EMAIL * sizeof(char));
			outFile.write(custPtr->getBankAccount(), CHARS_BANK_ACCOUNT * sizeof(char));

			// write bookings array of Customer to file
			for (size_t j{ 0 }; j < MAX_BOOKING; j++)
			{
				if ((bookingPtr = custPtr->getBooking(j)) != nullptr)
				{
					// write Booking info to file
					intVar = bookingPtr->getBookingId();
					outFile.write(reinterpret_cast<char*>(&intVar), sizeof(int));
					intVar = bookingPtr->getNoOfAccomm();
					outFile.write(reinterpret_cast<char*>(&intVar), sizeof(int));
					boolVar = bookingPtr->getActivityPass();
					outFile.write(reinterpret_cast<char*>(&boolVar), sizeof(bool));
					boolVar = bookingPtr->getSportPass();
					outFile.write(reinterpret_cast<char*>(&boolVar), sizeof(bool));
					boolVar = bookingPtr->getBikeRental();
					outFile.write(reinterpret_cast<char*>(&boolVar), sizeof(bool));
					boolVar = bookingPtr->getSubtropicPass();
					outFile.write(reinterpret_cast<char*>(&boolVar), sizeof(bool));

					// write accommodations array of Booking to file
					for (size_t k{ 0 }; k < MAX_BOOKING_ACCOM; k++)
					{
						if ((accomPtr = bookingPtr->getAccommodations(k)) != nullptr)
						{
							intVar = accomPtr->getId();
							outFile.write(reinterpret_cast<char*>(&intVar), sizeof(int));
						}
						else
						{
							outFile.write(reinterpret_cast<char*>(&intEmpty), sizeof(int)); // accommodations[k] == nullptr
						}
					} // end for accommodations array of Booking
				}
				else
				{
					outFile.write(reinterpret_cast<char*>(&intEmpty), sizeof(int)); // bookings[j] == nullptr
				}
			} // end for bookings array of Customer
		}
		else
		{
			outFile.write(empty, CHARS_NAME * sizeof(char)); // customers[i] == nullptr
		}
	} // end for customers array

	// write Company info to file
	outFile.write(co->getName(), CHARS_NAME * sizeof(char));
	outFile.write(co->getAddress(), CHARS_ADDRESS * sizeof(char));

	outFile.close();
}// end function saveToFile

// read the given file, store the content in a new Company object and
// return a pointer to the Company object
// If the given file cannot be read, a nullptr is returned
Company* readFromFile(const char* const file)
{
	char name[CHARS_NAME]{ "" };
	char address[CHARS_ADDRESS]{ "" };
	char email[CHARS_EMAIL]{ "" };
	char bankAccount[CHARS_BANK_ACCOUNT]{ "" };
	const char empty[CHARS_NAME]{ "empty" };
	const char typeCabin{ 'c' };
	const char typeHotelroon{ 'h' };
	const char typeEmpty{ 'e' };
	char type{ ' ' };
	bool bool1{ false };
	bool bool2{ false };
	bool bool3{ false };
	bool bool4{ false };
	bool bool5{ false };
	bool bool6{ false };
	int int1{ 0 };
	int int2{ 0 };
	int int3{ 0 };
	const int intEmpty{ DEFAULT_INT };
	size_t index{ DEFAULT_INDEX };
	size_t counter{ 0 };
	Accommodation* accomArray[MAX_PARK_ACCOM];
	Park* parkArray[MAX_PARKS];
	Customer* custArray[MAX_CUSTOMERS];
	Booking* bookingArray[MAX_BOOKING];
	Accommodation* bookAccomArray[MAX_BOOKING_ACCOM];
	Cabin cabinObj;
	Hotelroom hotelObj;
	Company* co{ nullptr };

	std::ifstream inFile{ file, std::ios::in | std::ios::binary };

	if (!inFile) // overloaded operator! returns true if either the failbit or the badbit is set for the stream
	{
		std::cerr << "Company data could not be read from file." << std::endl;
	}
	else
	{
		// read parks array from file
		for (size_t i{ 0 }; i < MAX_PARKS; i++)
		{
			parkArray[i] = nullptr;
			inFile.read(name, CHARS_NAME * sizeof(char));
			if (strcmp(empty, name) != 0)
			{
				// read park info from file
				inFile.read(address, CHARS_ADDRESS * sizeof(char));
				inFile.read(reinterpret_cast<char*>(&bool1), sizeof(bool)); // subtropicPar
				inFile.read(reinterpret_cast<char*>(&bool2), sizeof(bool)); // bikeRental
				inFile.read(reinterpret_cast<char*>(&bool3), sizeof(bool)); // waterBikeRental
				inFile.read(reinterpret_cast<char*>(&bool4), sizeof(bool)); // bowlingAlley
				inFile.read(reinterpret_cast<char*>(&bool5), sizeof(bool)); // kidsParadise
				inFile.read(reinterpret_cast<char*>(&bool6), sizeof(bool)); // sportsHall

				// read accommodations array from file
				for (size_t j{ 0 }; j < MAX_PARK_ACCOM; j++)
				{
					inFile.read(reinterpret_cast<char*>(&type), sizeof(char));
					// create new Cabin or Hotelroom object and assign to accomArray

					switch (type)
					{
					case typeCabin:
						inFile.read(reinterpret_cast<char*>(&cabinObj), sizeof(Cabin));
						accomArray[j] = new Cabin(cabinObj.getId(), cabinObj.getLuxuryLevel(), cabinObj.getMaxPeople(),
							cabinObj.getSize(), cabinObj.getPrice(), cabinObj.getNoOfBedrooms(), cabinObj.getBluRaySurround(),
							cabinObj.getBbq(), cabinObj.getBreakfastService(), cabinObj.getLaundryService());
						break;
					case typeHotelroon:
						inFile.read(reinterpret_cast<char*>(&hotelObj), sizeof(Hotelroom));
						accomArray[j] = new Hotelroom(hotelObj.getId(), hotelObj.getLuxuryLevel(), hotelObj.getMaxPeople(),
							hotelObj.getSize(), hotelObj.getPrice(), hotelObj.getFloor(), hotelObj.getSide(),
							hotelObj.getNoOfBeds(), hotelObj.getChildrensBed(), hotelObj.getMiniBar());
						break;
					case typeEmpty:
						accomArray[j] = nullptr;
						break;
					}
				} // end for accommodations array
				// create new Park object pointer and assign to parkArray
				parkArray[i] = new Park(name, address, bool1, bool2, bool3, bool4, bool5, bool6, accomArray, MAX_PARK_ACCOM);
			}
		} // end for parks array

		// read customers array from file
		for (size_t i{ 0 }; i < MAX_CUSTOMERS; i++)
		{
			custArray[i] = nullptr;
			inFile.read(name, CHARS_NAME * sizeof(char));
			if (strcmp(empty, name) != 0)
			{
				// read Customer info from file
				inFile.read(address, CHARS_ADDRESS * sizeof(char));
				inFile.read(email, CHARS_EMAIL * sizeof(char));
				inFile.read(bankAccount, CHARS_BANK_ACCOUNT * sizeof(char));

				// read bookings array from file
				for (size_t j{ 0 }; j < MAX_BOOKING; j++)
				{
					inFile.read(reinterpret_cast<char*>(&int1), sizeof(int)); // bookingId or intEmpty
					if (int1 != intEmpty)
					{
						// read Booking info from file
						inFile.read(reinterpret_cast<char*>(&int2), sizeof(int)); // noOfAccomm
						inFile.read(reinterpret_cast<char*>(&bool1), sizeof(bool)); // activityPass
						inFile.read(reinterpret_cast<char*>(&bool2), sizeof(bool)); // sportPass
						inFile.read(reinterpret_cast<char*>(&bool3), sizeof(bool)); // bikeRental
						inFile.read(reinterpret_cast<char*>(&bool4), sizeof(bool)); // subtropicPass

						// read Booking's accommodations array from file
						for (size_t k{ 0 }; k < MAX_BOOKING_ACCOM; k++)
						{
							inFile.read(reinterpret_cast<char*>(&int3), sizeof(int)); // id of accommodation or intEmpty
							if (int3 != intEmpty)
							{
								// search Accommodation pointer with the known id
								counter = 0;
								index = DEFAULT_INDEX;
								while (index == DEFAULT_INDEX && counter < MAX_PARKS)
								{
									if (parkArray[counter] != nullptr)
									{
										index = parkArray[counter]->getAccomIndexOf(int3);
									}
									counter++;
								}
								if (index != DEFAULT_INDEX)
								{
									bookAccomArray[k] = parkArray[counter - 1]->getAccommodations(index);
								}
								else
								{
									bookAccomArray[k] = nullptr;
								}
							}
							else
							{
								bookAccomArray[k] = nullptr;
							}
						} // end for Booking's accommodations array
						// create new Booking object pointer and assign to bookingArray
						bookingArray[j] = new Booking(int1, bool1, bool2, bool3, bool4, int2, bookAccomArray, MAX_BOOKING_ACCOM);
					}
					else
					{
						bookingArray[j] = nullptr;
					}
				} // end for bookings array
				// create new Customer object pointer and assign to custArray
				custArray[i] = new Customer(name, address, email, bankAccount, bookingArray, MAX_BOOKING);
			}
		} // end for customers array

		// read Company info from file
		inFile.read(name, CHARS_NAME);
		inFile.read(address, CHARS_ADDRESS);

		// create new Company object
		co = new Company(name, address, custArray, MAX_CUSTOMERS, parkArray, MAX_PARKS);

		// close file
		inFile.close();
	}

	return co;
}// end function readFromFile
