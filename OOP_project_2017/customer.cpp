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
#include "customer.h"

// default constructor
Customer::Customer(char name[], char address[], char email[], char bankAccount[])
{
	setName(name);
	setAddress(address);
	setEmail(email);
	setBankAccount(bankAccount);
} // end Customer default constructor


Customer::~Customer(void)
{
	// TO DO: implement destructor
} // end Customer destructor

// return constant pointer to constant name
const char* const Customer::getName(void) const
{
	return name;
} // end function getName

// return constant pointer to constant address
const char* const Customer::getAddress(void) const
{
	return address;
} // end function getAddress

// return constant pointer to constant email
const char* const Customer::getEmail(void) const
{
	return email;
} // end function getEmail

// return constant pointer to constant bankAccount
const char* const Customer::getBankAccount(void) const
{
	return bankAccount;
} // end function bankAccount

// set name
void Customer::setName(const char name[])
{
	size_t length = strlen(name);
	length = (length < CHARS_NAME ? length : CHARS_NAME - 1);
	strncpy_s(this->name, CHARS_NAME, name, length);
} // end function setName

// set address
void Customer::setAddress(const char address[])
{
	size_t length = strlen(address);
	length = (length < CHARS_ADDRESS ? length : CHARS_ADDRESS - 1);
	strncpy_s(this->address, CHARS_ADDRESS, address, length);
} // end function setAddress

// set email
void Customer::setEmail(const char email[])
{
	size_t length = strlen(email);
	length = (length < CHARS_EMAIL ? length : CHARS_EMAIL - 1);
	strncpy_s(this->email, CHARS_EMAIL, email, length);
} // end function setEmail

// set bankAccount
void Customer::setBankAccount(const char bankAccount[])
{
	size_t length = strlen(bankAccount);
	length = (length < CHARS_BANK_ACCOUNT ? length : CHARS_BANK_ACCOUNT - 1);
	strncpy_s
	(this->bankAccount, CHARS_BANK_ACCOUNT, bankAccount, length);
} // end function setBankAccount
