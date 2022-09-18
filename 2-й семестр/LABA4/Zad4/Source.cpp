#include <iostream>
#include <vector>
#include <map>

using namespace std;

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

int main()
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