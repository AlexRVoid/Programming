#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <windows.h>
#include <map>
#include <ctime>

using namespace std;

class LogIn
{
public:

    int UserLogIn(const int& username, const string& userpass);
    bool AdminLogIn(const int& username, const string& userpass);

protected:
    pair <int, string> admin = { 1111, "admin" };
    map <int, string> users;
};

class Applications : public LogIn
{
public:

    Applications()
    {
        admin = { 1111, "admin" };
    }
    Applications(const int& username, const string& adminpass)
    {
        admin.first = username;
        admin.second = adminpass;
    }

    friend ostream& operator<< (ostream& os, const Applications& applications)
    {
        os << "Member number\tMember\t\tMember result\n";
        map<int, string>::const_iterator it;
        map<int, int>::const_iterator itr;
        for (it = applications.members.begin(), itr = applications.result.begin(); it != applications.members.end(), itr != applications.result.end(); ++it, itr++)
            os << (*it).first << "\t\t" << (*it).second << "\t\t" << (*itr).second << endl;
        return os;
    }

    map <int, int> result;


    void PrintCertificate(const int& username);
    int GenMemberNumber();
    friend void AddMember(Applications& applications, pair <int, string>& member, const string& password);
    void GetMembers();
    friend void AddResult(Applications& applications, pair <int, int>& member);
    void FindMember(const int& membernumber);
protected:
    map <int, string> members;
};


void AddMember(Applications& applications, pair <int, string>& member, const string& password);
void AddResult(Applications& applications, pair <int, int>& member);

void adminmenu(Applications& application);
void usermenu(Applications& application, const int& username);
void mainmenu(Applications& application);