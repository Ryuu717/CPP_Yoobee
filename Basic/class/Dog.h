// #ifndef ANIMAL_H
// #define ANIMAL_H

#include <string>
// #include "Animal.h"
// using namespace std;

class Dog: public Animal{
private:
    string breed;

public:
    Dog(string name, double weight, string breed);         //constructor

    string getBreed() const;
    void digHole() const;
    string makeNoise() const;
};
