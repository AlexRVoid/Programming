#pragma once
#include "Application.h"

using namespace std;

void adminmenu(Applications& application)
{


    while (true)
    {
        system("cls");
        cout << "What do you need?\n" << "1)Add member;\n" << "2)Add result;\n" << "3)Find member;\n" << "4)Display a table of members;\n" << "5)Printing of the certificate;\n" << "6)Exit\n";
        int choice;
        cin >> choice;
        if (choice == 1)
        {
            string password;
            pair <int, string> member;
            cout << "Enter the full name of member:" << endl;
            string name;
            cin.ignore();
            getline(cin, member.second);
            //cin.ignore();
            cout << "Come up with a password: ";
            getline(cin, password);
            member.first = application.GenMemberNumber();
            AddMember(application, member, password);
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
            cout << application;
            system("pause");
        }
        else if (choice == 5)
        {
            int username;
            cout << "Enter the member number: ";
            cin >> username;
            application.PrintCertificate(username);
        }
        else if (choice == 6)
        {
            break;
        }

    }

}

void usermenu(Applications& application, const int& username)
{
    while (true)
    {
        system("cls");
        cout << "What do you need?\n" << "1)View the results table\n" << "2)View your result\n" << "3)Printing of the certificate\n" << "4)Exit" << endl;
        int choice;
        cin >> choice;
        if (cin.fail())
        {
            cout << "Incorrect input!!!" << endl;
            continue;
        }
        switch (choice)
        {
        case 1:
        {
            application.GetMembers();
            break;
        }
        case 2:
        {
            application.FindMember(username);
            break;
        }
        case 3:
        {
            application.PrintCertificate(username);
        }
        case 4:
        {
            return;
        }
        default:
        {
            system("cls");
            cout << "Incorrect input!!!" << endl;
            system("pause");
            break;
        }
        }
    }
}

void mainmenu(Applications& application)
{
    while (true)
    {
        system("cls");
        cout << "What do you need?\n" << "1)Submit an application\n" << "2)LogIn\n" << "3)Exit" << endl;
        int choice;
        cin >> choice;
        if (cin.fail())
        {
            system("cls");
            cout << "Incorrect input!!!" << endl;
            cin.clear();
            cin.ignore();
            system("pause");
            continue;
        }
        switch (choice)
        {
        case 1:
        {
            string password;
            pair <int, string> member;
            cout << "Enter the full name of member:" << endl;
            string name;
            cin.ignore();
            getline(cin, member.second);
            //cin.ignore();
            cout << "Come up with a password: ";
            getline(cin, password);
            member.first = application.GenMemberNumber();
            AddMember(application, member, password);
            break;
        }
        case 2:
        {
            while (true)
            {
                string password;
                int username;
                cout << "Enter the member's number: ";
                cin >> username;
                if (cin.fail())
                {
                    continue;
                }
                cout << "Enter the password: ";
                cin.ignore();
                getline(cin, password);
                if (application.AdminLogIn(username, password))
                {
                    adminmenu(application);
                    break;
                }
                if (application.UserLogIn(username, password) != 0)
                {
                    usermenu(application, username);
                    break;
                }
            }
            break;
        }
        case 3:
            exit(1);
        }
    }
}