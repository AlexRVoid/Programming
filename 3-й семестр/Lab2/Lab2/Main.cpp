#include "Algebra.h"
#include "Comparison.h"
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

int main()
{
    TimeData Mos(12, 0, 14, 10);
    Time NewCity;
    Time London(12, 60, 14, 52);
    Time Moscow(Mos);

    while (true)
    {
        system("cls");
        int n;
        cout << "What do you want?\n";
        cout << "1) Create city with time.\n";
        cout << "2) Output city\n";
        cout << "3) Addup times\n";
        cout << "4) Subtract times\n";
        cout << "5) Compare times\n";
        cout << "6) Exit\n";
        cout << "Your Choice: ";
        cin >> n;
        if (cin.fail()) {
            cin.clear();
            cout << "Inncorrect input!!!\n\n";
            exit(1);
        }
        system("cls");

        switch (n)
        {
        case 1:
            cin >> NewCity;
            break;
        case 2:
            cout << " 1) File\n 2) Console\n 3)String\n Your Choice: ";
            cin >> n;
            if (cin.fail()) {
                cin.clear();
                cout << "Inncorrect input!!!\n\n";
                exit(1);
            }

            if (n == 1) {
                ofstream fout;
                fout.open("Out.txt");
                if (fout.is_open())
                {
                    fout << "In city N now " << NewCity.hour << " hours " << NewCity.min << " minutes  " << NewCity.sec << " seconds " << NewCity.msec << " milliseconds\n";
                }
                fout.close();
            }
            else if (n == 2) {
                cout << NewCity << endl;
                system("pause");
            }
            else if (n == 3)
            {
                stringstream sout;
                sout << NewCity;
                cout << sout.str();
                system("pause");
            }
            break;
        case 3:
            cout << London << endl << Moscow << endl;
            NewCity = NewCity.CallingAdd(London, Moscow);
            cout << "Result of addition: " << NewCity << endl;
            system("pause");
            break;
        case 4:
            cout << London << endl << Moscow << endl;
            NewCity = NewCity.CallingSub(London, Moscow);
            cout << "Result of subtract: " << NewCity << endl;
            system("pause");
            break;
        case 5:
            cout << "Result comparison: " << NewCity.CallingEquals(London, Moscow) << endl << endl;
            cout << "Result comparison: " << NewCity.CallingGreater(London, Moscow) << endl << endl;
            cout << "Result comparison: " << NewCity.CallingLess(London, Moscow) << endl << endl;
            system("pause");
            break;
        case 6:
            exit(0);
        default:
            cout << "Inncorrect input!!!\n\n";
            main();
            break;
        }
    }
}