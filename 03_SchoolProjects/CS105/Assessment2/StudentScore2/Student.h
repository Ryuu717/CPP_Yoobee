#include <string>
using namespace std;

class Student : public Person{
    // private:
    string courseName;
    int module1;
    int module2;
    int module3;

    public:
    Student(string cn = " ", char m1 = 0, char m2 = 0, char m3 = 0){
        courseName = cn;
        module1 = m1;
        module2 = m2;
        module3 = m3;
    };

    void readRec();
    void displayRec();
    string grade(int grade);
};