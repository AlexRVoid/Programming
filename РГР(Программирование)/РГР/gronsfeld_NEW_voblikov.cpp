#include "shifri.h"
using namespace std;

void gronsf(string s)
{
    SetConsoleCP(1251); // Установка кодовой страницы win-cp1251 в поток ввода
    setlocale(LC_ALL, "Russian");


    cout << "1. Ввести предложение самому\n";
    cout << "2. Случайное предложение\n";

    int w;
    cin.ignore();
    char str[1000] = {};
    char n[1000] = {};
    w = 0;
    while (true) {
        cin >> w;
        if (w == 1) {
            cout << "Введите слово \n";
            cin.ignore();
            cin.getline(str, 1000);
            cout << "\n";
            break;
        }
        else if (w == 2) {
            cout << "Ваше предложение " << s << endl;
            for (int i = 0; i != s.length(); i++) {
                str[i] = s[i];
            }
            break;
        }
        cout << "Вы можете написать либо 1, либо 2 \n";
    }

    cout << "1. Ввести ключ самому\n";
    cout << "2. Случайный ключ\n";
    while (true) {
        cin >> w;
        if (w == 1) {
            cout << "Введите ключ\n";
            cin.getline(n, 1000);
            break;
        }
        else if (w == 2) {
            cout << "Ваш ключ 103" << endl;
            n[0] = '1';
            n[1] = '0';
            n[2] = '3';
            break;
        }
        cout << "Вы можете написать либо 1, либо 2 \n";
    }
    int q = 0, n1[100];
    for (int i = 0; i != strlen(n); i++) {
        if (n[i] == '0') {
            n1[i] = 0;
            q++;
        }
        if (n[i] == '1') {
            n1[i] = 1;
            q++;
        }
        if (n[i] == '2') {
            n1[i] = 2;
            q++;
        }
        if (n[i] == '3') {
            n1[i] = 3;
            q++;
        }
        if (n[i] == '4') {
            n1[i] = 4;
            q++;
        }
        if (n[i] == '5') {
            n1[i] = 5;
            q++;
        }
        if (n[i] == '6') {
            n1[i] = 6;
            q++;
        }
        if (n[i] == '7') {
            n1[i] = 7;
            q++;
        }
        if (n[i] == '8') {
            n1[i] = 8;
            q++;
        }
        if (n[i] == '9') {
            n1[i] = 9;
            q++;
        }
    }


    if (q == 0) cout << "В ключе содержатся недопустимые символы, пожалуйста вводите только цифры.";
    else {
    for (int i = 0, o = 0; i != strlen(str); i++) {//зашифровка
        str[i] = str[i] + n1[o];
        if (o != strlen(n) - 1) o++;
        else o = 0;
    }

    cout << "зашифрованное сообщение  " << str << endl;
    ofstream fout;
    fout.open("Гронсфельд.txt");
    fout << "Encrypted text: " << s;


    for (int i = 0, o = 0; i != strlen(str); i++) {//дешифровка
        str[i] = str[i] - n1[o];
        if (o != strlen(n) - 1) o++;
        else o = 0;
    }


    cout << "расшифрованное сообщение  " << str << endl;



    fout << "\nDecrypted text: ";

    fout.close();
    cout << "ключ  " << n;
}

}