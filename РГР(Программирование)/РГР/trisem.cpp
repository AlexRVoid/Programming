#include "shifri.h"

#define row 5
#define column 19

using namespace std;

string Key_f() {                 //функция очистки ключа
    string key_r;

    cout << "1. Ввести ключ самому\n";
    cout << "2. Случайный ключ\n";
    int n;
    cin.ignore();
    while (true) {
        cin >> n;

        if (n == 1) {
            cout << "Enter the key: ";
            cin.ignore();
            getline(cin, key_r);
            break;
        }
        else if (n == 2) {
            key_r = "key";
            break;
        }
        cout << "Вы можете написать либо 1, либо 2 \n";
    }
    for (int i = 0; i < key_r.length(); i++) {
        for (int j = i + 1; j < key_r.length(); ) {
            if (key_r[i] == key_r[j]) {          //если при переборе символы равны, то стираются все правые копии
                key_r.erase(j, 1);
            }
            else {
                j++;
            }
        }
    }
    return key_r;
}




void Cryptotable(string key, string s) {                                                                //заполнение матрицы
    char table[row][column];
    int c;
    for (c = 0; c < key.length(); c++) {
        table[c / column][c % column] = key[c];                                             //интеграция ключа с учётом его размера в матрицу
    }
    string asc = " !\"#$%&'()*+,-./0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ[\\]^_`abcdefghijklmnopqrstuvwxyz{|}~";        //ASCII 
    for (int i = 0; i < asc.length(); i++) {
        int k = 0;                                                                            //переменная-индикатор равенства символов
        for (int j = 0; j < key.length(); j++) {
            if (asc[i] == key[j]) {
                k++;
                break;
            }
        }
        if (k == 0) {
            table[c / column][c % column] = asc[i];
            c++;
        }
    }


    string text;

    cout << "1. Ввести предложение самому\n";
    cout << "2. Случайное предложение\n";
    int n;
    cin >> n;
    if (n == 1) {
        cout << "Enter the text:";
        cin.ignore();
        getline(cin, text);
    }
    else if (n==2) text = s;

    vector <int> newtext;
    for (int i = 0; i < text.length(); i++) {
        newtext.push_back(text[i]);
    }
    vector <char> encrypt;
    int q;
    for (int t = 0; t < newtext.size(); t++)
    {
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < column; j++)
            {
                if (table[i][j] == text[t])
                {
                    if (i != (row - 1))
                    {
                        q = table[i + 1][j];
                        encrypt.push_back(q);
                    }
                    else
                    {
                        q = table[0][j];
                        encrypt.push_back(q);
                    }
                    break;
                }
            }
        }
    }
    cout << "\n Encrypted text: ";

    copy(encrypt.begin(), encrypt.end(), ostream_iterator<char>(cout));

    vector <char> decrypt;
    for (int t = 0; t < encrypt.size(); t++)
    {
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < column; j++)
            {
                if (table[i][j] == encrypt[t])
                {
                    if (i != 0)
                    {
                        q = table[i - 1][j];
                        decrypt.push_back(q);
                    }
                    else
                    {
                        q = table[4][j];
                        decrypt.push_back(q);
                    }
                    break;
                }
            }
        }
    }
    cout << "\n Decrypted text: ";

    copy(decrypt.begin(), decrypt.end(), ostream_iterator<char>(cout));
    ofstream fout;
    fout.open("Трисемус.txt");
    fout << "Encrypted text: ";
    for (int i = 0; i < encrypt.size(); i++)
    {
        fout << encrypt[i];
    }
    fout << "\nDecrypted text: ";
    for (int i = 0; i < decrypt.size(); i++)
    {
        fout << decrypt[i];
    }
    fout.close();
}


int trit(string s)
{
    Cryptotable(Key_f(),s);

    return 0;
}