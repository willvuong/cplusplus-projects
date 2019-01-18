/***********************************************************
// OOP244 Workshop 2: Dynamic Memory
// File Kingdom.cpp
// Version 1.0
// Date ???????????
// Author ?????????
// Description
// ?????????????????????
//
//
// Revision History
///////////////////////////////////////////////////////////
// Name     Date
// William  Sept 22 2017
///////////////////////////////////////////////////////////
***********************************************************/
#include <iostream>
using namespace std;

namespace sict {
	
	struct Kingdom {
		public:
			char m_name[33];
			int m_population;
	};

	void display(const Kingdom&obj) {
		cout << obj.m_name <<", population "<< obj.m_population << endl;
	}

	void display(const Kingdom *obj, int count) {
		int totalPopulation = 0;

		cout << "------------------------------" << endl;
		cout << "Kingdoms of SICT" << endl;
		cout << "------------------------------" << endl;
		for (int i = 0; i < count; i++) {
			cout << i + 1 << ". ";
			display(obj[i]);
			totalPopulation += obj[i].m_population;
		}
		cout << "------------------------------" << endl;
		cout << "Total population of SICT: " << totalPopulation << endl;
		cout << "------------------------------" << endl;
	}
}

// TODO: include the necessary headers

// TODO: the sict namespace

    // TODO:definition for display(...) 
