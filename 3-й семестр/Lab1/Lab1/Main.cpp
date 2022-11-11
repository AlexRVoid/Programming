#include "Class_for_crypto_algorithm.h"

using namespace std;

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
	system("cls");

	cout << "Choose an encryption algorithm:" << endl;
	cin >> num;
	if (num == "1")
	{
		EncryptRSA(soursetext.GetTextForEncrypt());
	}
	if (num == "2")
	{
		EncryptDH(soursetext.GetTextForEncrypt());
	}
	if (num == "3")
	{
		EncryptElGam(soursetext.GetTextForEncrypt());
	}
	if (num == "4")
	{
		EncryptSH(soursetext.GetTextForEncrypt());
	}
}