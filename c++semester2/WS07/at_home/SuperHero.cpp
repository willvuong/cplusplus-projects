// Workshop 7
// Name: William Vuong
// ID: 105165179
// Email: wvuong@seneca.ca

#include "SuperHero.h"
using namespace std;
namespace sict {

	SuperHero::SuperHero() : Hero() {
		Hero();
		superHeroAttack = 0;
		superHeroDefend = 0;
	}

	SuperHero::SuperHero(const char* name, int health, int strength, int attack, int defend) : Hero(name, health, strength){
		superHeroAttack = attack;
		superHeroDefend = defend;
	}

	bool SuperHero::isEmptySuperHero() const {
		if (Hero::isEmpty() && superHeroAttack == 0 && superHeroDefend == 0) {
			return true;
		}
		else {
			return false;
		}
	}

	int SuperHero::attackStrengthSuper() const {
		if (isEmptySuperHero()) {
			return 0;
		}
		else {
			return Hero::attackStrength() + superHeroAttack;
		}
	}

	int SuperHero::defend() const {
		if (isEmptySuperHero()) {
			return 0;
		}
		else {
			return superHeroDefend;
		}
	}


	const SuperHero & operator*(const SuperHero & first, const SuperHero & second) {
		SuperHero superHeroOne = first;
		SuperHero superHeroTwo = second;
		const SuperHero *winner;
		int rounds = 0;

		while (superHeroOne.Hero::isAlive() && superHeroTwo.Hero::isAlive() && rounds <= max_rounds) {
			superHeroOne -= superHeroTwo.attackStrengthSuper() - superHeroOne.defend();
			superHeroTwo -= superHeroOne.attackStrengthSuper() - superHeroTwo.defend();
			rounds++;
		}

		if (superHeroOne.isAlive() && superHeroTwo.isAlive()) {
			winner = &first;
		}
		else if (superHeroOne.isAlive()) {
			winner = &first;
		}
		else {
			winner = &second;
		}

		cout << "Super Fight! " << first << " vs " << second << " : Winner is " << *winner << " in " << rounds << " rounds." << endl;
		return *winner;
	}

}