/***********************************************************
// OOP244 Workshop 2: Dynamic Memory
// File Kingdom.h
// Version 1.0
// Date ???????????
// Author ?????????
// Description
// ?????????????????????
//
//
// Revision History
///////////////////////////////////////////////////////////
// Name     Date    Reason
// 
///////////////////////////////////////////////////////////
***********************************************************/

// TODO: header safeguards
#ifndef _244_KINGDOM_H_
#define _244_KINGDOM_H_

namespace sict {
	struct Kingdom {
	public:
		char m_name[33];
		int m_population;
	};
	void display(const Kingdom&obj);
	void display(const Kingdom *obj, int count);
}
// TODO: sict namespace
// TODO: define the structure Kingdom in the sict namespace
// TODO: declare the function display(...),
//         also in the sict namespace

#endif