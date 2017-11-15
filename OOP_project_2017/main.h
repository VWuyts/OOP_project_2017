/*
 *	Lab assignment for course Object Oriented Programming 2017
 *
 *	Véronique Wuyts
 *	Bachelor Elektronica-ICT option Application Development
 *	Thomas More campus De Nayer
 */

#pragma once

// Includes
#include <iostream>
using std::cin;
using std::cout;
using std::endl;

#include "constants.h"

// Accomodation functions
void createAccommodation(void);
void changeAccommodation(void);
void deleteAccommodation(void);

// Booking functions
void createBooking(void);
void changeBooking(void);
void deleteBooking(void);

// Customer functions
void createCustomer(void);
void changeCustomer(void);
void deleteCustomer(void);

// Park functions
void createPark(void);
void changePark(void);
void deletePark(void);

// Utility functions
int login(void);
int menu(int);
