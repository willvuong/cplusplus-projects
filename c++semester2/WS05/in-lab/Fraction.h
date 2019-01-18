// Name: William Vuong
// ID: 105165179
// Email: wvuong@seneca.ca

#ifndef SICT_FRACTION_H
#define SICT_FRACTION_H

namespace sict {
	
	class Fraction {
	private:
		int numerator;
		int denominator;
		int max() const;
		int min() const;
		int gcd() const; //returns the greatest common divisor of num and denom
		void reduce();
	public:
		Fraction();
		Fraction(const int tempNumerator, const int tempDenominator);
		~Fraction();
		bool isEmpty() const;
		void display() const;
		Fraction operator+(const Fraction& rhs) const;
	};
}

#endif