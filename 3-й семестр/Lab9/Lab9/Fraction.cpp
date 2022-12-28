#include "pch.h"
#include "Fraction.h"


int nod(int a, int b)
{
	int t;
	if (a < b) { t = a; a = b; b = t; }
	while (b != 0) {
		t = b;
		b = a % b;
		a = t;
	}
	return a;
}

Fraction::Fraction() {
	numerator = 0;
	denominator = 1;

	logger.push_back("Create default Fraction\n");
	cout << "Create default Fraction\n";
}

Fraction::Fraction(int a, int b) {
	int getNod = nod(a, b);
	numerator = a / getNod;
	denominator = b / getNod;

	if (b == 0) {
		cout << "denominator could not be 0, now denominator = 1\n";
		denominator = 1;
	}

	if (numerator < 0 && denominator < 0) { numerator *= -1; denominator += -1; }


	logger.push_back("Create new Fraction\n");
	cout << "Create new Fraction\n";

}


Fraction Fraction::operator+(const Fraction& fraction2) {
	if (fraction2.denominator == this->denominator) {
		return Fraction((this->numerator + fraction2.numerator), (this->denominator));
	}
	else {
		int sum_den = fraction2.denominator * this->denominator;
		int sum_num = fraction2.numerator * this->denominator + this->numerator * fraction2.denominator;
		return Fraction((sum_num), (sum_den));
	}

	logger.push_back("Do summary\n");
	cout << "Do summary\n";

}

Fraction Fraction::operator-(const Fraction& fraction2) {
	if (fraction2.denominator == this->denominator) {
		return Fraction((this->numerator - fraction2.numerator), (this->denominator));
	}
	else {
		int sum_den = fraction2.denominator * this->denominator;
		int sum_num = this->numerator * fraction2.denominator - fraction2.numerator * this->denominator;
		return Fraction((sum_num), (sum_den));
	}
}

Fraction Fraction::operator/(Fraction& fraction2) {
	try {
		swap(fraction2.numerator, fraction2.denominator);
		logger.push_back("DIVISION OBJECT\n");
		cout << ("DIVISION OBJECT\n");
		return Fraction(fraction2.numerator * this->numerator, fraction2.denominator * this->denominator);
	}
	catch (IncorrectInput& e) {
		e.print();
	}
}

Fraction Fraction::operator*(const Fraction& fraction2) {
	logger.push_back("MULTIPLE OBJECT\n");
	cout << ("MULTIPLE OBJECT\n");
	return Fraction(fraction2.numerator * this->numerator, fraction2.denominator * this->denominator);
}

Fraction Fraction::pow(const Fraction& fraction2, int a) {
	int num_degree = fraction2.numerator, den_degree = fraction2.denominator;
	bool invert = false;
	if (a < 0) {
		a *= -1;
		invert = true;
	}
	while (a != 1) {
		num_degree *= fraction2.numerator;
		den_degree *= fraction2.denominator;
		a--;
	}
	if (invert)swap(num_degree, den_degree);
	logger.push_back("DEGREE OPERATOR\n");
	cout << ("DEGREE OPERATOR\n");
	return Fraction(num_degree, den_degree);
}

bool Fraction::operator<(const Fraction& fraction2) {
	logger.push_back("LESS OPERATOR\n");
	cout << ("LESS OPERATOR\n");
	if (fraction2.denominator == this->denominator) {
		return this->numerator < fraction2.numerator;
	}
	else return this->numerator * fraction2.denominator < fraction2.numerator* this->denominator;
}
bool Fraction::operator<=(const Fraction& fraction2) {
	logger.push_back("EQUALS OR LESS OPERATOR\n");
	cout << ("EQUALS OR LESS OPERATOR\n");
	if (fraction2.denominator == this->denominator) {
		return this->numerator <= fraction2.numerator;
	}
	else return this->numerator * fraction2.denominator <= fraction2.numerator * this->denominator;
}
bool Fraction::operator>(const Fraction& fraction2) {
	logger.push_back("LESS OPERATOR\n");
	cout << ("LESS OPERATOR\n");
	if (fraction2.denominator == this->denominator) {
		return this->numerator > fraction2.numerator;
	}
	else return this->numerator * fraction2.denominator > fraction2.denominator * this->denominator;

}
bool Fraction::operator>=(const Fraction& fraction2) {
	logger.push_back("EQUALS OR MORE OPERATOR\n");
	cout << ("EQUALS OR MORE OPERATOR\n");
	if (fraction2.denominator == this->denominator) {
		return this->numerator >= fraction2.numerator;
	}
	else return this->numerator * fraction2.denominator >= fraction2.numerator * this->denominator;
}
