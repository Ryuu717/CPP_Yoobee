#include"Person.h"
#include"Student.h"
#include<iostream>
using namespace std;


void Student:: readRec(){
	cout << "Enter your name : ";
	cin.getline(fullName, 30);
	cout << "Enter your gender : ";
	cin >> gender;
	cout << "Enter your age : ";
	cin >> age;
	cout << "Enter class name : ";
	cin >> courseName;
	cout << "Enter Module1 : ";
	cin >> module1;
	cout << "Enter Module2 : ";
	cin >> module2;
	cout << "Enter Module3 : ";
	cin >> module3;
}


void Student::displayRec(){
	cout << "\nStudent Name : \t" << fullName;
	cout << "\nGender : \t" << gender;
	cout << "\nAge : \t\t" << age;
	cout << "\nCourse Name : \t" << courseName;
	cout << "\nModule1 : \t"<< grade(module1);
	cout << "\nModule2 : \t"<< grade(module2);
	cout << "\nModule3 : \t"<< grade(module3);
	cout << "\n\n ※ Achieved ≧ 80";
	cout << "\n\n";
}

string Student::grade(int grade){
	if (grade < 80){
		return "Not Achieved";
	} else {
		return "Achieved";
	}
}



int main(){
	int n = 0;
	Student* s[20];
	char user_response = 'y';

	do {
		s[n] = new Student();
		s[n]->readRec();

		n++;

		cout << "\n\n Do you wish to continue ...(y/n) :";
		cin >> user_response;
		cin.clear();   // clear the buffer 
		cin.ignore();  // ignoring the numeric limits 

	} while (user_response == 'y' || user_response == 'Y');


	// printing the records 
	cout << "\n\n************************************************\n";
	cout << "Student details ...\n";
	cout << "************************************************\n";
	for (int i = 0; i < n; i++)
	{
		s[i]->displayRec();
	}
}

