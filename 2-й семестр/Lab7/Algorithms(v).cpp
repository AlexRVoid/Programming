//any_of, sort, find_if, for_each, generate, remove_if, max_element
#include "Algorithms(v).h"

void  Algv() {
    vector<vector<char>> any = { {'a','b','c','d'}, {'a','b','x'}, {'s','w','x'}, {'s','t','q','r'} };
    cout << "any_of: " << any_of(any.begin(), any.end(), [](vector<char> x) {
        return (x[1] == 'w');
        }) << endl;


    cout << endl;
    vector<int> s;
    mt19937 gen(43);//Генератор случайных чисел;
    uniform_int_distribution <int> range(0, 100);//Задаёт диапозон генерируемых чисел
    for (size_t i = 0; i < 20; i++) {
        s.push_back(range(gen));//Заполнение массива
    }
    cout << "sort: " << s << endl;
    sort(s.begin(), s.end(), [](int x, int y) {
        return (x < y);
        });
    cout << "sort: " << s << endl;

    cout << endl;
    vector<string> f = { "a","ba","c","aa","bb","cc" };
    auto b = find_if(f.begin(), f.end(), [](const string& s) {
        return (s[1] == 'a'); });
    cout << "find_if: " << *b << endl;


    cout << endl;
    vector<int> each = { 12,534,567,123,-12,123,-31,57,8,1,0,-456 };
    cout << "for_each: ";
    for_each(each.begin(), each.end(), [](int y) {
        cout << abs(y) << " ";
        });
    cout << endl;


    cout << endl;
    vector <int> m (5);
    int g = 7;
    generate(m.begin(), m.end(), [&g]() {
        return g++; });
    cout << "generate: " << m << endl;


    cout << endl;
    vector<int> part = { 29,23,20,22,17,15,26,51,19,12,35,40 };
    partition(part.begin(), part.end(), [](int elem) {
        if (elem % 2) return false;
        else return true;
        });
    cout << "remove_if: " << part << endl;


    cout << endl;
    vector <int> v = { 2, 1, 3, 6, 7, 9, 8 };
    int max = *max_element(v.begin(), v.end());
    cout << "max_element: " << max << endl;

}

