// C++ program to overload ++ (operator) when used as prefix
#include <iostream>
using namespace std;

class Count {
   private:
    int value;

   public:
    // Constructor to initialize count to 5
    // Count() : value(5) {}
    Count(int value = 5){
        this->value = value;
    };

    // Overload ++ when used as prefix
    void operator ++() {
        value = value + 1;
    }

    void display() {
        cout << "Count: " << value << endl;
    }
};

int main() {
    Count count1;

    // Call the "void operator ++()" function
    ++count1;
    // count1++;

    count1.display();
    return 0;
}
