#include <math.h>
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

void EncryptRSA()
{
	SourseText soursetext;
	EncryptionText ersa;
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
	int n = rand() + 1000;// Генерация экспоненты взаимнопростой с (p-1)*(q-1)

	while (1)
	{
		if (CheckingForSimplicity(rsa.Getp(), rsa.Getq(), n) == true)
		{
			rsa.n = n;
			break;
		}
		else {
			n--;
		}

	}
	cout << "e = " << rsa.n;

	for (auto i : soursetext.soursetext)
	{
		int enc = soursetext.soursetext[i];
		for (int k = 0; k < (rsa.n - 1); k++)
		{
			enc *= soursetext.soursetext[i]  % rsa.Na;
		}
		ersa.encrypttext.push_back(enc);
	}
	copy(ersa.encrypttext.begin(), ersa.encrypttext.end(), ostream_iterator<int>(cout, " "));
}