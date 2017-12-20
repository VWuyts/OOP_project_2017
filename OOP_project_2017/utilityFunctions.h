/*
 *	Lab assignment for course Object Oriented Programming 2017
 *
 *	Véronique Wuyts
 *	Bachelor Elektronica-ICT option Application Development
 *	Thomas More campus De Nayer
 *
 *	Definition of utility functions
 */

#pragma once

// Includes
#include "company.h"

// Utility functions
int login(const char*[], const int[], size_t);
int menu(int, const char*[], const int[], size_t);
int submenu(int, int, const char*[][FCTNS], const int[][FCTNS], size_t);
void saveToFile(Company* const, const char* const);
Company* readFromFile(const char* const);