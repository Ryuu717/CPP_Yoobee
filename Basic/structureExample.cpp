// StructureIntro.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <cstring>
using namespace std;

//structure is a complex type of data where a group of different data types 
// can be called with one name

//define the structure
struct Students {
	int age;
	float fees;
	string name;
	string phone;
	string address;

    //Constructor
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
void total_fees(struct Students bse_stud[5], int x);
void eldest(struct Students bse_stud_age[5], int y);



int main()
{
	//input
	input_data();
}



void total_fees(struct Students bse_stud[5], int x) {
	int total = 0;
	for (int i = 0; i < x; i++) {
		total += bse_stud[i].fees; // total = total + bse_stud[i].fees;
	}
	cout << "\nThe total = " << total;
}

void eldest(struct Students bse_stud_age[5], int y) {
	int eldest_age = 0;

	for (int i = 0; i < y; i++) {
        if (bse_stud_age[i].age > eldest_age)
		eldest_age = bse_stud_age[i].age;
	}
	cout << "\nThe eldest age = " << eldest_age << endl;
}


void output_data(struct Students bse_student[5], int n) {
	for (int i = 0; i < n; i++) {
		cout << "\nThe name of student" << i + 1 << " : " << bse_student[i].name;
		cout << "\nThe fees of student" << i + 1 << " : " << bse_student[i].fees;
        cout << "\nThe age of student" << i + 1 << " : " << bse_student[i].age;

	}
	total_fees(bse_student, n);
    eldest(bse_student, n);
}


void input_data() {
	struct Students bse[5];
	for (int i = 0; i < 5; i++) {
		cout << "Enter the name of student " << i + 1 << " : ";
		cin >> bse[i].name;
		cout << "Enter the fees of student" << i + 1 << " : ";
		cin >> bse[i].fees;
        cout << "Enter the age of student" << i + 1 << " : ";
		cin >> bse[i].age;
	}
	cout << "\n";
	output_data(bse, 5);
}


