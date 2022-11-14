#include "Class_for_crypto_algorithm.h"

using namespace std;

int ost(int a, int x, int p) {
	int res = 1;
	for (int i = 0; i < x; i++) {
		res *= a;
		res %= p;
	}
	return res;
}

int main()
{
	SourseText soursetext;
	string num;
	string stext;

	cout << "Enter the source text: " << endl;
	//cin.ignore();
	getline(cin, stext);

	system("cls");
	cout << "Text:\n" << stext << endl;

	soursetext.SetSourseElement(stext);

	cout << "Transform text: " << endl;
	soursetext.GetSourseText();

	cout << endl;
	system("pause");
	

	
	

	while (true)
	{
		system("cls");
		cout << "1.RSA \n" << "2.Diffie-Hellman \n" << "3.ElGamal \n" << "4.Shamir \n" << "5.Exit" << endl;

		cout << "Choose an encryption algorithm:" << endl;
			cin >> num;
		if (num == "1")
		{
			EncryptRSA(soursetext.GetTextForEncrypt());
		}
		else if (num == "2")
		{
			EncryptDH(soursetext.GetTextForEncrypt());
		}
		else if (num == "3")
		{
			EncryptElGam(soursetext.GetTextForEncrypt());
		}
		else if (num == "4")
		{
			EncryptSH(soursetext.GetTextForEncrypt());
		}
		else if (num == "5")
		{
			system("cls");
			return 0;
		}

		else {
			system("cls");
			cout << "Invalid number\n" << "Try again" << endl;
			system("pause");
		}
	}
}