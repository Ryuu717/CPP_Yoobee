// C++ program to overload ++ (operator) when used as prefix
#include <iostream>
using namespace std;

class ClassA {
   public:
   void display(){
    cout << "A" << endl;
   }
};

class ClassB : public ClassA{
    public:
    void display(){
        cout << "B" << endl;
   }
};

int main() {
    // ClassA classA;
    ClassB classB;

    // classA.display();
    classB.display();
    

    return 0;
}
