#include <iostream>
#include <math.h>
#include <stdio.h>
#include <locale>
#include <cstdint>
using namespace std;

void Task1 ()
{
    cout << " " << "X" << " " << "Y" << endl;
    for (int x = -8, y = -3; x <= -5; x++)
    {
        cout << x << " " << y << endl;
    }
    for (double x = -5, y = -3.0; x <= -3; x++)
    {
        y = 1.5 * x + 4.5;
        cout << x << " " << y << endl;
    }
    for (double x = -3, y = 0; x <= 3 ; x++)
    {
        y += x;
        cout << x << " " << y << endl;
    }
    for (double x = 3, y = 0; x <= 8; x++)
    {
        y = 0.27 * x + 0.82;
        cout << x << " " << y << endl;
    }
    for (int x = 8, y = 3; x <= 10; x++)
    {
        cout << x << " " << y << endl;
    }
}

int Task2 (int64_t base, int64_t exponent, int64_t mod)
{
    int64_t pow;
    base %= mod;
    if (exponent == 0) {
        pow = 1;
    }
    else if (exponent % 2 == 0) {
        pow = Task2(base * base, exponent / 2, mod) % mod;
    }
    else {
        pow = (base * Task2(base, exponent - 1, mod)) % mod;
    }
    return pow;
}

void Task3 (int64_t a, int64_t b)
{
    int64_t c;
    cout << "НОД (" << a << "," << b << ") = ";
    while (b != 0)
    {
        a %= b;
        c = a;
        a = b;
        b = c;
    }
    cout << a << endl;
}

void Task4 ()
{
    int a = 228, b = 7, y0 = 0, y1 = 1, x0 = 1, x1 = 0, q = 0, y2 = 0, x2 = 0, c;
    while (b != 0) { // Бегаем по итерациям до момента, пока остаток не станет равным 0
        q = a / b;
        a %= b;
        x2 = x0 - q * x1;
        y2 = y0 - q * y1;
        cout << "Остаток = " << a << " X = " << x2 << " Y = " << y2 << " Частные = " << q << endl; // для каждой итерации свои X и Y
        x0 = x1;
        y0 = y1;
        x1 = x2;
        y1 = y2;
        c = a;
        a = b;
        b = c;
    }
}

void Task5 ()
{

}

void Task7 ()
{

}

int main ()
{
    setlocale(LC_ALL, "Russian");
    cout << "Task 1:" << endl;
    Task1 ();
    cout << "Task 2:" << endl;
    int64_t base, exponent, mod, pow;
    cout << "Enter a: ";
    cin >> base;
    cout << "Enter x: ";
    cin >> exponent;
    cout << "Enter p:";
    cin >> mod;
    cout << Task2 (base, exponent, mod) << endl;
    cout << "Task 3:" << endl;
    int64_t a, b;
    cout << "Enter a: ";
    cin >> a;
    cout << "Enter b: ";
    cin >> b;
    Task3 (a, b);
    cout << "Task 4:" << endl;
    Task4();
}