// Name: William Vuong
// ID: 105165179
// Email: wvuong@seneca.ca

#include <iostream>
#include "Passenger.h"
#include <cstring>

using namespace std;

namespace sict {
	
	Passenger::Passenger() {
		strcpy(passengerName, "");
		strcpy(destination, "");
		yearOfDeparture = 0;
		monthOfDeparture = 0;
		dayOfDeparture = 0;
	}
	
	Passenger::~Passenger() {
	}

	Passenger::Passenger(const char* tempPassengerName, const char* tempDestination) {
		if (!isEmpty() && tempPassengerName != nullptr && tempDestination != nullptr) {
			strncpy(passengerName, tempPassengerName, length);
			strncpy(destination, tempDestination, length);
			yearOfDeparture = 2017;
			monthOfDeparture = 7;
			dayOfDeparture = 1;
		}
		else *this = Passenger();
	}

	Passenger::Passenger(const char* tempPassengerName, const char* tempDestination, int year, int month, int day) {
		if (tempPassengerName != nullptr && tempDestination != nullptr && (year >= 2017 && year <= 2020) && (month >= 1 && month <= 12) && (day >= 1 && day <= 31)) {
			strncpy(passengerName, tempPassengerName, length);
			strncpy(destination, tempDestination, length);
			yearOfDeparture = year;
			monthOfDeparture = month;
			dayOfDeparture = day;
		}
		else *this = Passenger();
	}

	bool Passenger::isEmpty() const {
		if (strcmp(passengerName, "") != 0 && strcmp(destination, "") != 0) {
			return false;
		}
		else return true;
	}

	void Passenger::display() const {
			if (!isEmpty() && (yearOfDeparture >= 2017 && yearOfDeparture <= 2020) && (monthOfDeparture >= 1 && monthOfDeparture <= 12) && (dayOfDeparture >= 1 && dayOfDeparture <= 31)) {
				cout << passengerName << " - " << destination << " on " << yearOfDeparture << "/";
			
				if (monthOfDeparture < 10) {
					cout << "0" << monthOfDeparture << "/";
				}
				else cout << monthOfDeparture << "/";

				if (dayOfDeparture < 10) {
					cout << "0" << dayOfDeparture << endl;
				}
				else cout << dayOfDeparture << endl;

			}
			else {
				cout << "No passenger!" << endl;
			}
	}

	const char* Passenger::name() const {
		const char * tempString = "";
		if (!isEmpty()) {
			return passengerName;
		}
		else return tempString;
	}

	bool Passenger::canTravelWith(const Passenger & tempPassenger) const {
		if (strcmp(this->destination, tempPassenger.destination) == 0 && this->yearOfDeparture == tempPassenger.yearOfDeparture && this->monthOfDeparture == tempPassenger.monthOfDeparture && this->dayOfDeparture == tempPassenger.dayOfDeparture) {
			return true;
		}
		else return false;
	}
}