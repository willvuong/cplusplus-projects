// Final Project Milestone 1
// Name: William Vuong
// ID: 105165179
// Email: wvuong@seneca.ca
#ifndef SICT_DATE_H
#define SICT_DATE_H
#include <iostream>
#define NO_ERROR   0 //no error - date is valid
#define CIN_FAILED 1 //istream failed on information entry 
#define YEAR_ERROR 2 //year value is invalid
#define MON_ERROR  3 //month value is invalid
#define DAY_ERROR  4 //day value is invalid

const int min_year = 2000;
const int max_year = 2030;
namespace sict {

	class Date {

	private:
		int year;
		int month;
		int day;
		long long comparator;
		int errorState;
		int mdays(int, int)const;
		void errCode(int);
	public:
		Date();
		Date(int tempYear, int tempMonth, int tempDay);
		bool operator==(const Date& rhs) const;
		bool operator!=(const Date& rhs) const;
		bool operator<(const Date& rhs) const;
		bool operator>(const Date& rhs) const;
		bool operator<=(const Date& rhs) const;
		bool operator>=(const Date& rhs) const;
		int errCode() const;
		bool bad() const;
		std::istream& read(std::istream& istr);
		std::ostream& write(std::ostream& ostr) const;
	};

	std::ostream& operator<<(std::ostream& ostr, Date& date);
	std::istream& operator>>(std::istream& istr, Date& date);

}
#endif