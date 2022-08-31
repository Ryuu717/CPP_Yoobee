#include <iostream>
#include "Animal.h"
#include "Dog.h"
#include "Cat.h"
using namespace std;

//Constructer
Animal::Animal(string name, double weight){
    this->name = name;
    this->weight = weight;
}

//Overrides
string Animal::getName() const {
    return name;
}
double Animal::getWeight() const {
    return weight;
}
string Animal::makeNoise() const {
    return "Unknown";
}


// Dog
Dog::Dog(string name, double weight, string breed) : Animal(name, weight) {     //Passing argument
    this->breed = breed;
}
string Dog::getBreed() const{
    return breed;
}
void Dog::digHole() const{
    cout << "I'm digging a hole";
}
string Dog::makeNoise() const{          //override
    return "Woof";
}

//Cat
Cat::Cat(string name, double weight) : Animal(name, weight) {                   //Passing argument
}
void Cat::chaseMouse() const{
    cout << "I am chasing a mosue!" << "\n"; 
}
string Cat::makeNoise() const{          //override
    return "Meow!"; 
}



int main (){
    //create object
    Animal a1("myPet", 100);
    Dog d1("Rover", 80, "breed");
    Cat c1("Felix", 12);

    cout << "Animal name: " << a1.getName() << "\n";
    cout << "Animal weight: " << a1.getWeight() << "\n";
    cout << "Animal noise: " << a1.makeNoise() << "\n\n";

    cout << "Dog's name: " << d1.getName() << "\n";
    cout << "Dog's weight: " << d1.getWeight() << "\n";
    cout << "Dog's noise: " << d1.makeNoise() << "\n";
    cout << "Dog's breed: " << d1.getBreed() << "\n";
    d1.digHole();
    cout << "\n\n";
    
    cout << "Cat's name: " << c1.getName() << "\n";
    cout << "Cat's weight: " << c1.getWeight() << "\n";
    cout << "Cat's noise: " << c1.makeNoise() << "\n";

    return 0;
}