#include "Class_for_crypto_algorithm.h"

using namespace std;

int DH::GetXkey()
{
	return xa;
}

void DH::SetYkey(const int t)
{
	ya = 1;
	for (int i = 0; i < (t - 1); i++)
	{
		ya = ya * g % p;
	}
	cout << Name << "'s Public Key: " << ya << endl;
}
void DH::SetXkey(const int t, const long int p_key)
{
	xa = 1;
	for (int i = 0; i < (t - 1); i++)
	{
		xa = xa * p_key % p;
	}
	cout << Name << "'s Private Key: " << xa << endl;
}

void EncryptDH(const vector <int>& stext)
{
	DH dha;
	DH dhb;

	system("cls");
	cout << "=========================Diffie-Hellman" << endl;

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

	system("pause");

}