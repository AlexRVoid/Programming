#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <windows.h>
#include <map>

using namespace std;

class Applications
{
public: 

    friend ostream& operator<<(const Applications& applications, ostream& os)
    {
        os << "Member\t Member number" << endl;
        for (auto i : applications.members)
        {
            os << i.first << "\t" << i.second << endl;
        }
        return os;
    }
    
    
    friend void AddMember(Applications& applications, pair <string, int>& member);
    void GetMembers();
    
private:
    map <string, int> members;
    pair <string, int> member = {"aaa",123};
    map <int, int> result;
};

void AddMember(Applications& applications, pair <string, int>& member)
{
    applications.members.insert(member);
}

void Applications::GetMembers()
{

}

int menu()
{
    Applications applications;
    
    cin >> applications;
}

int main()
{
    menu();
}