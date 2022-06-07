#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

template <typename T, typename T1>

ostream& operator<< (ostream& os, const map<T, T1>& rusreg) {
	for (auto i : rusreg) {
		os << i.first << " " << i.second << endl;
	}
	return os;
}


map <string, vector<string>> set_name(string text, map <string, vector<string>> trains) {
    string s, n;
    vector<string> v;
    int i = 0;
    while (text[i] != ' ') { // берем остановки и записываем трамвай
        n += text[i];
        i++;
    }
    for (i; i < text.size() + 1; i++) {
        if ((text[i] == ' ') || (text[i] == '\0')) { // записываем остановки 
            v.push_back(s);
            s.clear();
            continue;
        }
        s += text[i];
    }
    v.push_back(s);
    s.clear();
    trains[n] = v;
    return trains;
}

void printTown(map <string, vector<string>> b, string town) {
    string trains;
    int k = 0;
    for (auto i : b) {
        for (auto j : i.second) {
            if ((town == j)) { //проверяем какой трамвай проезжает эту остановку
                if (trains == i.first) continue;
                trains = i.first;
                k = 1;
                cout << i.first << " \n";
            }
        }
    }
    if (k == 0) cout << "No one\n";
}

void printTrains(map <string, vector<string>> b, string trains) {
    string town;
    int k;
    k = 0;
    for (auto i : b) {
        if (trains == i.first) {
            k = 1; // проверка сушествет ли данный трамвай
            for (auto j : i.second) { // для проверки какие еще трамваи проезжают эту остановку
                if (j != "") cout << j << "( ";
                town = j;
                for (auto h : b) {
                    for (auto z : h.second) {
                        if (z == "") continue;
                        if ((town == z) && (h != i)) { // пробегаем по мапу чтобы вывести трамваи
                            cout << h.first << " ";
                        }
                    }
                }
                if (j != "") cout << ") ";
            }
            cout << endl;
        }
    }
    if (k == 0) cout << "Tram is absent\n";
}

map <string, vector<string>> get_name(map <string, vector<string>> a) {
    for (auto i : a) {
        cout << i.first << " "; // выводим трамваи
        for (auto j : i.second) {
            cout << j << " ";// выводим остановки 
        }
        cout << endl;
    }
    return a;
}

void Task1() {

    map <string, vector<string>> mtram;
    while (1) {
        int s = 0;
        string text, stop, tram;
        bool f = true;
        while (f == true)
        {
            cout << "1.CREATE_TRAM" << endl << "2.TRAMS_IN_STOP" << endl << "3.STOPS_IN_TRAM" << endl << "4.TRAMS" << endl << "5.EXIT." << endl;
            cin >> s;
            switch (s)
            {
            case 1:
            {

                cin.ignore();
                getline(cin, text);
                mtram = set_name(text, mtram);
            }
            break;
            case 2:
            {
                cout << "What stop? ";
                cin >> stop;
                printTown(mtram, stop);
            }
            break;
            case 3:
            {
                cout << "What tram? ";
                cin >> tram;
                printTrains(mtram, tram);
            }
            break;
            case 4:
            {
                get_name(mtram);
            }
            break;
            case 5:
            {
                exit(1);
            }
            default:
                break;
            }
        }
       

        
        else if (s == 2) {
            
        }
        else if (s == 3) {
            
        }
        else if (s == 4) {
            get_name(mtram);
        }

        else if (s == 5) {
            exit(1);

        }
    }
}



void Task2()
{
	map <string, string> rusreg;
	map <string, string> :: iterator it;
	pair <string, string> p;
	
		bool f = true;
		while (f == true)
		{
			cout << "1.Change" << endl << "2.Rename" << endl << "3.About" << endl << "4.All" << endl << "5.Exit" << endl;
			int n;
			cin >> n;
			switch (n)
			{
			case 1:
			{
				cout << "Enter the name of the region: ";
					cin.ignore();
					getline(cin, p.first);
				cout << "Enter the name of the administrative center: ";
					getline(cin, p.second);
				it = rusreg.find(p.first);
				if (it != rusreg.end())
				{
					rusreg.erase(it);
				}
				rusreg.insert(p);
			}
			break;
			case 2:
			{
				cout << "Enter the name of the region: ";
					cin.ignore();
					getline(cin, p.first);
				it = rusreg.find(p.first);
				if (it == rusreg.end())
				{
					cout << "Incorrect" << endl;
					break;
				}
				if (it != rusreg.end())
				{
					p.second = it->second;
					rusreg.erase(it);
					cout << "Enter the new name of the region: ";
						cin.ignore();
						getline(cin, p.first);
					rusreg.insert(p);
				}
				
			}
			break;
			case 3:
			{
				cout << "Enter the name of the region: ";
					cin.ignore();
					getline(cin, p.first);
				it = rusreg.find(p.first);
				if (it == rusreg.end())
				{
					cout << "Incorrect" << endl;
					break;
				}
				if (it != rusreg.end())
				{
					cout << it->second;
				}
			}
			break;
			case 4:
			{
				cout << rusreg;
			}
			break;
			case 5:
			{
				f = false;
			}
			break;
			default:
				break;
			}
		}

}

int main()
{
    cout << "task 1:" << endl;
    Task1();
    cout << "task 2:" << endl;
	Task2();
}