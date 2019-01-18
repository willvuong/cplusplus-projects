#include "Notifications.h"

using namespace std;

namespace w5 {
	Notifications::Notifications() {
		message = nullptr;
		numOfMessages = 0;
	}

	Notifications::Notifications(const Notifications &obj) {
		if (&obj != nullptr) {
			*this = obj;
		}
	}

	Notifications & Notifications::operator=(const Notifications &obj) {
		if (this != &obj) {
			this->message = new Message[obj.numOfMessages];
			this->message = obj.message;
			this->numOfMessages = obj.numOfMessages;
		}
		else {
			delete[] this->message;
			this->message = nullptr;
			this->numOfMessages = 0;
		}
		return *this;
	}

	Notifications::Notifications(Notifications && obj) {
		//delete[] this->message;
		this->message = obj.message;
		this->numOfMessages = obj.numOfMessages;

		obj.message = nullptr;
		obj.numOfMessages = 0;

	}

	Notifications && Notifications::operator=(Notifications &&obj) {
		if (this != &obj) {
			delete[] this->message;
			this->message = obj.message;
			this->numOfMessages = obj.numOfMessages;
			obj.message = nullptr;
			obj.numOfMessages = 0;
		}
		return move(*this);
	}


	Notifications::~Notifications() {
		delete[] this->message;
		this->numOfMessages = 0;
	}

	void Notifications::operator+=(const Message & msg) {
		Message* temp = nullptr;
		temp = new Message[numOfMessages + 1];
		for (int i = 0; i < numOfMessages; i++)
		{
			temp[i] = message[i];
		}
		temp[numOfMessages] = msg;
		delete[] message;
		message = temp;
		temp = nullptr;
		numOfMessages++;
	}

	void Notifications::display(std::ostream & os) const {
		for (int i = 0; i < numOfMessages; i++) {
			message[i].display(os);
			//os << message[i];
		}
	}

} //end