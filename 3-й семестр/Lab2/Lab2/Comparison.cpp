#include "Comparison.h"
#include "Time.h"

using namespace std;

bool Comparison::equals(int city1, int city2)
{
	return city1 == city2;
}

bool Comparison::greater(int city1, int city2)
{
	return city1 > city2;
}

bool Comparison::less(int city1, int city2)
{
	return city1 < city2;
}

string Time::CallingEquals(Time day1, Time day2)
{
    Comparison comparison;
    string res = "";
    if (comparison.equals(day1.hour, day2.hour) == true) {
        res += "hours equal ";
    }
    else res += "hours not equal ";

    if (comparison.equals(day1.min, day2.min) == true) {
        res += " minutes equal ";
    }
    else res += " minutes not equal ";

    if (comparison.equals(day1.sec, day2.sec) == true) {
        res += " seconds equal ";
    }
    else res += " seconds not equal ";

    if (comparison.equals(day1.msec, day2.msec) == true) {
        res += " milliseconds equal ";
    }
    else res += " milliseconds not equal ";
    return res;
}

string Time::CallingGreater(Time day1, Time day2)
{
    Comparison comparison;
    string res = "";
    if (comparison.greater(day1.hour, day2.hour) == true) {
        res += "hours greater ";
    }
    else res += "hours not greater ";

    if (comparison.greater(day1.min, day2.min) == true) {
        res += " minutes greater ";
    }
    else res += " minutes not greater ";

    if (comparison.greater(day1.sec, day2.sec) == true) {
        res += " seconds greater ";
    }
    else res += " seconds not greater ";

    if (comparison.greater(day1.msec, day2.msec) == true) {
        res += " milliseconds greater ";
    }
    else res += " milliseconds not greater ";
    return res;

}

string Time::CallingLess(Time day1, Time day2)
{
    Comparison comparison;
    string res = "";
    if (comparison.less(day1.hour, day2.hour) == true) {
        res += "hours less ";
    }
    else res += "hours not less ";

    if (comparison.less(day1.min, day2.min) == true) {
        res += " minutes less ";
    }
    else res += " minutes less ";

    if (comparison.less(day1.sec, day2.sec) == true) {
        res += " seconds less ";
    }
    else res += " seconds not less ";

    if (comparison.less(day1.msec, day2.msec) == true) {
        res += " milliseconds less ";
    }
    else res += " milliseconds not less ";
    return res;

}

