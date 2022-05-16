#include <iostream>
#include <cstdint>
using namespace std;
int main()
{
	int8_t num;
	cout << "Enter the number: ";
	cin >> num >> endl;
	bool trueorfalse;
	cout << "Enter a boolean variable 1 or 0: ";
	cin >> trueorfalse >> endl;
	cout << "int=" << num << boolalpha << " bool=" << trueorfalse;
	return 0;
}
