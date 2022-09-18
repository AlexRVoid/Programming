#include <iostream>
#include <Windows.h>
#include <cstdlib>
#include <iomanip>
#include <vector>

#define PI acos(-1.0)
#define Exp 0.0001

using namespace std;

double F(double x)
{
	return ((2 * x) + tan(x));
}

double dF(double x)
{
	return 2 + (1 / pow(cos(x), 2));
}

double ddF(double x)
{
	return (2 * sin(x)) / (pow(cos(x), 3));
}

void polDel(vector<pair<double, double>> interval)
{
	for (pair<double, double> interv : interval)
	{
		cout << "-----------------------------------------------------------------" << endl
			<< "|" << setw(8) << "N" << setw(8)
			<< "|" << setw(8) << "An" << setw(8)
			<< "|" << setw(8) << "Bn" << setw(8)
			<< "|" << setw(11) << "Bn-An" << setw(5)
			<< "|" << endl
			<< "-----------------------------------------------------------------" << endl;

		double a0 = interv.first;
		double b0 = interv.second;

		int k = 0;
		cout << "|" << setw(8) << k << setw(8)
			<< "|" << setw(13) << a0 << setw(3)
			<< "|" << setw(13) << b0 << setw(3)
			<< "|" << setw(13) << b0 - a0 << setw(3)
			<< "|" << endl
			<< "-----------------------------------------------------------------" << endl;
		double a1 = 0, b1 = 0;
		while (true)
		{
			double c0 = (a0 + b0) / 2;
			if ((F(a0) * F(c0)) <= 0)
			{
				a1 = a0;
				b1 = c0;
			}
			else if ((F(a0) * F(c0)) > 0)
			{
				a1 = c0;
				b1 = b0;
			}

			if (abs(b1 - a1) <= Exp)
			{
				break;
			}
			a0 = a1;
			b0 = b1;
			k++;
			cout << "|" << setw(8) << k << setw(8)
				<< "|" << setw(13) << a1 << setw(3)
				<< "|" << setw(13) << b1 << setw(3)
				<< "|" << setw(13) << b1 - a1 << setw(3)
				<< "|" << endl
				<< "-----------------------------------------------------------------" << endl;
		}
		double X = (a1 + b1) / 2;
		cout << "x* = " << X << endl << endl;
	}
}

void Hord(vector<pair<double, double>> interval)
{
	for (pair<double, double> interv : interval)
	{
		double a0 = interv.first;
		double b0 = interv.second;

		double x0 = interv.second;
		double x1 = 0;
		int k = 0;

		x1 = x0 - F(x0) / (F(x0) - F(a0)) * (x0 - a0);
		cout << "-----------------------------------------------------------------" << endl
			<< "|" << setw(8) << "N" << setw(8)
			<< "|" << setw(10) << "x(n)" << setw(6)
			<< "|" << setw(11) << "x(n+1)" << setw(5)
			<< "|" << setw(14) << "x(n+1) - x(n)" << setw(2)
			<< "|" << endl
			<< "-----------------------------------------------------------------" << endl;

		cout << "|" << setw(8) << k++ << setw(8)
			<< "|" << setw(13) << x0 << setw(3)
			<< "|" << setw(13) << x1 << setw(3)
			<< "|" << setw(13) << x1 - x0 << setw(3)
			<< "|" << endl
			<< "-----------------------------------------------------------------" << endl;

		while (abs(x1 - x0) >= Exp) 
		{
			x0 = x1;
			x1 = x0 - F(x0) / (F(x0) - F(a0)) * (x0 - a0);
			cout << "|" << setw(8) << k++ << setw(8)
				<< "|" << setw(13) << x0 << setw(3)
				<< "|" << setw(13) << x1 << setw(3)
				<< "|" << setw(13) << x1 - x0 << setw(3)
				<< "|" << endl
				<< "-----------------------------------------------------------------" << endl;
		}
		cout << "x* = " << x1 << endl << endl;
	}
}


void Newton(vector<pair<double, double>> interval)
{
	for (pair<double, double> interv : interval)
	{
		cout << "-----------------------------------------------------------------" << endl
			<< "|" << setw(8) << "N" << setw(8)
			<< "|" << setw(10) << "x(n)" << setw(6)
			<< "|" << setw(11) << "x(n+1)" << setw(5)
			<< "|" << setw(14) << "x(n+1) - x(n)" << setw(2)
			<< "|" << endl
			<< "-----------------------------------------------------------------" << endl;

		int k = 0;
		double x0 = 0;
		double x1 = 0;
		double a0 = interv.first;
		double b0 = interv.second;
		if (F(a0) * ddF(a0) > 0)
		{
			x0 = a0;
		}
		else
		{
			x0 = b0;
		}
		x1 = x0 - F(x0) / dF(x0);

		cout << "|" << setw(8) << k++ << setw(8)
			<< "|" << setw(13) << x0 << setw(3)
			<< "|" << setw(13) << x1 << setw(3)
			<< "|" << setw(13) << x1 - x0 << setw(3)
			<< "|" << endl
			<< "-----------------------------------------------------------------" << endl;

		while (abs(x1 - x0) >= Exp) {
			x0 = x1;
			x1 = x0 - F(x0) / dF(x0);
			cout << "|" << setw(8) << k++ << setw(8)
				<< "|" << setw(13) << x0 << setw(3)
				<< "|" << setw(13) << x1 << setw(3)
				<< "|" << setw(13) << x1 - x0 << setw(3)
				<< "|" << endl
				<< "-----------------------------------------------------------------" << endl;
		}
		cout << "x* = " << x1 << endl << endl;
	}
}

int main()
{							//2x + tg(x)=0
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	/*
	cout << "Введите интервал поиска корней [a;b]: " << endl << "a = ";
	double a = 0;
	cin >> a;
	cout << "b = ";
	double b = 0;
	cin >> b;
	if (a > b)
	{
		double prom = a;
		a = b;
		b = prom;
	} //a - начало промежутка, b - конец промежутка


	/*  100% корнем функции является х = 0, функция tg(x) не сушествует при PI/2 + PIk, k принадлежит целым числам. при этом на промежутке (к примеру) (-PI/2;PI/2)
		существует только один единственный корень. Значит будем использовать промежутки с шагом PI. При это на графике видно, что при использовании промежутка, где a0 и b0 < 0,
		для точности из a0 можно вычесть 1, когда на промежутке, где a0 и b0 > 0, для точности из b0 можно вычесть 1  

	double promAInRad = PI/2;

	if (a <= 0)
	{
		while (promAInRad > a)
		{
			promAInRad -= PI;
		}
	}
	else
	{
		while (promAInRad < a)
		{
			promAInRad += PI;
		}
		promAInRad -= PI;
	}

	vector<double> intervA;
	for (double i = promAInRad; i <= b; i = i + PI)
	{
		intervA.push_back(i);
	}
	*/

	vector <pair<double, double>> interval = { {(-14 * PI) / 9,((-3 * PI) / 2) - 0.01}, {(-11 * PI) / 18,(-5 * PI) / 9},{(-PI) / 18,PI / 18},{(5 * PI) / 9,(11 * PI) / 18}, {((3 * PI) / 2) + 0.01,(14 * PI) / 9} };
	cout << "Метод половинного деления" << endl << endl;
	polDel(interval);
	cout << "Метод Хорд" << endl << endl;
	Hord(interval);
	cout << "Метод Ньютона" << endl << endl;
	Newton(interval);
}