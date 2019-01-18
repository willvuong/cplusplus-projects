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
	}
	
	Passenger::~Passenger() {
	}

	Passenger::Passenger(const char* tempPassengerName, const char* tempDestination) {
		if (!isEmpty() && tempPassengerName != nullptr && tempDestination != nullptr) {
			strcpy(passengerName, tempPassengerName);
			strcpy(destination, tempDestination);
		}
		else *this = Passenger();
	}

	bool Passenger::isEmpty() const {
		if (strcmp(passengerName, "") != 0 && strcmp(destination, "") != 0) {
			return false;
		}
		return true;
	}

	void Passenger::display() const {
			if (!isEmpty()) {
				cout << passengerName << " - " << destination << endl;
			}
			else {
				cout << "No passenger!" << endl;
			}
	}
}