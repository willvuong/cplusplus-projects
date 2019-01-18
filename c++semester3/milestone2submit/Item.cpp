#include "Item.h"
#include "Utilities.h"
#include <iostream>
#include <iomanip>

size_t Item::field_width = 1;

Item::Item(const std::string & itemInfo) {
	description = "no detailed description";
	code = 1;

	Utilities utilitiesObj;
	utilitiesObj.setFieldWidth(field_width);
	
	size_t position = 0;
	bool t = true;
	std::string token;
	token = utilitiesObj.nextToken(itemInfo, position, t);

	for (int i = 0; t; i++) {
		if (!token.empty()) {
			if (i == 0 && t) {
				name = token;
			}
			else if (i == 1) {
				filler = utilitiesObj.nextToken(itemInfo, position, t);
			}
			else if (i == 2) {
				remover = utilitiesObj.nextToken(itemInfo, position, t);
			}
			else if (i == 3) {
				code = (unsigned int)atoi(utilitiesObj.nextToken(itemInfo, position, t).data());
			}
			else if (i == 4) {
				description = utilitiesObj.nextToken(itemInfo, position, t);
				if (description.empty()) {
					description = "no detailed description";
				}
			}
			else {
				break;
			}
		}
		else {
			throw std::string("*** error ***");
		}

		if (field_width < utilitiesObj.getFieldWidth()) {
			field_width = utilitiesObj.getFieldWidth();
		}
	}
}

bool Item::empty() const {
	if (name.empty() && 
		filler.empty() && 
		remover.empty() && 
		description == "no detailed description"
		&& code == 1) {
		return true;
	}
	else {
		return false;
	}
}

Item & Item::operator++(int) {
	++code;
	return *this;
}

unsigned int Item::getCode() const {
	return code;
}

const std::string & Item::getName() const {
	return name;
}

const std::string & Item::getFiller() const {
	return filler;
}

const std::string & Item::getRemover() const {
	return remover;
}

void Item::display(std::ostream & os, bool full) const {
	os << std::left << std::setw(field_width) << name
		<< " [" << std::right << std::setfill('0') << std::setw(CODE_WIDTH)  << code << "]"
		<< std::left << std::setfill(' ');

	if (full) {
		os << " From " << std::setw(field_width) << filler;
		os << " To " << std::setw(field_width) << remover << std::endl;
		os << std::right << std::setw(field_width + CODE_WIDTH + 4) << ": " << description;
	}

	os << std::left << std::endl;
}
