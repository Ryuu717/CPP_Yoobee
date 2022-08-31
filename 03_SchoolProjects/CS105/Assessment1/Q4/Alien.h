#include <string>
using namespace std;

class Alien{
  public:           //accessible from everywhere
    string name;
    float weight;
    float height;
    char gender;
    float prestige;
    int selectedMenu;

    Alien (string n = " ", float w = 0, float  h = 0, char g = 'M', float p = 0){
      name = n;
      weight = w;
      height = h;
      gender = g;
      prestige = p;
    }

    //methods
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
        genderPoints = 2;                    //genderPoints(male = 2 and for female = 3)
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

        //name conversion
        if (gender == 'M'){
          cout << "  Gender: \tMale\n";  
        }else{
          cout << "  Gender: \tFemale\n";  
        }
        
        cout << "  Prestige: \t" << getPrestige(weight, height, gender) << "\n\n";
    }
};
