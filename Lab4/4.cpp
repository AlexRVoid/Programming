#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

int mod(int g, int x, int p) {
	int mod = 1;
	for (int i = 0; i < x; i++) {
		mod *= g;
		mod = mod % p;
	}
	return mod;
}

int find(vector<int> v, int j) {
	int ind = -1;
	for (int i = 0; i < v.size(); i++) {
		if (j == v[i]) {
			ind = i;
			break;
		}
	}
	return ind;
}

int step(int g, int a, int p) {
	int k = sqrt(p) + 1;
	int b = mod(g, k, p);
	vector<int> r_1(k);
	vector<int> r_2(k);
	int i_1 = -1;
	int j_1 = -1;
	for (int i = 1; i <= k; i++) {
		r_1[i] = mod(b, i, p);
		r_2[i] = mod(g, i, p) * a % p;
		if (find(r_2, r_1[i]) != -1) {		//g^(i)a = g^(ik)
			j_1 = find(r_2, r_1[i]);
			i_1 = i;
			break;
		}
		if (find(r_1, r_2[i]) != -1) {
			j_1 = i;
			i_1 = find(r_1, r_2[i]);
			break;
		}
	}
	int x = (k * i_1 - j_1) % (p - 1);
	return x;
}

int main() {
	setlocale(LC_ALL, "Russian");
	cout << "g^(x) mod p = a: " << endl;
	int g = 2;
	int a = 24322;
	int p = 30203;
	int x = step(g, a, p);
	cout << "Порядок: " << endl << x << endl;
	cout << "Проверка:" << endl << "2^" << x << " mod " << p << " = " << mod(g, x, p);
	cout << endl;
}