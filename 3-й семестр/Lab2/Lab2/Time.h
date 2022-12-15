#pragma once
#include <iostream>
#include <string>
#include "Algebra.h"
#include "Comparison.h"

using namespace std;

struct TimeData
{
public:
	int hour, min, sec, msec;
	TimeData(const int& h, const int& m, const int& s, const int& ms)
	{
		hour = h;
		min = m;
		sec = s;
		msec = ms;
	}
};

class Time
{
public:
	Time()
	{
		hour = 0;
		min = 0;
		sec = 0;
		msec = 0;
	}
	Time(const int& h, const int& m, const int& s, const int& ms)
	{
		hour = h;
		min = m;
		sec = s;
		msec = ms;
	}
	Time(const struct TimeData& data)
	{
		hour = data.hour;
		min = data.min;
		sec = data.sec;
		msec = data.msec;
	}

	friend ostream& operator <<(ostream& os, const Time& city) {

		os << "In city N now " << city.hour << " hours " << city.min << " minutes  " << city.sec << " seconds " << city.msec << " milliseconds\n";
		return os;
	}

	friend istream& operator>> (istream& is, Time& dt)
	{
		is >> dt.hour >> dt.min >> dt.sec >> dt.msec;
		return is;
	}



	int hour, min, sec, msec;

	Time CallingAdd(Time city1, Time city2);
	Time CallingSub(Time city1, Time city2);
	string CallingEquals(Time day1, Time day2);
	string CallingGreater(Time day1, Time day2);
	string CallingLess(Time day1, Time day2);
};