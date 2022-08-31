// function_Overloading.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;


class Manipulation
{
    int x, y;
    double a, b, c;

public :
    Manipulation(){
        x = 0;
        y = 0;
        a = 0;
        b = 0;
        c = 0;
     }

   

    void display(){
        cout << "\n x = " << x;
        cout << "\n y = " << y;
        cout << "\n a = " << a;
        cout << "\n b = " << b;
        cout << "\n c = " << c;
    }

    int add(int i, int j) {
        x = i;
        y = j;
        return x + y;
    }

    double add(double i, double j, double k)
    {
        a = i;
        b = j;
        c = k;
        return a + b + c;
    }
    double add(int i, double j, double k)
    {
        x = i;
        b = j;
        c = k;

        return x + b + c;
    }

    
};


int main()
{
    Manipulation  m;
    
    m.display();

    cout << "\n\n\n";
    cout << "\n Calling two integer addition process ";
    cout << m.add(23, 45);
    cout << "\n Calling three double values addition process ";
    cout << m.add(2.3, 4.5,78);
    cout << "\n Calling one integer and two double values addition process ";
    cout << m.add(23,67,45);

    return 0;
    
}

