#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
#include <random>  
#include <ctime>
using namespace std;

template <typename T>

ostream& operator<< (ostream& os, const vector<T>& v) {
    for (auto i : v) {
        os << i << " ";
    }
    return os;
}

void part1();