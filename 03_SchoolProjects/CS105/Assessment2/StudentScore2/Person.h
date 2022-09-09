#include<string.h>
#include<cstring>

class Person{
    protected:
    char fullName[100];
    char gender;
    int age;

    public:
    Person(char fn = ' ', char g = ' ', int a = 0){
        *fullName = fn;
        gender = g;
        age = a;
    };

    // void displayPerson();
};