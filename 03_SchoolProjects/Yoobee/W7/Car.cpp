#include <iostream>
using namespace std;

class Car {
    string name; 
    int y; 

public:     
    Car(string n = " ", int d = 0) { 
        name = n; 
        y= d;
    }
    void display(){
        cout << "\nCar Name: " << name; 
        cout << "\nYear: " << y ;
    }
};


int main() { 
    string nm; 
    int y1; 
    Car* cPtr[100]; //array of pointers to Car objects 
    int n = 0; //number of cars on list 
    char choice; 

    do {
        cout << "Enter the Car Name: ";
        cin >> nm; 
        cout << "Enter year: "; 
        cin >> y1; 

        //Normal object
        // Car c1(nm, y1);
        // cPtr[n] = &c1;

        //New object
        cPtr[n] = new Car(); // using New
        n++; 
        
        cout << " Enter another Car detail(y / n) ? "; 
        cin >> choice; 
    } 

    while (choice == 'y'); //cycle until not 'y' 
    cout << "\nCar List: "; 
    for (int j = 0; j < n; j++){ //print names of all
    cPtr[j]->display();
    } 
    
    return 0; 
} 