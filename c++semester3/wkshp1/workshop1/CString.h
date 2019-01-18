// Workshop 1
// Name: William Vuong
// ID: 105165179
// Email: wvuong3@myseneca.ca

#ifndef _W1_CSTRING_H_
#define _W1_CSTRING_H_

#include <iostream>
#include <cstring>

using namespace std;

namespace w1 {

	int const max = 3;

	class CString {
		char* str;
	public:
		CString(const char* tempStr);
		~CString();
		void display(ostream& os );
	};

	ostream& operator <<(ostream& obj, CString str);

}
#endif