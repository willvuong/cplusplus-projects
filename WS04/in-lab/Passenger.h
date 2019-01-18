// Name: William Vuong
// ID: 105165179
// Email: wvuong@seneca.ca

#ifndef _PASSENGER_H_
#define _PASSENGER_H_

namespace sict {
	
	const int length = 32;
	
	class Passenger {
	private:
		char passengerName[length];
		char destination[length];
	public:
		Passenger();
		Passenger(const char* tempPassengerName, const char* tempDestination);
		~Passenger();
		bool isEmpty() const;
		void display() const;
	};
}
#endif