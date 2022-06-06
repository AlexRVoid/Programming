using System;

public static class Lab3
{
	public static void Task1()
	{
		Console.Write(" ");
		Console.Write("X");
		Console.Write(" ");
		Console.Write("Y");
		Console.Write("\n");
		for (int x = -8, y = -3; x <= -5; x++)
		{
			Console.Write(x);
			Console.Write(" ");
			Console.Write(y);
			Console.Write("\n");
		}
		for (double x = -5, y = -3.0; x <= -3; x++)
		{
			y = 1.5 * x + 4.5;
			Console.Write(x);
			Console.Write(" ");
			Console.Write(y);
			Console.Write("\n");
		}
		for (double x = -3, y = 0; x <= 3 ; x++)
		{
			y += x;
			Console.Write(x);
			Console.Write(" ");
			Console.Write(y);
			Console.Write("\n");
		}
		for (double x = 3, y = 0; x <= 8; x++)
		{
			y = 0.27 * x + 0.82;
			Console.Write(x);
			Console.Write(" ");
			Console.Write(y);
			Console.Write("\n");
		}
		for (int x = 8, y = 3; x <= 10; x++)
		{
			Console.Write(x);
			Console.Write(" ");
			Console.Write(y);
			Console.Write("\n");
		}
	}

	public static int Task2(int @base, int exponent, int mod)
	{
		int pow = 1;
		for (int i = 0; i < exponent; i++)
		{
			pow *= @base;
			pow %= mod;
		}
		return pow;
	}

	public static void Task3()
	{
		int a;
		int b;
		int i = 1;
		int r = 1;
		int q;
		Console.Write("Enter a larger number: ");
		Console.Write("\n");
		a = int.Parse(ConsoleInput.ReadToWhiteSpace(true));
		Console.Write("Enter a smaller number: ");
		Console.Write("\n");
		b = int.Parse(ConsoleInput.ReadToWhiteSpace(true));
		while (i == 1)
		{
			if (r != 0)
			{ //a=bq+r
				r = a % b;
				q = a / b;

				a = b;
				b = r;
			}
			else
			{
				Console.Write("NOD = ");
				Console.Write(a);
				Console.Write("\n");
				i = 0;
			}
		}

	}

	public static void Task4()
	{
		int a; //зададим x1 и y1 начальные значени 
		int b;
		int i = 1;
		int r = 1;
		int q;
		int x1 = 1;
		int y1 = 0;
		int x2 = 0;
		int y2 = 1;
		int x3;
		int y3;
		Console.Write("Enter a larger number: ");
		Console.Write("\n");
		a = int.Parse(ConsoleInput.ReadToWhiteSpace(true));
		Console.Write("Enter a smaller number: ");
		Console.Write("\n");
		b = int.Parse(ConsoleInput.ReadToWhiteSpace(true));
		Console.Write("r\t\tx\t\ty\t\tq");
		Console.Write("\n");
		Console.Write(a);
		Console.Write("\t\t");
		Console.Write(x1);
		Console.Write("\t\t");
		Console.Write(y1);
		Console.Write("\t\t");
		Console.Write("\n");
		Console.Write(b);
		Console.Write("\t\t");
		Console.Write(x2);
		Console.Write("\t\t");
		Console.Write(y2);
		Console.Write("\n");
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
				if (r != 0)
				{
					Console.Write(r);
					Console.Write("\t\t");
					Console.Write(x3);
					Console.Write("\t\t");
					Console.Write(y3);
					Console.Write("\t\t");
					Console.Write(q);
					Console.Write("\n");
				}
				else
				{
					Console.Write(r);
					Console.Write("\t\t");
					Console.Write("---");
					Console.Write("\t\t");
					Console.Write("---");
					Console.Write("\t\t");
					Console.Write(q);
					Console.Write("\n");
				}
				a = b;
				b = r;
			}
			else
			{
				Console.Write("NOD = ");
				Console.Write(a);
				Console.Write("\n");
				i = 0;
			}
		}

	}


	public static void Task5()
	{
		int g;
		int p;
		int a;
		int b;
		int Xa = 1;
		int Xb = 1;
		int Ya = 1;
		int Yb = 1;
		Console.Write("Come up with 2 random numbers: ");
			g = int.Parse(ConsoleInput.ReadToWhiteSpace(true));
			p = int.Parse(ConsoleInput.ReadToWhiteSpace(true));
		Console.Write("Come up with a secret number for Alice: ");
			a = int.Parse(ConsoleInput.ReadToWhiteSpace(true));
		Console.Write("Come up with a secret number for Bob: ");
			b = int.Parse(ConsoleInput.ReadToWhiteSpace(true));
		for (int i = 0; i < a; i++)
		{
			Ya *= g;
			Ya %= p;
		}
		Console.Write("Alice's Public key: ");
		Console.Write(Ya);
		Console.Write("\n");
		for (int i = 0; i < b; i++)
		{
			Yb *= g;
			Yb %= p;
		}
		Console.Write("Bob's Public key: ");
		Console.Write(Yb);
		Console.Write("\n");
		for (int i = 0; i < a; i++)
		{
			Xa *= Yb;
			Xa %= p;
		}
		Console.Write("Alice's Private key: ");
		Console.Write(Xa);
		Console.Write("\n");
		for (int i = 0; i < b; i++)
		{
			Xb *= Ya;
			Xb %= p;
		}
		Console.Write("Приватный ключ Боба: ");
		Console.Write(Xb);
		Console.Write("\n");

	}


	public static void Task7()
	{
		int x = 3;
		int r = 7;
		int r1 = 8;
		int ans = 0;
		int itog_st = 0;
		int t = x % 10;
		int t1 = r % 10;
		int t2 = r1 % 10;

		//Числа с очевидными последними цифрами 
		if (t == 0)
		{
			Console.Write("Последняя цифра числа: 0");
		}
		else if (t == 1)
		{
			Console.Write("Последняя цифра числа: 1");
		}
		else if (t == 5)
		{
			Console.Write("Последняя цифра числа: 5");
		}
		else if (t == 6)
		{
			Console.Write("Последняя цифра числа: 6");
		}

		else
		{
			for (int i = 1; i <= r1; i++)
			{ //находим последнюю цифру итоговой степени
				itog_st = r % 10;
				r = t1 * itog_st;
			}

			if (itog_st == 0)
			{
				Console.Write("The last digit of the number: 1");
			}

			else
			{
				for (int j = 1; j <= itog_st; j++)
				{
					ans = x % 10;
					x = t * ans;
				}

				Console.Write("The last digit of the number: ");
				Console.Write(ans);
			}
		}

	}

	static int Main()
	{
		Console.Write("Task 1:");
		Console.Write("\n");
		Task1();
		Console.Write("Task 2:");
		Console.Write("\n");
		int @base;
		int exponent;
		int mod;
		Console.Write("Enter a: ");
		@base = int.Parse(ConsoleInput.ReadToWhiteSpace(true));
		Console.Write("Enter x: ");
		exponent = int.Parse(ConsoleInput.ReadToWhiteSpace(true));
		Console.Write("Enter p:");
		mod = int.Parse(ConsoleInput.ReadToWhiteSpace(true));
		Console.Write(Task2(@base, exponent, mod));
		Console.Write("\n");
		Console.Write("Task 3:");
		Console.Write("\n");
		Task3();
		Console.Write("Task 4:");
		Console.Write("\n");
		Task4();
		Console.Write("Task 5:");
		Console.Write("\n");
		Task5();
		Console.Write("Task 7:");
		Console.Write("\n");
		Task7();
		return 0;
	}
}