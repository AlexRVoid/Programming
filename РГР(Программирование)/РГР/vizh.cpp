
#include "shifri.h"
using namespace std;

vector <char> Encryption(const string text, const string key)
{
	string ascii = "~!@#$%^&*()_+QWERTYUIOP{}|ASDFGHJKL:ZXCVBNM<>?`1234567890-=qwertyuiop[]asdfghjkl;'zxcvbnm,./ ";
	char q;
	int alph;
	vector <int> newtext;
	vector <int> newkey;
	vector <char> newascii;
	for (int i = 0; i < ascii.length(); i++)
	{
		newascii.push_back(ascii[i]);
	}
	for (int i = 0; i < text.length(); i++) {
		q = text[i];
		for (int j = 0; i < newascii.size(); j++)
		{
			if (q == newascii[j])
			{
				alph = j;
				break;
			}
		}
		newtext.push_back(alph);
	}
	for (int i = 0, j = 0; i < text.length(); ++i, ++j) {
		if (j == key.length()) {
			j = 0;
		}
		q = key[j];
		for (int k = 0; i < newascii.size(); k++)
		{
			if (q == newascii[k])
			{
				alph = k;
				break;
			}
		}

		newkey.push_back(alph);
	}
	copy(newtext.begin(), newtext.end(), ostream_iterator<int>(cout, " "));
	cout << endl;
	copy(newkey.begin(), newkey.end(), ostream_iterator<int>(cout, " "));

	vector <char> result;
	int c;
	int m;
	for (int i = 0; i < newtext.size(); i++)
	{
		c = (newtext[i] + newkey[i]);
		if (c > 93)
		{
			m = c - 93;
			alph = ascii[m];
			result.push_back(alph);
		}
		if (c <= 93)
		{
			alph = ascii[c];
			result.push_back(alph);
		}
	}
	cout << endl;
	copy(result.begin(), result.end(), ostream_iterator<char>(cout));
	cout << endl;
	return result;
}

vector <char> Decryption(const vector <char> encrypttext, const string key)
{
	string ascii = "~!@#$%^&*()_+QWERTYUIOP{}|ASDFGHJKL:ZXCVBNM<>?`1234567890-=qwertyuiop[]asdfghjkl;'zxcvbnm,./ ";
	char q;
	int alph;
	vector <int> newkey;
	vector <int> newtext;
	vector <char> newascii;

	for (int i = 0; i < ascii.length(); i++)
	{
		newascii.push_back(ascii[i]);
	}
	cout << newascii.size() << " ascii: ";
	copy(newascii.begin(), newascii.end(), ostream_iterator<char>(cout, " "));

	for (int i = 0; i < encrypttext.size(); i++) {
		q = encrypttext[i];
		for (int j = 0; i < newascii.size(); j++)
		{
			if (q == newascii[j])
			{
				alph = j;
				break;
			}
		}
		newtext.push_back(alph);
	}
	for (int i = 0, j = 0; i < encrypttext.size(); ++i, ++j) {
		if (j == key.length()) {
			j = 0;
		}
		q = key[j];
		for (int k = 0; i < newascii.size(); k++)
		{
			if (q == newascii[k])
			{
				alph = k;
				break;
			}
		}

		newkey.push_back(alph);
	}
	vector <char> result;
	int c;

	for (int i = 0; i < encrypttext.size(); i++)
	{
		c = (newtext[i] + 93 - newkey[i]);

		alph = newascii[c];
		result.push_back(alph);
	}
	cout << endl;
	copy(result.begin(), result.end(), ostream_iterator<char>(cout));
	return result;
}

void vizh(string s)
{
	cout << "1. Ввести предложение самому\n";
	cout << "2. Случайное предложение\n";
	int n;
	cin.ignore();
	string text;
	while (true) {
		cin >> n;
		if (n == 1) {
			cout << "Enter the text:";
			getline(cin, text);
			break;
		}
		else if (n == 2) {
			text = s;
			break;
		}
		cout << "Вы можете написать либо 1, либо 2 \n";
	}
	string key = "nstu";
	vector <char> encrypttext = Encryption(text, key);
	vector <char> decrypttext = Decryption(encrypttext, key);

	ofstream fout;
	fout.open("Вижинер.txt");
	fout << "Encrypted text: ";
	for (int i = 0; i < encrypttext.size(); i++)
	{
		fout << encrypttext[i];
	}
	fout << "\nDecrypted text: ";
	for (int i = 0; i < decrypttext.size(); i++)
	{
		fout << decrypttext[i];
	}
	fout.close();



}