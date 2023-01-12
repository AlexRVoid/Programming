#pragma once
#include <iostream>

using namespace std;

class IError
{
public:
	string description = "Error: ";
	virtual void print() {
		cout << description << endl;
	}
};

class IncorrectInput : IError {
public:
	IncorrectInput() {};
	void print() {
		cout << description << " Incorrect input " << endl;
	}
};



class DivisionByZero : IError {
public:
	DivisionByZero() {};
	void print() {
		cout << description << " Integer division by zero " << endl;
	}
};

