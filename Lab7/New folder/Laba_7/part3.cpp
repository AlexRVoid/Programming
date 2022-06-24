#include "part3.h"
void part3() {
	//для каждого вывести его модуль
	cout << endl;
	vector<int> lec = { 12,534,567,123,-12,123,-31,57,8,1,0,-456 };
	cout << "exp_7: ";
	for_each(lec.begin(), lec.end(), [](int y) {
		cout << abs(y) << " ";
		});
	cout << endl;

	//Заполняет вектор
	cout << endl;
	vector<int> lec1(5);
	int g = 7;
	generate(lec1.begin(), lec1.end(), [&g]() {
		return g++; });
	cout << "exp_8: " << lec1 << endl;

	//сперва четные потом нечетные
	cout << endl;
	vector<int> lec2 = { 29,23,20,22,17,15,26,51,19,12,35,40 };
	partition(lec2.begin(), lec2.end(), [](int elem) {
		if (elem % 2) return false;
		else return true;
	});
	cout << "exp_9: " << lec2 << endl;

	//удаляет все кроме кратных 5
	cout << endl;
	vector<int> lec3 = { 29,20,17,26,19,12,35,40 };
	auto it = remove_if(lec3.begin(), lec3.end(), [](int elem) {
		return(elem % 5);
	});
	lec3.erase(it, lec3.end());

	cout << "exp_10: " << lec3 << endl;

}