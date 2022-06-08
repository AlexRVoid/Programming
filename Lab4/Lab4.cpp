#define _USE_MATH_DEFINES
#include <iostream>
#include <random>
#include <map>
#include <vector>
#include <cmath>
#include <math.h>
#include  <tgmath.h>

using namespace std;

void Task1(double a, double b, int q) {
    double c;
    double d;
    d = b - a;
    cout.precision(4);
    cout << q << " " << a << " " << b << " ";
    cout << round(d) / 10000 << endl;
    c = (a + b) / 2;
    if (abs(a - b) < 0.0001) cout << "метод половинного деления " << c << endl;
    else {
        q++;
        if ((2 * a + cos(a)) * ((2 * c) + cos(c)) < 0) Task1(a, c, q);
        if ((2 * c + cos(c)) * ((2 * b) + cos(b)) < 0) Task1(c, b, q);
    }


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

int Task3()
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

int ryd1Gen(int a, int range, int p)
{
    int genNum = 1;
    for (int i = 1; i <= range; i++)
    {
        genNum = (a * genNum) % p;
    }
    return genNum;
}

int ryd2Gen(int a, int y, int range, int p)
{
    int genNum = y;
    for (int i = 1; i <= range; i++)
    {
        genNum = (a * genNum) % p;
    }
    return genNum;
}

int Task4()
{
    //Шаг младенца шаг великана
    // 2^x mod 30203 = 24322      a^x mod p = y
    setlocale(LC_ALL, "Rus");

    int p = 30203, y = 24322, a = 2;

    map <int, int> ryd1;
    map <int, int> ryd2;

    int m = sqrt(p) + 1;
    for (int i = 1; i <= m; i++)
    {
        ryd1[i] = ryd1Gen(a, i * m, p);
    }
    for (int i = 1; i <= m; i++)
    {
        ryd2[i] = ryd2Gen(a, y, i, p);
    }

    int i0 = 0, j0 = 0;
    for (auto& i : ryd1)
    {
        for (auto& j : ryd2)
        {
            if (i.second == j.second)
            {
                i0 = i.first;
                j0 = j.first;
            }
        }
    }
    cout << "Уравнения вида (2^x mod 30203 = 24322) имеет решение при x = " << i0 * m - j0 << endl;
}

void DelitelCheck(int x, int p, int& BazMnog, int& StepenBazMnog) {
    int l = 0;
    for (int i = 1; pow(x, i) < p; i++)
    {                   //факторная база из первых 3 простых чисел
        if (pow(2, i) == x)
        {
            BazMnog = 2;
            StepenBazMnog = i;
        }
    }
    for (int i = 1; pow(x, i) < p; i++)
    {
        if (pow(3, i) == x) {
            BazMnog = 3;
            StepenBazMnog = i;
        }
    }
    for (int i = 1; pow(x, i) < p; i++)
    {
        if (pow(5, i) == x) {
            BazMnog = 5;
            StepenBazMnog = i;
        }
    }
}

int numGen1(int a, int x, int p)
{
    int genNum = 1;
    for (int i = 0; i < x; i++)
    {
        genNum = (a * genNum) % p;
    }
    return genNum;
}

int numGen2(int a, int x, int p, int y)
{
    int genNum = y;
    for (int i = 0; i < x; i++)
    {
        genNum = (a * genNum) % p;
    }
    return genNum;

}

int Task5()
{
    //Алгоритм исчисления порядка
    setlocale(LC_ALL, "Rus");
    int a = 2;
    int p = 30203;
    int y = 24322;


    int x = 0, i = 1, BazMnog = 0, StepenBazMnog = 0;
    while (BazMnog == 0)                      //по результатам цикл должен найти некотрый базовый множитель и степень такое что BazMnog^StepenBazMnog= y a^x mod p
    {
        x = numGen2(a, i++, p, y);                          //находится гладкое число вида ya^r
        DelitelCheck(x, p, BazMnog, StepenBazMnog);        //проверка на гладкость
    }
    int stepen = i;
    i = 0;

    int DelBazMnog = 0;
    while (DelBazMnog == 0)
    {
        x = numGen1(a, ++i, p);
        if (x == BazMnog)
        {
            DelBazMnog = i % p;
        }
    }
    cout << "Уравнения вида (2^x mod 30203 = 24322) имеет решение при x = " << (DelBazMnog * StepenBazMnog - stepen + 1) % (p - 1) << endl;
}
