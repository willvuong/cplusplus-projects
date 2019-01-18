// Final Project Milestone 2
// Name: William Vuong
// ID: 105165179
// Email: wvuong@seneca.ca

#define _CRT_SECURE_NO_WARNINGS
#include "ErrorMessage.h"
using namespace std;

namespace sict {

	sict::ErrorMessage::ErrorMessage(const char * errorMessage) {
		msg = new char[1];
		msg[0] = '\0';
		
		if (errorMessage == nullptr) {
			strcpy(msg, "");
		}
		else {
			if (isClear()) {
				msg = nullptr;
				msg = new char[strlen(errorMessage) + 1];
				strcpy(msg, errorMessage);
			}
		}
	}

	sict::ErrorMessage::~ErrorMessage(){
		delete[] msg;
	}

	void sict::ErrorMessage::clear() {
		delete[] msg;
		msg = nullptr;
		msg = new char[1];
		msg[0] = '\0';
	}

	bool sict::ErrorMessage::isClear() const {
		if (strcmp(msg, "") != 0) {
			return false;
		}
		else return true;
	}

	void ErrorMessage::message(const char * str) {
		delete[] msg;
		msg = new char[strlen(str) + 1];
		strcpy(msg, str);
	}

	const char * ErrorMessage::message() const {
		return msg;
	}

	std::ostream & operator<<(std::ostream & ostr, const ErrorMessage & em) {
		if (!em.isClear()) {
			ostr << em.message();
		}
		return ostr;
	}
}