#include <iostream>
#include <vector>
#include <fstream>      //for ofstream, ifstream
#include <sstream>      //for istringstream
#include "Common.h"
#include "Admin.h"
#include "Customer.h"

using namespace std;




/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Declare function prototypes
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void mainMenu(vector <Customers> &customers, vector <Drivers> &drivers, vector <Admins> &admins, vector <Orders> &orders, vector <Inquiries> &inquiries);





/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Main
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int main(){
    vector <Customers> customers;
    vector <Drivers> drivers;
    vector <Admins> admins;
    vector <Orders> orders;
    vector <Inquiries> inquiries;
    

    readCustomerList(customers);
    readDriverList(drivers);
    readAdminList(admins);
    readOrderList(orders);
    readInquiryList(inquiries);


    mainMenu(customers, drivers, admins, orders, inquiries);


    return 0;
}



/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Functions
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void mainMenu(vector <Customers> &customers, vector <Drivers> &drivers, vector <Admins> &admins, vector <Orders> &orders, vector <Inquiries> &inquiries){
    string option;

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
    cout << "  4.Exit\n";
    cout << "------------------------\n";

    //validation for option
    while (true){
        cout << "  Enter option: ";
        cin >> option;
        if (isIntegerValid(option) == true){                                                  //Determine if the number is integer
            if (option == "1" || option == "2" || option == "3" || option == "4"){            //Determine if the number is from the menu
                break;
            } else {
                cout << "\n  ❗️Please select a number from the menu\n\n";
            }
        } else {
            cout << "\n  ❗️Please select a number from the menu\n\n";
        }
    }
    cout << "\n\n";


    int optionInteger = stoi(option);       //string to integer

    switch (optionInteger) {
        case 1:
        customerMenu(customers, orders, inquiries);
        // cout << "Update later\n";
        break;
        case 2:
        // driverMenu();
        cout << "Update later\n";
        break;
        case 3:
        adminLogin(customers, drivers, admins, orders, inquiries);
        break;
        case 4:
        break;
    }

}