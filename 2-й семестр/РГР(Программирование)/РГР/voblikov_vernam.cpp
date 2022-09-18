
#include "shifri.h"
using namespace std;

void vern(string s)
{
	SetConsoleCP(1251); // Установка кодовой страницы win-cp1251 в поток ввода
	setlocale(LC_ALL, "Russian");
	int r = 0;
	char q[1000] = {}, key[1000]={};
	cout << "1. Ввести предложение самому\n";
	cout << "2. Случайное предложение\n";
	int n;
	cin.ignore();
	while (true) {
		cin >> n;


		if (n == 1) {
			cout << "Введите предложение\n";
			cin.ignore();
			cin.getline(q, 1000);
			cout << "\nВведите ключ (столько же символов сколько и в предложении).\n";
			cin.getline(key, 1000);
			break;
		}
		else if (n == 2) {
			cout << "Ваше предложение - " << s << "\n";
			for (int i = 0; i != s.length(); i++) {
				q[i] = s[i];
				srand(time(0));
				key[i] = 'a';
			}
			break;

		}
		cout << "Вы можете написать либо 1, либо 2 \n";
	}


	if (strlen(q) != strlen(key)) {
		cout << "Ошибка. Кол - во символов в слове не совпадает с кол-вом символов в ключе." << endl;
		r++;
	}
	if (r == 0){
		for (int i = 0; i != strlen(key); i++) {//шифровка
			q[i] = (q[i] ^ key[i])%2;
		}
		cout << "Зашифрованное сообщение   " << q << " \n";
		ofstream fout;
		fout.open("Верман.txt");
		fout << "Encrypted text: " << q;
		for (int i = 0; i != strlen(key); i++) {//дешифровка
			q[i] = q[i] ^ key[i];
		}
		cout << "Расшифрованное сообщение   " << q << " \n";


		fout << "\nDecrypted text: " << q;

		fout.close();
		cout << "ключ  * " << key << " *\n";
	}
}

