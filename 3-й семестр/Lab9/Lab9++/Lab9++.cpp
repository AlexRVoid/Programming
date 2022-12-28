#include "Fraction.h"
#include "IError.h"
using namespace std;

int main()
{
	try {
		int choice;
		cout << "What task to complete(PartI - 1, Exit - 2): ";
		cin >> choice;

		if (choice == 1)
		{
			PartI();
		}
		else if (choice == 2)
		{
			exit(0);
		}
	}
	catch (IncorrectInput& e) {
		e.print();
		main();
	}
}
