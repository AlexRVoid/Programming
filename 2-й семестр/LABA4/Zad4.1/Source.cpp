#include <iostream>
#include <vector>

using namespace std;

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

int main()
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