/*
 *	Lab assignment for course Object Oriented Programming 2017
 *
 *	Véronique Wuyts
 *	Bachelor Elektronica-ICT option Application Development
 *	Thomas More campus De Nayer
 *
 *	Implementation of Customer functions
 */

// Includes
#include "functionsCustomer.h"
#include "functionsUserInput.h"

// view all Customers included in the given Company
void checkCustomer(Company* co)
{
	Customer* custPtr{ nullptr };
	size_t counter{ 0 };

	std::cout << "\nCheck customers" << std::endl;
	printLine(15);
	// check if there are customers included in the given Company
	if (co->getNoOfCustomers() == 0)
	{
		std::cout << "Company " << co->getName() << " has no customers.\n" << std::endl;
	}
	else
	{
		// show customers
		for (size_t i{ 0 }; i < MAX_CUSTOMERS; i++)
		{
			if ((custPtr = co->getCustomers(i)) != nullptr)
			{
				std::cout << ++counter << ". " << *custPtr << std::endl;
			}
		}
	}
} // end function checkCustomer

// create a Customer and add the Customer to the given Company
void createCustomer(Company* co)
{
	char name[CHARS_NAME]{ "" };
	char address[CHARS_ADDRESS]{ "" };
	char email[CHARS_EMAIL]{ "" };
	char bankAccount[CHARS_BANK_ACCOUNT]{ "" };
	Customer* custPtr{ nullptr };

	std::cout << "\nCreate customer" << std::endl;
	printLine(15);
	// check if a customer can be added
	if (co->getNoOfCustomers() == MAX_CUSTOMERS)
	{
		std::cout << "\nCompany " << co->getName() << " has already reached the maximum number of Customers.\n" << std::endl;
	}
	else
	{
		std::cout << "Please give the requested information for the new customer:" << std::endl;
		requestString("name", name, CHARS_NAME);
		requestString("address", address, CHARS_ADDRESS);
		requestString("e-mail", email, CHARS_EMAIL);
		requestString("bank account", bankAccount, CHARS_BANK_ACCOUNT);
		// create new customer
		custPtr = new Customer(name, address, email, bankAccount);
		co->setCustomers(custPtr);
		delete custPtr;
		custPtr = nullptr;
		std::cout << "\nCustomer " << name << " has been added to company " << co->getName() << "\n" << std::endl;
	}
} // end function createCustomer

// change a Customer included in the given Company
void changeCustomer(Company* co)
{
	size_t custIndex{ 0 };
	size_t changeIndex{ 0 };
	size_t noOfCusts{ co->getNoOfCustomers() };
	char changedName[CHARS_NAME]{ "" };
	char changedAddress[CHARS_ADDRESS]{ "" };
	char changedEmail[CHARS_EMAIL]{ "" };
	char changedBankAccount[CHARS_BANK_ACCOUNT]{ "" };
	Customer* custPtr{ nullptr };

	std::cout << "\nChange customer" << std::endl;
	printLine(15);
	// check if there are customers included in the given Company
	if (noOfCusts == 0)
	{
		std::cout << "Company " << co->getName() << " has no customers.\n" << std::endl;
	}
	else
	{
		// request which customer has to be changed
		std::cout << "\nPlease check which customer you want to change:" << std::endl;
		checkCustomer(co);
		std::cout << (noOfCusts + 1) << ". cancel\n" << std::endl;
		custIndex = requestIndex("customer", noOfCusts + 1);
		if (custIndex != (noOfCusts + 1))
		{
			custIndex = co->getCustIndex(custIndex);
			if (custIndex != DEFAULT_INDEX)
			{
				std::cout << "\nWhat do you want to change?"
					<< "\n1. name"
					<< "\n2. address"
					<< "\n3. e-mail"
					<< "\n4. bank account"
					<< "\n5. cancel\n"
					<< std::endl;
				changeIndex = requestIndex("", 5);
				// change the requested item
				custPtr = co->getCustomers(custIndex);
				switch (changeIndex)
				{
				case 1:
					requestString("new name", changedName, CHARS_NAME);
					custPtr->setName(changedName);
					std::cout << "\nThe customer now has name: " << custPtr->getName() << "\n" << std::endl;
					break;
				case 2:
					requestString("new address", changedAddress, CHARS_ADDRESS);
					custPtr->setAddress(changedAddress);
					std::cout << "\nThe customer now has address: " << custPtr->getAddress() << "\n" << std::endl;
					break;
				case 3:
					requestString("new e-mail", changedEmail, CHARS_EMAIL);
					custPtr->setEmail(changedEmail);
					std::cout << "\nThe customer now has e-mail: " << custPtr->getEmail() << "\n" << std::endl;
					break;
				case 4:
					requestString("new bank account", changedBankAccount, CHARS_BANK_ACCOUNT);
					custPtr->setBankAccount(changedBankAccount);
					std::cout << "\nThe customer now has bank account: " << custPtr->getBankAccount() << "\n" << std::endl;
					break;
				case 5:
					break;
				}
			}
		}
	}
} // end function changeCustomer

// delete a Customer from the given Company
void deleteCustomer(Company* co)
{
	size_t custIndex{ 0 };
	size_t noOfCusts{ co->getNoOfCustomers() };
	char custName[CHARS_NAME]{ "" };

	std::cout << "\nDelete Customer" << std::endl;
	printLine(15);
	// check if there are customers included in the given Company
	if (noOfCusts == 0)
	{
		std::cout << "Company " << co->getName() << " has no customers.\n" << std::endl;
	}
	else
	{
		std::cout << "\nPlease check which customer you want to delete:" << std::endl;
		checkCustomer(co);
		std::cout << (noOfCusts + 1) << ". cancel\n" << std::endl;
		custIndex = requestIndex("customer", noOfCusts + 1);
		if (custIndex != (noOfCusts + 1))
		{
			custIndex = co->getCustIndex(custIndex);
			if (custIndex != DEFAULT_INDEX)
			{
				// delete the customer
				strcpy_s(custName, CHARS_NAME, co->getCustomers(custIndex)->getName());
				co->destructCustomerAt(custIndex);
				std::cout << "\nCustomer " << custName << " has been deleted from Company " << co->getName()
					<< "\n" << std::endl;
			}
		}
	}
} // end function deleteCustomer
