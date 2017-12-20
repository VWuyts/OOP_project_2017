/*
 *	Lab assignment for course Object Oriented Programming 2017
 *
 *	Véronique Wuyts
 *	Bachelor Elektronica-ICT option Application Development
 *	Thomas More campus De Nayer
 *
 *	Definition of Accommodation functions
 */

#pragma once

// Includes
#include "cabin.h"
#include "company.h"
#include "hotelroom.h"

// Accomodation functions
void checkAccommodation(Company*); // accessible to owner and employee
void createAccommodation(Company*); // accessible to owner
void changeAccommodation(Company*); // accessible to owner and employee
void deleteAccommodation(Company*); // accessible to owner
