#include "part2.h"
void part2() {
	//если ни один ключ не больше своего значения = 1
    cout << endl;
    map<int, int> m = { {1,2}, {3,4}, {5,6} };
    cout << "none_of: " << none_of(m.begin(), m.end(), [](pair<int, int> x) {
        return (x.first > x.second);
        }) << endl;


    cout << endl;
    map<int, string> m1 = { {2022, "Ice Cube"}, {1995, "Eazy - E"}, {2022, "Dr. Dre"}, {2022, "Mc Ren"}, {1996, "2Pac"}, {1997, "The Notorious B.I.G."}, {2018, "XXXTentacion"} };
    map<int, string> B;
    copy_if(m1.begin(), m1.end(), inserter(B, B.end()), [](pair<int, string> a) {return (a.first < 2022); });
    cout << "copy_if: \n" << B;


    cout << endl;
    map<int, bool> m2 = { {13, true}, {21, false}, {67, true}, {25, false}, {7, true} };
    cout << "count_if: " << count_if(m2.begin(), m2.end(), [](pair<int, bool> r) {return r.second; }) << endl;
}