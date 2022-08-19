#include <iostream>
#include <vector>
using namespace std;

class Shapes {
  protected:                              //accessible from child classes
    double length1, length2, length3;
    double result;

  public:                                 //accessible from everywhere
    int selectedMainMenu;

    // constructor
    Shapes (double l1 = 0, double l2 = 0, double l3 = 0, double r = 0, int sm = 0){
        l1 = length1;
        l2 = length2;
        l3 = length3;
        r = result;
        sm = selectedMainMenu;
    }

    // method
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
    }

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
      cin >> selectedMainMenu;
      cout << "\n";
    }

    int subMenu(){
      int selectedSubMenu;
      cout << "Please select the option\n";
      cout << " 1.  Area\n";
      cout << " 2.  Perimeter\n";
      cout << " 3.  Go Back\n";
      cout << "-----------------------------\n";
      cout << "Enter a number: ";
      cin >> selectedSubMenu;
      cout << "\n";
      return selectedSubMenu;
    }

    void getData(){
      cout << "Enter the length of the side(cm): ";     //in the case of a square
      cin >> length1;
    }
    void calculateArea(double length1) {                //in the case of a square
      result = length1 * length1;
    }
    void calculatePerimeter(double length1) {           //in the case of a square
      result = length1 * 4;
    }
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
    }
};


// Derived class
class Square: public Shapes {
  // private
    int selectedMainMenu = 1;
    int selectedSubMenu;
  
  public:
    void squareMenu(){
      cout << "************************************************\n";
      cout << "Square Calculator\n";
      cout << "************************************************\n";
      drawShape(selectedMainMenu);
      selectedSubMenu = subMenu();

      switch (selectedSubMenu){
        case 1:
          getData();
          calculateArea(length1);
          giveResult("Area", result);
          break;
        
        case 2:
          getData();
          calculatePerimeter(length1);
          giveResult("Perimeter", result);
          break;

        case 3:
          break;
      }
    };
};

class Rectangle: public Shapes {
  // private
    int selectedMainMenu = 2;
    int selectedSubMenu;

  public:
    void rectangleMenu(){
      cout << "************************************************\n";
      cout << "Rectangle Calculator\n";
      cout << "************************************************\n";
      drawShape(selectedMainMenu);
      selectedSubMenu = subMenu();

      switch (selectedSubMenu){
        case 1:
          getData();
          calculateArea(length1, length2);
          giveResult("Area", result);
          break;
        
        case 2:
          getData();
          calculatePerimeter(length1, length2);
          giveResult("Perimeter", result);
          break;

        case 3:
          break;
      }
    };

    void getData(){
      cout << "Enter the length of the short side(cm): ";
      cin >> length1;
      cout << "Enter the length of the long side(cm): ";
      cin >> length2;
    }

    void calculateArea(double length1, double length2) {
      result = length1 * length2;
    }
    
    void calculatePerimeter(double length1, double length2) {      
      result = length1 * 2 + length2 * 2;
    }
};

class Triangle: public Shapes {
  // private
    int selectedMainMenu = 3;
    int selectedSubMenu;
    vector<float> length;

  public:
    void triangleMenu(){
      cout << "************************************************\n";
      cout << "Triangle Calculator\n";
      cout << "************************************************\n";
      drawShape(selectedMainMenu);
      selectedSubMenu = subMenu();

      switch (selectedSubMenu){
        case 1:
          getData();
          calculateArea(length1, length2);
          giveResult("Area", result);
          break;
        case 2:
          calculatePerimeter();
          giveResult("Perimeter", result);
          break;
        case 3:
          break;
      }
    };

    void getData(){
      cout << "Enter the length of the bottom(cm): ";
      cin >> length1;
      cout << "Enter the length of the height(cm): ";
      cin >> length2;
    }

    void calculateArea(double length1, double length2) {
      result = length1 * length2 / 2;
    }
    
    void calculatePerimeter() {
      float l;

      cout << "Enter the 3 lengths of the triangle(cm): \n";
      for(int i = 0; i < 3; i++){
        cout << " Length" << i + 1 << ": ";
        cin >> l;

        length.push_back(l);
      }
      result = length[0] + length[1] + length[2];
    }
};

class Circle: public Shapes {
  // private
    int selectedMainMenu = 4;
    int selectedSubMenu;

  public:
    void circleMenu(){
      cout << "************************************************\n";
      cout << "Circle Calculator\n";
      cout << "************************************************\n";
      drawShape(selectedMainMenu);
      selectedSubMenu = subMenu();

      switch (selectedSubMenu){
        case 1:
          getData();
          calculateArea(length1);
          giveResult("Area", result);
          break;
        case 2:
          getData();
          calculatePerimeter(length1);
          giveResult("Perimeter", result);
          break;
        case 3:
          break;
      }
    };

    void getData(){
      cout << "Enter the radius of the circle(cm): ";
      cin >> length1;
    }

    void calculateArea(double length1) {
      result = length1 * length1 * 3.14;
    }
    
    void calculatePerimeter(double length1) {
      result = length1 * 2 * 3.14;
    }
};

int main(){
    Shapes shape;
    Square square;
    Rectangle rectangle;
    Triangle triangle;
    Circle circle;
    bool isContinue = true;
    
    while(isContinue){     //continue until user choose 5.Exit
      shape.mainMenu();

      switch (shape.selectedMainMenu){
      case 1:
        square.squareMenu();
        break;
      case 2:
        rectangle.rectangleMenu();
        break;
      case 3:
        triangle.triangleMenu();
        break;
      case 4:
        circle.circleMenu();
        break;
      case 5:
        cout << "Thank you!\n";
        cout << "See you again.\n\n";
        isContinue = false;
        break;
      }
    }
    return 0;
}