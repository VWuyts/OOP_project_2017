/*
 *	Lab assignment for course Object Oriented Programming 2017
 *
 *	Véronique Wuyts
 *	Bachelor Elektronica-ICT option Application Development
 *	Thomas More campus De Nayer
 *
 * Defintition of functions that request user input for Use Case functions
 */

#pragma once

// includes
#include "constants.h"

void printLine(size_t); // print a line
bool requestBool(char[], char[]); // request boolean input
size_t requestIndex(char[], size_t); // request index input
int requestInt(char[]); // request integer input
void requestString(char[], char[], size_t); // request string input