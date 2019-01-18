// Name: William Vuong
// ID: 105165179
// Email: wvuong@seneca.ca

#ifndef _CRA_ACCOUNT_H_
#define _CRA_ACCOUNT_H_

namespace sict {

	const int max_name_length = 41;
	const long long min_sin = 100000000;
	const long long max_sin = 999999999;

	class CRA_Account {
	private:
		char familyN[max_name_length];
		char givenN[max_name_length];
		long long sinNum;
	public:
		void set(const char* familyName, const char* givenName, int sin);
		bool isEmpty() const;
		void display() const;
	};
}

#endif
