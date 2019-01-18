// Name: William Vuong
// ID: 105165179
// Email: wvuong@seneca.ca

#include <iostream>
#include <cstring>
#include "CRA_Account.h"

using namespace std;

namespace sict {
	CRA_Account::CRA_Account() {
		for (int i = 0; i < max_yrs; i++) {
			taxReurnYears[i] = 0;
			balanceOrRefund[i] = 0;
		}
	}

	CRA_Account::~CRA_Account() {
	}

	void CRA_Account::set(const char* familyName, const char* givenName, int sin) {
		sinNum = sin;
		if (sinNum >= min_sin && sinNum <= max_sin) {
			strcpy(familyN, familyName);
			strcpy(givenN, givenName);
			numberOfYears = 0;
			sinNum = sin;
		}
		else CRA_Account();
	}

	void CRA_Account::set(int year, double balance) {
		if (!isEmpty()) {
			for (int i = 0; i < max_yrs; i++) {
				if (taxReurnYears[i] == 0) {
					taxReurnYears[i] = year;
					balanceOrRefund[i] = balance;
					break;
				}
			}
		}
	}

	bool CRA_Account::isEmpty() const {
		bool flag = true;
		if (sinNum >= min_sin && sinNum <= max_sin && strcmp(givenN, "") != 0  && strcmp(familyN, "") != 0) {
			int total = 0;

			int digitOne = sinNum / 100000000;
			int digitTwo = (sinNum - 100000000) / 10000000 % 10;
			int digitThree = ((sinNum - 10000000) / 1000000) % 10;
			int digitFour = ((sinNum - 1000000) / 100000) % 10;
			int digitFive = ((sinNum - 100000) / 10000) % 10;
			int digitSix = ((sinNum - 10000) / 1000) % 10;
			int digitSeven = ((sinNum - 1000) / 100) % 10;
			int digitEight = ((sinNum - 100) / 10) % 10;
			int digitNine = ((sinNum - 10) / 1) % 10;

			total = digitOne + digitTwo + digitThree + digitFour + digitFive + digitSix + digitSeven + digitEight + digitNine;
			if (total % 10 == 0) {
				flag = false;
			}
		}
		return flag;
	}

	void CRA_Account::display() const {
		if (!isEmpty()) {
			cout << "Family Name: " << familyN << endl;
			cout << "Given Name : " << givenN << endl;
			cout << "CRA Account: " << sinNum << endl;

			for (int i = 0; i < max_yrs; i++) {
				if (balanceOrRefund[i] > 2) {
					cout << "Year (" << taxReurnYears[i] << ") balance owing: " << balanceOrRefund[i] << endl;
				}
				else if (balanceOrRefund[i] < -2) {
					cout.precision(2);
					cout << "Year (" << taxReurnYears[i] << ") refund due: " << fixed << balanceOrRefund[i] * -1 << endl;
				}
				else {
					cout << "Year (" << taxReurnYears[i] << ") No balance owing or refund due!" << endl;
				}
			}
		}
		else cout << "Account object is empty!" << endl;
	}
}