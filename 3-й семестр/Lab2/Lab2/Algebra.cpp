#include "Algebra.h"
#include "Time.h"

using namespace std;

int Arithmetic::add(const int time1, const int time2)
{
    int time = time1 + time2;
    if (unitTrans > 0) {
        time += unitTrans;
        unitTrans = 0;
    }
    if (time / 60 == 0) return time;
    else {
        unitTrans = time / 60;
        return time % 60;
    }
}

int Arithmetic::addHour(const int time1, const int time2)
{
    int time = time1 + time2;
    if (unitTrans > 0) {
        time += unitTrans;
        unitTrans = 0;
    }
    if (time / 24 == 0) return time;
    else {
        unitTrans = time / 24;
        return time % 24;
    }
}

int Arithmetic::sub(const int time1, const int time2)
{
    int time = time1 - time2;
    if (unitTrans > 0) {
        time += 60;
        time -= unitTrans;
        unitTrans = 0;
    }
    if (time / 60 == 0) return time;
    else {
        unitTrans = time / 60;
        return time % 60;
    }
}

int Arithmetic::subHour(const int time1, const int time2)
{
    int time = time1 - time2;
    if (time / 24 == 0) return time;
    else {
        unitTrans = time / 24;
        return time % 24;
    }
}

Time Time::CallingAdd(Time city1, Time city2)
{
    Time siteN;
    Arithmetic arifm;
    siteN.msec = arifm.add(city1.msec, city2.msec);
    siteN.sec = arifm.add(city1.sec, city2.sec);
    siteN.min = arifm.add(city1.min, city2.min);
    siteN.hour = arifm.addHour(city1.hour, city2.hour);
    return siteN;
}

Time Time::CallingSub(Time city1, Time city2)
{
    Time siteN;
    Arithmetic arifm;
    siteN.msec = arifm.sub(city1.msec, city2.msec);
    siteN.sec = arifm.sub(city1.sec, city2.sec);
    siteN.min = arifm.sub(city1.min, city2.min);
    siteN.hour = arifm.subHour(city1.hour, city2.hour);
    return siteN;
}

