class Circle: public Shapes{
public:
    //constructor
    Circle(double length1 = 0, double result = 0) : Shapes(length1, result) {     //Passing argument
    }

    //override
    void getData()  {
        cout << "Enter the radius of the circle(cm): ";
        cin >> this->length1;
    }

    void calculateArea(double length1) {
        this->result = length1 * length1 * 3.14;
    }

    void calculatePerimeter(double length1) {
        this->result = length1 * 2 * 3.14; 
    }

    void subMenu(int selectedMainMenu){
        int selectedSubMenu;
        Circle circle;

        cout << "************************************************\n";
        cout << "Circle Calculator\n";
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
            circle.getData();
            circle.calculateArea(circle.length1);
            circle.giveResult("Area", circle.result);
            break;
            case 2:
            circle.getData();
            circle.calculatePerimeter(circle.length1);
            circle.giveResult("Perimeter", circle.result);
            break;
            case 3:
            break;
        }
    }
};