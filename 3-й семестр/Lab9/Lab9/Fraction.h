#pragma once
#include <iostream>
#include <sstream>
#include <vector>
#include "IError.h"

using namespace std;

extern "C++" __declspec(dllexport) class Fraction {
private:
	int numerator, denominator;
	vector <string> logger;
public:
	__declspec(dllexport) Fraction();
	__declspec(dllexport) Fraction(int a, int b);

	__declspec(dllexport) friend ostream& operator<<(ostream& os, const Fraction& fraction) {
		os << fraction.numerator << " / " << fraction.denominator;
		return os;
	}

	__declspec(dllexport) friend istream& operator>>(istream& is, Fraction& fraction) {
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
	__declspec(dllexport) Fraction operator=(const Fraction& sravn) {


		return *this;
	}

	__declspec(dllexport) Fraction operator+(const Fraction& fraction2);
	__declspec(dllexport) Fraction operator-(const Fraction& fraction2);
	__declspec(dllexport) Fraction operator/(Fraction& fraction2);
	__declspec(dllexport) Fraction operator*(const Fraction& fraction2);
	__declspec(dllexport) Fraction pow(const Fraction& fraction2, int a);
	__declspec(dllexport) bool operator<(const Fraction& fraction2);
	__declspec(dllexport) bool operator<=(const Fraction& fraction2);
	__declspec(dllexport) bool operator>(const Fraction& fraction2);
	__declspec(dllexport) bool operator >=(const Fraction& fraction2);

};
__declspec(dllexport) int nod(int a, int b);
__declspec(dllexport) int PartI();
