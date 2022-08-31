#include <iostream>
using namespace std;

class Circle{
    private:
        float radius;

    public:
        void area(float radius){
            float area = radius * radius * 3.14;
            cout << "Area is " << area << "\n";
        }
};

int main(){
    Circle circle;
    // Student stu1, stu2, stu3,stu4;

    float radius;

    cout << "Give me a radius(cm): ";
    cin >> radius;

    circle.area(radius);
    

    return 0;
}
