// Workshop 7
// Name: William Vuong
// ID: 105165179
// Email: wvuong@seneca.ca

#ifndef _SICT_HERO_H_
#define _SICT_HERO_H_
#include <iostream>
#include <cstring>

namespace sict {

	const int max_rounds = 100;

	class Hero {
	private:
		char heroName[40];
		int heroHealth;
		int heroAttackStength;
	public:
		Hero();
		Hero(const char* name, int health, int strength);
		void operator-=(int attack);
		bool isAlive() const;
		bool isEmpty() const;
		int attackStrength() const;
		std::ostream& read(std::ostream& os) const;
		friend std::ostream& operator<<(std::ostream& os, const Hero& hero);
	};

	const Hero& operator*(const Hero& first, const Hero& second);

}
#endif 