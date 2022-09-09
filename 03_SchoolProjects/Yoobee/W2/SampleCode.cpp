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