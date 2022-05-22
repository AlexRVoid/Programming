#include <iostream>
#include <math.h>
#include <stdio.h>
using namespace std;

void Task1 ()
{
    cout << "X" << " " << "Y" << endl;
    for (int x = -8, y = -3; x <= -5; x++)
    {
        cout << x << " " << y << endl;
    }
    for (double x = -5, y = -3.0; x <= -3; x++)
    {
        y = 1.5 * x + 4.5;
        cout << x << " " << y << endl;
    }
    for (double x = -3, y = 0; x <= 3 ; x++)
    {
        y += x;
        cout << x << " " << y << endl;
    }
    for (double x = 3, y = 0; x <= 8; x++)
    {
        y = 0.2727 * x + 0.8181;
        cout << x << " " << y << endl;
    }
    for (int x = 8, y = 3; x <= 10; x++)
    {
        cout << x << " " << y << endl;
    }
}

void Task2 ()
{

}

void Task3 ()
{

}

void Task4 ()
{

}

void Task5 ()
{

}

void Task7 ()
{

}

int main ()
{
    cout << "Task 1:" << endl;
    Task1;
}