// doubleDimension.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

int main()
{
    int a[3][3] = { {0,1,2},{3,4,5}, {6,7,8} };//Matrix of 3 rows and 3 columnns can store 9 values
    int b[3][3] = { {10,20,30},{40,50,60},{70,80,90} };
    int i, j;
    cout << "A Matrix" << endl;
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            cout << a[i][j]<< "\t";
        }
        cout << "\n";
    }
    cout << "\n";
    cout << "B Matrix" << endl;
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            cout << b[i][j] << "\t";
        }
        cout << "\n";
    }
    cout << "\n";
    cout << "A+B Matrix" << endl;

    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            cout << a[i][j] + b[i][j] << "\t";
        }
        cout << "\n";
    }

    cout << "\n";
    cout << "B-A Matrix" << endl;

    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            cout <<  b[i][j] - a[i][j] << "\t";
        }
        cout << "\n";
    }

    cout << "\n";
    cout << "Multiply Matrix A with 5" << endl;

    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            cout << 5 *  a[i][j] << "\t";
        }
        cout << "\n";
    }
}
