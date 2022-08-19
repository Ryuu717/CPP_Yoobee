#include <string>
using namespace std;

class Shapes{
  protected:                            //accessible from child classes
    double length1, result;

  public:                               //accessible from everywhere
    int selectedMainMenu;

    Shapes(double l1 = 0, double r = 0){        //constructor
      this->length1 = l1;
      this->result = r;
    };
    
    //methods
    void drawShape(int shapeNumber){
      switch(shapeNumber){
        case 1:
          cout <<  " ・・・・ \n ・    ・\n ・    ・\n ・・・・ \n";
          break;
        case 2:
          cout <<  " ・・・・・・ \n ・        ・\n ・        ・\n ・・・・・・ \n";
          break;
        case 3:
          cout << "    ・\n   ・・\n  ・  ・\n ・    ・\n・・・・・\n";
          break;
        case 4:
          cout <<  "   ・・   \n ・    ・\n ・    ・\n   ・・   \n";
          break;
      }
    };

    void mainMenu(){
      cout << "************************************************\n";
      cout << "Shapes Calculator\n";
      cout << "************************************************\n";
      cout << "Please select the option\n";
      cout << " 1.  Square\n";
      cout << " 2.  Rectangle\n";
      cout << " 3.  Triangle\n";
      cout << " 4.  Circle\n";
      cout << " 5.  Exit\n";
      cout << "-----------------------------\n";
      cout << "Enter a number: ";
      cin >> this->selectedMainMenu;
      cout << "\n";
    };

    void subMenu(int selectedMainMenu);
    void getData();
    void calculateArea(double length1);
    void calculatePerimeter(double length1);
    void giveResult(string name, double result){
      int option;
      string unit;

      //Switch units according to area and perimeter
      if (name == "Area"){
      option = 1;
      } else {
      option = 2;
      }
      switch(option){
      case 1:
          unit = "㎠";
          break;
      case 2:
          unit = "cm";
          break;
      }
      cout << "-----------------------------\n";
      cout << name << " is " << result << " " << unit << "\n\n";
    };
};
