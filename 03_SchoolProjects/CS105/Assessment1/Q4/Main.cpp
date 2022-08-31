#include <iostream>
#include <vector>
#include <stdlib.h>        //srand, rand
#include "Alien.h"
#include "Offspring.h"
using namespace std;

int main (){
  Alien alien;
  Offspring base1, base2, offspring;  //base1,2 = base parents
  vector<Alien> vectorAlien;          //to store aliens
  vector<Offspring> vectorOffspring;  //to store offsprings

  string name;
  float weight, height;
  char gender;
  char answer = 'y';
  bool isContinue = true;
  char isBreed = 'y';
  srand (time(NULL));                                   //seed random

  string parentName1, parentName2, offspringName;                             //to create offsprings
  string offspringName1, offspringName2, offspringGender1, offspringGender2;  //to compare prestiges
  float firstOffspringPrestige, secondOffspringPrestige;


  while(isContinue){
    //show main menu
    alien.menu();

    //switch depend on the user input
    switch(alien.selectedMenu){
      case 1:
        //get user input
        cout << "*******************************************\n";
        cout << "Enter alien Information\n";
        cout << "*******************************************\n";
        while(answer == 'y'){                                //Repeat until no
            cout << "  Name: ";
            cin >> alien.name;
            cout << "  Weight(kg): ";
            cin >> alien.weight;
            cout << "  Height(cm): ";
            cin >> alien.height;
            cout << "  Gender(M/F): ";
            cin >> alien.gender;

            vectorAlien.push_back(alien);                         //store data
            cout << "\nDo you want to continue? (y/n): ";
            cin >> answer;
            cout << "\n";
        }

        //output
        cout << "*******************************************\n";
        cout << "Result\n";
        cout << "*******************************************\n";

        for (int i = 0; i < vectorAlien.size(); i++) {
          cout << "Alien " << i + 1 << "\n";
          vectorAlien[i].display();                  
        }
        cout << "   ※Prestige = Height * Weight * Gender Points (M = 2, F = 3)\n\n";
        break;


      case 2:
        while(isBreed == 'y'){
          cout << "Enter first parent alian name: ";
          cin >> parentName1;
          cout << "Enter second parent alian name: ";
          cin >> parentName2;
          cout << "Enter offspring alian name: ";
          cin >> offspringName;
          
          for (int i = 0; i < vectorAlien.size(); i++){
            if (vectorAlien[i].getName() == parentName1){
              base1.weight = vectorAlien[i].getWeight();
              base1.height = vectorAlien[i].getHeight();
              base1.gender = vectorAlien[i].getGender();
              base1.prestige = vectorAlien[i].getPrestige(base1.weight, base1.height, base1.gender);
            }            
            if (vectorAlien[i].getName() == parentName2){
              base2.weight = vectorAlien[i].getWeight();
              base2.height = vectorAlien[i].getHeight();
              base2.gender = vectorAlien[i].getGender();
              base2.prestige = vectorAlien[i].getPrestige(base2.weight, base2.height, base2.gender);
            }
          }

          //operator overloading 
          offspring = base1 + base2;

          //get offspring's data
          offspring.name = offspringName;
          offspring.weight = offspring.getWeight(offspring.weight) ;      //sum of parents’ weights)/2
          offspring.height = offspring.getHeight(offspring.height) ;      //sum of parents’ heights)/2
          offspring.prestige = offspring.getPrestige(offspring.prestige); //sum of parents’ prestiges)/2

          //if the parents are not of the same gender
          if (base1.gender == base2.gender){
            offspring.gender = base1.gender;
          } else {
            if (rand() % 2 ==0){        //50% chance of gender
              offspring.gender = 'M';
            } else {
              offspring.gender = 'F';
            }
          }
          
          //output
          cout << " Name: \t\t" << offspring.name << "\n";
          cout << " Weight: \t" << offspring.weight << "\t(sum of parents’ weights)/2)\n";
          cout << " Height: \t" << offspring.height << "\t(sum of parents’ heights)/2\n";
          if (offspring.gender == 'M'){
            cout << " Gender: \tMale\n";  
          }else{
            cout << " Gender: \tFemale\n";  
          }
          cout << " Prestige: \t" << offspring.prestige << "\t(sum of parents’ prestiges)/2\n\n";
          cout << "  ※If the parents are not of the same gender, there is a 50% chance that the gender will be chosen.\n";

          vectorOffspring.push_back(offspring);         //store data
          cout << "\nDo you want to continue? (y/n): ";
          cin >> isBreed;
          cout << "\n";
        }
        break;

      case 3:
        cout << "Enter first offspring's name: ";
        cin >> offspringName1;
        cout << "Enter second offspring's name: ";
        cin >> offspringName2;

        for (int i = 0; i < vectorOffspring.size(); i++){
          if (offspringName1 == vectorOffspring[i].name){
            firstOffspringPrestige = vectorOffspring[i].prestige;
          }
          if (offspringName2 == vectorOffspring[i].name){
            secondOffspringPrestige = vectorOffspring[i].prestige;
          }
        }

        cout << "-----------------------------\n";          
        if(firstOffspringPrestige == secondOffspringPrestige){
          cout << " Prestige:  " << offspringName1 << "(" << firstOffspringPrestige << ")" << " = " << offspringName2 << "(" << secondOffspringPrestige << ")\n\n";
        }
        if(firstOffspringPrestige > secondOffspringPrestige){
          cout << " Prestige:  " << offspringName1 << "(" << firstOffspringPrestige << ")" << " > " << offspringName2 << "(" << secondOffspringPrestige << ")\n\n";
        }
        if(firstOffspringPrestige < secondOffspringPrestige){
          cout << " Prestige:  " << offspringName1 << "(" << firstOffspringPrestige << ")" << " < " << offspringName2 << "(" << secondOffspringPrestige << ")\n\n";
        }
        break;

      case 4:
        isContinue = false;
        break;
    }
  }
  return 0;
}