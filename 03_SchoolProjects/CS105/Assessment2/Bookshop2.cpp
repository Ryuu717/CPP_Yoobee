#include <iostream>
#include <string>
using namespace std;



class Person {
public:
    //member values
    string firstName, lastName;
    int age;
    char gender;

    // constructor
    /*Person(string fn = " ", string ln = "",  int a = 0,  char g = 'f') {*/
    Person() {
        firstName = " ";
        lastName = " ";
        age = 0;
        gender = 'f';
    }

    //setter & getter
    void setPerson() {
        cout << " First name: ";
        cin >> firstName;
        cout << " Last name: ";
        cin >> lastName;
        cout << " Age: ";
        cin >> age;
        cout << " Gender: ";
        cin >> gender;

        cin.clear();
        cin.ignore();
        //fflush(stdin);

    }
    void getPerson() {
        cout << "\n******************************************************\n";
        cout << "Your information: \n";
        cout << "******************************************************\n";
        cout << " Name: \t\t" << firstName << "  " << lastName << "\n";
        cout << " Gender: \t" << gender << "\n";
        cout << " Age: \t\t" << age << "\n";
    }
};



class Book {
public:
    //member values
    // char bookName[100];
    string bookName;
    string edition;
    double price;

    // constructor
    Book() {
        edition = " ";
        price = 0.0;
    }

    //setter & getter
    void setBook() {
        cout << " Book name: ";
        // cin.getline(bookName, 100);
        getline(cin, bookName);
        cout << " Edition details: ";
        cin >> edition;
        cout << " Price: ";
        cin >> price;

        cin.clear();
        cin.ignore();
    }

    void getBook() {
        cout << "  " << bookName;
        cout << "\t" << edition;
        cout << "\t" << price;
    }

    double returnPrice() {
        return price;
    }
};


class Shop : public Person, public Book {
    double discount;
    double totalCost;

public:
    Shop() {
        discount = 0;
        totalCost = 0;
    }

    void setDiscount() {
        cout << " \n Enter the discount percentage : ";
        cin >> discount;
    }

    double getDiscount() {
        return discount;
    }

    void DisplayShoppingCart() {
        getPerson();
        getBook();
        cout << "\n Discount : " << discount;

       /* double discount_cal = return_price() * discount / 100;*/

        /*cout << "\n Price after discount  : " << return_price() - discount_cal;*/
    }
};



int main() {
    Shop* s = new Shop();

    Book* b[100];
    char isContinue = 'y';
    int n = 0;
    double totalPrice = 0;

    //input
    cout << "\n******************************************************\n";
    cout << "Enter your information: \n";
    cout << "******************************************************\n";
    s->setPerson();


    cout << "\n******************************************************\n";
    cout << "Enter book information: \n";
    cout << "******************************************************\n";
    while (isContinue == 'y') {
        cout << "Enter book " << n + 1 << " :\n";

        b[n] = new Book();
        b[n]->setBook();
        n++;

        cout << "\n Do you want to continue?(y/n): ";
        cin >> isContinue;

        cin.clear();
        cin.ignore();
    }

    s->setDiscount();
    

    //output
    s->getPerson();


    cout << "\n******************************************************\n";
    cout << "Book information: \n";
    cout << "******************************************************\n";
    for (int i = 0; i < n; i++) {
        b[i]->getBook();
        totalPrice += b[i]->returnPrice();
        cout << "\n";
    }
    

    cout << "\n\n******************************************************\n";
    cout << "Total price: \n";
    cout << "******************************************************\n";
    cout << "  Total Price: \t\t" << totalPrice << "\n";
    cout << "  Discount Percentage: \t" << s->getDiscount() << "(%)\n";

    double discountAmount = totalPrice * s->getDiscount() / 100;

    cout << "  Discount Amount: \t" << discountAmount << "\n";
    cout << "  Your Payment: \t" << totalPrice - discountAmount << "\n";

    return 0;
}
