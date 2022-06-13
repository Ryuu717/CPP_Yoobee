#include <iostream>
#include <vector>
using namespace std;

//declare structures
struct Customer{
    string name;
    string phoneNumber;
    string email;
    // string address;
    string street;
    string city;
    string state;
    string country;
    string postalCode;

    string password;
    
    string paymentMethod;
    string pickupLocation;
    string destination;
    int selectedService;

    //constructor
    Customer(string n="customer", string pn="000-0000-0000", string e="email@email.com", string p="password", string str="street", string cit="city", string sta="state", string cou="country", string pc="000-0000", string pm="credit",string pl="area1",string des="area2",int ss=1){
        name = n;
        phoneNumber = pn;
        email = e;
        // address[] = a[];
        street = str;
        city = cit;
        state = sta;
        country = cou;
        postalCode = pc;
        password = p;
        paymentMethod = pm;
        pickupLocation = pl;
        destination = des;
        selectedService = ss;
    }
};

// struct Driver{};
// struct Admin{};


//declare function prototypes
void mainMenu();
void customerMenu(vector <Customer> &customer);
void driverMenu();
void adminMenu(vector <Customer> &customer);
void ride(vector <Customer> &customer);
void signup();
void login();
void guestOrder();
void myPage();




int main(){
    // struct Customer customer;
    vector <Customer> customer;


    // mainMenu();
    // customerMenu();
    // driverMenu();
    // adminMenu();
    ride(customer);
    // signup();
    // login();
    // guestOrder();
    // myPage();
    





    return 0;
}





//functions

void mainMenu(){
    int option;

    cout << "===============================================================================================\n";
    cout << "_____.___.            ___.                   ________________  ____  ___.___\n\\__  |   | ____   ____\\_ |__   ____   ____   \\__    ___/  _  \\ \\   \\/  /|   |\n /   |   |/  _ \\ /  _ \\| __ \\_/ __ \\_/ __ \\    |    | /  /_\\  \\ \\     / |   |\n \\____   (  <_> |  <_> ) \\_\\ \\  ___/\\  ___/    |    |/    |    \\/     \\ |   |\n / ______|\\____/ \\____/|___  /\\___  >\\___  >   |____|\\____|__  /___/\\  \\|___|\n\n";
    cout << "===============================================================================================\n\n";
    cout << "************************************************\n";
    cout << "Welcome to Yoobee Taxi!\n";
    cout << "Please select a number from the menu\n";
    cout << "************************************************\n";
    cout << "Menu\n";
    cout << "  1.Customer\n";
    cout << "  2.Driver\n";
    cout << "  3.Admin\n";
    cin >> option;
    cout << "\n\n";

    switch (option) {
        case 1:
        // customerMenu();
        break;
        case 2:
        // driverMenu();
        break;
        case 3:
        // adminMenu();
        break;
    }

}

void customerMenu(vector <Customer> &customer){
    int option;

    cout << "************************************************\n";
    cout << "Welcome Yoobee Customers!\n";
    cout << "Please select a number from the menu\n";
    cout << "************************************************\n";
    cout << "Menu\n";
    cout << "  1.Ride\n";
    cout << "  2.My Page\n";
    cout << "  3.Contact\n";
    cin >> option;
    cout << "\n\n";

    switch (option) {
        case 1:
        // ride(customer);
        break;
        case 2:
        // driverMenu();
        break;
        case 3:
        // adminMenu();
        break;
    }
}

void driverMenu(){
    cout << "************************************************\n";
    cout << "Welcome Yoobee Drivers!\n";
    cout << "Please select a number from the menu\n";
    cout << "************************************************\n";
    cout << "Menu\n";
    cout << "  1.Resister\n";
    cout << "  2.My Page\n";
    cout << "  3.Contact\n";
    // cout << "************************************************\n";
    cout << "\n\n";

}

void adminMenu(vector <Customer> &customer){
    int option;

    cout << "************************************************\n";
    cout << "Welcome Yoobee Admin!\n";
    cout << "Please select a number from the menu\n";
    cout << "************************************************\n";
    cout << "Menu\n";
    cout << "  1.Customer Info\n";
    cout << "  2.Driver Info\n";
    cout << "  3.Report\n";
    cout << "  4.Add Admin\n";
    cin >> option;
    cout << "\n\n";

    switch(option){
        case 1:
        for (int i = 0; i < customer.size(); i++){
            cout << "  Customer ID:\t\t(update later)\n";
            cout << "  Name:\t\t\t" << customer[i].name <<"\n";
            cout << "  Phone number:\t\t" << customer[i].phoneNumber << "\n";
            cout << "  Email address:\t" << customer[i].email << "\n";
            cout << "  Address:\t\t" << customer[i].street << " " << customer[i].city << " " << customer[i].state << " " << customer[i].country << " " << customer[i].postalCode << "\n";
            cout << "  Payment Method:\t" << customer[i].paymentMethod << "\n";
        }
        break;

        case 2:
        cout << "Driver information(Update later)\n";
        break;

        case 3:
        cout << "Report(Update later)\n";
        break;

        case 4:
        cout << "Add Admin(Update later)\n";
        break;
    }
}

void ride(vector <Customer> &customer){
    struct Customer c;
    char requestNow;
    int option;

    cout << "************************************************\n";
    cout << "Ride\n";
    cout << "************************************************\n";
    // cout << " Please enter a destination: \n";
    cout << " Enter pickup location: ";
    cin >> c.pickupLocation;
    cout << " Enter destination: ";
    cin >> c.destination;
    cout << " ------------------------------------------------\n";
    cout << " Request Now? (y/n): ";
    cin >> requestNow;
    
    if (requestNow = 'y'){
        // cout << " Schedule for later? (y/n) \n";
        cout << " ------------------------------------------------\n";
        cout << " Please select a service: \n";
        cout << "  1. Taxi\t\t4 people\t$10.00\t10:30AM(Pick up) \n";
        cout << "  2. Van\t\t5 people\t$15.00\t10:35AM(Pick up) \n";
        cout << "  3. Premium Van\t6 people\t$20.00\t10:40AM(Pick up) \n";
        cin >> c.selectedService;

        cout << " ------------------------------------------------\n";
        cout << " Please tell us your information: \n";
        cout << "  1. Login (if you are a member)\n";
        cout << "  2. Sign up (if not a member)\n";
        cout << "  3. Guest Order (no registration)\n";
        cin >> option;
        cout << " ------------------------------------------------\n";
        switch (option){
            case 1:
            cout << "Call Login\n";
            break;

            case 2:
            cout << " Sign up: \n";

            cout << "  Enter your name: ";
            cin >> c.name;
            cout << "  Enter your phone number(e.g. 000-0000-0000): ";
            cin >> c.phoneNumber;
            cout << "  Enter your email address: ";
            cin >> c.email;
            cout << "  Enter your address\n";
            cout << "    Street: ";
            cin >> c.street;
            cout << "    City: ";
            cin >> c.city;
            cout << "    State: ";
            cin >> c.state;
            cout << "    Country: ";
            cin >> c.country;
            cout << "    Postal Code(e.g. 000-0000): ";
            cin >> c.postalCode;
            cout << "  Enter your password: ";
            cin >> c.password;
            cout << "  Enter your paymentMethod: "; //-->Choose your payment method
            cin >> c.paymentMethod;
            break;

            case 3:
            cout << "Guest Order\n";
        }

        customer.push_back(c);

        // cout << " Login: \n";
        // cout << "  Enter your email address\n";
        // cin >> customer[i].email << "\n";
        // cout << "  Enter your password\n";
        // cin >> customer[i].password << "\n";
        cout << " ------------------------------------------------\n";
        cout << " Please confirm your order \n";
        cout << "  Your Name:\t\t" << c.name <<"\n";
        cout << "  Your Phone number:\t" << c.phoneNumber << "\n";
        cout << "  Pickup location:\t" << c.pickupLocation << "\n";
        cout << "  Destination:\t\t" << c.destination << "\n";

        switch (c.selectedService) {
            case 1:
            cout << "  Car type:\t\t\tTaxi(4 people)\n";
            cout << "  Fare:\t\t\t$10.00\n";
            cout << "  Pick up time:\t\t10:30AM\n";
            break;

            case 2:
            cout << "  Car type:\tVan(5 people)\n";
            cout << "  Fare:\t\t\t$15.00\n";
            cout << "  Pick up time:\t\t10:35AM\n";
            break;

            case 3:
            cout << "  Car type:\tPremium Van(6 people)\n";
            cout << "  Fare:\t\t\t$20.00\n";
            cout << "  Pick up time:\t\t10:40AM\n\n";
            break;
        }
        // cout << "  Car:\t\t\tTaxi(4 people)\n";
        // cout << "  Fare:\t\t\t$10.00\n";
        // cout << "  Pick up time:\t\t10:30AM\n";
        // cout << "  Driver Name:\t\tDriver1\n";
        // cout << "  Driver Rate:\t\t★★★☆☆\n";
        // cout << "  Contact:\t\t111-1111-1111\n";
        // cout << "  License Plate:\t111-111\n\n";
        // cout << "  Request now?(y/n): \n\n";

        cout << "  Thank you! \n";
    }
    cout << "\n\n";

    adminMenu(customer);
}

void signup(){
    cout << "************************************************\n";
    cout << "Sign up\n";
    cout << "************************************************\n";
    cout << "Enter your information \n";
    cout << " Name: \n";
    cout << " Phone number: \n";
    cout << " Email address: \n";
    cout << " Home address: \n";
    cout << " Password: \n";
    cout << " Password (confirm): \n";
    cout << " Payment method: \n";
    cout << "  1. Cash \n";
    cout << "  2. Credit Card \n";
    cout << "  3. Online Payment \n";
    cout << "  4. - \n";
    cout << " ------------------------------------------------\n";

    cout << "\n\n";
}

void login(){
    cout << "************************************************\n";
    cout << "Login\n";
    cout << "************************************************\n";
    cout << "Enter your information \n";
    cout << " Email address: \n";
    cout << " Password: \n";
    cout << " Password (confirm): \n";
    cout << " ------------------------------------------------\n";

    cout << "\n";
}

void guestOrder(){
    cout << "************************************************\n";
    cout << "Guest order\n";
    cout << "************************************************\n";
    cout << "Enter your information \n";
    cout << " Name: \n";
    cout << " Phone number: \n";
    cout << " Payment method: \n";
    cout << "  1. Cash \n";
    cout << "  2. Credit Card \n";
    cout << "  3. Online Payment \n";
    cout << "  4. Cryptocurrency \n";
    cout << " ------------------------------------------------\n";

    cout << "\n\n";
}

void myPage(){
    cout << "************************************************\n";
    cout << "My Page\n";
    cout << "************************************************\n";
    cout << "Please login \n";
    cout << "  1. Login (if you are a member)\n";
    cout << "  2. Sign up (if not a member)\n";
    cout << "  3. Go Back to Home\n\n";

    login();

    cout << "************************************************\n";
    cout << "Welcome back Customer1 \n";
    cout << "************************************************\n";
    cout << "Menu \n";
    cout << "  1. Account Info\n";
    cout << "  2. Trip history \n";
    cout << "  3. Coupon \n";
    cout << "  4. - \n";
    cout << " ------------------------------------------------\n";

    cout << "\n\n";
}