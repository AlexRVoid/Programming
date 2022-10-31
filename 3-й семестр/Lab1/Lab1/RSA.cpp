#include "Class_for_crypto_algorithm.h"

using namespace std;


bool CheckingForSimplicity(const int& p, const int& q, const int& e)
{
	if (e % ((p - 1) * (q - 1)) == 1)
	{
		return true;
	}
	else return false;
}

void EncryptRSA(const vector <int>& stext)
{
	RSA rsa;

	system("cls");
	cout << "=========================RSA" << endl;
	int t;
	cout << "Select the number p: ";
	cin >> t;
	rsa.Setp(t);
	cout << "Select the number q: ";
	cin >> t;
	rsa.Setq(t);
	rsa.Na = rsa.Getp() * rsa.Getq();

	srand(time(NULL));
	int n = rand() % 10000 + 100;// Генерация экспоненты взаимнопростой с (p-1)*(q-1)

	rsa.GenOpenKey(n);
	cout << "Open key: " << rsa.o_key << endl;

	rsa.GenPrivateKey();


	rsa.EncryptText(stext);
	cout << "Your encrypted text: " << endl;
	rsa.GetEncryptText();


	cout << endl;


	rsa.DecryptText();
	cout << "Your decrypted text: " << endl;
	rsa.GetDecryptText();
}