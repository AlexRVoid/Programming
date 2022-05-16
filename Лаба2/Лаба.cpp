/*
ЗАДАНИЕ 1.
Даны длины ребер a, b, c прямоугольного параллелепипеда.
Найти его объем V = a·b·c и площадь поверхности S = 2·(a·b + b·c + a·c).

ЗАДАНИЕ 2
Учитывая массив nums целых чисел, 
вернуть, сколько из них содержат нечетное количество цифр.

ЗАДАНИЕ 3
Для каждого трёхзначного числа определить является ли оно палиндромом 
(Читается одинаково с любой стороны, например 101, 222 и т.д.).
*/
#include <iostream>
#include <vector>
using namespace std;

void Task1()
{
	int a, b, c;
	cout << "Enter the length:";
		cin >> a;
	cout << "\nEnter the width:";
		cin >> b;
	cout << "\nEnter the height:";
		cin >> c;
	int V, S;
	S = 2 * (a * b + b * c + a * c);
	cout << "S = " << S << endl;
	V = a * b * c;
	cout << "V = " << V << endl;
}

void Task2()
{
	int n, s;        //n - кол-во входящих чисел, s - кол-во подходящих чисел
	s = 0;
	cout << "Kol-vo chisel v viborke = "; cin >> n;
	vector <int> nums(n, 0);       //инициализация массива

	for (int i = 1; i <= n; i++) {
		nums[i] = rand() % 9999;         //рандом значений
		cout << nums[i] << " ";             //вывод заполненного массива
	}

	cout << "\n";

	for (int i = 1; i <= n; i++) {         //перебор значений
		int o = nums[i];      //значение из вектора
		int k = 0;                  //кол-во цифр
		if (o != 0) {                //проверка на 0
			while (o != 0) {                      //подсчёт цифр
				o = o / 10;
				k++;
			}
			if (k % 2 == 1)
				s++;
		}
	}

	cout << s;
	
}

void Task3()
{
	while (true)
	{
		int num;
		cout << "Enter The number:";
		cin >> num;
		if (num >= 100 && num < 1000) { // Провека, является ли число трёхзначным или нет
			if (num / 100 == num % 10)// Проверка, является ли число полиндромом
				cout << "Yes" << endl;
			else cout << "No" << endl;
		}
		else
			cout << "No" << endl;
		num = 0;
		bool res;
		cout << "Continue or not(1/0):";
		cin >> res;
		if (res == 0)
			break;
	}
}


int main()
{
	int task;
	cout << "Select a task:";
	cin >> task;
	if (task == 1) {
		cout << "Task 1:" << endl;
		Task1();
	}
	if (task == 2) {
		cout << "\nTask 2:" << endl;
		Task2();
	}
	if (task == 3) {
		cout << "\nTask 3:" << endl;
		Task3();
	}
	else
	{
		cout << "Invalid value";
	}
	return 0;
}
