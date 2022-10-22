#include "Class_for_crypto_algorithm.h"

using namespace std;

int main()
{
	SourseText soursetext;
	vector <int> sourcetext;
	int num;
	string stext;

	cout << "Enter the source text: " << endl;
	//cin.ignore();
	getline(cin, stext);

	cout << "Text:\n" << stext << endl;
	
	TransformText(stext);

	cout << "Transform text: " << endl;
	copy(soursetext.soursetext.begin(), soursetext.soursetext.end(), ostream_iterator<int>(cout, " "));

	cout << endl;
	system("pause");
	system("cls");

	cout << "Choose an encryption algorithm:" << endl;
	cin >> num;
	switch (num)
		case 1:
			EncryptRSA();

	
}