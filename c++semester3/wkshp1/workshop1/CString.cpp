// Workshop 1
// Name: William Vuong
// ID: 105165179
// Email: wvuong3@myseneca.ca

#include "CString.h"

namespace w1 {
	
	CString::CString(const char* tempStr) {
		if (tempStr[0] == '\0') {
			str[0] = '\0';
		}
		else {
			str = new char[max + 1];
			strncpy(str, tempStr, max + 1);
			str[max] = '\0';
		}
	}

	CString::~CString(){
	}

	void CString::display(ostream & os) {
		os << str;
	}

	ostream & operator<<(ostream & os, CString tempStr) {
		static int i = 0;

		os << i << ": ";
		tempStr.display(os);
		i++;
		return os;
	}

}