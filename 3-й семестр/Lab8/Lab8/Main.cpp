#include "WithoutThr.h"
#include "Ring.h"
#include "Star.h"

int main() 
{
	while (true)
	{
		system("cls");
		cout << "What to do?" << endl << "1)Multithreading" << endl << "2)Single-threaded" << endl << "3)Exit" << endl;
		int choice;
		cin >> choice;
		if (cin.fail())
		{
			exit(0);
		}
		else if (choice == 1)
		{
			system("cls");
			cout << "What topology should I perform?" << endl << "1)Ring" << endl << "2)Star" << endl << "3)Exit" << endl;
			int topology;
			cin >> topology;

			if (cin.fail())
			{
				exit(0);
			}
			else if (topology == 1)
			{
				system("cls");
				SellRing sell;
				sell.ring();
			}
			else if (topology == 2)
			{
				system("cls");
				SellStar sell;
				sell.star();
			}
			else continue;
		}
		else if (choice == 2)
		{
			system("cls");
			Sell sell;
			sell.withoutThr();
		}
		else if (choice == 3)
		{
			exit(0);
		}
		else continue;
	}
}