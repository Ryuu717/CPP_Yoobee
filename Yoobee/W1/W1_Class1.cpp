#include <iostream>
using namespace std;

class Student{
    private:
        int id;
        string firstName;
        string lastName;
        int age;

    public:
        void setID(int inputID){
            id = inputID;
        }

        void setName(string first, string last){
            firstName = first;
            lastName = last;
        }

        void setAge(int age){
            this->age = age;        //pointer needs because using the same name(age)
        }

        void printInfo(){
            // cout << "Student name: " << firstName << " " << lastName << "\n";
            cout << "Student name: " << firstName << " " << lastName << "\n";
            cout << "Student ID: " << id << "\n";
            cout << "Student age: "<< age << "\n";
        }
};

int main(){
    Student stu;
    // Student stu1, stu2, stu3,stu4;

    stu.setID(1234);
    stu.setName("First", "Last");
    stu.setAge(20);
    
    stu.printInfo();

    return 0;
}
