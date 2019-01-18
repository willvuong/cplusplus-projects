// Name: William Vuong
// ID: 105165179
// Email: wvuong@seneca.ca

#include <iostream>
#include <cstring>
#include "CRA_Account.h"

using namespace std;

namespace sict {
		void CRA_Account::set(const char* familyName, const char* givenName, int sin) {
			sinNum = sin;
			if (!isEmpty()) {
				strcpy(familyN, familyName);
				strcpy(givenN, givenName);
			}
			else sin = 0;
		}
		
		bool CRA_Account::isEmpty() const {
			if (sinNum >= min_sin && sinNum <= max_sin) {
				return false;
			} else return true;
		}

		void CRA_Account::display() const {
			if (!isEmpty()) {
				cout << "Family Name: " << familyN << endl;
				cout << "Given Name : " << givenN << endl;
				cout << "CRA Account: " << sinNum << endl;
			}
			else cout << "Account object is empty!" << endl;
		}
}