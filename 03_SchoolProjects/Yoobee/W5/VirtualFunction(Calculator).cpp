#include <iostream>
using namespace std;

//abstract class with virtual function
class Cal{
    protected:
    float x, y, result;

    public:
        virtual void getNum(){
        }
        virtual void cal(){
        }
};

class Add : public Cal{
    public:
        void getNum(){
            cout << "First value: ";
            cin >> x;
            cout << "Second value: ";
            cin >> y;

            result = x + y;
        }

        void cal(){
            cout << "x = " << x << " y = " << y << " result = " << result << endl;
        }
};

class Sub : public Cal{
    public:
        void getNum(){
            cout << "First value: ";
            cin >> x;
            cout << "Second value: ";
            cin >> y;

            result = x - y;
        }

        void cal(){
            cout << "x = " << x << " y = " << y << " result = " << result << endl;
        }
};


int main(){
    Add add;
    Sub sub;

    Cal* ptr[] = {&add, &sub};

    for(int i = 0; i < sizeof(ptr)/sizeof(*ptr); i++){
        ptr[i]->getNum();
        ptr[i]->cal();
    }

    return 0;
}
