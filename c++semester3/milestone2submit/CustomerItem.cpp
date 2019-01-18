#include "CustomerItem.h"
#include "Item.h"
#include <iomanip>

CustomerItem::CustomerItem(const std::string & nameOfCustomerItem) {
	name = nameOfCustomerItem;
	filled = false;
	code = 0;
	
}

bool CustomerItem::asksFor(const Item & item) const {
	if (name == item.getName()) {
		return true;
	}
	else {
		return false;
	}
}

bool CustomerItem::isFilled() const {
	if (filled == true) {
		return true;
	}
	else {
		return false;
	}
}

void CustomerItem::fill(const unsigned int c) {
	code = c;
	filled = true;
}

void CustomerItem::clear() {
	code = 0;
	filled = false;
}

const std::string & CustomerItem::getName() const {
	return name;
}

void CustomerItem::display(std::ostream & os) const {
	char symbol;

	if (filled == true) {
		symbol = '+';
	}
	else {
		symbol = '-';
	}

	if (!name.empty()) {
		os << " " << symbol << " [" << std::right << std::setw(CODE_WIDTH)
			<< std::setfill('0') << code << std::setfill(' ') << "] "
			<< name << std::endl;
	}
}
