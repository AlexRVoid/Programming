import java.util.Scanner;
public class Лаба
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
		Scanner in = new Scanner(System.in);
		System.out.print("Enter the length:");
			a = in.nextInt();
		System.out.print("\nEnter the width:");
			b = in.nextInt();
		System.out.print("\nEnter the height:");
			c = in.nextInt();
		int V;
		int S;
		S = 2 * (a * b + b * c + a * c);
		System.out.print("S = ");
		System.out.print(S);
		System.out.print("\n");
		V = a * b * c;
		System.out.print("V = ");
		System.out.print(V);
		System.out.print("\n");
		in.close();
	}

	public static void Task2()
	{
		Scanner in = new Scanner(System.in);
		int n; //n - кол-во входящих чисел, s - кол-во подходящих чисел
		int s;
		s = 0;
		System.out.print("Enter the number of items in the selection: ");
		n = in.nextInt();;
		ArrayList<Integer> nums = new ArrayList<Integer>(n); //инициализация массива

		for (int i = 1; i <= n; i++)
		{
			nums.set(i, tangible.RandomNumbers.nextNumber() % 9999); //рандом значений
			System.out.print(nums.get(i));
			System.out.print(" ");
		}

		System.out.print("\n");

		for (int i = 1; i <= n; i++)
		{ //перебор значений
			int o = nums.get(i); //значение из вектора
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

		System.out.print(s);
		in.close();
	}

	public static void Task3()
	{
		Scanner in = new Scanner(System.in);
		while (true)
		{
			int num;
			System.out.print("Enter The number:");
			num = in.nextInt();;
			if (num >= 100 && num < 1000)
			{ // Провека, является ли число трёхзначным или нет
				if (num / 100 == num % 10) // Проверка, является ли число полиндромом
				{
					System.out.print("Yes");
					System.out.print("\n");
				}
				else
				{
					System.out.print("No");
					System.out.print("\n");
				}
			}
			else
			{
				System.out.print("No");
				System.out.print("\n");
			}
			num = 0;
			boolean res;
			System.out.print("Continue or not(1/0):");
			res = in.nextBoolean();
			if (res == false)
			{
				break;
			}
		}
		in.close();
	}


	public static int Main()
	{
		Scanner in = new Scanner(System.in);
		int task;
		System.out.print("Select a task:");
		task = in.nextInt();
		if (task == 1)
		{
			System.out.print("Task 1:");
			System.out.print("\n");
			Task1();
		}
		if (task == 2)
		{
			System.out.print("\nTask 2:");
			System.out.print("\n");
			Task2();
		}
		if (task == 3)
		{
			System.out.print("\nTask 3:");
			System.out.print("\n");
			Task3();
		}
		else
		{
			System.out.print("Invalid value");
		}
		in.close();
		return 0;
	}

}