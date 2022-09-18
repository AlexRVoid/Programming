#define _USE_MATH_DEFINES
#include <iostream>
#include <random>
#include <map>
#include <vector>
#include <cmath>

using namespace std;

double XiKvadratCalk(map<double, double> mas) 
{
    double xn = 0, n = 0, xSred = 0;

    for (auto x : mas) 
    {
        xn = xn + (x.first * x.second);
        n++;
    }
    xSred = xn / n;

    double xPromeg = 0, S = 0;
    for (auto x : mas) 
    {
        xPromeg = xPromeg + pow((xSred - x.first), 2) * x.second;
    }
    S = sqrt(xPromeg / (n - 1));

    double  U = 0, funkU = 0, n0 = 0, XiKvadrat = 0;
    for (auto x : mas) 
    {
        U = (x.first - xSred) / S;
        funkU = pow(M_E, (pow(U, 2) / -2)) / sqrt(2 * M_PI);
        n0 = (n * funkU) / S;
        XiKvadrat = XiKvadrat + pow((x.second - n0), 2) / n0;
    }
    return XiKvadrat;
}

int main()
{
    setlocale(LC_ALL, "Rus");
    ranlux48_base gen(time(0));
    int n1 = 50, n2 = 100, n3 = 1000;

    map<double, double> mas50;
    for (int i = 0; i < n1; i++)
    {
        mas50[(1 + gen() % 100)]++;
    }
    double XiKvadrat = XiKvadratCalk(mas50);
    cout << "XiKvadrat первого массива: " << XiKvadrat << endl << "Критический XiKvadrat для заданных условий: " << 67.5 << endl;
    if (XiKvadrat > 67.5)
    {
        cout << "Гипотеза ложна" << endl << endl;
    }
    else
    {
        cout << "Гипотеза верна" << endl << endl;
    }


    map<double, double> mas100;
    for (int i = 0; i < n2; i++)
    {
        mas100[(1 + gen() % 100)]++;
    }
    XiKvadrat = XiKvadratCalk(mas100);
    cout << "XiKvadrat второго массива: " << XiKvadrat << endl << "Критический XiKvadrat для заданных условий: " << 124.3 << endl;
    if (XiKvadrat > 124.3)
    {
        cout << "Гипотеза ложна" << endl << endl;
    }
    else
    {
        cout << "Гипотеза верна" << endl << endl;
    }


    map<double, double> mas1000;
    for (int i = 0; i < n3; i++)
    {
        mas1000[(1 + gen() % 100)]++;
    }
    XiKvadrat = XiKvadratCalk(mas1000);
    cout << "XiKvadrat второго массива: " << XiKvadrat << endl << "Критический XiKvadrat для заданных условий: " << 1074.7 << endl;
    if (XiKvadrat > 1074.7)
    {
        cout << "Гипотеза ложна" << endl << endl;
    }
    else
    {
        cout << "Гипотеза верна" << endl << endl;
    }
}