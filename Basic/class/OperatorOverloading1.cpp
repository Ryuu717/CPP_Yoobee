
#include<iostream>
using namespace std;
 
class Complex {
private:
    int weight, height;

public:
    Complex(int r = 0, int i = 0) {     //constructor
        weight = r;   
        height = i;
    }
     
    // This is automatically called when '+' is used with
    // between two Complex objects
    
    Complex operator + (Complex const &obj) {
         Complex res;
         res.weight = weight + obj.weight;
         res.height = height + obj.height;
         return res;
    }
    void print() { cout << weight << " + i" << height << '\n'; }
};
 
int main()
{
    Complex c1(10, 5), c2(2, 4);
    Complex c3 = c1 + c2;
    c3.print();
}