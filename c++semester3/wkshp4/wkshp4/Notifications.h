#ifndef _W5_NOTIFICATIONS_H_
#define _W5_NOTIFICATIONS_H_

#include "Message.h"

namespace w5 {
	class Notifications {
	private:
		Message* message;
		int numOfMessages;
	public:
		Notifications();
		Notifications(const Notifications&);
		Notifications& operator=(const Notifications&);
		Notifications(Notifications&&);
		Notifications&& operator=(Notifications&&);
		~Notifications();
		void operator+=(const Message& msg);
		void display(std::ostream& os) const;
	};
}

#endif // !_W5_NOTIFICATIONS_H_