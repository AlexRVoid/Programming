#include<iostream>
#include <random>

using namespace std;

int main()
{
	ranlux48_base gen(time(NULL));

	cout << gen() % 101;
}