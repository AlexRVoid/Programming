#include <ctime>
#include <cstdlib>
#include <iostream>
#include <vector>
#include "Fraction.h"

using namespace std;


class FunnyGame {
public:
	vector < vector < bool >> matrica;

	FunnyGame(int n) {
		matrica = vector < vector < bool >>(n, vector<bool>(n, false));
		int stroka, stolbec;
		for (int i = 0; i != n / 2; i++) {
			stroka = rand() % n;
			stolbec = rand() % n;
			while (matrica[stroka][stolbec] == true) {
				stroka = rand() % n;
				stolbec = rand() % n;
			}
			matrica[stroka][stolbec] = true;
		}
	}

	bool isWin(int n) {
		int q = 0;
		for (int i = 0; i < n; i++) {
			if (matrica[rand() % n][rand() % n] == true) q++;
		}
		if (q >= n / 3) return true;
		else return false;
	}

};


int PartII()
{
	srand(time(0));
	int n;
	cin >> n;
	FunnyGame FG(n);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << FG.matrica[i][j] << " ";
		}
		cout << endl;
	}

	bool win = FG.isWin(n);
	if (win)
		cout << endl << "win" << endl;
	else cout << endl << "lose" << endl;;
	system("pause");
	return 0;
}