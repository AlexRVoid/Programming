#include <cmath>
#include <iostream>
#include <random>
#include <vector>
#include <ctime>
#include <cstdint>
#include <algorithm>
using namespace std;

double y(double x) {
	return cos(x) - pow((x - 1), 2);
}
double proizv(double x) {
	return -sin(x) - 2 * (x - 1);
}
void MetPrItr(double x0, double e) {
	int k = 0;
	double x = 0.5 * (pow(x0, 2) + 1 - cos(x0));
	while (abs(x - x0) > e) {
		k++;
		if (k == 1) {
			x = 0.5 * (pow(x0, 2) + 1 - cos(x0));
		}
		else
		{
			x0 = x;
			x = 0.5 * (pow(x0, 2) + 1 - cos(x0));
		}
		cout << "N: " << k;
		cout << " Xn: " << x0;
		cout << " Xn+1: " << x;
		cout << " Xn - Xn+1: " << x - x0 << endl;
		cout << " _____________________________________________________" << endl;
	}
	cout << "x* = " << x << endl;
}
void MetPolDel(double a0, double b0, double e) {
	int k = 0;
	double c = 0, a1 = a0, b1 = b0;
	while (abs(b1 - a1) > e) {
		b0 = b1;
		a0 = a1;
		c = (a0 + b0) / 2;
		if (y(a0) * y(c) < 0) {
			a1 = a0;
			b1 = c;
		}
		else {
			a1 = c;
			b1 = b0;
		}
		k++;
		cout << "N_" << k;
		cout << " a: " << a1;
		cout << " b: " << b1;
		cout << " b-a: " << b1 - a1 << endl;
		cout << " _____________________________________________________" << endl;
	}
	cout << "x* = " << (a1 + b1) / 2 << endl;
}
void MetNut(double x0, double e) {
	int k = 0;
	double vspom = proizv(x0);
	double x = x0 - (y(x0) / proizv(x0));
	while (fabs(x - x0) >= e) {
		k++;
		x0 = x;
		x = x0 - (y(x0) / vspom);
		cout << "N:" << k;
		cout << " Xn: " << x0;
		cout << " Xn+1: " << x;
		cout << " Xn - Xn+1: " << x - x0 << endl;
		cout << " _____________________________________________________" << endl;
	}
	cout << "x* = " << x << endl;
}
void zad_1() {
	double x = 1.4, e = 0.0001, a0 = 1, b0 = 2;
	MetPolDel(a0, b0, e);
	cout << "................................................. " << endl;
	MetNut(x, e);
	cout << "................................................. " << endl;
	MetPrItr(x, e);
	cout << endl;
}
void zad_2() {
	knuth_b gen(time(0));
	uniform_int_distribution<int> uid0(0, 1);
	uniform_int_distribution<int> uid1(-300, -150);
	uniform_int_distribution<int> uid2(150, 300);
	int n = 11;
	vector<int> arr;
	for (auto i = 0; i < n; i++) {
		if (uid0(gen) == 0)
		{
			arr.push_back(uid1(gen));
		}
		else
		{
			arr.push_back(uid2(gen));
		}
		cout << arr[i] << " ";
	}
	cout << endl;
	double sum = 0, naib = -100000, naim = 100000;
	for (auto i : arr)
	{
		sum += i;
		if (i > naib)
			naib = i;
		if (i < naim)
			naim = i;
	}
	cout << "—реднее арифметическое = " << sum / (arr.size()) << endl;
	cout << "Ќаибольшее число = " << naib << endl;
	cout << "Ќаименьшее число = " << naim << endl;

	reverse(arr.begin(), arr.end());
	cout << "ќбратный вектор: ";
	for (auto i : arr)
	{
		cout << i << " ";
	}
	cout << endl;
	reverse(arr.begin(), arr.end()); // возврат вектора в исходное состо€ние
	int k = 0;
	int indik;
	for (auto i : arr) // перва€ половина - по возрастанию, втора€ - по убыванию
	{
		if (k <= (arr.size() / 2))
		{
			sort(arr.begin(), arr.begin() + k);
			indik = k;
		}
		else
		{
			sort(arr.begin() + indik, arr.end(), greater<int>());
		}
		k++;
	}
	for (auto i : arr)
	{
		cout << i << " ";
	}
	cout << endl;
	vector<char> arr1{ 'f', 'H', '2', '&', '!', '.', 'l' };
	vector<char> reserv;
	reserv.push_back('A');
	for (auto i : arr1)
	{
		reserv.push_back(i);
		if (48 <= int(i) && int(i) <= 57)
		{
			reserv.erase(reserv.end() - 1);
		}
		if (97 <= int(i) && int(i) <= 122)
		{
			reserv.erase(reserv.end() - 1);
		}
	}
	reserv.erase(reserv.begin());
	arr1 = reserv;
	for (auto i : arr1)
	{
		cout << i << " ";
	}
	cout << endl;
	vector<int> a1{ 1, 2, 3, 4 };
	vector<int> a2{ 5, 6, 7, 8 };
	k = 2;
	int j = 0;
	while (j < k)
	{
		a1.push_back(a2[0]);
		a2.push_back(a1[0]);
		a1.erase(a1.begin());
		a2.erase(a2.begin());
		j++;
	}
	for (auto i : a1)
	{
		cout << i << " ";
	}
	for (auto i : a2)
	{
		cout << i << " ";
	}
	cout << endl;
}
void zad_3() {
	knuth_b gen(time(0));
	uniform_int_distribution<int> uid(1, 100);
	vector<int> m1,
		m2, m3;
	vector < pair <int, int>> d;
	double dlin1 = 50, dlin2 = 100, dlin3 = 1000;
	for (int i = 0; i < dlin1; i++)
	{
		m1.push_back(uid(gen));
	}
	for (int i = 0; i < dlin2; i++)
	{
		m2.push_back(uid(gen));
	}
	for (int i = 0; i < dlin3; i++)
	{
		m3.push_back(uid(gen));
	}
	for (auto j = 0; j < 10; j++) { // раздел€ем на отрезки, длиной 10
		int n = 0;
		for (auto i = 0; i < dlin1; i++) {
			if (m1[i] > j * 10 && m1[i] <= j * 10 + 10) {
				n++;
			}
		}
		d.push_back(make_pair(j, n)); // j - xi, n - ni
	}
	auto xandn = 0;
	for (auto i : d)
	{
		xandn += i.first * i.second;
	}
	double averX;
	averX = xandn / dlin1;
	double s2 = 0, s;
	for (auto i : d)
	{
		s2 += pow((averX - i.first), 2) * i.second;
	}
	s2 = s2 / (dlin1 - 1);
	s = sqrt(s2);
	double X = 0;
	for (auto i : d) {
		auto u = (i.first - averX) / s;
		auto fi = 1 / sqrt(6.26) * exp(-pow(u, 2) / 2);
		auto n0 = (dlin1 * 10) / s * fi;
		X += pow((i.second - n0), 2) / n0;
	}
	cout << "1) X ^ 2 = " << X << endl;
	cout << "M = " << averX << endl;
	d.clear();
	// __________________________________________________________
	for (auto j = 0; j < 10; j++) { // раздел€ем на отрезки, длиной 10
		int n = 0;
		for (auto i = 0; i < dlin2; i++) {
			if (m2[i] > j * 10 && m2[i] <= j * 10 + 10) {
				n++;
			}
		}
		d.push_back(make_pair(j, n)); // j - xi, n - ni
	}
	xandn = 0;
	for (auto i : d)
	{
		xandn += i.first * i.second;
	}
	averX = xandn / dlin2;
	s2 = 0;
	for (auto i : d)
	{
		s2 += pow((averX - i.first), 2) * i.second;
	}
	s2 = s2 / (dlin2 - 1);
	s = sqrt(s2);
	X = 0;
	for (auto i : d) {
		auto u = (i.first - averX) / s;
		auto fi = 1 / sqrt(6.26) * exp(-pow(u, 2) / 2);
		auto n0 = (dlin2 * 10) / s * fi;
		X += pow((i.second - n0), 2) / n0;
	}
	cout << "2) X ^ 2 = " << X << endl;
	cout << "M = " << averX << endl;
	d.clear();
	//_________________________________________________________
	for (auto j = 0; j < 10; j++) { // раздел€ем на отрезки, длиной 10
		int n = 0;
		for (auto i = 0; i < dlin3; i++) {
			if (m3[i] > j * 10 && m3[i] <= j * 10 + 10) {
				n++;
			}
		}
		d.push_back(make_pair(j, n)); // j - xi, n - ni
	}
	xandn = 0;
	for (auto i : d)
	{
		xandn += i.first * i.second;
	}
	averX = xandn / dlin3;
	s2 = 0;
	for (auto i : d)
	{
		s2 += pow((averX - i.first), 2) * i.second;
	}
	s2 = s2 / (dlin3 - 1);
	s = sqrt(s2);
	X = 0;
	for (auto i : d) {
		auto u = (i.first - averX) / s;
		auto fi = 1 / sqrt(6.26) * exp(-pow(u, 2) / 2);
		auto n0 = (dlin3 * 10) / s * fi;
		X += pow((i.second - n0), 2) / n0;
	}
	cout << "3) X ^ 2 = " << X << endl;
	cout << "M = " << averX << endl;
	d.clear();
}

int mod(int delim, int delit, int stepen) {
	int a = 0, a0 = delim % delit;
	for (int i = 1; i <= stepen; i++) {
		a = delim % delit;
		delim = a * a0;
	}
	return a;
}
void zad_4() {
	// 2^x mod 30803 = 16190
	int a = 2, p = 30803, y = 16190, m, k, pom1, pom2, i1, j1, brperem = 0, answer;
	m = k = int(sqrt(p)) + 1;
	pom1 = y;
	for (int j = 1; j < m; j++)
	{
		pom1 = (pom1 * a) % p; // шаги великана
		for (int i = 1; i <= k; i++)
		{
			pom2 = mod(a, p, i * m); // шаги младенца
			if (pom1 == pom2)
			{
				brperem += 1;
				i1 = i;
				j1 = j;
				break;
			}
		}
		if (brperem != 0)
		{
			answer = (i1 * m - j1) % (p - 1);
			cout << "x = " << answer << endl;
			break;
		}
	}
	cout << "Checking: y = " << mod(a, p, answer);
}

vector<int> find(int n) {
	vector<int> v;
	int div = 2;
	while (n > 1) {
		while (n % div == 0) {
			n = n / div;
			v.push_back(div);
		}
		div++;
	}
	return v;
}

int moduleOfStepen(int x, int y, int mod) {
	//x^y
	int res = 1;
	int temp = x % mod;
	int temp1;
	for (int i = 1; i <= y; i++) {
		res = res * x % mod;
	}
	return res;
}
void deliteli(int x, vector < pair<int, int>>& v) {
	int k = 0;
	int i = 2;
	int temp = x;
	for (i; i < temp; i++) {
		while (x % i == 0) {
			k++;
			x /= i;
		}
		if (k != 0) {
			v.push_back(make_pair(i, k));
		}
		k = 0;
	}
}


bool full_coincidence(vector<int>& a, vector < pair<int, int>>& b) {
	bool flag = true;
	for (auto i : b) {
		if
			(find(a.begin(), a.end(), i.first) == a.end())
			flag = false;
	}
	if (b.size() == 0) flag = false;
	return flag;
}

bool full_base(vector < pair < vector < pair<int, int> >, int>>& v, vector <int>& base) {
	bool u1 = false, u2 = false, u3 = false;
	for (auto i : v) {
		auto t = i.first;
		for (auto k : t) {
			if (k.first == base[0]) u1 = true;
			if (k.first == base[1]) u2 = true;
			if (k.first == base[2]) u3 = true;
		}

	}
	return u1 && u2 && u3 && v.size() > 8;
}

bool moreOne(vector < pair<int, int>>& delitels, vector <int>& S) {
	vector <int> temp_del;
	int k1 = 0;
	int k2 = 0;
	int k3 = 0;
	for (auto i : delitels) {
		temp_del.push_back(i.first);
	}
	for (auto i : temp_del) {
		if (k1 < 1) {
			if (i == S[0]) k1++;
		}
		if (k2 < 1) {
			if (i == S[1]) k2++;
		}
		if (k3 < 1) {
			if (i == S[2]) k3++;
		}
	}
	if (k1 + k2 + k3 > 1) return true;
	else return false;
}
void zad_4_2() {
	int aa = 2;
	int p = 30803;
	int y = 16190;
	int k = 5000, b = aa, i = 0, t0 = aa % 30803, x = 0;
	vector <int> S = { 2, 3, 5 };
	int t = S.size();
	int e = 1;
	vector < pair <int, int>> delitels;
	vector<int> stepeni, ter;
	vector < pair < vector < pair<int, int> >, int>> equation;
	for (int k = 15; ; k++) {
		deliteli(moduleOfStepen(aa, k, p), delitels);
		if (full_coincidence(S, delitels) && moreOne(delitels, S)) {
			equation.push_back(make_pair(delitels, k));
		}
		delitels.clear();
		if (full_base(equation, S)) break;
	}
	for (auto i : equation)
		for (auto j : i.first)
		{
			cout << j.first << " " << j.second << " " << i.second << endl;
		}
	int u1 = 1;
	int u2 = 16358;
	int u3 = 21409;

	t0 = y % p;
	t = 1;
	b = aa;
	for (i = 1; i <= 15000; i++) {
		t = (t * b) % p;
		t0 = y * t % p;
		ter = find(t0);
		if ((ter[ter.size() - 1] <= S[S.size() - 1]) and (ter.size() >= 2)) {
			break;
		}
		ter.clear();
	}
	for (auto i : ter) {
		if (i == 2)
		{
			x += u1;
		}
		if (i == 3)
		{
			x += u2;
		}
		if (i == 5)
		{
			x += u3;
		}
	}
	x = (x - i) % (p - 1);//?
	cout << x << endl;

}

int main()
{
	setlocale(LC_ALL, "ru");
	//zad_1();
	//zad_2();
	//zad_3();
	//zad_4();
	zad_4_2();
}