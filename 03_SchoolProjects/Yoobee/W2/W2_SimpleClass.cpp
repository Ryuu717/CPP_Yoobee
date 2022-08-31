#include <iostream>
using namespace std;

class SimpleClass {                //define classs
    int number;                      //class data
    float cost;                      //class data
public:
    void setData(int a, float b);    //member function to set data

    void getData(void)              //member function to display data
    {
        cout << "number: " << number << "\n";
        cout << "cost: " << cost << "\n";
    }
};
void SimpleClass::setData(int a, float b) //Defining member function
{                                         //outside the class definition
    number = a;
    cost = b;
}

int main()
{
    SimpleClass x;                          // define  object of class SimpleClass
    cout << "\nobject x" << "\n";

    x.setData(100, 299.95);                 //call member function to set data
    x.getData();                            // call member function to display data

    SimpleClass y;                          // define  objects of class SimpleClass
    cout << "\nobject y" << "\n";

    y.setData(200, 175.50);
    y.getData();
    return 0;
}