#include "text.h"

using namespace std;

namespace w3 {

	Text::Text() {
		nameOfFile = nullptr;
		numOfRecords = 0;
	}

	Text::Text(char * tempNameOfFile) {
		fstream file;
		string str;

		file.open(tempNameOfFile, ios::in);
		if (file.is_open()) {
			while (getline(file, str, ' ')) {
				numOfRecords++;
			}
			this->nameOfFile = new string[this->numOfRecords];
		}
	}

	Text::Text(Text & obj) {
		*this = obj;
	}

	Text & Text::operator=(Text & obj) {
		if (this != &obj) {
			if (this->nameOfFile != nullptr) {
				delete[] this->nameOfFile;
				this->numOfRecords = 0;
				this->nameOfFile = nullptr;
			}

			this->nameOfFile = new string[obj.numOfRecords];
			this->numOfRecords = obj.numOfRecords;

			for (size_t i = 0; i < obj.numOfRecords; i++) {
				this->nameOfFile[i] = obj.nameOfFile[i];
			}
		}
		return *this;
	}

	Text::Text(Text && obj) {
		this->nameOfFile = obj.nameOfFile;
		this->numOfRecords = obj.numOfRecords;
		obj.nameOfFile = nullptr;
		obj.numOfRecords = 0;
	}

	Text & Text::operator=(Text && obj) {
		return *this;
	}

	Text::~Text() {
		this->nameOfFile = nullptr;
		delete[] this->nameOfFile;
		this->numOfRecords = 0;
	}

	size_t Text::size() const {
		return numOfRecords;
	}

}