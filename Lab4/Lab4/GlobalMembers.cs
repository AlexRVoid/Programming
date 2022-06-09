using System;
using System.Collections.Generic;

public static class GlobalMembers
{



	public static void Task1pol(double a, double b, int q)
	{
		double c;
		double d;
		d = b - a;
		Console.Write("{0:4}", q);
		Console.Write("{0:4}", " ");
		Console.Write("{0:4}", a);
		Console.Write("{0:4}", " ");
		Console.Write("{0:4}", b);
		Console.Write("{0:4}", " ");
		Console.Write("{0:4}", Math.Round(d) / 10000);
		Console.Write("{0:4}", "\n");
		c = (a + b) / 2;
		if (Math.Abs(a - b) < 0.0001)
		{
			Console.Write("{0:4}", "метод половинного деления ");
			Console.Write("{0:4}", c);
			Console.Write("{0:4}", "\n");
		}
		else
		{
			q++;
			if ((Math.Pow(a, 2) + Math.Pow(Math.E, a) - 2) * (Math.Pow(c, 2) + Math.Pow(Math.E, c) - 2) < 0)
			{
				Task1pol(a, c, q);
			}
			if ((Math.Pow(c, 2) + Math.Pow(Math.E, c) - 2) * (Math.Pow(c, b) + Math.Pow(Math.E, b) - 2) < 0)
			{
				Task1pol(c, b, q);
			}
		}
	}

	public static double f(double x)
	{

		return Math.Pow(x, 2) + Math.Pow(Math.E, x) - 2;
	}

	public static double f1(double x)
	{

		return 2 * x + Math.Pow(Math.E, x);
	}

	public static double f2(double x)
	{

		return 2 + Math.Pow(Math.E, x);
	}

	public static void Task1nut(double a1, double b1)
	{
		double a = a1;
		double b = b1;
		double x;
		double e = 0.0001;
		int k = 0;

		if (f(a) * f2(a) > 0)
		{
			x = a;
		}
		else
		{
			if (f(b) * f2(b) > 0)
			{
				x = b;
			}
			else
			{
				x = -0.0001;
			}
		}
		k = 0;
		while (true)
		{
			Console.Write(k);
			Console.Write(" ");
			Console.Write(Math.Round(x) / 10000);
			Console.Write(" ");
			Console.Write(Math.Round(x - f(x) / f1(x)) / 10000);
			Console.Write(" ");
			Console.Write(Math.Round((x - x - f(x) / f1(x)) * 10000) / 10000);
			Console.Write("\n");
			x = x - f(x) / f1(x);
			k += 1;
			if (Math.Abs(f(x)) < e)
			{
				break;
			}
		}
		Console.Write("{0:4}", "Метод Ньютона ");
		Console.Write("{0:4}", x);
		Console.Write("{0:4}", "\n");
	}

	public static int ryd1Gen(int a, int range, int p)
	{
		int genNum = 1;
		for (int i = 1; i <= range; i++)
		{
			genNum = (a * genNum) % p;
		}
		return genNum;
	}

	public static int ryd2Gen(int a, int y, int range, int p)
	{
		int genNum = y;
		for (int i = 1; i <= range; i++)
		{
			genNum = (a * genNum) % p;
		}
		return genNum;
	}

	public static void Task4()
	{
		//Шаг младенца шаг великана
		// 2^x mod 30203 = 24322      a^x mod p = y

		int p = 30203;
		int y = 24322;
		int a = 2;

		SortedDictionary<int, int> ryd1 = new SortedDictionary<int, int>();
		SortedDictionary<int, int> ryd2 = new SortedDictionary<int, int>();

		int m = Math.Sqrt(p) + 1;
		for (int i = 1; i <= m; i++)
		{
			ryd1[i] = ryd1Gen(a, i * m, p);
		}
		for (int i = 1; i <= m; i++)
		{
			ryd2[i] = ryd2Gen(a, y, i, p);
		}

		int i0 = 0;
		int j0 = 0;
		foreach (var i in ryd1)
		{
			foreach (var j in ryd2)
			{
				if (i.second == j.second)
				{
					i0 = i.first;
					j0 = j.first;
				}
			}
		}
		Console.Write("Уравнения вида (2^x mod 30203 = 24322) имеет решение при x = ");
		Console.Write(i0 * m - j0);
		Console.Write("\n");
	}

	public static void DelitelCheck(int x, int p, ref int BazMnog, ref int StepenBazMnog)
	{
		int l = 0;
		for (int i = 1; Math.Pow(x, i) < p; i++)
		{ //факторная база из первых 3 простых чисел
			if (Math.Pow(2, i) == x)
			{
				BazMnog = 2;
				StepenBazMnog = i;
			}
		}
		for (int i = 1; Math.Pow(x, i) < p; i++)
		{
			if (Math.Pow(3, i) == x)
			{
				BazMnog = 3;
				StepenBazMnog = i;
			}
		}
		for (int i = 1; Math.Pow(x, i) < p; i++)
		{
			if (Math.Pow(5, i) == x)
			{
				BazMnog = 5;
				StepenBazMnog = i;
			}
		}
	}

	public static int numGen1(int a, int x, int p)
	{
		int genNum = 1;
		for (int i = 0; i < x; i++)
		{
			genNum = (a * genNum) % p;
		}
		return genNum;
	}

	public static int numGen2(int a, int x, int p, int y)
	{
		int genNum = y;
		for (int i = 0; i < x; i++)
		{
			genNum = (a * genNum) % p;
		}
		return genNum;

	}

	public static void Task5()
	{
		//Алгоритм исчисления порядка
		int a = 2;
		int p = 30203;
		int y = 24322;


		int x = 0;
		int i = 1;
		int BazMnog = 0;
		int StepenBazMnog = 0;
		while (BazMnog == 0) //по результатам цикл должен найти некотрый базовый множитель и степень такое что BazMnog^StepenBazMnog= y a^x mod p
		{
			x = numGen2(a, i++, p, y); //находится гладкое число вида ya^r
			DelitelCheck(x, p, ref BazMnog, ref StepenBazMnog); //проверка на гладкость
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
		Console.Write("Уравнения вида (2^x mod 30203 = 24322) имеет решение при x = ");
		Console.Write((DelBazMnog * StepenBazMnog - stepen + 1) % (p - 1));
		Console.Write("\n");
	}

	static int Main()
	{
		Console.Write("Task1:");
		Console.Write("\n");
		Task1pol(-10, 10, 0);
		Task1nut(0, 1);
		Console.Write("Task4:");
		Console.Write("\n");
		Task4();
		Console.Write("Task4.1:");
		Console.Write("\n");
		Task5();
	}

}