#ifndef _W3_TEXT_H_
#define _W3_TEXT_H_

#include <iostream>
#include <string>
#include <fstream>

namespace w3 {

	class Text {
	private:
		std::string* nameOfFile = nullptr;
		size_t numOfRecords = 0;
	public:
		Text();
		Text(char* tempNameOfFile);
		Text(Text& obj);
		Text& operator=(Text& obj);
		Text(Text&& obj);
		Text& operator=(Text&& obj);
		~Text();
		size_t size() const;
	};
}
#endif#pragma once
