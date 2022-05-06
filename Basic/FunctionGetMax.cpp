// arrays.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;


string getMaxWeight (float weightArray[], string personArray[], int arraySize);
string getYoungestPerson (int ageArray[], string personArray[], int arraySize);
int getMaleCount (char gender[], int arraySize);



int main(){
    //Array is a list of values stored under a common name
    string person[3] = { "Ryuu","Veni","Darijan" };
    int age[3] = { 23, 25, 16 };    
    float weight[3] = { 45.0, 30.0, 25.5 };
    char gender[3] = { 'M' , 'F', 'M' };


    cout << getMaxWeight(weight, person, 3) << " is the heaviest person " << endl;
    cout << getYoungestPerson(age, person, 3) << " is the youngest person " << endl;
    cout << "There are " << getMaleCount(gender,3) << " male members" << endl;

    return 0;
}



string getMaxWeight (float weightArray[], string personArray[], int arraySize) {
    float maxWeight = 0;
    string heaviestPerson;

    for (int i = 0; i < arraySize; i++){
        if (weightArray[i] > maxWeight){
            maxWeight = weightArray[i];
            heaviestPerson = personArray[i];
        }
    }
    return heaviestPerson;
}

string getYoungestPerson (int ageArray[], string personArray[], int arraySize) {
    int youngestAge = 100;
    string youngestPerson;

    for (int i = 0; i < arraySize; i++){
        if (ageArray[i] < youngestAge){
            youngestAge = ageArray[i];
            youngestPerson = personArray[i];
        }
    }
    return youngestPerson;
}

int getMaleCount(char genderArray[], int arraySize){
    int maleCount = 0;
    int femaleCount = 0;

    for (int i = 0; i < arraySize; i++){
        if (genderArray[i] == 'M'){
            maleCount++;
        } else {
            femaleCount++;
        }
    }
    return maleCount;
}