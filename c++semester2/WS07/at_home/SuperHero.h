// Workshop 7
// Name: William Vuong
// ID: 105165179
// Email: wvuong@seneca.ca

#ifndef _SICT_SUPERHERO_H_
#define _SICT_SUPERHERO_H_
#include "Hero.h"

namespace sict {

	class SuperHero : public Hero {
	private:
		int superHeroAttack;
		int superHeroDefend;
	public:
		SuperHero();
		SuperHero(const char* name, int health, int strength, int attack, int defend);
		bool isEmptySuperHero() const;
		int attackStrengthSuper() const;
		int defend() const;
	};
	const SuperHero& operator*(const SuperHero& first, const SuperHero& second);
}
#endif