#include <iostream>
using namespace std;

//abstract class with virtual function
class Shape{
    public:
        virtual void draw(){    //virtual function
            cout << "Shape\n";
        }
};

class Triangle : public Shape{
    public:
        void draw(){
            cout << "Triangle\n";
        }
};

class Square : public Shape{
    public:
        void draw(){
            cout << "Square\n";
        }
};


int main(){
    Shape shape;
    Triangle triangle;
    Square square;

    // 1. single
    // Shape* obj = new Triangle;
    // obj->draw();


    //2. multi
    Shape* ptr[] = {&shape, &triangle, &square};

    // for(int i = 0; i < 2; i++){
    for(int i = 0; i < sizeof(ptr)/sizeof(*ptr); i++){
        ptr[i]->draw();
    }


    return 0;
}
