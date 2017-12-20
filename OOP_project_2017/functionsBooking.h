/*
 *	Lab assignment for course Object Oriented Programming 2017
 *
 *	Véronique Wuyts
 *	Bachelor Elektronica-ICT option Application Development
 *	Thomas More campus De Nayer
 *
 *	Definition of Booking functions
 */

#pragma once

 // Includes
#include "booking.h"
#include "company.h"

// Booking functions
void checkBooking(Company*); // accessible to employee and customer
void createBooking(Company*); // accessible to employee and customer
void changeBooking(Company*); // accessible to employee and customer
void deleteBooking(Company*); // accessible to employee
void bookServices(bool[], Park*); // accessible to function createBooking

// Utility functions
Accommodation* searchAccommodation(Park*); // search an Accommodation in the given Park
bool inArray(int, int[], size_t); // search the array for the given integer
//bool idInArray(int, Accommodation*[], size_t); // search the Accommodation array for the given id
