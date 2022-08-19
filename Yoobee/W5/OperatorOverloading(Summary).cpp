// C++ program to overload ++ (operator) when used as prefix
#include <iostream>
using namespace std;

class Count {
   private:
    int value;

    //constructor
   public:
    Count(int value = 5){
        this->value = value;
    };



    //1. OperatorOverloading (prefix)///////////////////////////////////////////////////////////////////////////
    void operator ++() {
        value = value + 1;
    }

    //2. OperatorOverloading(+)/////////////////////////////////////////////////////////////////////////////////
    Count operator +(Count &obj) {
        Count count;
        count.value = value + obj.value;
        return count; 
    }

    //3. OperatorOverloading(+=)/////////////////////////////////////////////////////////////////////////////////
    Count operator +=(Count &obj) {
        Count count;
        count.value = value + value + obj.value;
        return count; 
    }


    void display() {
        cout << "Count: " << value << endl;
    }
};

int main() {
    //1. Call the "void operator ++()" function
    // Count count1;
    // ++count1;
    // count1++;
    // count1.display();


    //2. OperatorOverloading(+)
    // Count count1(1), count2(2), count3;
    // count3 = count1 + count2;
    // count3.display();

    //3. OperatorOverloading(+=)
    Count count1(1), count2(2), count3;
    count3 = count1 += count2;
    count3.display();  


    return 0;
}
