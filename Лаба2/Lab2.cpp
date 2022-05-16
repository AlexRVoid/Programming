/*
������� 1.
���� ����� ॡ�� a, b, c ��אַ㣮�쭮�� ��ࠫ����������.
���� ��� ��ꥬ V = a�b�c � ���頤� �����孮�� S = 2�(a�b + b�c + a�c).

������� 2
���뢠� ���ᨢ nums 楫�� �ᥫ,
������, ᪮�쪮 �� ��� ᮤ�ঠ� ���⭮� ������⢮ ���.

������� 3
��� ������� ���姭�筮�� �᫠ ��।����� ���� �� ��� ������஬��
(��⠥��� ��������� � �� ��஭�, ���ਬ�� 101, 222 � �.�.).
*/
#include <iostream>
#include <vector>
using namespace std;

void Task1()
{
int a, b, c;
    cout << "Enter the length:";
        cin >> a;
    cout << "\nEnter the width:";
        cin >> b;
    cout << "\nEnter the height:";
        cin >> c;
    int V, S;
    S = 2 * (a * b + b * c + a * c);
        cout << "S = " << S << endl;
    V = a * b * c;
        cout << "V = " << V << endl;
}

void Task2()
{
    int n, s;        //n - ���-�� �室��� �ᥫ, s - ���-�� ���室��� �ᥫ
        s = 0;
    cout << "Enter the number of numbers in the array: ";
        cin >> n;
    vector <int> nums(n, 0);       //���樠������ ���ᨢ�

    for (int i = 1; i <= n; i++) {
        nums[i] = rand() % 9999;         //࠭��� ���祭��
        cout << nums[i] << " ";             //�뢮� ������������ ���ᨢ�
    }

    cout << "\n";

    for (int i = 1; i <= n; i++) {         //��ॡ�� ���祭��
        int o = nums[i];      //���祭�� �� �����
        int k = 0;                  //���-�� ���
        if (o != 0) {                //�஢�ઠ �� 0
            while (o != 0) {                      //������� ���
                o = o / 10;
                k++;
            }
        if (k % 2 == 1)
            s++;
        }
    }

    cout << s;

}

void Task3()
{
    while (true)
    {
        int num;
        cout << "Enter The number:";
        cin >> num;
        if (num >= 100 && num < 1000) { // �஢���, ���� �� �᫮ ���姭��� ��� ���
            if (num / 100 == num % 10)// �஢�ઠ, ���� �� �᫮ ������஬��
                cout << "Yes" << endl;
            else cout << "No" << endl;
        }
        else
            cout << "No" << endl;
        num = 0;
        bool res;
        cout << "Continue or not(1/0):";
            cin >> res;
        if (res == 0)
            break;
    }
}


int main()
{
    int task;
    cout << "Select a task:";
        cin >> task;
    if (task == 1) {
        cout << "Task 1:" << endl;
        Task1();
    }
    if (task == 2) {
        cout << "\nTask 2:" << endl;
        Task2();
    }
    if (task == 3) {
        cout << "\nTask 3:" << endl;
        Task3();
    }
    return 0;
}

