#include <iostream>
#include <vector>
#include <set>
#include <random>
#include <chrono>
#include <math.h>

using namespace std;

void randomNum(int n, vector <int>& massive)
{
	random_device rd;
	ranlux24_base gen(rd());
	uniform_int_distribution<> dist(1, 100);

	for (int i = 0; i < n; i++) {
		massive.push_back(dist(gen));
	}
}

vector <int> arr_set(vector<int> massive) {
	set <int> arr_sort_pr(massive.begin(), massive.end());
	vector <int> arr_sort(arr_sort_pr.size());
	int j = 0;
	for (int i : arr_sort_pr) {
		arr_sort[j++] = i;
	}
	return arr_sort;
}

double f(int x, double m, double sr) {
	double y = (exp(-1 * pow((x - m), 2) / (2 * sr * sr)) / (sr * sqrt(2 * 3.14)));
	return y;
}

int find(vector<int> massive, int el) {
	int n = 0;
	for (int i : massive) {
		if (el == i) n++;
	}
	return n;
}

vector<double> norm(vector<int> massive) {
	vector <int> arr_un = arr_set(massive);
	double m = 0;
	for (int i : massive) m += i;
	m /= massive.size();

	double sr = 0;
	double su = 0;
	for (int i = 0; i < arr_un.size(); i++) {
		su += pow(arr_un[i], 2) * find(massive, arr_un[i]);
	}
	su /= massive.size();
	su -= m * m;
	sr = sqrt(su);

	vector<double> arr_norm(arr_un.size());
	for (int i = 0; i < arr_un.size(); i++) {
		arr_norm[i] = 2 * f(arr_un[i], m, sr) * massive.size();
	}
	return arr_norm;
}

double f_hi(vector<int> massive, vector<double> arr_norm) {
	vector <int> arr_un = arr_set(massive);
	double hi = 0;
	for (int i = 0; i < arr_un.size(); i++) {
		hi += pow((find(massive, arr_un[i]) - arr_norm[i]), 2) / arr_norm[i];
	}
	return hi;
}

void check(vector <int> massive, int df) {
	vector <double> arr_norm = norm(massive);
	double hi = f_hi(massive, arr_norm);
	cout << "’и-квадрат: " << hi << endl;
	cout << "—тепень свободы: " << df << endl;
}

int main()
{
	setlocale(LC_ALL, "Russian");
	vector <int> massive;
	int n = 50;
	randomNum(n, massive);
	check(massive, n - 1);
	cout << "’и-квадрат дл€ данной степени свободы (" << n - 1 << ") и уровне значимости 0.05: " << 66.34 << endl;
	cout << endl;

	massive = {};
	n = 100;
	randomNum(n, massive);
	check(massive, n - 1);
	cout << "’и-квадрат дл€ данной степени свободы (" << n - 1 << ") и уровне значимости 0.05: " << 123.23 << endl;
	cout << endl;

	massive = {};
	n = 1000;
	randomNum(n, massive);
	check(massive, n - 1);
	cout << "’и-квадрат дл€ данной степени свободы (" << n - 1 << ") и уровне значимости 0.05: " << 1073.64 << endl;
	cout << endl;
}