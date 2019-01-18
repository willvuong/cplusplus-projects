// Name: William Vuong
// ID: 105165179
// Email: wvuong@seneca.ca

#ifndef _CRA_ACCOUNT_H_
#define _CRA_ACCOUNT_H_

namespace sict {

	const int max_name_length = 41;
	const long long min_sin = 100000000;
	const long long max_sin = 999999999;
	const int max_yrs = 4;

	class CRA_Account {
	private:
		char familyN[max_name_length];
		char givenN[max_name_length];
		long long sinNum;
		int taxReurnYears[max_yrs];
		double balanceOrRefund[max_yrs];
		int numberOfYears;
	public:
		CRA_Account();
		~CRA_Account();
		void set(const char* familyName, const char* givenName, int sin);
		bool isEmpty() const;
		void display() const;
		void set(int year, double balance);
	};
}
#endif
