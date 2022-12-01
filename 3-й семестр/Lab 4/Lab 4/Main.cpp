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
    map <string, int> members = { {"Papa ", 1},
                            {"Mama ", 2},
                            {"Kate ", 3} };
    friend ostream& operator<<(const Applications& applications, ostream& os)
    {
        os << "Member\t Member number\n";
        map<string, int>::const_iterator it;
        for (it = applications.members.begin(); it != applications.members.end(); ++it)
            os << (*it).first << " " << (*it).second << "\n";
        return os;
    }
    
    
    friend void AddMember(Applications& applications, pair <string, int>& member);
    void GetMembers();
    
private:
    
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
    Applications application;
    
    cout << application.members;
}

int main()
{
    menu();
}