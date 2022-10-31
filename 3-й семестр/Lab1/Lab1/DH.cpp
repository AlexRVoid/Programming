#include "Class_for_crypto_algorithm.h"

using namespace std;

void EncryptDH(const vector <int>& stext)
{
	DH dha;
	DH dhb;

	string choice;

	srand(time(NULL));
	int g = rand() % 10000 + 100;
	
	int p = rand() % 10000 + 100;

	dha.Name = "Alice";
	dhb.Name = "Bob";
	
	while (1)
	{
		cout << "Enter numbers manually or automatically? (m / a)" << endl;
		cin >> choice;
		if (choice == "m")
		{
			cout << "Enter g: ";
				cin >> dha.g;
				dhb.g = dha.g;
			cout << "Enter p: ";
				cin >> dha.p;
				dhb.p = dha.p;
			cout << "Your numbers are: (g, p)\n" << g << p << endl;
			break;
		}
		else if(choice == "a")
		{
			dha.g = g;
			dhb.g = dha.g;
			dha.p = p;
			dhb.p = dha.p;
			cout << "Your numbers are: (g, p)\n" << g << ", " << p << endl;
			break;
		}
		else {
			system("cls");
			cout << "Incorrect data, try again" << endl;
		}
	}

	int a, b;
	cout << "Come up with a secret number for Alice" << endl;
		cin >> a;
	dha.SetYkey(a);

	cout << "Come up with a secret number for Bob" << endl;
	cin >> b;
	dhb.SetYkey(b);

	dha.SetXkey(a, dhb.ya);

	dhb.SetXkey(b, dha.ya);

}