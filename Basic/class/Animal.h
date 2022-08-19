// #ifndef ANIMAL_H
// #define ANIMAL_H

#include <string>
using namespace std;

class Animal{
private:
    string name;
    double weight;

public:
    Animal(string name, double weight);         //constructor
    
    string getName() const;
    double getWeight() const;
    
    string makeNoise() const;
};
