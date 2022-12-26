#pragma once
#include <iostream>
#include <sstream>
#include <vector>
#include "IError.h"
using namespace std;

class Fraction {
private:
	int numerator, denominator;
	vector <string> logger;
public:
	Fraction();
	Fraction(int a, int b);

	friend ostream& operator<<(ostream& os, const Fraction& fraction) {
		os << fraction.numerator << " / " << fraction.denominator;
		return os;
	}

	friend istream& operator>>(istream& is, Fraction& fraction) {
		try {
			cout << "Enter Numerator ";
			is >> fraction.numerator;
			cout << "Enter Denominator ";
			is >> fraction.denominator;
			if (is.fail())
			{
				throw IncorrectInput();
			}
			if (fraction.denominator == 0)
			{
				throw DivisionByZero();
			}
		}
		catch (DivisionByZero& e)
		{
			e.print();
			exit(0);
		}
		return is;
	}
	Fraction operator=(const Fraction& sravn) {


		return *this;
	}

	Fraction operator+(const Fraction& fraction2);
	Fraction operator-(const Fraction& fraction2);
	Fraction operator/( Fraction& fraction2);
	Fraction operator*(const Fraction& fraction2);
	Fraction pow(const Fraction& fraction2, int a);
	bool operator<(const Fraction& fraction2);
	bool operator<=(const Fraction& fraction2);
	bool operator>(const Fraction& fraction2);
	bool operator >=(const Fraction& fraction2);

};
int nod(int a, int b);
int PartI();
int PartII();
