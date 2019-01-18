// Workshop 7
// Name: William Vuong
// ID: 105165179
// Email: wvuong@seneca.ca

#include "Hero.h"
using namespace std;

namespace sict {
	
	Hero::Hero() {
		strcpy(heroName, "");
		heroHealth = 0;
		heroAttackStength = 0;
	}

	Hero::Hero(const char * name, int health, int strength) {
		if (strcmp(name, "") != 0 && health > 0 && strength > 0) {
			strcpy(heroName, name);
			heroHealth = health;
			heroAttackStength = strength;
		}
		else *this = Hero();
	}

	void Hero::operator-=(int attack) {
		if (attack >= 0) {
			heroHealth = heroHealth - attack;
			if (heroHealth < 0) {
				heroHealth = 0;
			}
		}
	}

	bool Hero::isAlive() const {
		if (heroHealth > 0) {
			return true;
		}
		else {
			return false;
		}
	}

	bool Hero::isEmpty() const {
		if (strcmp(heroName, "") == 0 && heroHealth == 0 && heroAttackStength == 0) {
			return true;
		}
		else {
			return false;
		}
	}

	int Hero::attackStrength() const {
		if (isEmpty()) {
			return 0;
		}
		else {
			return heroAttackStength;
		}
	}

	std::ostream & Hero::read(std::ostream & os) const {
		if (isEmpty()) {
			cout << "No hero" << endl;
		}
		else {
			os << heroName;
		}
		return os;
	}

	ostream & operator<<(ostream & os, const Hero & hero) {
		return hero.read(os);
	}

	const Hero & operator*(const Hero & first, const Hero & second) {
		Hero heroOne = first;
		Hero heroTwo = second;
		const Hero *winner;
		int rounds = 0;
		
		while (heroOne.isAlive() && heroTwo.isAlive() && rounds <= max_rounds) {
			heroOne -= heroTwo.attackStrength();
			heroTwo -= heroOne.attackStrength();
			rounds++;
		}

		if (heroOne.isAlive() && heroTwo.isAlive()) {
			winner = &first;
		}
		else if (heroOne.isAlive()) {
			winner = &first;
		}
		else {
			winner = &second;
		}

		cout << "Ancient Battle! " << first << " vs " << second << " : Winner is " << *winner << " in " << rounds << " rounds." << endl;
		return *winner;
	}

}