// arrays.cpp : This file contains the 'main' function. Program execution begins and ends there.
//



#include <iostream>
using namespace std;



int main(){
    //Array is a list of values stored under a common name
    // string person[3] = { "Ryuu","Veni","Darijan" }; //declaring an array of string
    // int age[3] = { 23, 25, 16 };//declaring an array of int
    // float weight[3] = { 45.0, 30.0, 25.5 };
    // char gender[3] = { 'M' , 'F', 'M' };

    string person[] = { "A", "B", "C", "D", "E" };
    int age[] = { 23, 25, 16, 12, 19 };
    float weight[] = { 1, 2, 3, 4, 5 };
    char gender[] = { 'M' , 'F', 'M', 'F', 'M'};
    


    
    //1. Find the heaviest person in the list//////////////////////////////////////////////////////////
    //Idea.1    Compare each number manually
    // if (weight[0] > weight[1] && weight[0] > weight[2]){
    //     cout << person[0] << "is the heaviest person " << endl;
    // } else if (weight[1] > weight[0] && weight[1] > weight[2]){
    //     cout << person[1] << "is the heaviest person " << endl;
    // } else {
    //     cout << person[2] << "is the heaviest person " << endl;
    // }


    //Idea.2    Use "For Loop"
    //1. Declare maxWeight and heaviestPerson
    float maxWeight = 0;
    string heaviestPerson;

    //2. Compare each number
    for (int i = 0; i < 5; i++){
        for (int j = 0; j < 5; j++){

            //3. if the weight is greater than the others and the maxWeight, then update the maxWeight and the heaviestPerson
            if (weight[i] - weight[j] > 0 && weight[i] > maxWeight){
                maxWeight = weight[i];
                heaviestPerson = person[i];
            }
        }
    }
    cout << heaviestPerson << " is the heaviest person " << "("  << maxWeight << " kg)" << endl;





    //2. Find the youngest person in the list////////////////////////////////////////////////////////////
    // //Idea.1    Compare each number manually
    // if (age[0] < age[1] && age[0] < age[2]){
    //     cout << person[0] << "is the youngest person " << endl;
    // } else if (age[1] < age[0] && age[1] < age[2]){
    //     cout << person[1] << "is the youngest person " << endl;
    // } else {
    //     cout << person[2] << "is the youngest person " << endl;
    // }

    float youngestAge = 100;
    string youngestPerson;

    //1. Compare each age
    for (int i = 0; i < 5; i++){
        for (int j = 0; j < 5; j++){

            //2. if the age is smaller than the others and the youngestAge, then update the youngestAge and the youngestPerson
            if (age[i] - age[j] < 0 && age[i] < youngestAge){
                youngestAge = age[i];
                youngestPerson = person[i];
            }
        }
    }
    cout << youngestPerson << " is the youngest person " << "("  << youngestAge << " years old)" << endl;



    //3. How many male members in the list
    int maleCount = 0;
    int femaleCount = 0;

    for (int i = 0; i < 5; i++){
        if (gender[i] == 'M'){
            maleCount++;
        } else {
            femaleCount++;
        }
    }
    cout << "There are " << maleCount << " male members" << endl;


    return 0;
}