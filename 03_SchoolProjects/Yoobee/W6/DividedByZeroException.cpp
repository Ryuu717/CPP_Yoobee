// ExceptionEx.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

int main(){
    double x, y;
    try {
            cout << "Enter x value :";
            cin >> x;
            cout << "Enter y value :";
            cin >> y;

            if (y == 0.0){
                throw string("Divided by zero error");
            }
            else{
                cout << "\n\n x/y = " << x / y;
            }

    }catch (string u){
        cout << "\n Error code :" << u;
        cout << " \n Please feed non zero to y...";
    }

    cout << "\n\n\n";
    return 0;
}
