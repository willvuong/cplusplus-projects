// Name: William Vuong
// ID: 105165179
// Email: wvuong@seneca.ca

#ifndef SICT_CONTACT_H
#define SICT_CONTACT_H

namespace sict {

	const int length = 21;

	class Contact {
	private:
		char name[length];
		long long* phoneNumber;
	public:
		Contact();
		~Contact();
		Contact(const char* tempName, const long long* tempPhonenNumber, int numOfNumbers);
		bool isEmpty() const;
		bool isValid(long long phoneNumber) const;
		void display() const;
	};
}

#endif
