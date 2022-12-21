#pragma once
#include "Application.h"

using namespace std;

int LogIn::UserLogIn(const int& username, const string& userpass)
{
    if (users.empty())
    {
        cout << "No registered users" << endl;
        system("pause");
        return 0;
    }
    for (auto i : users)
    {
        if (i.first == username && i.second == userpass)
        {
            return i.first;
        }
        else continue;
    }
    return 0;
}

bool LogIn::AdminLogIn(const int& username, const string& userpass)
{
    if (username == admin.first && userpass == admin.second)
    {
        return true;
    }
    else return false;
}

void Applications::PrintCertificate(const int& username)
{
    map <int, string> ::iterator it = members.find(username);
    int place = 1;
    for (auto i : result)
    {
        if (i.second > (*it).first)
        {
            place++;
        }
    }
    ofstream fout;
    fout.open("Certificate.txt");
    if (fout.is_open())
    {
        fout << "Diploma\n" << endl;
        fout << "to" << endl;
        fout << "\n" << (*it).second << endl;
        fout << "\n" << "for achiving the " << place << " place" << endl;
        fout << "\n\n" << "Director____________" << endl;
        fout << "Date________________" << endl;
    }

    fout.close();
}

void AddMember(Applications& applications, pair <int, string>& member, const string& password)
{
    system("cls");
    applications.members.insert(member);
    pair <int, int> res = { member.first, 0 };
    applications.result.insert(res);

    pair <int, string> user = { member.first, password };
    applications.users.insert(user);

    cout << "Application accepted" << endl;

    cout << "Your member number: " << member.first << endl;
    cout << "Your password: " << password << endl;

    system("pause");
}

void Applications::GetMembers()
{
    system("cls");
    cout << "Member number\t Result" << endl;
    for (auto i : result)
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
        if (members.find(membernum) == members.end())
        {
            return membernum;
        }
        else continue;
    }
}

void Applications::FindMember(const int& membernumber)
{
    system("cls");
    map<int, string>::iterator it;
    map <int, int>::iterator itr;
    it = members.find(membernumber);
    itr = result.find(membernumber);
    if (it != members.end() && itr != result.end()) {
        cout << "Member number\t Member\t\t\t\t Result" << endl;
        cout << (*it).first << "\t\t " << (*it).second << "\t " << (*itr).second << endl;
    }
    else cout << "There is no such member";
    system("pause");
}