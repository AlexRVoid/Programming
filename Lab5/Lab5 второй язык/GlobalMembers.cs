using System;
using System.Collections.Generic;

public static class GlobalMembers
{
	public static ostream operator << <T, T1>(ostream os, SortedDictionary<T, T1> rusreg)
	{
		foreach (var i in rusreg)
		{
			os << i.first << " " << i.second << "\n";
		}
		return os;
	}


	public static SortedDictionary<string, List<string>> set_name(string text, SortedDictionary<string, List<string>> trains)
	{
		string s;
		string n;
		List<string> v = new List<string>();
		int i = 0;
		while (text[i] != ' ')
		{ // ����� ��������� � ���������� �������
			n += text[i];
			i++;
		}
		for (i; i < text.Length + 1; i++)
		{
			if ((text[i] == ' ') || (text[i] == '\0'))
			{ // ���������� ���������
				v.Add(s);
				s = "";
				continue;
			}
			s += text[i];
		}
		v.Add(s);
		s = "";
		trains[n] = v;
		return new SortedDictionary<string, List<string>>(trains);
	}

	public static void printTown(SortedDictionary<string, List<string>> b, string town)
	{
		string trains;
		int k = 0;
		foreach (var i in b)
		{
			foreach (var j in i.second)
			{
				if ((town == j))
				{ //��������� ����� ������� ��������� ��� ���������
					if (trains == i.first)
					{
						continue;
					}
					trains = i.first;
					k = 1;
					Console.Write(i.first);
					Console.Write(" \n");
				}
			}
		}
		if (k == 0)
		{
			Console.Write("No one\n");
		}
	}

	public static void printTrains(SortedDictionary<string, List<string>> b, string trains)
	{
		string town;
		int k;
		k = 0;
		foreach (var i in b)
		{
			if (trains == i.first)
			{
				k = 1; // �������� ��������� �� ������ �������
				foreach (var j in i.second)
				{ // ��� �������� ����� ��� ������� ��������� ��� ���������
					if (j != "")
					{
						Console.Write(j);
						Console.Write("( ");
					}
					town = j;
					foreach (var h in b)
					{
						foreach (var z in h.second)
						{
							if (z == "")
							{
								continue;
							}
							if ((town == z) && (h != i))
							{ // ��������� �� ���� ����� ������� �������
								Console.Write(h.first);
								Console.Write(" ");
							}
						}
					}
					if (j != "")
					{
						Console.Write(") ");
					}
				}
				Console.Write("\n");
			}
		}
		if (k == 0)
		{
			Console.Write("Tram is absent\n");
		}
	}

	public static SortedDictionary<string, List<string>> get_name(SortedDictionary<string, List<string>> a)
	{
		foreach (var i in a)
		{
			Console.Write(i.first);
			Console.Write(" ");
			foreach (var j in i.second)
			{
				Console.Write(j);
				Console.Write(" ");
			}
			Console.Write("\n");
		}
		return new SortedDictionary<string, List<string>>(a);
	}

	public static void Task1()
	{

		SortedDictionary<string, List<string>> mtram = new SortedDictionary<string, List<string>>();
		while (true)
		{
			int s = 0;
			string text;
			string stop;
			string tram;
			bool f = true;
			while (f == true)
			{
				Console.Write("1.CREATE_TRAM");
				Console.Write("\n");
				Console.Write("2.TRAMS_IN_STOP");
				Console.Write("\n");
				Console.Write("3.STOPS_IN_TRAM");
				Console.Write("\n");
				Console.Write("4.TRAMS");
				Console.Write("\n");
				Console.Write("5.EXIT.");
				Console.Write("\n");
				s = int.Parse(ConsoleInput.ReadToWhiteSpace(true));
				switch (s)
				{
				case 1:
				{

					cin.ignore();
					text = Console.ReadLine();
					mtram = new SortedDictionary<string, List<string>>(set_name(text, new SortedDictionary<string, List<string>>(mtram)));
				}
				break;
				case 2:
				{
					Console.Write("What stop? ");
					stop = ConsoleInput.ReadToWhiteSpace(true);
					printTown(new SortedDictionary<string, List<string>>(mtram), stop);
				}
				break;
				case 3:
				{
					Console.Write("What tram? ");
					tram = ConsoleInput.ReadToWhiteSpace(true);
					printTrains(new SortedDictionary<string, List<string>>(mtram), tram);
				}
				break;
				case 4:
				{
					get_name(new SortedDictionary<string, List<string>>(mtram));
				}
				break;
				case 5:
				{
					f = false;
				}
//C++ TO C# CONVERTER TODO TASK: C# does not allow fall-through from a non-empty 'case':
				default:
				{
					Console.Write("Invalid comand");
					Console.Write("\n");
				}
				break;
				}
			}
		}
	}



	public static void Task2()
	{
		SortedDictionary<string, string> rusreg = new SortedDictionary<string, string>();
		SortedDictionary<string, string> iterator it;
		pair<string, string> p = new pair<string, string>();

			bool f = true;
			while (f == true)
			{
				Console.Write("1.Change");
				Console.Write("\n");
				Console.Write("2.Rename");
				Console.Write("\n");
				Console.Write("3.About");
				Console.Write("\n");
				Console.Write("4.All");
				Console.Write("\n");
				Console.Write("5.Exit");
				Console.Write("\n");
				int n;
				n = int.Parse(ConsoleInput.ReadToWhiteSpace(true));
				switch (n)
				{
				case 1:
				{
					Console.Write("Enter the name of the region: ");
						cin.ignore();
						p.first = Console.ReadLine();
					Console.Write("Enter the name of the administrative center: ");
						p.second = Console.ReadLine();
					it = rusreg.find(p.first);
					if (it != rusreg.end())
					{
						rusreg.Remove(it);
					}
					rusreg.insert(p);
				}
				break;
				case 2:
				{
					Console.Write("Enter the name of the region: ");
						cin.ignore();
						p.first = Console.ReadLine();
					it = rusreg.find(p.first);
					if (it == rusreg.end())
					{
						Console.Write("Incorrect");
						Console.Write("\n");
						break;
					}
					if (it != rusreg.end())
					{
						p.second = it.second;
						rusreg.Remove(it);
						Console.Write("Enter the new name of the region: ");
							cin.ignore();
							p.first = Console.ReadLine();
						rusreg.insert(p);
					}

				}
				break;
				case 3:
				{
					Console.Write("Enter the name of the region: ");
						cin.ignore();
						p.first = Console.ReadLine();
					it = rusreg.find(p.first);
					if (it == rusreg.end())
					{
						Console.Write("Incorrect");
						Console.Write("\n");
						break;
					}
					if (it != rusreg.end())
					{
						Console.Write(it.second);
					}
				}
				break;
				case 4:
				{
					Console.Write(rusreg);
				}
				break;
				case 5:
				{
					f = false;
				}
				break;
				default:
					break;
				}
			}

	}

	static int Main()
	{
		Console.Write("task 1:");
		Console.Write("\n");
		Task1();
		Console.Write("task 2:");
		Console.Write("\n");
		Task2();
	}
}