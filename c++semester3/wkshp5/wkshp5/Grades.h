#ifndef _GRADES_GRADES_H_
#define _GRADES_GRADES_H_

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

class Grades {
private:
	std::string* studentNumber;
	double* grade;
	int count;
public:
	Grades() { studentNumber = nullptr; grade = 0; count = 0; };
	~Grades() {};

	Grades(const char* file) {
		std::ifstream is;
		std::string line;
		int tempCount = 0;

		try {
			is.open(file);
			if (is.fail()) {
				throw "fail";
			}
			else {
				if (is.is_open() && !is.eof()) {
					while (getline(is, line, '\n')) {
						tempCount++;
					}
					count = tempCount;
				}

				is.clear();
				is.seekg(0);

				studentNumber = new std::string[count];
				grade = new double[count];

				for (int i = 0; i < count; i++) {
					is >> studentNumber[i];
					is >> grade[i];
				}
				is.close();
			}
		}
		catch (char fail) {
			std::cout << fail;
		}
	}
	
	template <typename Func>
	void displayGrades(std::ostream& os, Func func) const {
		for (int i = 0; i < count; i++) {
			os << studentNumber[i] << " "; 
			std::cout << std::fixed;
			std::cout << std::setprecision(2);
			os << grade[i] << " "; 
			os << func(grade[i]) << std::endl;
		}
	}
};

#endif // _GRADES_GRADES_H_