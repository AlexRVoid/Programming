#pragma once
#include <iostream>

using namespace std;

extern "C++" __declspec(dllexport) class IError
{
public:
	string description = "Error: ";
	__declspec(dllexport) virtual void print() {
		std::cout << description << std::endl;
	}
};

extern "C++" __declspec(dllexport) class IncorrectInput : IError {
public:
	__declspec(dllexport) IncorrectInput() {};
	__declspec(dllexport) void print() {
		cout << description << " Incorrect input " << std::endl;
	}
};


extern "C++" __declspec(dllexport) class DivisionByZero : IError {
public:
	__declspec(dllexport) DivisionByZero() {};
	__declspec(dllexport) void print() {
		cout << description << " Integer division by zero " << std::endl;
	}
};

