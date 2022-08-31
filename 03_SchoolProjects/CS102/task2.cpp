#include <iostream>
using namespace std;

int main() {
    // 1. Get start & end numbers
    int startNum, endNum;
    cout << "Enter starting number: ";
    cin >> startNum;
    cout << "Enter final number: ";
    cin >> endNum;
    cout << endl;


    // 2. Numbers divisible by 7
    cout << "Numbers divisible by 7 from " << startNum << " to " << endNum << endl;
    cout << "******************************" << endl;

    for (int i = startNum; i <= endNum; i++){
        if (i%7==0){        
            cout << i << ",";
        }
    } 
    cout << endl << endl;

    // 3. Prime Numbers
    cout << "Prime Numbers" << endl;
    cout << "******************************" << endl;

    int totalNum = 0;

    for (int i = startNum; i <= endNum; i++){
        if (i%2 != 0 & i%3 != 0 & i%5 != 0 & i%7 != 0){        
            cout << i << ",";
            totalNum++;
        }
    } 
    cout << endl;
    cout << "Total number of prime numbers from (20 and 70) :" << totalNum << endl;

    return 0;
}