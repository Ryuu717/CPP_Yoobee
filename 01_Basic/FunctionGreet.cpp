#include <iostream>
using namespace std;


//Take the name of a person in the main function and pass it to a function called Greet.///////////

//Greet function
void Greet (string name) {
  cout << "Nice to meet you " << name << endl;
}


int main() {
    string name;
    
    //Take the name of a person
    cout << "What's your name? : " ;
    cin >> name;

    //Called Greet function
    Greet(name);
    
    return 0;
}
