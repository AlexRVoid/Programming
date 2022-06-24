#pragma once
#include <iostream>
#include <map>
#include <algorithm>

using namespace std;

template <typename T, typename T1>

ostream& operator<< (ostream& os, const map<T,T1>& v) {
    for (auto i : v) {
        os << i.first << " " << i.second << endl;
    }
    return os;
}


void part2();