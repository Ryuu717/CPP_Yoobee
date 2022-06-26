#include <iostream>
using namespace std;

int main(){
    int value{};
        string entry {};
        bool done = false;
        do {
            cout << "Please enter an integer: ";
            getline(cin, entry);
            istringstream validator {entry};
            if (validator >> value) 
                done = true;
            else 
                cout << "Sorry, that's not an integer" << endl;
                
            // no need to use cin.ignore
        } while (!done);
        
        cout << "You entered the integer: " << value << endl;
        
        cout << endl;
}
