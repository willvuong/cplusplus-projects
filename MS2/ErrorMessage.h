// Final Project Milestone 2
// Name: William Vuong
// ID: 105165179
// Email: wvuong@seneca.ca

#ifndef SICT_ERROR_MESSAGE_H
#define SICT_ERROR_MESSAGE_H
#include <iostream>
#include <cstring>

namespace sict {

	class ErrorMessage {
	private:
		char* msg;
	public:
		explicit ErrorMessage(const char* errorMessage = nullptr);
		ErrorMessage(const ErrorMessage& em) = delete;
		ErrorMessage& operator=(const ErrorMessage& em) = delete;
		virtual ~ErrorMessage();
		void clear();
		bool isClear() const;
		void message(const char* str);
		const char* message()const;
	};
	std::ostream & operator<<(std::ostream&ostr, const ErrorMessage &em);
}

#endif
