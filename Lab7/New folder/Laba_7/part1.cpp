#include "part1.h"
void  part1(){
    cout << endl;
    vector<vector<char>> v3 = { {'a','b','c','d'}, {'a','b','z'}, {'y','w','x'}, {'s','t','v','q','r'} };
    cout << "any_of: " << any_of(v3.begin(), v3.end(), [](vector<char> x) {
        return (x[1] == 'w');
        }) << endl;


    cout << endl;
    vector<int> v1;
    mt19937 gen(time(0));//Генератор случайных чисел;
    uniform_int_distribution<int> range(0, 100);//Задаёт диапозон генерируемых чисел
    for (size_t i = 0; i < 10; i++) {
        v1.push_back(range(gen));//Заполнение массива
    }
    cout << "sort: " << v1 << endl;
    sort(v1.begin(), v1.end(), [](int x, int y) {
        return (x < y);
        });
    cout << "sort: " << v1 << endl;

    cout << endl;
    vector<string> v = { "a","ba","c","aa","bb","cc" };
    auto b = find_if(v.begin(), v.end(), [](const string& s) {
        return (s[1] == 'a'); });
    cout << "find_if: " << *b << endl;


    cout << endl;
    vector<int> lec = { 12,534,567,123,-12,123,-31,57,8,1,0,-456 };
    cout << "for_each: ";
    for_each(lec.begin(), lec.end(), [](int y) {
        cout << abs(y) << " ";
        });
    cout << endl;


    cout << endl;
    vector<int> lec1(5);
    int g = 7;
    generate(lec1.begin(), lec1.end(), [&g]() {
        return g++; });
    cout << "generate: " << lec1 << endl;


    cout << endl;
    vector<int> lec2 = { 29,23,20,22,17,15,26,51,19,12,35,40 };
    partition(lec2.begin(), lec2.end(), [](int elem) {
        if (elem % 2) return false;
        else return true;
        });
    cout << "remove_if: " << lec2 << endl;


    cout << "max_element: " << endl;

}