#include <iostream>
#include <vector>
#include <ctime>
#include <stdlib.h>

using namespace std;

class Alien {
  //private
    string name;
    float weight;
    float height;
    char gender;
    float prestige;

  public:
    int selectedMenu;

    // constructor
    Alien (string n = " ", float w = 0, float  h = 0, char g = 'M'){
      n = name;
      w = weight;
      h = height;
      g = gender;
    }

    // method
    void menu(){
      cout << "************************************************\n";
      cout << "Alien Generator\n";
      cout << "************************************************\n";
      cout << "Please select the option\n";
      cout << " 1.  Create alien\n";
      cout << " 2.  Create offspring\n";
      cout << " 3.  Compare offspring prestage\n";
      cout << " 4.  Exit\n";
      cout << "-----------------------------\n";
      cout << "Enter a number: ";
      cin >> selectedMenu;
      cout << "\n\n";
    };

    void setter(string n, float w, float h, char g){
      name = n;
      weight = w;
      height = h;
      gender = g;
    }

    string getName(){
      return name;
    }
    float getWeight(){
      return weight;
    }
    float getHeight(){
      return height;
    }
    char getGender(){
      return gender;
    }
    float getPrestige(float w, float h, char g){
      int genderPoints;

      if (g == 'M'){
        genderPoints = 2;             //genderPoints(male = 2 and for female = 3)
      } else {
        genderPoints = 3;
      }

      prestige = h * w * genderPoints;       // p = height * weight * genderPoints(male = 2 and for female = 3)
      return prestige;
    }

    void display(){
        cout << "  Name: \t" << name << "\n";
        cout << "  Weight(kg): \t" << weight << "\n";
        cout << "  Height(cm): \t" << height << "\n";

        if (gender == 'M'){
          cout << "  Gender: \tMale\n";  
        }else{
          cout << "  Gender: \tFemale\n";  
        }
        cout << "  Prestige: \t" << getPrestige(weight, height, gender) << "\n\n";
    } 
};


// Derived class
class Offspring: public Alien {
  public:
    string name;
    float weight;
    float height;
    char gender;
    float prestige;

    float getWeight(float w){
      weight = w/2;
      return weight;
    }

    float getHeight(float h){
      height = h/2;
      return height;
    }

    char getGender(char g){
      gender = g;
      return gender;
    }

    float getPrestige(float w, float h, char g){
      int genderPoints;

      if (g == 'M'){
        genderPoints = 2;           //genderPoints(male = 2 and for female = 3)
      } else {
        genderPoints = 3;
      }
      prestige = h * w * genderPoints;     // p = height * weight * genderPoints(male = 2 and for female = 3)
      return prestige;
    }
};


int main(){
    Alien alien;
    Offspring offspring;
    vector<Alien> vectorAlien;
    vector<Offspring> vectorOffspring;

    string parentAlienName, offspringAlienName;
    string firstOffspringName, secondOffspringName;
    float firstOffspringPrestige, secondOffspringPrestige;

    string name;
    float weight, height;
    char gender;
    
    char answer = 'y';
    bool isContinue = true;
    char isBreed = 'y';
    srand (time(NULL));

    while(isContinue){
      alien.menu();

      switch(alien.selectedMenu){
        case 1:
          //get user input
          cout << "*******************************************\n";
          cout << "Enter alien Information\n";
          cout << "*******************************************\n";

          while(answer == 'y'){                                //Repeat until no
              cout << "  Name: ";
              cin >> name;
              cout << "  Weight(kg): ";
              cin >> weight;
              cout << "  Height(cm): ";
              cin >> height;

              //choose gender randomly
              if (rand() % 2 ==0){
                gender = 'M';
              } else {
                gender = 'F';
              }
              alien.setter(name, weight, height, gender);
              vectorAlien.push_back(alien);                   //store data
              cout << "\nDo you want to continue? (y/n): ";
              cin >> answer;
              cout << "\n";
          }

          //show user input
          cout << "*******************************************\n";
          cout << "Result\n";
          cout << "*******************************************\n";

          for (int i = 0; i < vectorAlien.size(); i++) {
              cout << "Alien " << i + 1 << "\n";
              vectorAlien[i].display();                  
          }
          cout << "   ※Prestige = Height * Weight * Gender Points (M = 2, F = 3)\n";
          cout << "\n";
          break;

        case 2:
          while(isBreed == 'y'){
            cout << "Enter parent alian name: ";
            cin >> parentAlienName;
            cout << "Enter offspring alian name: ";
            cin >> offspring.name;
            

            for (int i = 0; i < vectorAlien.size(); i++){
              if (vectorAlien[i].getName() == parentAlienName){
                cout << " Name: \t\t" << offspring.name << "\n";
                cout << " Weight: \t" << offspring.getWeight(vectorAlien[i].getWeight()) << "\t(Half of parent)\n";
                cout << " Height: \t" << offspring.getHeight(vectorAlien[i].getHeight()) << "\t(Half of parent)\n";
                
                if(vectorAlien[i].getGender() == 'M'){
                  cout << " Gender: \tMale\t(Equal to parent)\n";  
                } else {
                  cout << " Gender: \tFemale\t(Equal to parent)\n";  
                }
                cout << " Prestige: \t" << offspring.getPrestige(vectorAlien[i].getWeight(), vectorAlien[i].getHeight(), vectorAlien[i].getGender()) << "\t(Equal to parent)\n\n";

                vectorOffspring.push_back(offspring);
                cout << "\nDo you want to continue? (y/n): ";
                cin >> isBreed;
                cout << "\n";
              }
            }
          }
          break;

        case 3:
          cout << "Enter first offspring's name: ";
          cin >> firstOffspringName;
          cout << "Enter second offspring's name: ";
          cin >> secondOffspringName;

          for (int i = 0; i < vectorOffspring.size(); i++){
            if (firstOffspringName == vectorOffspring[i].name){
              firstOffspringPrestige = vectorOffspring[i].prestige;
            }
            if (secondOffspringName == vectorOffspring[i].name){
              secondOffspringPrestige = vectorOffspring[i].prestige;
            }
          }

          cout << "-----------------------------\n";          
          if(firstOffspringPrestige == secondOffspringPrestige){
            cout << " Prestige:  " << firstOffspringName << "(" << firstOffspringPrestige << ")" << " = " << secondOffspringName << "(" << secondOffspringPrestige << ")\n\n";
          }
          if(firstOffspringPrestige >= secondOffspringPrestige){
            cout << " Prestige:  " << firstOffspringName << "(" << firstOffspringPrestige << ")" << " ≧ " << secondOffspringName << "(" << secondOffspringPrestige << ")\n\n";
          }
          if(firstOffspringPrestige <= secondOffspringPrestige){
            cout << " Prestige:  " << firstOffspringName << "(" << firstOffspringPrestige << ")" << " ≦ " << secondOffspringName << "(" << secondOffspringPrestige << ")\n\n";
          }
          break;

        case 4:
          isContinue = false;
          break;
      }
    }
    return 0;
}