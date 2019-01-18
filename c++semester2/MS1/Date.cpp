// Final Project Milestone 1
// Name: William Vuong
// ID: 105165179
// Email: wvuong@seneca.ca
#include "Date.h"
using namespace std;

namespace sict {

	int Date::mdays(int mon, int year)const {
		int days[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31, -1 };
		int month = mon >= 1 && mon <= 12 ? mon : 13;
		month--;
		return days[month] + int((month == 1)*((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0));
	}

	void Date::errCode(int errorCode) {
		errorState = errorCode;
	}

	Date::Date() {
		year = 0000;
		month = 00;
		day = 00;
		errCode(0);
		comparator = 0;
	}

	Date::Date(int tempYear, int tempMonth, int tempDay) {
		*this = Date();
		if (tempYear >= min_year && tempYear <= max_year) {
			if (tempMonth >= 1 && tempMonth <= 12) {
				int maxDays = mdays(tempMonth, tempYear);
				if (tempDay >= 1 && tempDay <= maxDays) {
					day = tempDay;

					month = tempMonth;
					year = tempYear;
					errCode(0);
					comparator = tempYear * 372 + tempMonth * 13 + tempDay;
				}
				else errCode(4);
			}
			else errCode(3);
		}
		else errCode(2);

	}

	bool Date::operator==(const Date& rhs) const {
		if (this->comparator == rhs.comparator) {
			return true;
		}
		else return false;
	}

	bool Date::operator!=(const Date& rhs) const {
		if (*this == rhs) {
			return false;
		}
		else return true;
	}

	bool Date::operator<(const Date& rhs) const {
		if (this->comparator < rhs.comparator) {
			return true;
		}
		else return false;
	}

	bool Date::operator>(const Date& rhs) const {
		if (this->comparator > rhs.comparator) {
			return true;
		}
		else return false;
	}

	bool Date::operator<=(const Date& rhs) const {
		if (this->comparator <= rhs.comparator) {
			return true;
		}
		else return false;
	}

	bool Date::operator>=(const Date& rhs) const {
		if (this->comparator >= rhs.comparator) {
			return true;
		}
		else return false;
	}

	int Date::errCode() const {
		return errorState;
	}

	bool Date::bad() const {
		if (errorState == 0) {
			return true;
		}
		return false;
	}

	std::istream & Date::read(std::istream & istr) {
		istr >> year;
		istr.ignore();
		istr >> month;
		istr.ignore();
		istr >> day;
		if (istr.fail()) {
			errCode(CIN_FAILED);
			return istr;
		}
		while (true) {
			if (year > max_year || year < min_year) {
				errCode(YEAR_ERROR);
				break;
			}
			if (month < 1 || month > 12) {
				errCode(MON_ERROR);
				break;
			}
			if (day < 1 || day > mdays(month, year)) {
				errCode(DAY_ERROR);
				break;
			}

			break;
		}

		//return istr;
		if (errorState != 0) {
			month = 0;
			year = 0;
			day = 0;
			comparator = 0;
		}
		return istr;
	}
	
	std::ostream & Date::write(std::ostream & ostr) const {
		
		ostr << year;
		
		ostr << "/";
		ostr.setf(ios::fixed);
		ostr.width(2);
		ostr.fill('0');
		ostr << month;
		ostr << "/"; 
		ostr.width(2);
		ostr.fill('0');
		ostr << day;
		ostr.unsetf(ios::fixed);
		return ostr;
	}
	
	std::ostream & operator<<(std::ostream & ostr, Date & date)
	{
		date.write(ostr);
		return ostr;
	}

	std::istream & operator >> (std::istream & istr, Date & date)
	{
		date.read(istr);
		return istr;
	}

}
