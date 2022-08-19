class Square: public Shapes{
public:
    //constructor
    Square(double length1 = 0, double result = 0) : Shapes(length1, result) {     //Passing argument
    }

    //override
    void getData()  {
        cout << "Enter the length1 of the side(cm): ";
        cin >> this->length1;
    }

    void calculateArea(double length1) {
        this->result = length1 * length1;
    }

    void calculatePerimeter(double length1) {
        this->result = length1 * 4;
    }

    void subMenu(int selectedMainMenu){
        int selectedSubMenu;
        Square square;

        cout << "************************************************\n";
        cout << "Square Calculator\n";
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
                square.getData();
                square.calculateArea(square.length1);
                square.giveResult("Area", square.result);
                break;
            case 2:
                square.getData();
                square.calculatePerimeter(square.length1);
                square.giveResult("Perimeter", square.result);
                break;
            case 3:
                break;
        }
    }
};
