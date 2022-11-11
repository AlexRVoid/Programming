#pragma once
#include <ctime>
#include <iostream>
#include <vector>
#include <windows.h>
#include <string>

using namespace std;

class RSA
{
public:
	
	int o_key; //Открытый ключ
	int Na;//p*q
	

	int Getq()
	{
		return q;
	}
	int Getp()
	{
		return p;
	}
	void Setq(const int& iq)
	{
		q = iq;
	}
	void Setp(const int& ip)
	{
		p = ip;
	}
	void GenOpenKey(int& n)
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
	void GenPrivateKey()// генерация закрытого ключа 
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

	void EncryptText(const vector <int>& stext)// шифровка текста
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
	

	void DecryptText()// дешифровка текста 
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
			cout << decrypttext[i] << endl;
		}
	}

	void GetEncryptText()
	{
		for (int i = 0; i < encrypttext.size(); i++)
		{
			cout << encrypttext[i] << " ";
		}
	}

	void GetDecryptText()
	{
		for (int i = 0; i < decrypttext.size(); i++)
		{
			cout << decrypttext[i] << " ";
		}
	}

private:
	int p_key;//Закрытый ключ 
	int p, q;// Простые числа по выбору пользователя 
	vector <int> encrypttext;
	vector <int> decrypttext;
};

class DH
{
public:
	int p,g;
	long int ya;
	string Name;

	int GetXkey()
	{
		return xa;
	}

	void SetYkey(const int t)
	{
		ya = 1;
		for (int i = 0; i < (t - 1); i++)
		{
			ya = ya * g % p;
		}
		cout << Name << "'s Public Key: " << ya << endl;
	}
	void SetXkey(const int t, const long int p_key)
	{
		xa = 1;
		for (int i = 0; i < (t - 1); i++)
		{
			xa = xa * p_key % p;
		}
		cout << Name << "'s Private Key: " << xa << endl;
	}

private:
	long int xa;
};

class SH
{
public:
	int p, x1, x2;

	SH(int a) {
		p = a; Ca = 0; Cb = 0; da = 0; db = 0, x1 = 0; x2 = 0;
	}



	const int GetCa() {
		return Ca;
	}

	const int GetCb() {
		return Cb;
	}

	void SetCa(const int& a) {
		Ca = a;
	}

	void SetCb(const int& b) {
		Cb = b;
	}

	const int Getda() {
		return da;
	}

	const int Getdb() {
		return db;
	}

	void Setda(const int& a) {
		da = a;
	}

	void Setdb(const int& b) {
		db = b;
	}

private:
	int Ca, Cb, da, db;
};

class ElGam
{
public:
	int p, g, y, k, decel;
	pair <int, int> encrel;
	vector <pair<int, int>> encrypttext;
	vector <int> decrypttext;

	ElGam(int a, int b, int d) {
		p = a; g = b; y = 1; p_key = d; decel = 1; k = 10;
	}

	int GetPKey()
	{
		return p_key;
	}

	void GenKey(int a, int x, int m)
	{
		y = 1;
		for (int i = 0; i < x; i++) {
			y *= a;
			y %= m;
		}
		cout << "y = " << y << endl;
	}

	void GetEncryptText()
	{
		for (int i = 0; i < encrypttext.size(); i++)
		{
			cout << encrypttext[i].first << " " << encrypttext[i].second << "  ";
		}
	}

	void GetDecryptText()
	{
		for (int i = 0; i < decrypttext.size(); i++)
		{
			cout << decrypttext[i] << " ";
		}
	}

private:
	int p_key;//x
};

class EG {
public:
	int p, g, k, Da, Db, e, r, m;

	EG(int a, int b, int c) {
		p = a; g = b; k = c, Ca = 0; Cb = 0; Da = 0; Db = 0; e = 0; r = 0; m = 0;
	}

	const int GetCa() {
		return Ca;
	}

	const int GetCb() {
		return Cb;
	}

	void SetCa(const int& a) {
		Ca = a;
	}

	void SetCb(const int& b) {
		Cb = b;
	}

private:
	int Ca, Cb;
};

class SourseText
{
public:
	vector <int> soursetext;
	void SetSourseElement(const string& stext)
	{
		for (int i = 0; i < stext.length(); i++) {
			int q = stext[i];
			soursetext.push_back(q);
		}
	}
	void GetSourseText()
	{
		for (int i = 0; i < soursetext.size(); i++)
		{
			cout << soursetext[i] << " ";
		}
	}
	vector <int> GetTextForEncrypt()
	{
		return soursetext;
	}
};

void EncryptRSA(const vector <int>& stext);
void EncryptDH(const vector <int>& stext);
void EncryptElGam(const vector <int>& stext);
void EncryptSH(const vector <int>& stext);
int ost(int a, int x, int m);
