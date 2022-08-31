// #ifndef CAT_H
// #define CAT_H 

#include <string> 
// #include "Animal.h"

class Cat: public Animal{
    public:
        Cat(string name, double weight); 
        void chaseMouse() const;
        string makeNoise() const; 
};


