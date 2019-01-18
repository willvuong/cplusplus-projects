// Workshop 6 - Lambda Expression
// w6.cpp

#include <iostream>
#include "Grades.h"

int main(int argc, char* argv[]) {
	if (argc != 2) {
		std::cerr << argv[0] <<
			": incorrect number of arguments\n";
		std::cerr << "Usage: " << argv[0] << " file_name\n";
		return 1;
	}

	Grades grades(argv[1]);
	auto letter = [](double grade) {
		if (grade >= 90) {
			return "A+";
		}
		else if (grade >= 80){
			return "A";
		}
		else if (grade >= 75) {
			return "B+";
		} 
		else if (grade >= 70) {
			return "B";
		}
		else if (grade >= 65) {
			return "C+";
		}
		else if (grade >= 60) {
			return "C";
		}
		else if (grade >= 55) {
			return "D+";
		}
		else if (grade >= 50) {
			return "D";
		}
		else {
			return "F";
		}
	};

	grades.displayGrades(std::cout, letter);
	std::cout << "Press any key to continue ... ";
	std::cin.get();
}