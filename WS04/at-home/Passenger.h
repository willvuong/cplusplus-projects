// Name: William Vuong
// ID: 105165179
// Email: wvuong@seneca.ca

#ifndef SICT_PASSENGER_H
#define SICT_PASSENGER_H

namespace sict {

	const int length = 32;

	class Passenger {
	private:
		char passengerName[length];
		char destination[length];
		int yearOfDeparture;
		int monthOfDeparture;
		int dayOfDeparture;
	public:
		Passenger();
		Passenger(const char* tempPassengerName, const char* tempDestination);
		Passenger(const char* tempPassengerName, const char* tempDestination, int year, int month, int day);
		~Passenger();
		bool isEmpty() const;
		void display() const;
		const char* name() const;
		bool canTravelWith(const Passenger & tempPassenger) const;
	};
}
#endif