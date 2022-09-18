
#include "shifri.h"
using namespace std;

ostream& operator<< (ostream& os, const vector <int>& encrypted_text)
{
	for (int i = 0; i < encrypted_text.size(); i++) {
		os << encrypted_text[i] << "";
	}
	return os;
}

vector <int> encryption(string source_text, int o_key1, int o_key2) { //функия 
	int dcrC;
	char q;
	vector <int> encrResult;
	vector <int> enc_text;
	int s;
	for (int i = 0; i < source_text.length(); i++) {
		q = source_text[i];
		int dcrC = q; //приведение к целочисленному типу данных 
		encrResult.push_back(dcrC); //добавляем его в вектор 
	}


	for (int i = 0; i < encrResult.size(); i++) {
		s = encrResult[i];
		for (int k = 0; k < (o_key1 - 1); k++)
		{
			s = s * encrResult[i] % o_key2;
		}
		enc_text.push_back(s);
	}
	return enc_text;
}

string decryption(vector <int> source_text, int d, int n) {
	string decrResult;
	int s;
	char q;
	for (int i = 0; i < source_text.size(); i++) {
		s = source_text[i];
		for (int k = 0; k < d - 1; k++) {
			s = s * source_text[i] % n;
		}
		q = s;
		decrResult += q;
	}
	return decrResult;
}

void rsa(string s) {
	int static open_key1 = 5;
	int open_key2 = 323;
	int static close_key1 = 173;
	int close_key2 = 323;

	string source_text;
	string decrypted_text;
	cout << "1. Ввести предложение самому\n";
	cout << "2. Случайное предложение\n";
	int n;
	cin.ignore();
	while (true) {
		cin >> n;
		if (n == 1) {
			cout << "Enter the text: " << endl;
			cin.ignore();
			getline(cin, source_text);
			break;
		}
		else if (n == 2) {
			source_text = s;
			break;
		}
		cout << "Вы можете написать либо 1, либо 2 \n";
	}

	vector <int> encrypted_text(encryption(source_text, open_key1, open_key2)); //результат функции 
	decrypted_text = decryption(encrypted_text, close_key1, close_key2);

	cout << "Encrypted text: ";
	cout << encrypted_text;

	cout << endl << "Decrypt text: ";
	cout << decrypted_text << endl;
	ofstream fout;
	fout.open("RSA.txt");
	fout << "Encrypted text: ";
	for (int i = 0; i < encrypted_text.size(); i++)
	{
		fout << encrypted_text[i];
	}
	fout << "\nDecrypted text: " << decrypted_text;

	fout.close();
}
