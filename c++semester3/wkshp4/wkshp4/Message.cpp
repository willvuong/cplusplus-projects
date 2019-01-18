#include "Message.h"

using namespace std;

namespace w5 {
	Message::Message() {
	}

	Message::Message(std::ifstream & in, char c) {
		std::string line;
		std::string tempUser;
		
		in >> tempUser;
		for (int i = 0; i < tempUser.length(); i++) {
			if (tempUser.back()  != '\n') {
				user += tempUser[i];
			}
		}
		in.ignore();
		getline(in, line, c);

		if (in.is_open() && !in.eof()) {

			int j;
			if (line[0] == '@') {
				for (int i = 1; i < line.length(); i++) {
					if (line[i] != ' ') {
						reply += line[i];
					}
					else {
						i = line.length();
					}
				}
				j = line.find(' ') + 1;
				line = line.substr(j, line.length());
			}
				tweet += line;
		}
		else {
			tweet = "";
			in.close();
		}

	}

	bool Message::empty() const {
		if (user == "" && reply == "" && tweet == "") {
			return true;
		}
		else {
			return false;
		}
	}

	void Message::display(std::ostream & os) const {
		if (!empty()) {
			os << "Message" << endl;
			os << " User  : " << user << endl;
			if (!reply.empty()){
				os << " Reply : " << reply << endl;
			}
			os << " Tweet : " << tweet << endl << endl;
		}
	}

} //end