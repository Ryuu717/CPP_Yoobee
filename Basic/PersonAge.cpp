// testvector.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
using namespace std;



struct Person {
    string name;
    int age;



    Person(string n = "beula", int a = 45) {
        name = n;
        age = a;
    }
};


int main(){
    vector <Person> persons;
    vector <int> age;

    int yourAge;
    int i=0;
    string ans = "yes";

    while (ans == "yes") {
        cout << "enter age: ";
        cin >> yourAge;
        age.push_back(yourAge);
        cout << "do you want to continue?";
        cin >> ans;

    }



    for (i = 0; i < age.size(); i++) {
        cout << age[i]<<endl;
    }
}