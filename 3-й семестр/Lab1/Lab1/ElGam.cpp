#include "Class_for_crypto_algorithm.h"

using namespace std;

void EncryptElGam(const vector <int>& stext)
{
	ElGam elgam(593, 123, 8);

	system("cls");

	elgam.GenKey();



	elgam.EncryptText(stext);
	cout << "Encrypto ";
	elgam.GetEncryptText();
	cout << endl;

	elgam.DecryptText();
	cout << "Decrypto ";
	elgam.GetDecryptText();
	cout << endl;
}
