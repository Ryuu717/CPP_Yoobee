#include <iostream>
using namespace std;

int main()
{
    // //1. read a word
    // char str[100];
    // cout << "Enter a string: ";
    // cin >> str;
    // cout << "You entered: " << str << endl;


    // //2. String to read a line of text
    // char str[100];
    // cout << "Enter a string: ";
    // cin.get(str, 100);
    // cout << "You entered: " << str << endl;


    //3. Declaring a string object
    string str;
    cout << "Enter a string: ";
    getline(cin, str);

    cout << "You entered: " << str << endl;






    return 0;
}