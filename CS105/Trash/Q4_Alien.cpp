#include <iostream>
#include <vector>
#include <ctime>
#include <stdlib.h>

using namespace std;

class Alien {
    public:
      string name;
      float weight;
      float height;
      char gender;
      int selectedMenu;

    // constructor
    Alien (string n = " ", float w = 0, float  h = 0, char g = 'M'){
      n = name;
      w = weight;
      h = height;
      g = gender;
    }

    // method
    void getPrestige(float w, float h, char g){
      int genderPoints;
      float p;

      if (g == 'M'){
        genderPoints = 2;             //genderPoints(male = 2 and for female = 3)
      } else {
        genderPoints = 3;
      }

      p = h * w * genderPoints;       // p = height * weight * genderPoints(male = 2 and for female = 3)
      cout << "  Prestige: " << p << "\t(height * weight * gender points)\n";
    }

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

    // void setter(string n, float w, float h, char g){
    //   name = n;
    //   weight = w;
    //   height = h;
    //   gender = g;
    // }

    void createalien(){
      cout << "  Name: ";
      cin >> name;
      cout << "  Weight(kg): ";
      cin >> weight;
      cout << "  Height(cm): ";
      cin >> height;
      cout << "  Gender(M/F): ";
      cin >> gender;
    }

    void display(){
        cout << "  Name: \t" << name << "\n";
        cout << "  Weight: \t" << weight << "\n";
        cout << "  Height: \t" << height << "\n";
        cout << "  Gender: \t" << gender << "\n";
    } 
};


// Derived class
class Offspring: public Alien {
  public:
    string name;
    float weight;
    float height;

    // if (rand() % 2 == 0) {
    //   char gender = 'm';
    // } else {
    //   char gender = 'f';
    // };

    float getWeight(float w){
      weight = w/2;
      return weight;
    }
    float getHeight(float h){
      height = h/2;
      return height;
    }

    float getPrestige(float w, float h, char g){
      int genderPoints;
      float p;

      if (g == 'M'){
        genderPoints = 2;           //genderPoints(male = 2 and for female = 3)
      } else {
        genderPoints = 3;
      }

      p = h * w * genderPoints;     // p = height * weight * genderPoints(male = 2 and for female = 3)
      return p;
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

    srand (time(0));
    
    char answer = 'y';
    bool isContinue = true;
    char isBreed = 'y';
    
    while(isContinue){
      alien.menu();

      switch(alien.selectedMenu){
        case 1:
          //get user input
          cout << "*******************************************\n";
          cout << "Enter alien Information\n";
          cout << "*******************************************\n";

          while(answer == 'y'){                                //Repeat until no
              alien.createalien();                             //get user input
              alien.getPrestige(alien.weight, alien.height, alien.gender);
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
          cout << "\n";
          break;

        case 2:
          while(isBreed == 'y'){
            cout << "Enter parent alian name: ";
            cin >> parentAlienName;
            cout << "Enter offspring alian name: ";
            cin >> offspring.name;
            

            for (int i = 0; i < vectorAlien.size(); i++){
              if (vectorAlien[i].name == parentAlienName){
                cout << " Name: \t\t" << offspring.name << "\n";
                cout << " Weight: \t" << offspring.getWeight(vectorAlien[i].weight) << "\t(Half of parent)\n";
                cout << " height: \t" << offspring.getHeight(vectorAlien[i].height) << "\t(Half of parent)\n";
                cout << " Prestige: \t" << offspring.getPrestige(vectorAlien[i].weight, vectorAlien[i].height, vectorAlien[i].gender) << "\t(equal to parent)\n\n";

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
              firstOffspringPrestige = offspring.getPrestige(vectorOffspring[i].weight, vectorOffspring[i].height, vectorOffspring[i].gender);
            }

            if (secondOffspringName == vectorOffspring[i].name){
              secondOffspringPrestige = offspring.getPrestige(vectorOffspring[i].weight, vectorOffspring[i].height, vectorOffspring[i].gender);
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