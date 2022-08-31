#include <iostream>
using namespace std;

//abstract class with virtual function
class Shape{
    public:
        virtual void draw(){
            cout << "Shape\n";
        }
};

class Triangle : public Shape{
    public:
        void draw(){
            // cout << "Triangle\n";
            int num1=10;
            

            // for (int i = 0; i < 10; i++){
            //     for (int j = 0; j < num1; j++){
            //         cout << " ";
                    
            //     }
            //     cout << "*";
            //     cout << "\n";
            //     num1--;
            // }


            int num2=0;

            for (int i = 0; i < 10; i++){

                for (int j = 0; j < num2; j++){
                    cout << "*";
                    
                }
                cout << "\n";
                num2++;
            }
        }
};

class Square : public Shape{
    public:
        void draw(){
            cout << "Square\n";
        }
};


int main(){
    Triangle triangle;
    Square square;

    // 1. single
    Shape* obj = new Triangle;
    obj->draw();


    //2. multi
    // Shape* ptr[] = {&triangle, &square};

    // // for(int i = 0; i < 2; i++){
    // for(int i = 0; i < sizeof(ptr)/sizeof(*ptr); i++){
    //     ptr[i]->draw();
    // }

    return 0;
}
