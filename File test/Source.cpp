#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main()
{

	string file;
	cout << "������� ������ �������� ����� � ������� (�������� Text.txt):" << endl;
	getline(cin, file);
	string text;
	ifstream in(file);
	if (in.is_open())
	{
		getline(in, text);
	}
	else if (!in.is_open())
	{
		cout << " file don`t open" << endl;
	}
	in.close();
	cout << "Your text: " << text << endl;
}