#ifndef _W5_MESSAGE_H_
#define _W5_MESSAGE_H_

#include <iostream>
#include <string>
#include <fstream>

namespace w5 {
	class Message {
	private:
		std::string user;
		std::string reply;
		std::string tweet;
	public:
		Message();
		Message(std::ifstream& in, char c);
		bool empty() const;
		void display(std::ostream&) const;
	};
}

#endif // !_W5_MESSAGE_H_