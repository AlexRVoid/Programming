

#include "shifri.h"
using namespace std;


void tarab() {
    SetConsoleCP(1251); // Установка кодовой страницы win-cp1251 в поток ввода
    SetConsoleOutputCP(1251);// Установка кодовой страницы win - cp1251 в поток вывода




    string slova[] = { "Александр","Валерий","семья.","введение", "подъем","блок", "отцы и дети","костюм?", "работа, шлем","улица", "дома","фонарь" };
    srand(time(0));
    string s = slova[rand() % slova->length()];


    cout << "1. Ввести предложение самому\n";
    cout << "2. Случайное предложение\n";
    int n;
    cin.ignore();
    char str[1000]={};
    while (true) {
        cin >> n;
        if (n == 1) {
            cout << "\nВведите предложение на русском\n";
            cin.ignore();
            cin.getline(str, 1000);
            break;
        }
        else if (n == 2) {
            cout << "Ваше предложение - " << s << "\n";
            for (int i = 0; i != s.length(); i++) {
                str[i] = s[i];
            }
            break;
        }
        cout << "Вы можете написать либо 1, либо 2 \n";
    }
    
    int q = 0;
    for (int i = 0; i < strlen(str); i++) {
        char a = 'а';
        char b = 'А';
        q = 0;
        for (int j = 0; j < 33; j++) {
            if (str[i] == a) {
                q++;
                break;
            }
            if (str[i] == 'ё') {
                q++;
                break;
            }
            if (str[i] == 'Ё') {
                q++;
                break;
            }
            if (str[i] == b) {
                q++;
                break;
            }
            if (str[i] == ' ') {
                q++;
                break;
            }
            a++;
            b++;
        }
        if (q == 0) {
            cout << "Ошибка. В предложении имеется не только русские буквы.\n";
            break;
        }


    }
    if (q != 0) {
        for (int i = 0; i < strlen(str); i++) {
            if (str[i] == 'Б') {
                str[i] = 'Щ';
            }
            else if (str[i] == 'Щ')
                str[i] = 'Б';

            if (str[i] == 'В')
                str[i] = 'Ш';
            else if (str[i] == 'Ш')
                str[i] = 'В';

            if (str[i] == 'Г')
                str[i] = 'Ч';
            else if (str[i] == 'Ч')
                str[i] = 'Г';

            if (str[i] == 'Д')
                str[i] = 'Ц';
            else if (str[i] == 'Ц')
                str[i] = 'Д';

            if (str[i] == 'Ж')
                str[i] = 'Х';
            else if (str[i] == 'Х')
                str[i] = 'Ж';

            if (str[i] == 'З') {
                str[i] = 'Ф';
            }
            else {
                if (str[i] == 'Ф')
                    str[i] = 'З';
            }

            if (str[i] == 'К')
                str[i] = 'Т';
            else if (str[i] == 'Т')
                str[i] = 'К';

            if (str[i] == 'Л')
                str[i] = 'С';
            else if (str[i] == 'С')
                str[i] = 'Л';

            if (str[i] == 'М')
                str[i] = 'Р';
            else if (str[i] == 'Р')
                str[i] = 'М';

            if (str[i] == 'Н')
                str[i] = 'П';
            else if (str[i] == 'П')
                str[i] = 'Н';

        }
        for (int i = 0; i < strlen(str); i++) {
            if (str[i] == 'б') {
                str[i] = 'щ';
            }
            else if (str[i] == 'щ')
                str[i] = 'б';

            if (str[i] == 'в')
                str[i] = 'ш';
            else if (str[i] == 'ш')
                str[i] = 'в';

            if (str[i] == 'г')
                str[i] = 'ч';
            else if (str[i] == 'ч')
                str[i] = 'г';

            if (str[i] == 'д')
                str[i] = 'ц';
            else if (str[i] == 'ц')
                str[i] = 'д';

            if (str[i] == 'ж')
                str[i] = 'х';
            else if (str[i] == 'х')
                str[i] = 'ж';

            if (str[i] == 'з') {
                str[i] = 'ф';
            }
            else {
                if (str[i] == 'ф')
                    str[i] = 'з';
            }

            if (str[i] == 'к')
                str[i] = 'т';
            else if (str[i] == 'т')
                str[i] = 'к';

            if (str[i] == 'л')
                str[i] = 'с';
            else if (str[i] == 'с')
                str[i] = 'л';

            if (str[i] == 'м')
                str[i] = 'р';
            else if (str[i] == 'р')
                str[i] = 'м';

            if (str[i] == 'н')
                str[i] = 'п';
            else if (str[i] == 'п')
                str[i] = 'н';

        }
        cout << "Шифрованное сообщение  " << str;
        ofstream fout;
        fout.open("Тарабарская грамота.txt");
        fout << "Encrypted text: " << str;

        for (int i = 0; i < strlen(str); i++) {
            if (str[i] == 'Б') {
                str[i] = 'Щ';
            }
            else if (str[i] == 'Щ')
                str[i] = 'Б';

            if (str[i] == 'В')
                str[i] = 'Ш';
            else if (str[i] == 'Ш')
                str[i] = 'В';

            if (str[i] == 'Г')
                str[i] = 'Ч';
            else if (str[i] == 'Ч')
                str[i] = 'Г';

            if (str[i] == 'Д')
                str[i] = 'Ц';
            else if (str[i] == 'Ц')
                str[i] = 'Д';

            if (str[i] == 'Ж')
                str[i] = 'Х';
            else if (str[i] == 'Х')
                str[i] = 'Ж';

            if (str[i] == 'З') {
                str[i] = 'Ф';
            }
            else {
                if (str[i] == 'Ф')
                    str[i] = 'З';
            }

            if (str[i] == 'К')
                str[i] = 'Т';
            else if (str[i] == 'Т')
                str[i] = 'К';

            if (str[i] == 'Л')
                str[i] = 'С';
            else if (str[i] == 'С')
                str[i] = 'Л';

            if (str[i] == 'М')
                str[i] = 'Р';
            else if (str[i] == 'Р')
                str[i] = 'М';

            if (str[i] == 'Н')
                str[i] = 'П';
            else if (str[i] == 'П')
                str[i] = 'Н';

        }
        for (int i = 0; i < strlen(str); i++) {
            if (str[i] == 'б') {
                str[i] = 'щ';
            }
            else if (str[i] == 'щ')
                str[i] = 'б';

            if (str[i] == 'в')
                str[i] = 'ш';
            else if (str[i] == 'ш')
                str[i] = 'в';

            if (str[i] == 'г')
                str[i] = 'ч';
            else if (str[i] == 'ч')
                str[i] = 'г';

            if (str[i] == 'д')
                str[i] = 'ц';
            else if (str[i] == 'ц')
                str[i] = 'д';

            if (str[i] == 'ж')
                str[i] = 'х';
            else if (str[i] == 'х')
                str[i] = 'ж';

            if (str[i] == 'з') {
                str[i] = 'ф';
            }
            else {
                if (str[i] == 'ф')
                    str[i] = 'з';
            }

            if (str[i] == 'к')
                str[i] = 'т';
            else if (str[i] == 'т')
                str[i] = 'к';

            if (str[i] == 'л')
                str[i] = 'с';
            else if (str[i] == 'с')
                str[i] = 'л';

            if (str[i] == 'м')
                str[i] = 'р';
            else if (str[i] == 'р')
                str[i] = 'м';

            if (str[i] == 'н')
                str[i] = 'п';
            else if (str[i] == 'п')
                str[i] = 'н';

        }
        cout << "\n" << "Расшифрованное сообщение  " << str;



        fout << "\nDecrypted text: " << str;

        fout.close();
    }

}