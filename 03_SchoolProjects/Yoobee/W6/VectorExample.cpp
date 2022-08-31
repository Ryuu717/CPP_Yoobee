// VectorExample.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>

using namespace std;

class Student {
public:
    string name;
    int rollno;

public :
    Student(string name, int rollno){
        this->name = name;
        this->rollno = rollno;
    }

    void display(){
        cout << " Name : " << name;
        cout << " Rollno : " << rollno;
    }
};

int main(){
    char response = 'n';
    string name;
    int rollno;
    vector<Student> s;
    int size = 0;

    do {
        cout << " Enter name : ";
        cin >> name;
        cout << " Enter Rollno : ";
        cin >> rollno;

        s.push_back(Student(name, rollno));

        cout << " Do you want to continoue.. ";
        cin >> response;

    } while (response == 'y');



    size = s.size();
    for (int i = 0; i < size; i++){
        s[i].display();
        cout << "\n\n";
    }

    return 0;
}
