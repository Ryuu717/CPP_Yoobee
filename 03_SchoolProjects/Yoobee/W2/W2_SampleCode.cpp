// Sample Code.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

class Student {

    int id;

public:
    string name;
    
    void setID(int id) {
        this->id = id;
    }

    int getID() {
        return id;
    }

    string getName() {
        return name;
    }

};

int main()
{
    //Using Reference variable
    Student std1;

    //The created object then can use the . (dot) to access any public members of the class.
    std1.setID(001);

    //Using New operator
    Student* std2 = new Student();

    //The created object then can use the -> to access any public members of the class.
    std2->setID(002);

}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
