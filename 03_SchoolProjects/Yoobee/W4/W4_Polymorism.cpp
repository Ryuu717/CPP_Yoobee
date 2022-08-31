#include <iostream>
using namespace std;

class Manipulation1{
    protected:
        int x, y;
    
    public:
        Manipulation1(int x = 0, int y = 0){
            this->x = x;
            this->y = y;
        }

        void add(int x, int y){
            cout << x + y << "\n";
        };
};

class Manipulation2 : public Manipulation1{
    public:
        void add(double x, double y, double z){
            cout << x + y + z << "\n";
        };
};

class Manipulation3 : public Manipulation2{
    public:
        void add(int x, double y, double z){
            cout << x + y + z << "\n";
        };
};


int main(){
    Manipulation1 manipulation1;
    Manipulation2 manipulation2;
    Manipulation3 manipulation3;

    manipulation1.add(1.1, 2.2);
    manipulation2.add(1.1, 2.2, 3.3);
    manipulation3.add(1.1, 2.2, 3.3);


    return 0;
}

