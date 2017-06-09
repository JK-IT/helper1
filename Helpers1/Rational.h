#pragma once
#ifndef RATIONAL_H
#define RATIONAL_H
#include <iostream>
#include <cmath>
#include <string>



class Rational {
	int numerator;
	int denominator;

	//compute the greatest common divisor of 2 num
	static int gcd(int m, int n) {
		if (n == 0) {
			return m;
		}
		else {
			return gcd(n, m%n);
		}
	}

	//compute the least common multiple of 2 integer
	static int lcm(int m, int n) {
		return m*n / gcd(m, n);
	}

public:
	Rational() : numerator(0), denominator(1) {};
	virtual ~Rational() {};

	Rational(int n, int d) :numerator(n), denominator(d) {
		if (d == 0) {
			std::cout << "bad denominator\n";
			numerator = 0;
			denominator = 1;
		}
	}

	int getNumerator() const {
		return numerator;
	}

	int getDenominator() const {
		return denominator;
	}

	Rational Reduce()const{
		//get tthe simple form of the original rational
		int factor = gcd(numerator, denominator);
		//when using this obj as return u re actually doing initailze list
		//in this case it is similar to Rational(n/ fac, d/ fac);
		return { numerator / factor, denominator / factor }; 
	}

	//overload compare operator of rational type
	bool operator==(const Rational& fract)const{
		//first find the reduce form of this and the param
		Rational f1 = this->Reduce();
		Rational f2 = fract.Reduce();
		return (f1.numerator == f2.numerator) && (f1.denominator == f2.denominator);
	}

	//unequal check of fraction
	bool operator!=(const Rational& other) {
		return (*this == other);
	}

	//compute the sum of fract and current rational num
	Rational operator+(const Rational & fract) {
		//find the common multiply
		int commonDenom = lcm(denominator, fract.denominator);
		//calculate the new numerator
		int newNum = numerator * commonDenom / denominator + fract.numerator * commonDenom / fract.denominator;
		return { newNum, commonDenom };
	}

	//compute product of 2 fracts
	Rational operator*(const Rational& fract) const {
		return Rational(this->numerator * fract.numerator, this->denominator * fract.denominator).Reduce();
	}

	//now overload the output obj so it can be printed out
	friend std::ostream& operator<<(std::ostream& os, const Rational& r) {
		os << r.getNumerator() << "/" << r.getDenominator();
		return os;
	}

};



#endif // !RATIONAL_H
