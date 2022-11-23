#include "Class_for_crypto_algorithm.h"

using namespace std;

int GenFirstKey(const int& p)
{
    int ca = rand() % (p - 1);
    while (true) {
        if (ca > 0) {
            if (ca % (p - 1) == 1) {
                return ca;
            }
            else ca -= 1;
        }else ca += (p - 1);
    }

}

int GenSecondKey(const int& ca, const int& p)
{
    int da = rand() % (p - 1);
    while (true) {
        if (da > 0) {
            if ((ca * da) % (p - 1) == 1)  
            {
                return da;
            }else da -= 1;
        }else da += (p - 1);
    }
}

void EncryptSH(const vector <int>& stext)
{
    system("cls");
    cout << "=========================Shamir" << endl;

    srand(time(NULL));
    int p = rand() % 10000 + 1000;
	SH ash{ p };
    SH bsh{ p };

    ash.SetCa(GenFirstKey(ash.p));
    ash.Setda(GenSecondKey(ash.GetCa(), ash.p));

    bsh.SetCa(GenFirstKey(bsh.p));
    bsh.Setda(GenSecondKey(bsh.GetCa(), bsh.p));

    cout << "p = " << ash.p << " Alice Ca = " << ash.GetCa() <<  " Alice Da = " << ash.Getda() << " Bob Cb = " << bsh.GetCa() << " Bob Db = " << bsh.Getda() << endl;

    cout << "Encrypto Alice = ";
    for (int i = 0; i < stext.size(); i++)
    {
        int x1;
        x1 = ost(stext[i], ash.GetCa(), ash.p);
        ash.x1.push_back(x1);
        cout << ash.x1[i] << " ";
    }

    cout << endl;

    cout << "Encrypto Bob = ";
    for (int i = 0; i < ash.x1.size(); i++)
    {
        int x1;
        x1 = ost(ash.x1[i], bsh.GetCa(), bsh.p);
        bsh.x1.push_back(x1);
        cout << bsh.x1[i] << " ";
    }

    cout << endl;

    cout << "Encrypto Alice = ";
    for (int i = 0; i < bsh.x1.size(); i++)
    {
        int x2;
        x2 = ost(bsh.x1[i], ash.Getda(), ash.p);
        ash.x2.push_back(x2);
        cout << ash.x2[i] << " ";
    }
    
    cout << endl;

    cout << "Decrypto Bob = ";
    for (int i = 0; i < ash.x2.size(); i++)
    {
        int x2;
        x2 = ost(ash.x2[i], bsh.Getda(), bsh.p);
        bsh.x2.push_back(x2);
        cout << bsh.x1[i] << " ";
    }
    system("pause");
}