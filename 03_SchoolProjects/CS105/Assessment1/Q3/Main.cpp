#include <iostream>
#include "Shapes.h"
#include "Square.h"
#include "Rectangle.h"
#include "Triangle.h"
#include "Circle.h"
using namespace std;

int main (){
    Shapes shapes;
    Square square;
    Rectangle rectangle;
    Triangle triangle;
    Circle circle;

    bool isContinue = true;

    while(isContinue){                              //continue until user choose 5.Exit
      shapes.mainMenu();                            //call main menu

      switch (shapes.selectedMainMenu){
      case 1:
        square.subMenu(shapes.selectedMainMenu);    //call sub menu
        break;
      case 2:
        rectangle.subMenu(shapes.selectedMainMenu);
        break;
      case 3:
        triangle.subMenu(shapes.selectedMainMenu);
        break;
      case 4:
        circle.subMenu(shapes.selectedMainMenu);
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