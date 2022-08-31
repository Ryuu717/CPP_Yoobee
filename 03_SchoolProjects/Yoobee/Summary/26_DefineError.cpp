#include <iostream>
using namespace std;

#define error1 101                      //define error code
#define error2 "Enter less than 10"

int main(){
    int a;
    
    try{
        cout << "Enter a natural number(1 - 10): ";
        cin >> a;

        if (a <= 0){
            throw error1;
        } else if(a > 10) {
            throw string(error2);
        }
            

    } catch(int e1) {
        cout << "Error: " << e1 << "\n";
    } catch (string e2) {
        cout << "Error: " << e2 << "\n";
    }

    return 0;
}