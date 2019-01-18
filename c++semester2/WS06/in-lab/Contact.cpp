// Name: William Vuong
// ID: 105165179
// Email: wvuong@seneca.ca

#include <iostream>
#include <cstring>
#include "Contact.h"

using namespace std;

namespace sict {

	Contact::Contact() {
		strcpy(name, "");
		phoneNumber = 0;
	}
	//*****************************************************************************************************
	Contact::~Contact() {
		//swag
	}
	//*****************************************************************************************************
	Contact::Contact(const char* tempName, const long long* tempPhoneNumber, int numOfNumbers) {
		if (tempPhoneNumber != nullptr) {
			int i = 0;
			int j = 0;
			int* validNumber;
			validNumber = new int[numOfNumbers];
			for (i = 0; i < numOfNumbers; i++) {
				if (isValid(tempPhoneNumber[i])) {
					validNumber[j] = i;
					++j;
				}
			}
		}
		
		phoneNumber = new long long[numOfNumbers];
		for (int i = 0; i <= numOfNumbers; i++) {
			if (phoneNumber[i] == !isEmpty()) {
				strcpy(name, tempName);
				phoneNumber[i] = tempPhoneNumber[i];
			}
			else Contact();
			
		}
	}
	//*****************************************************************************************************
	bool Contact::isEmpty() const {
		if (strcmp(name, "") != 0 && phoneNumber != 0) {
			return false;
		}
		else return true;
	}
	//*****************************************************************************************************
	bool Contact::isValid(long long number) const {
		bool flag = true;
		int digitOne = phoneNumber[0];
		int digitTwo = phoneNumber[1];
		int digitThree = phoneNumber[2];
		int digitFour = phoneNumber[3];
		int digitFive = phoneNumber[4];
		int digitSix = phoneNumber[5];
		int digitSeven = phoneNumber[6];
		int digitEight = phoneNumber[7];
		int digitNine = phoneNumber[8];
		int digitTen = phoneNumber[9];
		int digitEleven = phoneNumber[10];
		int digitTwelve = phoneNumber[11];

		if ((digitOne + digitTwo) <= 18 && (digitOne + digitTwo) != 0) {
			if (digitThree != 0 && (digitThree + digitFour + digitFive <= 27)) {
				if (digitSix != 0 && (digitSix + digitSeven + digitEight + digitNine + digitTen + digitEleven + digitTwelve) <= 63) {
					flag = false;
				}
			}
		}
		return flag;
	}
	//*****************************************************************************************************
	void Contact::display() const {
		if (!isEmpty()) {
			cout << name << endl;
			
		}

	}
}
