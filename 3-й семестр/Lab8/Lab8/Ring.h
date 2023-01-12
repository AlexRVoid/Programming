#pragma once
#include <iostream>
#include <thread>
#include <vector>
#include <random>
#include <mutex>
#include <ctime>
using namespace std;


class SellRing
{
public:
    void sell();
    void ring();
private:
    int earnings = 0;
    mutex mx;
};
