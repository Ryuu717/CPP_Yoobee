#include <vector>

class Triangle: public Shapes{
public:
    //add augment
    double length2;

    Triangle(double length1 = 0, double length2 = 0, double result = 0) : Shapes(length1, result) {     //Passing argument
        this->length2 = length2;
    }

    //override
    void getData()  {
        cout << "Enter the length of the bottom(cm): ";
        cin >> length1;
        cout << "Enter the length of the height(cm): ";
        cin >> length2;
    }

    void calculateArea(double length1, double length2) {
        this->result = length1 * length2 / 2;
    }

    void calculatePerimeter() {
        vector<float> length;       //use vector to store values
        float l;

        cout << "Enter the 3 lengths of the triangle(cm): \n";
        for(int i = 0; i < 3; i++){
            cout << " Length" << i + 1 << ": ";
            cin >> l;

            length.push_back(l); 
        }
        result = length[0] + length[1] + length[2];
    }

    void subMenu(int selectedMainMenu){
        int selectedSubMenu;
        Triangle triangle;

        cout << "************************************************\n";
        cout << "Triangle Calculator\n";
        cout << "************************************************\n";
        drawShape(selectedMainMenu);
        cout << "Please select the option\n";
        cout << " 1.  Area\n";
        cout << " 2.  Perimeter\n";
        cout << " 3.  Go Back\n";
        cout << "-----------------------------\n";
        cout << "Enter a number: ";
        cin >> selectedSubMenu;
        cout << "\n";
        
        switch (selectedSubMenu){
            case 1:
            triangle.getData();
            triangle.calculateArea(triangle.length1, triangle.length2);
            triangle.giveResult("Area", triangle.result);
            break;
            case 2:
            triangle.calculatePerimeter();
            triangle.giveResult("Perimeter", triangle.result);
            break;
            case 3:
            break;
        }
    }
};

