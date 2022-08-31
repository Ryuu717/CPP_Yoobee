#include <iostream>
#include <vector>

using namespace std;


class Shapes {
    public:
        double height;
        double result;
        int selectedMenu;

    // constructor
    Shapes (double h = 0, double r = 0, int sm = 0){
        h = height;
        r = result;
        sm = selectedMenu;
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
    void menu(){
      cout << "************************************************\n";
      cout << "Shapes Calculator\n";
      cout << "************************************************\n";
      cout << "Please select an option\n";
      cout << " 1.  Square\n";
      cout << " 2.  Rectangle\n";
      cout << " 3.  Triangle\n";
      cout << " 4.  Circle\n";
      cout << " 5.  Exit\n";
      cout << "-----------------------------\n";
      cout << "Enter a number: ";
      cin >> selectedMenu;
      cout << "\n";
    }

    void getData(){
    }
    void calculateArea(){
    }
    void calculatePerimeter(){
    }
    void giveResult(){
    }
};


// Derived class
class Square: public Shapes {
  public:
    int selectedMenu = 1;
    float length, area, perimeter;

    void squareMenu(){
      cout << "************************************************\n";
      cout << "Square Calculator\n";
      cout << "************************************************\n";
      drawShape(selectedMenu);
      cout << "Please select an option\n";
      cout << " 1.  Area\n";
      cout << " 2.  Perimeter\n";
      cout << " 3.  Go Back\n";
      cout << "-----------------------------\n";
      cout << "Enter a number: ";
      cin >> selectedMenu;
      cout << "\n";

      switch (selectedMenu){
        case 1:
          calculateArea();
          break;
        
        case 2:
          calculatePerimeter();
          break;

        case 3:
          menu();
          break;
      }
    };

    void calculateArea() {
      cout << "Enter the length of the side(cm): ";
      cin >> length;
      
      area = length * length;
      cout << "-----------------------------\n";
      cout << "Area is " << area << " ㎠\n\n";
    }
    
    void calculatePerimeter() {
      cout << "Enter the length of the side(cm): ";
      cin >> length;
      
      perimeter = length * 4;
      cout << "-----------------------------\n";
      cout << "Perimeter is " << perimeter << " cm\n\n";
    }
};

class Rectangle: public Shapes {
  public:
    int selectedMenu = 2;
    float shortLength, longLength, area, perimeter;

    void rectangleMenu(){
      cout << "************************************************\n";
      cout << "Rectangle Calculator\n";
      cout << "************************************************\n";
      drawShape(selectedMenu);
      cout << "Please select an option\n";
      cout << " 1.  Area\n";
      cout << " 2.  Perimeter\n";
      cout << " 3.  Go Back\n";
      cout << "-----------------------------\n";
      cout << "Enter a number: ";
      cin >> selectedMenu;
      cout << "\n";

      switch (selectedMenu){
        case 1:
          calculateArea();
          break;
        
        case 2:
          calculatePerimeter();
          break;

        case 3:
          menu();
          break;
      }
    };

    void calculateArea() {
      cout << "Enter the length of the short side(cm): ";
      cin >> shortLength;
      cout << "Enter the length of the long side(cm): ";
      cin >> longLength;
      
      area = shortLength * longLength;
      cout << "-----------------------------\n";
      cout << "Area is " << area << " ㎠\n\n";
    }
    
    void calculatePerimeter() {
      cout << "Enter the length of the short side(cm): ";
      cin >> shortLength;
      cout << "Enter the length of the long side(cm): ";
      cin >> longLength;
      
      perimeter = shortLength * 2 + longLength * 2;
      cout << "-----------------------------\n";
      cout << "Perimeter is " << perimeter << " cm\n\n";
    }
};

class Triangle: public Shapes {
  public:
    int selectedMenu = 3;
    float btmLength, height, area, perimeter;
    vector<float> length;

    void triangleMenu(){
      cout << "************************************************\n";
      cout << "Triangle Calculator\n";
      cout << "************************************************\n";
      drawShape(selectedMenu);
      cout << "Please select an option\n";
      cout << " 1.  Area\n";
      cout << " 2.  Perimeter\n";
      cout << " 3.  Go Back\n";
      cout << "-----------------------------\n";
      cout << "Enter a number: ";
      cin >> selectedMenu;
      cout << "\n";

      switch (selectedMenu){
        case 1:
          calculateArea();
          break;
        
        case 2:
          calculatePerimeter();
          break;

        case 3:
          menu();
          break;
      }
    };

    void calculateArea() {
      cout << "Enter the length of the bottom(cm): ";
      cin >> btmLength;
      cout << "Enter the length of the height(cm): ";
      cin >> height;
      
      area = btmLength * height / 2;
      cout << "-----------------------------\n";
      cout << "Area is " << area << " ㎠\n\n";
    }
    
    void calculatePerimeter() {
      float l;

      cout << "Enter the 3 lengths of the triangle(cm): \n";
      for(int i = 0; i < 3; i++){
        cout << " Length" << i + 1 << ": ";
        cin >> l;

        length.push_back(l);
      }

      perimeter = length[0] + length[1] + length[2];
      cout << "-----------------------------\n";
      cout << "Perimeter is " << perimeter << " cm\n\n";
    }
};

class Circle: public Shapes {
  public:
    int selectedMenu = 4;
    float radius, area, perimeter;

    void circleMenu(){
      cout << "************************************************\n";
      cout << "Circle Calculator\n";
      cout << "************************************************\n";
      drawShape(selectedMenu);
      cout << "Please select an option\n";
      cout << " 1.  Area\n";
      cout << " 2.  Perimeter\n";
      cout << " 3.  Go Back\n";
      cout << "-----------------------------\n";
      cout << "Enter a number: ";
      cin >> selectedMenu;
      cout << "\n";

      switch (selectedMenu){
        case 1:
          calculateArea();
          break;
        
        case 2:
          calculatePerimeter();
          break;

        case 3:
          menu();
          break;
      }
    };

    void calculateArea() {
      cout << "Enter the radius of the circle(cm): ";
      cin >> radius;
      
      area = radius * radius * 3.14;
      cout << "-----------------------------\n";
      cout << "Area is " << area << " ㎠\n\n";
    }
    
    void calculatePerimeter() {
      cout << "Enter the radius of the side(cm): ";
      cin >> radius;
      
      perimeter = radius * 2 * 3.14;
      cout << "-----------------------------\n";
      cout << "Perimeter is " << perimeter << " cm\n\n";
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
      shape.menu();

      switch (shape.selectedMenu)
      {
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