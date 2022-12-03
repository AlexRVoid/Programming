#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <windows.h>
#include <map>
#include <ctime>

using namespace std;



class Applications
{
public:
    friend ostream& operator<< (ostream& os, const Applications& applications)
    {
        os << "Member number\tMember\n";
        map<int, string>::const_iterator it;
        for (it = applications.members.begin(); it != applications.members.end(); ++it)
            os << (*it).first << "\t " << (*it).second << "\n";
        return os;
    }

    /*friend istream& operator>>(istream& is, Applications& applications)
    {
        is << 
        return is;
    }*/

    map <int, int> result;

    int GenMemberNumber();
    friend void AddMember(Applications& applications, pair <int, string>& member);
    void GetMembers();
    friend void AddResult(Applications& applications, pair <int, int>& member);
    void FindMember(int membernumber);

protected:
    map <int, string> members;
    map <int, string> users;
};

class Users : private Applications
{
public:
    int UserLogIn(const Users& users, const int& username, const string& userpass);
    bool AdminLogIn(const Users& users, const string& username, const string& userpass);

private:
};

int Users::UserLogIn(const Users& users, const int& username, const string& userpass)
{
    if (users.users.empty())
    {
        cout << "No registered users" << endl;
        system("pause");
        return 0;
    }
    for (auto i : users.users)
    {
        if (i.first == username && i.second == userpass)
        {
            return i.first;
        }
        else continue;
    }

}

void AddMember(Applications& applications, pair <int, string>& member)
{
    applications.members.insert(member);
    pair <int, int> res = { member.first, 0 };
    applications.result.insert(res);
    pair <int, string> user = {member.first, ""};
    applications.users.insert(user);
    

}

void Applications::GetMembers()
{
    system("cls");
    cout << "Member number\t Member" << endl;
    for (auto i : members)
    {
        cout << i.first << "\t\t " << i.second << endl;
    }
    system("pause");
}

void AddResult(Applications& applications, pair <int, int>& member)
{
    system("cls");
    if (applications.result.find(member.first) != applications.result.end())
    {
        map <int, int> ::iterator it;
        it = applications.result.find(member.first);
        (*it).second = member.second;
    }
    else cout << "There is no such member";
    system("pause");
}

int Applications::GenMemberNumber()
{
    system("cls");
    while (true)
    {
        srand(time(NULL));
        int membernum = rand() % 1000 + 1;
        map <int, string> ::iterator it;
        if (members.find(membernum) != members.end() || members.empty())
        {
            return membernum;
        }
        else continue;
    }
}

void Applications::FindMember(int membernumber)
{
    system("cls");
    map<int, string>::iterator it;
    map <int, int>::iterator itr;
    it = members.find(membernumber);
    itr = result.find(membernumber);
    if (it != members.end() && itr != result.end()) {
        cout << "Member number\t Member\t Result" << endl;
        cout << (*it).first << "\t " << (*it).second << "\t " << (*itr).second << endl;
    }else cout << "There is no such member";
}

void adminmenu()
{
    Applications application;

    while (true)
    {
        system("cls");
        cout << "What do you need?\n" << "1)Add member;\n" << "2)Add result;\n" << "3)Find member;\n" << "4)Display a table of members;\n" << "5)Printing of the certificate;\n";
        int choice;
        cin >> choice;
        if (choice == 1)
        {
            pair <int, string> member;
            cout << "Enter the full name of member:" << endl;
            string name;
            cin.ignore();
            getline(cin, name);
            member.second = name;
            member.first = application.GenMemberNumber();
            AddMember(application, member);
        }
        else if (choice == 2)
        {
            pair <int, int> result;
            cout << "Enter the member number: ";
                cin >> result.first;

            cout << "Enter the member result: ";
                cin >> result.second;
            
                AddResult(application, result);
        }
        else if (choice == 3)
        {
            int membernum;
            cout << "Enter the member number: ";
                cin >> membernum;
            application.FindMember(membernum);

            
        }
        else if (choice == 4)
        {
            application.GetMembers();
        }
        else if (choice == 5)
        {

        }
        
    }

}

int main()
{
    adminmenu();
}