#include "Utilities.h"
#include <iostream>
#include <sstream>

char Utilities::delimiter;
std::ofstream Utilities::logFile;

Utilities::Utilities() {
	field_width = 1;
}

void Utilities::setFieldWidth(size_t fw) {
	field_width = fw;
}

size_t Utilities::getFieldWidth() const {
	return this->field_width;
}

const std::string Utilities::nextToken(const std::string & str, size_t & next_pos, bool & more) {
	std::string token;

	try {
		int c = 0;
		
		for (size_t i = next_pos; i < str.size(); i++)
		{
			c = str.at(i);
			if (c != delimiter)
			{
				token += c;
			}
			else {
				next_pos = i + 1;
				more = next_pos < str.size() ? true : false;
				break;
			}


			if (i == str.size() - 1) {
				more = false;
				break;
			}
		}

		if (token.size() > field_width)
		{
			field_width = token.size();
		}
	}
	catch (const std::string& error) {
		std::cout << error << std::endl;
		more = false;
	}
	
	size_t token_pos;
	while ((token_pos = token.size() - 1) != std::string::npos) {
		if (isspace(token.at(token_pos))) token.erase(token_pos);
		else break;
	}
	while (token.size() > 0) {
		if (isspace(token.at(0))) token.erase(0, 1);
		else break;
	}

	return token;
}

void Utilities::setDelimiter(const char tempDelimiter) {
	delimiter = tempDelimiter;
}

void Utilities::setLogFile(const char * tempLogFile) {
	logFile.close();
	logFile.open(tempLogFile);
}

std::ofstream & Utilities::getLogFile() {
	return logFile;
}
