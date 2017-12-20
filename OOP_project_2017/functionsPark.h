/*
 *	Lab assignment for course Object Oriented Programming 2017
 *
 *	Véronique Wuyts
 *	Bachelor Elektronica-ICT option Application Development
 *	Thomas More campus De Nayer
 *
 *	Definition of Park functions
 */

#pragma once

// Includes
#include "company.h"

// Park functions
void checkPark(Company*); // accessible to owner
void createPark(Company*); // accessible to owner
void changePark(Company*); // accessible to owner
void deletePark(Company*); // accessible to owner