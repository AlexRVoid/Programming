#include "Class_for_crypto_algorithm.h"

using namespace std;

int RSA::Getq()
{
	return q;
}

int RSA::Getp()
{
	return p;
}
void RSA::Setq(const int& iq)
{
	q = iq;
}
void RSA::Setp(const int& ip)
{
	p = ip;
}
void RSA::GenOpenKey(int& n)
{
	while (1)
	{
		o_key = n;
		if (o_key % ((p - 1) * (q - 1)) == 1)
		{
			o_key = n;
			break;
		}
		else {
			n--;
		}

	}
}
void RSA::GenPrivateKey()// генерация закрытого ключа 
{
	int k = 1;

	while (1)
	{
		k = k + ((p - 1) * (q - 1));

		if (k % o_key == 0 && k / o_key != 1)
		{
			p_key = (k / o_key);
			break;
		}
	}
	cout << "Private key: " << p_key << endl;
}

void RSA::EncryptText(const vector <int>& stext)// шифровка текста
{
	for (int i = 0; i < stext.size(); i++)
	{
		long int current, result;

		current = stext[i] - 97;
		result = 1;

		for (long int j = 0; j < o_key; j++)
		{
			result = result * current;
			result = result % Na;
		}

		encrypttext.push_back(result);
	}
}


void RSA::DecryptText()// дешифровка текста 
{

	for (int i = 0; i < encrypttext.size(); i++)
	{
		long int current, result;

		current = encrypttext[i];
		result = 1;

		for (long int j = 0; j < p_key; j++)
		{
			result = result * current;
			result = result % Na;
		}

		decrypttext.push_back(result + 97);
	}
}

void RSA::GetEncryptText()
{
	for (int i = 0; i < encrypttext.size(); i++)
	{
		cout << encrypttext[i] << " ";
	}
}

void RSA::GetDecryptText()
{
	for (int i = 0; i < decrypttext.size(); i++)
	{
		cout << decrypttext[i] << " ";
	}
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

	system("pause");
}