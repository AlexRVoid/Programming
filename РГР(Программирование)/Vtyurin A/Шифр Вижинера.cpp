#include <ctime>
#include <string>
#include <iostream>
#include <conio.h>

using namespace std;

int main()
{
    string word, key, D = "";
    string alphabet = "abcdefghijklmnopqrstuvwxyz"; //наш алфавит
    setlocale(LC_ALL, "Rus");
    cout << "Введите слово: ";
    cin >> word;
    cout << "Введите ключ: ";
    cin >>key;
    int* F = new int[word.size()];
    int* G = new int[word.size()];
    int c = key.size(); //делаем замену переменных для удобства
    int b = word.size();
    //Первое условие. Если длина вводимого слова больше, либо равна длине ключа
    if (b >= c)
    {
        for (int i = 0; i < (b / c); i++)
        {
            D = D + key; //Записываем целое количество ключа. Растягивая ключ по длине слова.
        }
        for (int j = 0; j < (b % c); j++)
        {
            D = D + key[j];
        }
    }
    else  //Иначе если ключ длиннее слова, укорачиваем ключ до длины слова.
    {
        for (int s = 0; s < b; s++)
        {
            D = D + word[s];
        }
    }
    for (int k = 0; k < b; k++)
    {
        for (int n = 0; n < 26; n++)
        {
            if (word[k] == alphabet[n])
            {
                F[k] = n;
            }

            if (D[k] == alphabet[n])
            {
                G[k] = n;
            } //Здесь мы уже начинаем шифровать. Смысл заключается втом, что мы ищем номер буквы во вводимом ключе и номере, а после чего записываем их в массив

        }
    }

    int e = 0; //Для суммы номеров символов. Чтобы при достижении 26 буквы, программа шла по кругу, начиная с первого номера
    for (int u = 0; u < b; u++)
    {
        e = ((F[u] + G[u]) % 26);
        word[u] = alphabet[e];
    }

    cout << "Зашифрованное слово: " << word << endl;


    _getch();
    return 0;

}
