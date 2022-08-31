#include <iostream>
using namespace std;

int main(){
    int a;

    //////////////////////////////////////////////////////////////////////////////////////////
    // 1. throw int
    //////////////////////////////////////////////////////////////////////////////////////////
    // try{
    //     cout << "Enter a natural number(1 - 10): ";         // 0 is not a natural number
    //     cin >> a;

    //     if (!a) throw 101;

    // } catch(int error) {
    //     cout << "Error: " << error << "\n";
    // }


    //////////////////////////////////////////////////////////////////////////////////////////
    // 2. throw string
    //////////////////////////////////////////////////////////////////////////////////////////
    // try{
    //     cout << "Enter a natural number(1 - 10): ";
    //     cin >> a;

    //     if (!a) throw string("101");

    // } catch(string error) {
    //     cout << "Error: " << error << "\n";
    // }


    //////////////////////////////////////////////////////////////////////////////////////////
    // 3. multiple throw
    //////////////////////////////////////////////////////////////////////////////////////////
    // try{
    //     cout << "Enter a natural numbe(1 - 10): ";
    //     cin >> a;

    //     if (a <= 0){
    //         throw 101;
    //     } else if(a > 10) {
    //         throw string("Enter less than 10");
    //     }

    // } catch(int error1) {
    //     cout << "Error: " << error1 << "\n";
    // } catch (string error2) {
    //     cout << "Error: " << error2 << "\n";
    // }


    //////////////////////////////////////////////////////////////////////////////////////////
    // 4. catch all exceptions
    //////////////////////////////////////////////////////////////////////////////////////////
    try{
        cout << "Enter a natural numbe(1 - 10): ";
        cin >> a;

        if (a <= 0){
            throw 101;
        } else if(a > 10) {
            throw string("Enter less than 10");
        }

    } catch(...) {              //catch all exceptions
        cout << "Error\n";
    }
}