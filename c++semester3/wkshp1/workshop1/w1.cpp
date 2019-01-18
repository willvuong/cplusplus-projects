// Workshop 1
// Name: William Vuong
// ID: 105165179
// Email: wvuong3@myseneca.ca

#include "CString.h"
#include "process.h"

using namespace std;

int main(int argc, char* argv[]) {
	if (argc == 0) {
		cout << "No arguments entered" << endl;
		return 1;
	}

	cout << "Command Line : ";
	
	for (int i = 1; i < argc; i++) {
		cout << " " << argv[i];	
	}

	cout << endl;

	if (argc <= 2) {
		cout << "Insufficient number of arguments (min 1)" << endl;
		return 1;
	}
	else {
		cout << "Maximum number of characters stored : " << argc - 1 << endl;
	}

	for (int i = 1; i < argc; i++) {
		process(argv[i]);
	}

	return 0;
}