// Name: William Vuong
// ID: 105165179
// Email: wvuong@seneca.ca

#include <iostream>
#include <cstring>
#include "Fraction.h"

using namespace std;

namespace sict {

	Fraction::Fraction() {
		numerator = 0;
		denominator = 0;
	}

	Fraction::~Fraction() {
		//ilikecheese
	}

	Fraction::Fraction(const int tempNumerator, const int tempDenominator) {
		if (!isEmpty() && tempNumerator > 0 && tempDenominator > 0) {
			numerator = tempNumerator;
			denominator = tempDenominator;
			reduce();
		}
		else *this = Fraction();
	}

	int Fraction::max() const {
		if (numerator > denominator) {
			return numerator;
		}
		else return denominator;
	}

	int Fraction::min() const{
		if (numerator < denominator) {
			return numerator;
		}
		else return denominator;
	}

	int Fraction::gcd() const {
		int mn = min();  // min of numerator and denominator
		int mx = max();  // max of numerator and denominator
		int g_c_d = 1;
		bool found = false;

		for (int x = mn; !found && x > 0; --x) { // from mn decrement until divisor found
			if (mx % x == 0 && mn % x == 0) {
				found = true;
				g_c_d = x;
			}
		}
		return g_c_d;
	}

	void Fraction::reduce() {
		int tempGcd = gcd();
		numerator = numerator / tempGcd;
		denominator = denominator / tempGcd;
	}

	bool Fraction::isEmpty() const {
		if (numerator == 0 && denominator == 0) {
			return true;
		}
		else return false;
	}

	void Fraction::display() const {
		if (!isEmpty() && denominator != 1) {
			cout << numerator << "/" << denominator;
		}
		else if (!isEmpty() && denominator == 1) {
				cout << numerator;
		}
		else {
			if (isEmpty()) {
				cout << "no fraction stored";
			}
		}
	}

	Fraction Fraction::operator+(const Fraction& rhs) const {
		if (this->numerator >= 0 && this->denominator > 0 && rhs.numerator >= 0 && rhs.denominator > 0) {
			Fraction temp = Fraction();
			temp.numerator = this->numerator*rhs.denominator + this->denominator*rhs.numerator;
			temp.denominator = this->denominator*rhs.denominator;
			return temp;
		}
		else return Fraction();
	}
}