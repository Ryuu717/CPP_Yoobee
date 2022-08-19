class Rectangle: public Shapes{
public:
    //add augment
    double length2;

    //constructor
    Rectangle(double length1 = 0, double length2 = 0, double result = 0) : Shapes(length1, result) {     //Passing argument
        this->length2 = length2;    
    }

    //override
    void getData()  {
        cout << "Enter the length1 of the short side(cm): ";
        cin >> this->length1;
        cout << "Enter the length1 of the long side(cm): ";
        cin >> this->length2;
    }
    void calculateArea(double length1, double length2) {
        this->result = length1 * length2;
    }
    void calculatePerimeter(double length1, double length2) {
        this->result = length1 * 2 + length2 * 2;
    }

    void subMenu(int selectedMainMenu){
        int selectedSubMenu;
        Rectangle rectangle;

        cout << "************************************************\n";
        cout << "Rectangle Calculator\n";
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
                rectangle.getData();
                rectangle.calculateArea(rectangle.length1, rectangle.length2);
                rectangle.giveResult("Area", rectangle.result);
                break;
            case 2:
                rectangle.getData();
                rectangle.calculatePerimeter(rectangle.length1, rectangle.length2);
                rectangle.giveResult("Perimeter", rectangle.result);
                break;
            case 3:
                break;
        }
    }
};

