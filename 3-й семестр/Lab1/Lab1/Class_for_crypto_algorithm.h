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
	
	int n; //Открытый ключ
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

private:
	int d;//Закрытый ключ 
	int p, q;// Простые числа по выбору пользователя 
};

class DH
{
public:
	int p;
	int g;
	int ya;
	int yb;
	int Getxa()
	{
		return xa;
	}
	int Getxb()
	{
		return xb;
	}
	void Setxa(int t)
	{
		xa = t;
	}
	void Setxb(int t)
	{
		xb = t;
	}
private:
	int xa, xb;
};

class SH
{
public:

private:

};

class ElGam
{
public:

private:

};

class DecryptRSA
{
public:

private:

};

class DecryptDH
{
public:

private:

};

class DecryptSH
{
public:

private:

};

class DecryptElGam
{
public:
	vector <int> decrypttext;
private:

};

class EncryptionText
{
public:
	vector <int> encrypttext;
private:

};

class DecryptionText
{
public:
	vector <int> decrypttext;
private:

};

class SourseText
{
public:
	vector <int> soursetext;
private:
	
};

void EncryptRSA();

void TransformText(const string& stext);