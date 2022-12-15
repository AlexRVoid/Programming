#pragma once
#include <iostream>
#include <string>
#include "Comparison.h"
#include "Time.h"
using namespace std;



class Arithmetic
{
public:
	int add(const int time1, const int time2);
	int addHour(const int time1, const int time2);
	int sub(const int time1, const int time2);
	int subHour(const int time1, const int time2);

private:
	int unitTrans;
};

