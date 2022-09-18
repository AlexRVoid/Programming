#include <ctime>
#include <string>
#include <iostream>
#include <conio.h>

using namespace std;

int main()
{
    string word, key, D = "";
    string alphabet = "abcdefghijklmnopqrstuvwxyz"; //��� �������
    setlocale(LC_ALL, "Rus");
    cout << "������� �����: ";
    cin >> word;
    cout << "������� ����: ";
    cin >>key;
    int* F = new int[word.size()];
    int* G = new int[word.size()];
    int c = key.size(); //������ ������ ���������� ��� ��������
    int b = word.size();
    //������ �������. ���� ����� ��������� ����� ������, ���� ����� ����� �����
    if (b >= c)
    {
        for (int i = 0; i < (b / c); i++)
        {
            D = D + key; //���������� ����� ���������� �����. ���������� ���� �� ����� �����.
        }
        for (int j = 0; j < (b % c); j++)
        {
            D = D + key[j];
        }
    }
    else  //����� ���� ���� ������� �����, ����������� ���� �� ����� �����.
    {
        for (int s = 0; s < b; s++)
        {
            D = D + word[s];
        }
    }
    for (int k = 0; k < b; k++)
    {
        for (int n = 0; n < 26; n++)
        {
            if (word[k] == alphabet[n])
            {
                F[k] = n;
            }

            if (D[k] == alphabet[n])
            {
                G[k] = n;
            } //����� �� ��� �������� ���������. ����� ����������� ����, ��� �� ���� ����� ����� �� �������� ����� � ������, � ����� ���� ���������� �� � ������

        }
    }

    int e = 0; //��� ����� ������� ��������. ����� ��� ���������� 26 �����, ��������� ��� �� �����, ������� � ������� ������
    for (int u = 0; u < b; u++)
    {
        e = ((F[u] + G[u]) % 26);
        word[u] = alphabet[e];
    }

    cout << "������������� �����: " << word << endl;


    _getch();
    return 0;

}
