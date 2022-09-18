#include "shifri.h"
using namespace std;

int main()
{
	
	setlocale(LC_ALL, "Russian");
	bool pass = false;
	int password;
	
	while (pass == false)
	{
		cout << "Введите пароль:";
		cin >> password;
		if (password == 1111)
		{
			cout << "Верно" << endl;
			pass == true;
			break;
		}
		if (password != 1111)
		{
			cout << "Неверный пароль" << endl;
		}
	}
		if (pass = true)
		{
			cout << "Выберите номер шифра. \n";
			cout << "1.ШИФРУЮЩАЯ СИСТЕМА ТРИСЕМУСА(ТРИТЕМИЯ) \n";
			cout << "2.Шифр Вижинера \n";
			cout << "3.RSA \n";
			cout << "4.Тарабарская грамота \n";
			cout << "5.Шифр Вернама \n";
			cout << "6.Шифр Гронсфельда \n";

			string slova[] = { "Alexandr","Valeriy","family.","vvedenie", "privet","hello", "qwer rewq","kostume", "hinata","naruto", "!@##$%$%6","_)_)@#$!!" };
			srand(time(0));
			string s = slova[rand() % slova->length()];

			int n;
			while (true) {
				cin >> n;
				if (n == 0) break;
				switch (n) {
				case 1:
					trit(s);
					n = 0;
					break;
				case 2:
					vizh(s);
					n = 0;
					break;
				case 3:
					rsa(s);
					n = 0;
					break;
				case 4:
					tarab();
					n = 0;
					break;
				case 5:
					vern(s);
					n = 0;
					break;
				case 6:
					gronsf(s);
					n = 0;
					break;
				default:
					cout << "Неправильный номер шифра. Попробуйте ещё раз.\n";
					cout << "Для того чтобы завершить программу введите 0.\n";
					break;
				}
				if (n == 0) break;
			}
		}
}
