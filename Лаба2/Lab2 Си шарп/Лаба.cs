using System;
using System.Collections.Generic;

public static class Лаба
{
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

	public static void Task1()
	{
		int a;
		int b;
		int c;
		Console.Write("Enter the length:");
			a = Console.ReadLine();
		Console.Write("\nEnter the width:");
			b = Console.ReadLine();
		Console.Write("\nEnter the height:");
			c = Console.ReadLine();
		int V;
		int S;
		S = 2 * (a * b + b * c + a * c);
		Console.Write("S = ");
		Console.Write(S);
		Console.Write("\n");
		V = a * b * c;
		Console.Write("V = ");
		Console.Write(V);
		Console.Write("\n");
	}

	public static void Task2()
	{
		int n; //n - кол-во входящих чисел, s - кол-во подходящих чисел
		int s;
		s = 0;
		Console.Write("Enter the number of items in the selection: ");
		n = Console.ReadLine();
		List<int> nums = new List<int>(n); //инициализация массива

		for (int i = 1; i <= n; i++)
		{
			nums[i] = RandomNumbers.NextNumber() % 9999; //рандом значений
			Console.Write(nums[i]);
			Console.Write(" ");
		}

		Console.Write("\n");

		for (int i = 1; i <= n; i++)
		{ //перебор значений
			int o = nums[i]; //значение из вектора
			int k = 0; //кол-во цифр
			if (o != 0)
			{ //проверка на 0
				while (o != 0)
				{ //подсчёт цифр
					o = o / 10;
					k++;
				}
				if (k % 2 == 1)
				{
					s++;
				}
			}
		}

		Console.Write(s);

	}

	public static void Task3()
	{
		while (true)
		{
			int num;
			Console.Write("Enter The number:");
			num = Console.ReadLine();
			if (num >= 100 && num < 1000)
			{ // Провека, является ли число трёхзначным или нет
				if (num / 100 == num % 10) // Проверка, является ли число полиндромом
				{
					Console.Write("Yes");
					Console.Write("\n");
				}
				else
				{
					Console.Write("No");
					Console.Write("\n");
				}
			}
			else
			{
				Console.Write("No");
				Console.Write("\n");
			}
			num = 0;
			bool res;
			Console.Write("Continue or not(1/0):");
			res = Console.ReadLine();
			if (res == false)
			{
				break;
			}
		}
	}


	static int Main()
	{
		int task;
		Console.Write("Select a task:");
		task = Console.ReadLine();
		if (task == 1)
		{
			Console.Write("Task 1:");
			Console.Write("\n");
			Task1();
		}
		if (task == 2)
		{
			Console.Write("\nTask 2:");
			Console.Write("\n");
			Task2();
		}
		if (task == 3)
		{
			Console.Write("\nTask 3:");
			Console.Write("\n");
			Task3();
		}
		else
		{
			Console.Write("Invalid value");
		}
		return 0;
	}

}