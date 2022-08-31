// StructureIntro.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
#include <cstring>
using namespace std;

//structure is a complex type of data where a group of different data types
// can be called with one name//define the structure

struct Students {
    int age;
    float fees;
    string name;
    string phone;
    string address; 
    
    Students(int a = 0, float f = 0, string n = "", string p = "", string ad = "") {
        age = a;
        fees = f;
        name = n;
        phone = p;
        address = ad;
    }
};

//funtion prototypes
void input_data();
void output_data(struct Students bse_student[5], int n);




int main()
{
    //input
    input_data();

}

void output_data(struct Students bse_student[5], int n) {
    int i;
    float total_fees = 0;

    for (i = 0; i < n; i++) {
        cout << "\nThe name of student" << i + 1 << " : " << bse_student[i].name;
        cout << "\nThe fees of student" << i + 1 << " : " << bse_student[i].fees; 
    }

    //total_fees()
    for (i = 0; i < n; i++){
        total_fees += bse_student[i].fees;
    }
    cout << endl;
    cout << "Total fee is $ " << total_fees << endl;

}

void input_data() {
    struct Students bse[5];
    int i;
    for (i = 0; i < 5; i++) {
        cout << "Enter the name of student " << i + 1 << " : ";
        cin >> bse[i].name;
        cout << "\nEnter the fees of student" << i + 1 << " : ";
        cin >> bse[i].fees;
    }
    output_data(bse, 5);
}
