//none_of, copy_if, count_if
#include "Algorithms(m).h"

void Algm() {
    cout << endl;
    map<int, int> m = { {1,2}, {3,4}, {5,6} };
    cout << "none_of: " << none_of(m.begin(), m.end(), [](pair<int, int> x) {
        return (x.first > x.second);
        }) << endl;


    cout << endl;
    map<int, string> m1 = { {1991, "Python"}, {1991, "Visual Basic"}, {2014, "Swift"}, {1983, "Ada"}, {1980, "C++"}, {1995, "PHP"}, {1995, "Java"} };
    map<int, string> B;
    copy_if(m1.begin(), m1.end(), inserter(B, B.end()), [](pair<int, string> a) {return (a.first < 1995); });
    cout << "copy_if: \n" << B;


    cout << endl;
    map<int, bool> c = { {22, true}, {31, false}, {11, true}, {75, false}, {57, true} };
    cout << "count_if: " << count_if(c.begin(), c.end(), [](pair<int, bool> r) {return r.second; }) << endl;
}