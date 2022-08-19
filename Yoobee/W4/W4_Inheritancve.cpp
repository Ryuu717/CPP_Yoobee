#include <iostream>
using namespace std;

class Person{
    protected:
        string name;
        int phoneNumber;
    
    public:
        Person(string n=" ", int pn = 000000000){
            name = n;
            phoneNumber = pn;
        }

        void read(string name, int phoneNumber){
            this->name = name;
            this->phoneNumber = phoneNumber;
        };

        void display(){
            cout << "Name: "<< name << "\n";
            cout << "Phone Number: "<< phoneNumber << "\n";
        };
};

class Student : public Person{
    // private:
    public:
        string courseName;
        float courseFees;

    Student(string n=" ", int pn = 000000000, string cn = " ", float cf = 0) : Person(n,pn){
        this->courseName = cn;
        this->courseFees = cf;
    }

    public:
        void read(string courseName, int courseFees){
            this->courseName = courseName;
            this->courseFees = courseFees;
        }

        void display(){
            cout << "Course Name: "<< courseName << "\n";
            cout << "Course Fees: "<< courseFees << "\n";
        }
};

class Academic : public Student{
    public:
        char M1, M2, M3;

    Academic(string n=" ", int pn = 000000000, string cn = " ", float cf = 0, char m1 = 0, char m2 = 0, char m3 = 0) : Student(n,pn,cn,cf){
        this->M1 = m1;
        this->M2 = m2;
        this->M3 = m3;
    }

    public:
    void read(char M1, char M2, char M3){
        this->M1 = M1;
        this->M2 = M2;
        this->M3 = M3;
    }

    void display(){
        cout << "M1: "<< M1 << "\n";
        cout << "M2: "<< M2 << "\n";
        cout << "M3: "<< M3 << "\n";
    }
};



int main(){
    Person person;
    Student student;
    Academic academic;

    person.read("A", 111111);
    person.display();

    student.read("Course A", 100);
    student.display();
    
    academic.read('A', 'B', 'C');
    academic.display();


    return 0;
}

