#include "pch.h"
#include "Fraction.h"


int PartI()
{
    Fraction number(7, 23);
    Fraction number1;

    cin >> number1;

    cout << (number > number1) << endl;
    cout << (number >= number1) << endl;
    cout << (number < number1) << endl;
    cout << (number <= number1) << endl;
    cout << (number + number1) << endl;
    cout << (number - number1) << endl;
    cout << (number * number1) << endl;
    cout << (number / number1) << endl;
    system("pause");
    return 0;
}