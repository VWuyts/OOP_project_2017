/*
 *	Lab assignment for course Object Oriented Programming 2017
 *
 *	Véronique Wuyts
 *	Bachelor Elektronica-ICT option Application Development
 *	Thomas More campus De Nayer
 *
 *	Definition of Customer functions
 */

#pragma once

// Includes
#include "company.h"

// Customer functions
void checkCustomer(Company*); // accessible to employee and customer
void createCustomer(Company*); // accessible to employee and customer
void changeCustomer(Company*); // accessible to employee and customer
void deleteCustomer(Company*); // accessible to employee
