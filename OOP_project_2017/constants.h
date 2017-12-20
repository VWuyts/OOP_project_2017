/*
 *	Lab assignment for course Object Oriented Programming 2017
 *
 *	Véronique Wuyts
 *	Bachelor Elektronica-ICT option Application Development
 *	Thomas More campus De Nayer
 *
 *	Definition of enumerations and symbolic constants
 */

#pragma once

// array sizes
#define ROLES 3
#define CATS 4
#define FCTNS 4

// default values
#define DEFAULT_BEDS 2
#define DEFAULT_CO_NAME "Parks en Zo"
#define DEFAULT_CO_ADDRESS "Jan De Nayerlaan 5, 2860 Sint-Katelijne-Waver"
#define DEFAULT_INDEX 999
#define DEFAULT_INT -999
#define DEFAULT_LINE 80
#define DEFAULT_PARK_NAME "Fun Parks"
#define DEFAULT_PARK_ADDRESS "Piet De Nayerlaan 10, 2860 Sint-Katelijne-Waver"
#define DEFAULT_PEOPLE 2
#define DEFAULT_PRICE 90
#define DEFAULT_SIDE "street"
#define DEFAULT_SIZE 20

// maximum chars
#define CHARS_ADDRESS 60
#define CHARS_BANK_ACCOUNT 17
#define CHARS_BOOL 4
#define CHARS_EMAIL 60
#define CHARS_NAME 40
#define CHARS_SIDE 10

// maximum numbers
#define MAX_BEDROOMS 6
#define MAX_BEDS 4 // for hotelroom
#define MAX_BOOKING 10
#define MAX_BOOKING_ACCOM 3
#define MAX_CUSTOMERS 10
#define MAX_FLOOR 15
#define MAX_PARKS 2
#define MAX_PARK_ACCOM 10
#define MAX_PEOPLE 18
#define MAX_PRICE 200 // per night
#define MAX_SIZE 200

// minimum numbers
#define MIN_BEDROOMS 2 // for cabin
#define MIN_BEDS 1 // for hotelroom
#define MIN_FLOOR 0
#define MIN_PEOPLE 1
#define MIN_PRICE 20 // per night
#define MIN_SIZE 16

// price
#define PRICE_ACTIVITY 20
#define PRICE_SPORT 10
#define PRICE_BIKE_RENTAL 10
#define PRICE_SUB_TROPIC 10

// prime numbers
#define PN_CUSTOMER 3
#define PN_EMPLOYEE 5
#define PN_OWNER 7

// required
#define NAME_REQUIRED "name is required"
#define ADDRESS_REQUIRED "address is required"
#define EMAIL_REQUIRED "email is required"
#define BANK_ACCOUNT_REQUIRED "BA is required"

// width ostream
#define WIDTH_ACCOM 20
#define WIDTH_BOOKING 26
#define WIDTH_CUST 14
#define WIDTH_PARK 20