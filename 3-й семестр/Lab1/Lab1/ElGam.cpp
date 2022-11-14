#include "Class_for_crypto_algorithm.h"

using namespace std;



void EncryptElGam(const vector <int>& stext)
{
	ElGam elgam(593, 123, 8);

	system("cls");

    cout << "=========================ElGamal" << endl;

	elgam.GenKey(elgam.g, elgam.GetPKey(), elgam.p);

    for (int i = 0; i < stext.size(); i++) //encrypt
    {
        elgam.encrel.first = ost(elgam.g, elgam.k, elgam.p);
        elgam.encrel.second = ost(elgam.y, elgam.k, elgam.p);
        elgam.encrel.second = (elgam.encrel.second * stext[i]) % elgam.p;

        elgam.encrypttext.push_back(elgam.encrel);
    }

    for (int i = 0; i < elgam.encrypttext.size(); i++) //decrypt
    {
        elgam.decel = ost(elgam.encrypttext[i].first, elgam.p - 1 - elgam.GetPKey(), elgam.p);
        elgam.decel = elgam.decel * elgam.encrypttext[i].second % elgam.p;
        
        elgam.decrypttext.push_back(elgam.decel);
    }

	cout << "Encrypto ";
	elgam.GetEncryptText();
	cout << endl;

	cout << "Decrypto ";
	elgam.GetDecryptText();
	cout << endl;

    system("pause");
}


