#include <iostream>
#include <math.h>
#include <stdio.h>
#include <locale>
#include <cstdint>
#include <vector>
#include <string>
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

int Task2 (const int base, const int exponent, const int mod)
{
    int pow = 1;
    for (int i = 0; i < exponent; i++)
    {
        pow *= base;
        pow %= mod;
    }
    return pow;
}

void Task3 ()
{
    int a, b, i = 1, r = 1, q;
    cout << "������� ������� �����: " << endl;
    cin >> a;
    cout << "������� ������� �����: " << endl;
    cin >> b;
    while (i == 1)
    {
        if (r != 0)
        {//a=bq+r
            r = a % b;
            q = a / b;

            a = b;
            b = r;
        }
        else
        {
            cout << "��� = " << a << endl;
            i = 0;
        }
    }

}

void Task4 ()
{
    int a, b, i = 1, r = 1, q, x1 = 1, y1 = 0, x2 = 0, y2 = 1, x3, y3, a1; //������� x1 � y1 ��������� ������� 
    cout << "������� ������� �����: " << endl;
    cin >> a;
    cout << "������� ������� �����: " << endl;
    cin >> b;
    cout << "r\t\tx\t\ty\t\tq" << endl;
    cout << a << "\t\t" << x1 << "\t\t" << y1 << "\t\t" << endl;
    cout << b << "\t\t" << x2 << "\t\t" << y2 << endl;
    while (i == 1)
    {
        if (r != 0)
        {
            r = a % b;
            q = a / b;
            x3 = x1 - q * x2;
            y3 = y1 - q * y2;
            x1 = x2;
            x2 = x3;
            y1 = y2;
            y2 = y3;
            if (r != 0)  cout << r << "\t\t" << x3 << "\t\t" << y3 << "\t\t" << q << endl;
            else cout << r << "\t\t" << "---" << "\t\t" << "---" << "\t\t" << q << endl;
            a = b;
            b = r;
        }
        else
        {
            cout << "��� = " << a << endl;
            i = 0;
        }
    }

}


void Task5 ()
{
    int g, p, a, b, Xa = 1, Xb = 1, Ya = 1, Yb = 1;
    cout << "���������� 2 ��������� �����: ";
        cin >> g;
        cin >> p;
    cout << "���������� ��������� ����� ��� �����: ";
        cin >> a;
    cout << "���������� ��������� ����� ��� ����: ";
        cin >> b;
    for (int i = 0; i < a; i++)
    {
        Ya *= g;
        Ya %= p;
    }
    cout << "��������� ���� �����: " << Ya << endl;
    for (int i = 0; i < b; i++)
    {
        Yb *= g;
        Yb %= p;
    }
    cout << "��������� ���� ����: " << Yb << endl;
    for (int i = 0; i < a; i++)
    {
        Xa *= Yb;
        Xa %= p;
    }
    cout << "��������� ���� �����: " << Xa << endl;
    for (int i = 0; i < b; i++)
    {
        Xb *= Ya;
        Xb %= p;
    }
    cout << "��������� ���� ����: " << Xb << endl;
    
}


void Task7 ()
{
    int x = 3, r = 7, r1 = 8, ans = 0, itog_st = 0;
    int t = x % 10;
    int t1 = r % 10;
    int t2 = r1 % 10;

    //����� � ���������� ���������� ������� 
    if (t == 0) cout << "��������� ����� �����: 0";
    else if (t == 1) cout << "��������� ����� �����: 1";
    else if (t == 5) cout << "��������� ����� �����: 5";
    else if (t == 6) cout << "��������� ����� �����: 6";

    else {
        for (int i = 1; i <= r1; i++)
        { //������� ��������� ����� �������� �������
            itog_st = r % 10;
            r = t1 * itog_st;
        }

        if (itog_st == 0) cout << "��������� ����� �����: 1";

        else
        {
            for (int j = 1; j <= itog_st; j++)
            {
                ans = x % 10;
                x = t * ans;
            }

            cout << "��������� ����� �����: " << ans;
        }
    }

}

int main ()
{
    setlocale(LC_ALL, "Russian");
    cout << "Task 1:" << endl;
    Task1 ();
    cout << "Task 2:" << endl;
    int base, exponent, mod, pow;
    cout << "Enter a: ";
    cin >> base;
    cout << "Enter x: ";
    cin >> exponent;
    cout << "Enter p:";
    cin >> mod;
    cout << Task2 (base, exponent, mod) << endl;
    cout << "Task 3:" << endl;
    Task3 ();
    cout << "Task 4:" << endl;
    Task4();
    cout << "Task 5:" << endl;
    Task5();
    cout << "Task 7:" << endl;
    Task7();
}