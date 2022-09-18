#include <iostream>
#include <chrono>
#include <random>
#include <vector>

#include <map>

//ranlux48_base

using namespace std;

int main()
{
	setlocale(LC_ALL, "Rus");

	unsigned seed = chrono::system_clock::now().time_since_epoch().count();
	ranlux48_base gen(seed);

	cout << "������� #1 (�������� ������):" << endl;
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
	cout << "������� #2 (������� �������� �-� �������):" << endl;
	double sum = 0;
	for (double x : mas)
	{
		sum += x;
	}
	double sred = sum / n;
	cout << sred << endl << endl;

	cout << "������� #3 (����� ��������� ��������):" << endl;
	double sumKvadr = 0;
	for (double x : mas)
	{
		sumKvadr += pow((x - sred), 2);
	}
	cout << sumKvadr << endl << endl;

	cout << "������� #4 (����� � ��������� ���������):" << endl;
	int poz = 0;
	for (double x : mas)
	{
		/*
		double svedenie = x;  // tut nada x
		int kolMnog = 0;
		while ((int)svedenie != svedenie)
		{
			svedenie *= 10;
			kolMnog++;
		}
		int intX = (int)svedenie;

		if (intX % 2 == 0 && poz % 2 == 0)
		{
			vector<int>num;
			while (intX > 0)
			{
				num.push_back(intX % 10);
			}
			reverse(num.begin(), num.end());

			int a = num[0];
			int b = num[num.size() - 1];
			num.pop_back();
			num.insert(num.begin(), b);
			num.push_back(a);

			int newX = 0;
			for (int i = 0; i < num.size(); i++)
			{
				newX = newX + num[i] * (10 * (num.size() - i - 1));
			}

			double doubleX = newX;
			for (int i = 0; i < kolMnog; i++)
			{
				doubleX = doubleX / 10;
			}
		}*/
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

	cout << "������� #5 (������� ������� ����� ������� � �����):" << endl;
	double m = mas[0];
	mas.erase(mas.cbegin());
	mas.push_back(m);
	for (double i : mas)
	{
		cout << i << ' ';
	}
	cout << endl << endl;

	cout << "������� #6 (������� ���-�� ��������� ��������� ������� � �������� �������������):" << endl;
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