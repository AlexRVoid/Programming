#include "Class_for_crypto_algorithm.h"

using namespace std;

int ost(int a, int x, int m) {
    int res = 1;
    for (int i = 0; i < x; i++) {
        res *= a;
        res %= m;
    }
    return res;
}

void EncryptElGam(const vector <int>& stext)
{
	ElGam elgam(593, 123, 8);

	system("cls");

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

	/*elgam.EncryptText(stext);*/
	cout << "Encrypto ";
	elgam.GetEncryptText();
	cout << endl;

	/*elgam.DecryptText();*/
	cout << "Decrypto ";
	elgam.GetDecryptText();
	cout << endl;

    //EG eg{ 593, 123, 10 };//p,g,k
    //int text = 122;

    //eg.SetCa(4);
    //eg.SetCb(8);

    //eg.Da = ost(eg.g, eg.GetCa(), eg.p);
    //eg.Db = ost(eg.g, eg.GetCb(), eg.p);

    //eg.r = ost(eg.g, eg.k, eg.p);
    //eg.e = ost(eg.Db, eg.k, eg.p);
    //eg.e = (text * eg.e) % eg.p;

    //eg.m = ost(eg.r, eg.p - 1 - eg.GetCb(), eg.p);
    //eg.m = eg.m * eg.e % eg.p;

    //cout << "\nElGamal\n\n";
    //cout << "text = " << text << ", p = " << eg.p << ", g = " << eg.g << ", k = " << eg.k << ", Ca = " << eg.GetCa() << ", Cb = " << eg.GetCb() << ", da = " << eg.Da << ", db = " << eg.Db << endl << endl;
    //cout << "Encrypto " << eg.e << ", " << eg.r << endl;
    //cout << "Decrypto " << eg.m << endl << endl;
}


