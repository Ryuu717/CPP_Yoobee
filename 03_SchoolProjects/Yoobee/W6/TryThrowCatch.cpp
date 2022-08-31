#include <iostream>
using namespace std;

int main(){
    int a;

    // 1. throw int
    // try{
    //     cout << "Enter the nuber zero: ";
    //     cin >> a;

    //     if (a != 0) throw 101;

    // } catch(int error) {
    //     cout << "Error: " << error << "\n";
    // }


    // 2. throw string
    // try{
    //     cout << "Enter the nuber zero: ";
    //     cin >> a;

    //     if (a != 0) throw string("101");

    // } catch(string error) {
    //     cout << "Error: " << error << "\n";
    // }


    // 3. data type error(throw -> chatch)
    try{
        cout << "Enter the nuber zero: ";
        cin >> a;

        if (a != 0) throw string("101");

    } catch(int error) {
        cout << "Error: " << error << "\n";
    }

    return 0;
}