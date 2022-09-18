#define _USE_MATH_DEFINES
#include <iostream>
#include <random>
#include <map>
#include <vector>
#include <cmath>
#include <math.h>
#include <algorithm>
#include <locale>


using namespace std;

void Task1pol(double a, double b, int q)
{
    double c;
    double d;
    d = b - a;
    cout.precision(4);
    cout << q << " " << a << " " << b << " ";
    cout << round(d) / 10000 << endl;
    c = (a + b) / 2;
    if (abs(a - b) < 0.0001) cout << "����� ����������� ������� " << c << endl;
    else {
        q++;
        if ((pow(a, 2) + pow(M_E, a) - 2) * (pow(c, 2) + pow(M_E, c) - 2) < 0) Task1pol(a, c, q);
        if ((pow(c, 2) + pow(M_E, c) - 2) * (pow(c, b) + pow(M_E, b) - 2) < 0) Task1pol(c, b, q);
    }
}

double f(double x) {

    return pow(x, 2) + pow(M_E, x) - 2;
}

double f1(double x) {

    return 2 * x + pow(M_E, x);
}

double f2(double x) {

    return   2 + pow(M_E, x);
}

void Task1nut(double a1, double b1) {
    double a = a1;
    double b = b1;
    double x;
    double e = 0.0001;
    int k = 0;

    if (f(a) * f2(a) > 0) {
        x = a;
    }
    else {
        if (f(b) * f2(b) > 0) {
            x = b;
        }
        else {
            x = -0.0001;
        }
    }
    k = 0;
    while (1) {
        cout << k << " " << round(x) / 10000 << " " << round(x - f(x) / f1(x)) / 10000 << " " << round((x - x - f(x) / f1(x)) * 10000) / 10000 << endl;
        x = x - f(x) / f1(x);
        k += 1;
        if (fabs(f(x)) < e) {
            break;
        }
    }
    cout.precision(4);
    cout << "����� ������� " << x << endl;
}

void Task2()
{
    ranlux48_base gen(time(0));
    
    cout << "1.�������� ������:" << endl;
    vector<double> mas;
    cout << "������� ���-�� ��������� �������: ";
    int n = 0;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        mas.push_back(gen() % 101);
    }

    for (double i : mas)
    {
        cout << i << ' ';
    }
    cout << endl << endl;
    cout << "2.������� �������� �-� �������:" << endl;
    double sum = 0;
    for (double x : mas)
    {
        sum += x;
    }
    double sred = sum / n;
    cout << sred << endl << endl;

    cout << "3.����� ��������� ��������:" << endl;
    double sumKvadr = 0;
    for (double x : mas)
    {
        sumKvadr += pow((x - sred), 2);
    }
    cout << sumKvadr << endl << endl;

    cout << "4.����� � ���������� ���������:" << endl;
    int poz = 0;
    for (double x : mas)
    {
        if ((int)x % 2 == 0 && poz % 2 == 0)
        {
            int intX = x;
            int a = intX % 10;
            intX = intX / 10;
            intX = intX + (a * 10);
            cout << intX << ' ';
        }
        poz++;
    }
    cout << endl << endl;

    cout << "5.������� ������� ����� ������� � �����:" << endl;
    double m = mas[0];
    mas.erase(mas.cbegin());
    mas.push_back(m);
    for (double i : mas)
    {
        cout << i << ' ';
    }
    cout << endl << endl;

    cout << "6.������� ���-�� ���������� ��������� ������� � �������� �������������:" << endl;
    vector<int> mas2;
    cout << "������� ���-�� ��������� �������: ";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        mas2.push_back((gen() % 21) - 10);
    }
    cout << "�������� ������: " << endl;
    for (int i : mas2)
    {
        cout << i << ' ';
    }
    cout << endl << "��� - �� ���������� ����� � �������: " << endl;
    map<int, int> countNum;
    for (int i : mas2)
    {
        if (countNum.find(i) != countNum.end())
        {
            countNum[i]++;
        }
        else
        {
            pair<int, int> m = { i,1 };
            countNum.insert(m);
        }
    }
    for (auto i : countNum)
    {
        cout << i.first << " = " << i.second << endl;
    }

    cout << "������ ����� ���������: " << endl;
    vector <int> mas2_copy;
    for (int i : mas2)
    {
        if (countNum[i] > 1)
        {
            countNum[i]--;
            continue;
        }
        else
        {
            mas2_copy.push_back(i);
        }
    }
    for (int i : mas2_copy)
    {
        cout << i << ' ';
    }
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

void Task3()
{
    ranlux48_base gen(time(0));
    int n1 = 50, n2 = 100, n3 = 1000;

    map<double, double> mas50;
    for (int i = 0; i < n1; i++)
    {
        mas50[(1 + gen() % 100)]++;
    }
    double XiKvadrat = XiKvadratCalk(mas50);
    cout << "XiKvadrat ������� �������: " << XiKvadrat << endl << "����������� XiKvadrat ��� �������� �������: " << 67.5 << endl;
    if (XiKvadrat > 67.5)
    {
        cout << "�������� �����" << endl << endl;
    }
    else
    {
        cout << "�������� �����" << endl << endl;
    }


    map<double, double> mas100;
    for (int i = 0; i < n2; i++)
    {
        mas100[(1 + gen() % 100)]++;
    }
    XiKvadrat = XiKvadratCalk(mas100);
    cout << "XiKvadrat ������� �������: " << XiKvadrat << endl << "����������� XiKvadrat ��� �������� �������: " << 124.3 << endl;
    if (XiKvadrat > 124.3)
    {
        cout << "�������� �����" << endl << endl;
    }
    else
    {
        cout << "�������� �����" << endl << endl;
    }


    map<double, double> mas1000;
    for (int i = 0; i < n3; i++)
    {
        mas1000[(1 + gen() % 100)]++;
    }
    XiKvadrat = XiKvadratCalk(mas1000);
    cout << "XiKvadrat ������� �������: " << XiKvadrat << endl << "����������� XiKvadrat ��� �������� �������: " << 1074.7 << endl;
    if (XiKvadrat > 1074.7)
    {
        cout << "�������� �����" << endl << endl;
    }
    else
    {
        cout << "�������� �����" << endl << endl;
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

void Task4()
{
    //��� �������� ��� ��������
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
    cout << "��������� ���� (2^x mod 30203 = 24322) ����� ������� ��� x = " << i0 * m - j0 << endl;
}

void DelitelCheck(int x, int p, int& BazMnog, int& StepenBazMnog) {
    int l = 0;
    for (int i = 1; pow(x, i) < p; i++)
    {                   //��������� ���� �� ������ 3 ������� �����
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

void Task5()
{
    //�������� ���������� �������
    setlocale(LC_ALL, "Rus");
    int a = 2;
    int p = 30203;
    int y = 24322;


    int x = 0, i = 1, BazMnog = 0, StepenBazMnog = 0;
    while (BazMnog == 0)                      //�� ����������� ���� ������ ����� �������� ������� ��������� � ������� ����� ��� BazMnog^StepenBazMnog= y a^x mod p
    {
        x = numGen2(a, i++, p, y);                          //��������� ������� ����� ���� ya^r
        DelitelCheck(x, p, BazMnog, StepenBazMnog);        //�������� �� ���������
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
    cout << "��������� ���� (2^x mod 30203 = 24322) ����� ������� ��� x = " << (DelBazMnog * StepenBazMnog - stepen + 1) % (p - 1) << endl;
}

int main()
{
    setlocale(LC_ALL, "Rus");
    cout << "Task1:" << endl;
    Task1pol(-10, 10, 0);
    Task1nut(0, 1);
    cout << "Task2:" << endl;
    Task2();
    cout << "\nTask3:" << endl;
    Task3();
    cout << "Task4:" << endl;
    Task4();
    cout << "Task4.1:" << endl;
    Task5();
}
