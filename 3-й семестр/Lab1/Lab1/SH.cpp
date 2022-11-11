#include "Class_for_crypto_algorithm.h"

using namespace std;

void EncryptSH(const vector <int>& stext)
{
	SH sr{ 23 };

    int text = 10;

    sr.SetCa(7);
    sr.SetCb(5);
    sr.Setda(19);
    sr.Setdb(9);

    cout << "\nShamir\n\n";
    cout << "text = " << text << ", p = " << sr.p << ", Ca = " << sr.GetCa() << ", Cb = " << sr.GetCb() << ", da = " << sr.Getda() << ", db = " << sr.Getdb() << endl << endl;

    sr.x1 = ost(text, sr.GetCa(), sr.p);
    cout << "Encrypto Alice = " << sr.x1 << endl;

    sr.x1 = ost(sr.x1, sr.GetCb(), sr.p);
    cout << "Encrypto Bob = " << sr.x1 << endl;

    sr.x1 = ost(sr.x1, sr.Getda(), sr.p);
    cout << "Encrypto Alice = " << sr.x1 << endl;

    sr.x1 = ost(sr.x1, sr.Getdb(), sr.p);
    cout << "Decrypto BOB = " << sr.x1 << endl << endl;

}