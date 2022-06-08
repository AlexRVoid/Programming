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

	public static void Task2()
	{
		ranlux48_base gen = new ranlux48_base(time(0));

		Console.Write("1.исходный массив:");
		Console.Write("\n");
		List<double> mas = new List<double>();
		Console.Write("Введите кол-во элементов массива: ");
		int n = 0;
		n = int.Parse(ConsoleInput.ReadToWhiteSpace(true));

		for (int i = 0; i < n; i++)
		{
			mas.Add(gen() % 101);
		}

		foreach (double i in mas)
		{
			Console.Write(i);
			Console.Write(' ');
		}
		Console.Write("\n");
		Console.Write("\n");
		Console.Write("2.среднее значение э-в массива:");
		Console.Write("\n");
		double sum = 0;
		foreach (double x in mas)
		{
			sum += x;
		}
		double sred = sum / n;
		Console.Write(sred);
		Console.Write("\n");
		Console.Write("\n");

		Console.Write("3.сумма квадратов разности:");
		Console.Write("\n");
		double sumKvadr = 0;
		foreach (double x in mas)
		{
			sumKvadr += Math.Pow((x - sred), 2);
		}
		Console.Write(sumKvadr);
		Console.Write("\n");
		Console.Write("\n");

		Console.Write("4.числа с сменёнными разрядами:");
		Console.Write("\n");
		int poz = 0;
		foreach (double x in mas)
		{
			if ((int)x % 2 == 0 && poz % 2 == 0)
			{
				int intX = (int)x;
				int a = intX % 10;
				intX = intX / 10;
				intX = intX + (a * 10);
				Console.Write(intX);
				Console.Write(' ');
			}
			poz++;
		}
		Console.Write("\n");
		Console.Write("\n");

		Console.Write("5.перенос первого числа массива в конец:");
		Console.Write("\n");
		double m = mas[0];
		mas.erase(mas.cbegin());
		mas.Add(m);
		foreach (double i in mas)
		{
			Console.Write(i);
			Console.Write(' ');
		}
		Console.Write("\n");
		Console.Write("\n");

		Console.Write("6.подсчёт кол-ва конкретных элементов массива и удаление повторяющихся:");
		Console.Write("\n");
		List<int> mas2 = new List<int>();
		Console.Write("Введите кол-во элементов массива: ");
		n = int.Parse(ConsoleInput.ReadToWhiteSpace(true));
		for (int i = 0; i < n; i++)
		{
			mas2.Add((gen() % 21) - 10);
		}
		Console.Write("Исходный массив: ");
		Console.Write("\n");
		foreach (int i in mas2)
		{
			Console.Write(i);
			Console.Write(' ');
		}
		Console.Write("\n");
		Console.Write("Кол - во конкретных чисел в массиве: ");
		Console.Write("\n");
		SortedDictionary<int, int> countNum = new SortedDictionary<int, int>();
		foreach (int i in mas2)
		{
			if (countNum.ContainsKey(i))
			{
				countNum[i]++;
			}
			else
			{
				Tuple<int, int> m = new Tuple<int, int>(i,1);
				countNum.insert(m);
			}
		}
		foreach (var i in countNum)
		{
			Console.Write(i.first);
			Console.Write(" = ");
			Console.Write(i.second);
			Console.Write("\n");
		}

		Console.Write("Массив после обработки: ");
		Console.Write("\n");
		List<int> mas2_copy = new List<int>();
		foreach (int i in mas2)
		{
			if (countNum[i] > 1)
			{
				countNum[i]--;
				continue;
			}
			else
			{
				mas2_copy.Add(i);
			}
		}
		foreach (int i in mas2_copy)
		{
			Console.Write(i);
			Console.Write(' ');
		}
	}

	public static double XiKvadratCalk(SortedDictionary<double, double> mas)
	{
		double xn = 0;
		double n = 0;
		double xSred = 0;

		foreach (var x in mas)
		{
			xn = xn + (x.first * x.second);
			n++;
		}
		xSred = xn / n;

		double xPromeg = 0;
		double S = 0;
		foreach (var x in mas)
		{
			xPromeg = xPromeg + Math.Pow((xSred - x.first), 2) * x.second;
		}
		S = Math.Sqrt(xPromeg / (n - 1));

		double U = 0;
		double funkU = 0;
		double n0 = 0;
		double XiKvadrat = 0;
		foreach (var x in mas)
		{
			U = (x.first - xSred) / S;
			funkU = Math.Pow(Math.E, (Math.Pow(U, 2) / -2)) / Math.Sqrt(2 * Math.PI);
			n0 = (n * funkU) / S;
			XiKvadrat = XiKvadrat + Math.Pow((x.second - n0), 2) / n0;
		}
		return XiKvadrat;
	}

	public static void Task3()
	{
		setlocale(LC_ALL, "Rus");
		ranlux48_base gen = new ranlux48_base(time(0));
		int n1 = 50;
		int n2 = 100;
		int n3 = 1000;

		SortedDictionary<double, double> mas50 = new SortedDictionary<double, double>();
		for (int i = 0; i < n1; i++)
		{
			mas50[(1 + gen() % 100)]++;
		}
		double XiKvadrat = XiKvadratCalk(new SortedDictionary<double, double>(mas50));
		Console.Write("XiKvadrat первого массива: ");
		Console.Write(XiKvadrat);
		Console.Write("\n");
		Console.Write("Критический XiKvadrat для заданных условий: ");
		Console.Write(67.5);
		Console.Write("\n");
		if (XiKvadrat > 67.5)
		{
			Console.Write("Гипотеза ложна");
			Console.Write("\n");
			Console.Write("\n");
		}
		else
		{
			Console.Write("Гипотеза верна");
			Console.Write("\n");
			Console.Write("\n");
		}


		SortedDictionary<double, double> mas100 = new SortedDictionary<double, double>();
		for (int i = 0; i < n2; i++)
		{
			mas100[(1 + gen() % 100)]++;
		}
		XiKvadrat = XiKvadratCalk(new SortedDictionary<double, double>(mas100));
		Console.Write("XiKvadrat второго массива: ");
		Console.Write(XiKvadrat);
		Console.Write("\n");
		Console.Write("Критический XiKvadrat для заданных условий: ");
		Console.Write(124.3);
		Console.Write("\n");
		if (XiKvadrat > 124.3)
		{
			Console.Write("Гипотеза ложна");
			Console.Write("\n");
			Console.Write("\n");
		}
		else
		{
			Console.Write("Гипотеза верна");
			Console.Write("\n");
			Console.Write("\n");
		}


		SortedDictionary<double, double> mas1000 = new SortedDictionary<double, double>();
		for (int i = 0; i < n3; i++)
		{
			mas1000[(1 + gen() % 100)]++;
		}
		XiKvadrat = XiKvadratCalk(new SortedDictionary<double, double>(mas1000));
		Console.Write("XiKvadrat второго массива: ");
		Console.Write(XiKvadrat);
		Console.Write("\n");
		Console.Write("Критический XiKvadrat для заданных условий: ");
		Console.Write(1074.7);
		Console.Write("\n");
		if (XiKvadrat > 1074.7)
		{
			Console.Write("Гипотеза ложна");
			Console.Write("\n");
			Console.Write("\n");
		}
		else
		{
			Console.Write("Гипотеза верна");
			Console.Write("\n");
			Console.Write("\n");
		}
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
		setlocale(LC_ALL, "Rus");
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
		setlocale(LC_ALL, "Rus");
		Console.Write("Task1:");
		Console.Write("\n");
		Task1pol(-10, 10, 0);
		Task1nut(0, 1);
		Console.Write("Task2:");
		Console.Write("\n");
		Task2();
		Console.Write("\nTask3:");
		Console.Write("\n");
		Task3();
		Console.Write("Task4:");
		Console.Write("\n");
		Task4();
		Console.Write("Task4.1:");
		Console.Write("\n");
		Task5();
	}

}