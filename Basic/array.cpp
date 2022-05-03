// arrays.cpp : This file contains the 'main' function. Program execution begins and ends there.
//



#include <iostream>
using namespace std;



int main(){
    //Array is a list of values stored under a common name
    string person[3] = { "Ryuu","Veni","Darijan" }; //declaring an array of string
    int age[3] = { 23, 25, 16 };//declaring an array of int
    float weight[3] = { 45.0, 30.0, 25.5 };
    char gender[3] = { 'M' , 'F', 'M' };


    //Task///////////////////////////////////////////////////
    //1. Find the heaviest person in the list
    if (weight[0] > weight[1] && weight[0] > weight[2]){
        cout << person[0] << "is the heaviest person " << endl;
    } else if (weight[1] > weight[0] && weight[1] > weight[2]){
        cout << person[1] << "is the heaviest person " << endl;
    } else {
        cout << person[2] << "is the heaviest person " << endl;
    }

    //2. Find the youngest person in the list
    if (age[0] < age[1] && age[0] < age[2]){
        cout << person[0] << "is the youngest person " << endl;
    } else if (age[1] < age[0] && age[1] < age[2]){
        cout << person[1] << "is the youngest person " << endl;
    } else {
        cout << person[2] << "is the youngest person " << endl;
    }

    //3. How many male members in the list
    int maleCount = 0;
    int femaleCount = 0;

    for (int i = 0; i <3; i++){
        if (gender[i] == 'M'){
            maleCount++;
        } else {
            femaleCount++;
        }
    }
    cout << "There are " << maleCount << " male members" << endl;


    return 0;
}