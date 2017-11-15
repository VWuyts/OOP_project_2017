/*
 *	Lab assignment for course Object Oriented Programming 2017
 *
 *	Véronique Wuyts
 *	Bachelor Elektronica-ICT option Application Development
 *	Thomas More campus De Nayer
 *
 *	Definition of symbolic constants
 */

#pragma once

// accommodation luxuryLevels
// maximum chars is equal to CHARS_LUXURY_LEVEL - 1
#define LUX_LEVEL_LOW "comfort"
#define LUX_LEVEL_MEDIUM "premium"
#define LUX_LEVEL_HIGH "vip"

// accommodation types
#define HOTEL_ROOM 'h'
#define CABIN 'c'

// default values
#define DEFAULT_PEOPLE 2
#define DEFAULT_PRICE 90
#define DEFAULT_SIZE 20

// maximum chars
#define CHARS_ADDRESS 60
#define CHARS_BANK_ACCOUNT 17
#define CHARS_EMAIL 60
#define CHARS_LUXURY_LEVEL 8 // comfort, premium or vip
#define CHARS_NAME 40

// maximum numbers
#define MAX_ACCOMMODATIONS 10
#define MAX_BOOKING 3
#define MAX_CUSTOMERS 100
#define MAX_PARKS 2
#define MAX_PEOPLE 18
#define MAX_PRICE 200 // per night
#define MAX_SIZE 100

// minimum numbers
#define MIN_PEOPLE 1
#define MIN_PRICE 20 // per night
#define MIN_SIZE 16

// price
#define ACTIVITY_PRICE 10
#define SPORT_PRICE 10
#define BIKE_RENTAL_PRICE 10
#define SUB_TROPIC_PRICE 10

// required
#define NAME_REQUIRED "name is required"
#define ADDRESS_REQUIRED "address is required"
#define EMAIL_REQUIRED "email is required"
#define BANK_ACCOUNT_REQUIRED "bankAccount is required"