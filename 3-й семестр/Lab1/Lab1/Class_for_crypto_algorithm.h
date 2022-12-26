#pragma once
#include <ctime>
#include <iostream>
#include <vector>
#include <windows.h>
#include <string>
#include <math.h>

using namespace std;

class RSA
{
public:
	
	int o_key; //Открытый ключ
	int Na;//p*q
	
	int Getq();
	int Getp();
	void Setq(const int& iq);
	void Setp(const int& ip);
	void GenOpenKey(int& n);
	void GenPrivateKey();// генерация закрытого ключа 
	void EncryptText(const vector <int>& stext);// шифровка текста
	void DecryptText();// дешифровка текста 
	void GetEncryptText();
	void GetDecryptText();

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

	int GetXkey();
	void SetYkey(const int t);
	void SetXkey(const int t, const long int p_key);

private:
	long int xa;
};

class SH
{
public:
	int p;
	vector <int> x1;
	vector <int> x2;


	SH(int a) {
		p = a; Ca = 0; da = 0;
	}



	int GetCa();


	void SetCa(const int& a);

	int Getda();


	void Setda(const int& a);


private:
	int Ca, da;
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

	int GetPKey();


	void GenKey(int a, int x, int m);

	void GetEncryptText();

	void GetDecryptText();

private:
	int p_key;//x
};


class SourseText
{
public:
	vector <int> soursetext;
	void SetSourseElement(const string& stext);
	void GetSourseText();
	vector <int> GetTextForEncrypt();
};

void EncryptRSA(const vector <int>& stext);
void EncryptDH(const vector <int>& stext);
void EncryptElGam(const vector <int>& stext);
void EncryptSH(const vector <int>& stext);
int ost(int a, int x, int m);
