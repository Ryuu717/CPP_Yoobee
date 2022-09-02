#include <iostream>
#include <vector>
using namespace std;


int main() {
    ///////////////////////////////////////////////////////////////////
    // Array-1 (without vector)
    ///////////////////////////////////////////////////////////////////
    // int a[] = {1, 2, 3};
    // float b[] = {0.1, 0.2, 0.3};
    // double c[] = {0.1, 0.2, 0.3};
    // string d[] = {"a", "b", "c"};
    // char e[] = {'A', 'B', 'C'};

    // for(int i = 0; i < size(a); i++){           // = for(int i = 0; i < 3; i++){
    //     cout << "int: \t" << a[i] << "\n";
    // }


    ///////////////////////////////////////////////////////////////////
    // Array-2 (vector)
    ///////////////////////////////////////////////////////////////////
    vector<int> vectorA;
    vector<float> vectorB;
    vector<string> vectorC;
    vector<char> vectorD;

    int value;
    char isContinue = 'y';

    //input
    while (isContinue == 'y') {
        cout << "Enter value: ";
        cin >> value;

        vectorA.push_back(value);

        cout << "Do you want to continue? (y/n): ";
        cin >> isContinue;
    }

    //output
    for (int i = 0; i < size(vectorA); i++) {           // = for(int i = 0; i < 3; i++){
        cout << "Value " << i + 1 << ":\t" << vectorA[i] << "\n";
    }

    return 0;
}