#include <iostream>
#include <vector>
#include <fstream>      //for ofstream, ifstream
#include <sstream>      //for istringstream
// #include <limits>
#include <regex>    //include regular expressions library
#include <ctime>
// #include "Structure.h"

using namespace std;



// /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// //Declare structures
// /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// struct Customers{
//     string name;
//     string phone;
//     string email;
//     string street;
//     string city;
//     string state;
//     string country;
//     string postalCode;
//     string password;
//     string payment;
//     // string creditCardNumber;
//     string pickupLocation;
//     string destination;
//     int selectedService;

//     //constructor
//     Customers(string n="name", string pn="000-0000-0000", string e="email@email.com", string p="password", string str="street", string cit="city", string sta="state", string cou="country", string pc="000-0000", string pm="credit", string ccn="NA", string pl="area1",string des="area2",int ss=1){
//         name = n;
//         phone = pn;
//         email = e;
//         street = str;
//         city = cit;
//         state = sta;
//         country = cou;
//         postalCode = pc;
//         password = p;
//         payment = pm;
//         // creditCardNumber = ccn;
//         pickupLocation = pl;
//         destination = des;
//         selectedService = ss;
//     }
// };


// struct Drivers{
//     string name;
//     string phone;
//     string email;
//     string street;
//     string city;
//     string state;
//     string country;
//     string postalCode;
//     string password;
//     string license;
//     string area;

//     //constructor
//     Drivers(string n="name", string pn="000-0000-0000", string e="email@email.com", string p="password", string str="street", string cit="city", string sta="state", string cou="country", string pc="000-0000", string li="0000-0000", string a="area"){
//         name = n;
//         phone = pn;
//         email = e;
//         street = str;
//         city = cit;
//         state = sta;
//         country = cou;
//         postalCode = pc;
//         password = p;
//         license = li;
//         area = a;
//     }
// };


// struct Admins{
//     string name;
//     string phone;
//     string email;
//     string street;
//     string city;
//     string state;
//     string country;
//     string postalCode;
//     string password;
//     string payment;

//     //constructor
//     Admins(string n="name", string pn="000-0000-0000", string e="email@email.com", string p="password", string str="street", string cit="city", string sta="state", string cou="country", string pc="000-0000", string pm="credit"){
//         name = n;
//         phone = pn;
//         email = e;
//         street = str;
//         city = cit;
//         state = sta;
//         country = cou;
//         postalCode = pc;
//         password = p;
//         payment = pm;
//     }
// };

// struct Orders{
//     int year;
//     int month;
//     int day;
//     int days;
//     int week;
//     string customerName;
//     string driverName;
//     string carType;
//     string pickupLocation;
//     string destination;
//     float fare;
//     int selectedService;

//     Orders(int y=2022, int m=01, int d=01, int ds=01, int w=01, string cn="customer name", string dn="driver name", string ct="taxi", string pl="pickup location", string des="destination", float fa=10.00, int ss=1){
//         year = y;
//         month = m;
//         day = d;
//         days = ds;
//         week = w;
//         customerName = cn; 
//         driverName = dn; 
//         carType = ct;
//         pickupLocation = pl; 
//         destination = des;
//         fare = fa;
//         selectedService = ss;
//     }
// };

// struct Inquiries{
//     int year;
//     int month;
//     int day;
//     string name;
//     string userType;
//     string phone;
//     string email;
//     string topic;
//     string detail;

//     Inquiries(int y=2022, int m=01, int d=01, string n="name", string ut="user type", string p="000-0000-0000", string e="email@email.com", string t="topic", string de="detail"){
//         year = y;
//         month = m;
//         day = d;
//         name = n; 
//         userType = ut; 
//         phone = p;
//         email = e; 
//         topic = t;
//         detail = de;
//     }
// };






/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Declare function prototypes
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// void mainMenu(vector <Customers> &customers, vector <Drivers> &drivers, vector <Admins> &admins, vector <Orders> &orders, vector <Inquiries> &inquiries);
void customerMenu(vector <Customers> &customers, vector <Orders> &orders, vector <Inquiries> &inquiries);
void driverMenu();
void ride(vector <Customers> &customers, vector <Orders> &orders, vector <Inquiries> &inquiries);
void customerSignup(vector <Customers> &customers);
int customerLogin(vector <Customers> &customers);
void guestOrder();
void myPage(vector <Customers> &customers);
void ride(vector <Customers> &customers, vector <Orders> &orders);
void customerInquiry(vector <Customers> &customers, vector <Orders> &orders, vector <Inquiries> &inquiries);

//read files
// void readCustomerList(vector <Customers> &customers);
// void readDriverList(vector <Drivers> &drivers);
// void readAdminList(vector <Admins> &admins);
// void readOrderList(vector <Orders> &orders);
// void readInquiryList(vector <Inquiries> &inquiries);

//Validation//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
bool isPhoneValid(string& phone);
bool isEmailValid(string& email);
bool isPasswordValid(string& password);
bool isIntegerValid(string& number);

int calculateDays(int month, int day);
int calculateWeeks(int days);








/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Functions (Menu)
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void customerMenu(vector <Customers> &customers, vector <Orders> &orders, vector <Inquiries> &inquiries){
    int option;
    bool isUserInfo = false;

    cout << "************************************************\n";
    cout << "Welcome Yoobee Customers!\n";
    cout << "Please select a number from the menu\n";
    cout << "************************************************\n";
    cout << "Menu\n";
    cout << "  1.Ride\n";
    cout << "  2.My Page\n";
    cout << "  3.Inquiry\n";
    cout << "  4.Exit\n";
    cout << " ------------------------------------------------\n";
    cout << "  Enter option: ";
    cin >> option;
    cout << "\n\n";

    switch (option) {
        case 1:
        ride(customers, orders, inquiries);
        break;


        case 2:
        int option;
        int j;

        cout << " ------------------------------------------------\n";
        cout << " Do you have Yoobee Taxi account?: \n";
        cout << "  1. Login       (if you have our account)\n";
        cout << "  2. Sign up     (if you don't have our account and  want to create(free))\n";
        cout << " ------------------------------------------------\n";
        cout << "  Enter option: ";
        cin >> option;
        // cout << " ------------------------------------------------\n";
        switch (option){
            case 1:
            j = customerLogin(customers);
            if (j != 0){
                isUserInfo = true;
            }
            break;

            case 2:
            customerSignup(customers);
            j = customers.size() -1;

            if (j != 0){
                isUserInfo = true;
            }
            break;
        }

        if (isUserInfo == true){
            myPage(customers);
        }
        break;


        case 3:
        cout << "Update later\n";
        customerInquiry(customers, orders, inquiries);
        break;

        case 4:
        break;
    }
}



/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Functions (Ride, etc..)
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void ride(vector <Customers> &customers, vector <Orders> &orders, vector <Inquiries> &inquiries){
    struct Customers c;
    struct Orders o;
    char requestNow;
    int option1, option2;
    int j;
    int i = orders.size();
    bool isUserInfo = false;
    time_t now = time(0);
    tm *ltm = localtime(&now);


    cout << " Enter pickup location: ";
    cin >> o.pickupLocation;
    cout << " Enter destination: ";
    cin >> o.destination;
    cout << " ------------------------------------------------\n";
    cout << " Request Now? (y/n): ";
    cin >> requestNow;
    
    if (requestNow == 'y'){
        // get current date
        o.year = 1900 + ltm->tm_year;
        o.month = 1 + ltm->tm_mon;
        o.day = ltm->tm_mday;

        o.days = calculateDays(o.month, o.day);
        o.week = calculateWeeks(o.days);

    } 

    if(requestNow == 'n') {
        cout << "------------------------------------------------\n";
        cout << "When are you going to ride?\n";
        cout << "  Year (e.g. 2022): ";
        cin >> o.year;
        cout << "  Month (e.g. 01): ";
        cin >> o.month;
        cout << "  Day (e.g. 01): ";
        cin >> o.day;

        o.days = calculateDays(o.month, o.day);
        o.week = calculateWeeks(o.days);
    }  
    //select service
    cout << " ------------------------------------------------\n";
    cout << " Please select a service: \n";
    cout << "  1. Taxi\t\t4 people\t$10.00\t10:30AM(Pick up) \n";
    cout << "  2. Van\t\t5 people\t$15.00\t10:35AM(Pick up) \n";
    cout << "  3. Premium Van\t6 people\t$20.00\t10:40AM(Pick up) \n";
    cout << " ------------------------------------------------\n";
    cout << "  Enter option: ";
    cin >> o.selectedService;

    cout << " ------------------------------------------------\n";
    cout << " Do you have Yoobee Taxi account?: \n";
    cout << "  1. Login       (if you have our account)\n";
    cout << "  2. Sign up     (if you don't have our account and  want to create(free))\n";
    cout << "  3. Guest Order (If you don't want to create our account)\n";
    cout << " ------------------------------------------------\n";
    cout << "  Enter option: ";
    cin >> option1;
    // cout << " ------------------------------------------------\n";
    switch (option1){
        case 1:
        j = customerLogin(customers);
        if (j != 0){
            isUserInfo = true;
        }
        break;

        case 2:
        customerSignup(customers);
        j = customers.size() -1;

        if (j != 0){
            isUserInfo = true;
        }
        break;


        case 3:
        cout << " ------------------------------------------------\n";
        cout << "Enter your information \n";
        cout << " Name: ";
        cin >> c.name;
        while (true){
            cout << " Phone number (e.g. 000-0000-0000): ";
            cin  >> c.phone;

            if (isPhoneValid(c.phone) == true){
                break;
            } else {
                cout << "\n  ❗️Please enter a valid phone number\n\n";
            }
        }

        //email validation
        while (true){
            cout << " Email address (e.g. test@email.com): ";
            cin  >> c.email;

            if (isEmailValid(c.email) == true){
                break;
            } else {
                cout << "\n  ❗️Please enter a valid email address\n\n";
            }
        }

        cout << " Payment method: \n";
        cout << "  1. Cash \n";
        cout << "  2. Credit Card \n";
        cout << "  3. Online Payment \n";
        cout << "  4. - \n";
        cout << " ------------------------------------------------\n";
        cout << "  Enter option: ";
        cin >> option2;
        
        switch(option2){
            case 1:
            c.payment = "Cash";
            break;

            case 2:
            c.payment = "Credit Card";
            // cout << "Enter your Credit Card Number(e.g. 0000-0000-0000) :";
            // cin >> c.creditCardNumber;
            break;

            case 3:
            // cout << "Choose your Online Payment Service :"
            c.payment = "Online Payment";
            break;
        }
        isUserInfo = true;
    }



    if (isUserInfo == true){
        cout << " ------------------------------------------------\n";
        cout << " Please check and confirm your order information \n\n";
        if (option1 == 1 || option1 == 2){
            cout << "  Your Name:\t\t" << customers[j].name <<"\n";
            cout << "  Your Phone number:\t" << customers[j].phone << "\n";
        } else {
            cout << "  Your Name:\t\t" << c.name <<"\n";
            cout << "  Your Phone number:\t" << c.phone << "\n"; 
        }
        cout << "  Pickup location:\t" << o.pickupLocation << "\n";
        cout << "  Destination:\t\t" << o.destination << "\n";


        switch (o.selectedService) {
            case 1:
            o.carType = "Taxi(4 people)";

            cout << "  Car type:\t\tTaxi(4 people)\n";
            cout << "  Fare:\t\t\t$10.00\n";
            cout << "  Pick up time:\t\t10:30AM\n";
            break;

            case 2:
            o.carType = "Van(5 people)";

            cout << "  Car type:\t\tVan(5 people)\n";
            cout << "  Fare:\t\t\t$15.00\n";
            cout << "  Pick up time:\t\t10:35AM\n";
            break;

            case 3:
            o.carType = "Premium Van(6 people)";

            cout << "  Car type:\t\tPremium Van(6 people)\n";
            cout << "  Fare:\t\t\t$20.00\n";
            cout << "  Pick up time:\t\t10:40AM\n\n";
            break;
        }



        if (option1 == 3){
            o.customerName = c.name;
        } else {
            o.customerName = customers[j].name;
        }

        o.driverName = "Not assigned";
        o.fare = 111.11;
        
        orders.push_back(o);


        //confirm order
        char confirm;
        ofstream orderList("OrderList.csv", ios::app);

        cout << "------------------------------------------------\n";
        cout << "Confirm order (y/n): ";
        cin >> confirm;
        
        if (confirm == 'y'){
            cout << "------------------------------------------------\n";
            cout << "\n  Thank you!\n  See you later!\n";
            orderList << orders[i].year << "," << orders[i].month << "," << orders[i].day << "," << orders[i].days << "," << orders[i].week << "," << orders[i].customerName << "," << orders[i].driverName << "," << orders[i].carType << "," << orders[i].pickupLocation << "," << orders[i].destination << "," << orders[i].fare << ",\n" ;

        } else {
            cout << "\n  Your order was canceled.\n";
        }

        //go back to the admin menu
        cout << "\nPress any key to go back to the Customer Menu\n";
        system("read");
        customerMenu(customers, orders, inquiries);
    }
    cout << "\n\n";

}



/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Functions (Sign up, Login)
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void customerSignup(vector <Customers> &customers){
    struct Customers c;
    int option;
    int i = customers.size();

    cout << "\n************************************************\n";
    cout << "Sign up\n";
    cout << "************************************************\n";
    cout << "Enter your information \n";
    cout << " Name: ";
    cin >> c.name;
    // cout << " Phone number (e.g. 000-0000-0000): ";
    // cin >> c.phone;
    //phone validation
    while (true){
        cout << " Phone number (e.g. 000-0000-0000): ";
        cin  >> c.phone;

        if (isPhoneValid(c.phone) == true){
            break;
        } else {
            cout << "\n  ❗️Please enter a valid phone number\n\n";
        }
    }

    // cout << " Email address: ";
    // cin >> c.email;
    //email validation
    while (true){
        cout << " Email address (e.g. test@email.com): ";
        cin  >> c.email;

        if (isEmailValid(c.email) == true){
            break;
        } else {
            cout << "\n  ❗️Please enter a valid email address\n\n";
        }
    }

    cout << " Home address: \n";
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
    // cout << " Password: ";
    // cin >> c.password;
    //password validation
    cout << "\nEnter your password: \n";
    cout << "  -At least 8 characters\n";
    cout << "  -At least one upper case character\n";
    cout << "  -At least one lower case character\n";
    cout << "  -At least one special character (@, !, ?, #)\n";
    cout << "  -At least one number\n";
    
    while (true){
        cout << "---------------------------------------------------------\n";
        cout << "   Your password is: ";
        cin  >> c.password;
        cout << "\n";

        if (isPasswordValid(c.password) == true){
            break;
        } else {
            cout << "\nPlease enter a valid password.\n";
        }
    }

    cout << " Payment method: \n";
    cout << "  1. Cash \n";
    cout << "  2. Credit Card \n";
    cout << "  3. Online Payment \n";
    cout << "  4. - \n";
    cout << " ------------------------------------------------\n";
    cout << "  Enter option: ";
    cin >> option;
    
    switch(option){
        case 1:
        c.payment = "Cash";
        break;

        case 2:
        c.payment = "Credit Card";
        // cout << "Enter your Credit Card Number(e.g. 0000-0000-0000) :";
        // cin >> c.creditCardNumber;
        break;

        case 3:
        // cout << "Choose your Online Payment Service :"
        c.payment = "Online Payment";
        break;
    }

    customers.push_back(c);

    cout << "\n\n";

    ofstream customerList("CustomerList.csv", ios::app);


    // customerList << "Name,Phone,Email,Street,City,State,Country,Postal Code,Password,Payment\n" ;
    customerList << customers[i].name << "," << customers[i].phone << "," << customers[i].email << "," << customers[i].street << "," << customers[i].city << "," << customers[i].state << "," << customers[i].country << "," << customers[i].postalCode << "," << customers[i].password << "," << customers[i].payment << ",\n" ;
}




int customerLogin(vector <Customers> &customers){
    string userEmail, userPassword;
    int attemptCounts = 3;          //limit of attempts
    int customerId;

    cout << "\n************************************************\n";
    cout << "Customer Login\n";
    cout << "************************************************\n";
    cout << "Enter your information \n";
    
    while (attemptCounts > 0){
        cout << " Email address: ";
        cin >> userEmail;
        cout << " Password: ";
        cin >> userPassword;

        int emailFlag = 0, passwordFlag = 0;                    //initialize flag

        for (int i = 1; i < customers.size(); i++){        
            if (customers[i].email == userEmail && customers[i].password == userPassword){
                emailFlag = 1;
                passwordFlag = 1;

                customerId = i;
                break;
            }
            if (customers[i].email == userEmail && customers[i].password != userPassword){
                emailFlag = 1;
                passwordFlag = 0;
                break;
            }
            if (customers[i].email != userEmail){
                emailFlag = 0;
                passwordFlag = 0;
            }
        }

        attemptCounts--;    
        
        //check results
        if (emailFlag == 1 & passwordFlag == 1){
            cout << "----------------------------------------------------------------\n";
            cout << "Logged in successfully\n\n";
            //Login successfully
            // customerMenu(customers, orders);
            break;
            
        } else if (attemptCounts == 0){
            cout << "----------------------------------------------------------------\n";
            cout << "The number of login attempts has exceeded the limit.\n";
            cout << "Please wait a while and try again.\n";

            customerId = 0;

        } else {
            if (emailFlag == 1 && passwordFlag == 0){
                cout << "\n  ❗️Your password is wrong\n";
                cout << "    Please try again.\n\n";
            } else if (emailFlag == 0 & passwordFlag == 0){
                // cout << "\n  ❗️Your email address and password are wrong (or you are not authorized)\n";
                cout << "\n  ❗️Your email address is not registered.\n";
                cout << "    Please try again.\n\n";
            } 
        }
    }
    cout << "\n";

    return customerId;
}




// void guestOrder(){
//     cout << "************************************************\n";
//     cout << "Guest order\n";
//     cout << "************************************************\n";
//     cout << "Enter your information \n";
//     cout << " Name: \n";
//     cout << " Phone number: \n";
//     cout << " Payment method: \n";
//     cout << "  1. Cash \n";
//     cout << "  2. Credit Card \n";
//     cout << "  3. Online Payment \n";
//     cout << "  4. Cryptocurrency \n";
//     cout << " ------------------------------------------------\n";

//     cout << "\n\n";
// }

void myPage(vector <Customers> &customers){    
    int j;
    int option;

    cout << "************************************************\n";
    cout << "Welcome our customer \n";
    cout << "************************************************\n";
    cout << "Menu \n";
    cout << "  1. Account Info\n";
    cout << "  2. Trip Orders \n";
    cout << "  3. - \n";
    cout << "  4. Exit \n";
    cout << " ------------------------------------------------\n";
    cout << "  Enter option: ";
    cin >> option;
    cout << "\n";

    switch (option){
        case 1:
        cout << "************************************************\n";
        cout << "Account Information\n";
        cout << "************************************************\n";
        cout << "  Name:\t\t" << customers[j].name <<"\n";
        cout << "  Phone number:\t\t" << customers[j].phone << "\n";
        cout << "  Email address:\t" << customers[j].email <<"\n";
        cout << "  Street:\t\t" << customers[j].street << "\n";
        cout << "  City:\t\t\t" << customers[j].city << "\n";
        cout << "  State:\t\t" << customers[j].state << "\n";
        cout << "  Country:\t\t" << customers[j].country << "\n";
        cout << "  Postal Code:\t\t" << customers[j].postalCode << "\n\n";
        cout << "  Do you want to edit? (Update later)\n\n";

        //go back to the My Page
        cout << "\nPress any key to go back to the My Page\n";
        system("read");
        myPage(customers);
        break;

        case 2:
        cout << "************************************************\n";
        cout << "Trip orders\n";
        cout << "************************************************\n";
        cout << "Update later" << "\n";

        //go back to the My Page
        cout << "\nPress any key to go back to the My Page\n";
        system("read");
        myPage(customers);
        break;

        case 3:
        cout << "************************************************\n";
        cout << "Coupons? Messages? etc..\n";
        cout << "************************************************\n";
        cout << "Update later" << "\n";

        //go back to the My Page
        cout << "\nPress any key to go back to the My Page\n";
        system("read");
        myPage(customers);
        break;

        case 4:
        break;
    }
}



// /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// //Functions (Read Files)
// /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// void readOrderList(vector <Orders> &orders){
//     ifstream orderList("OrderList.csv");
//     string line, item;
//     struct Orders o;

//     while (getline(orderList, line)) {    
//         istringstream i_stream(line);
        
//         //String to integer conversion
//         getline(i_stream, item, ',');
//         o.year = atoi(item.c_str());
//         getline(i_stream, item, ',');
//         o.month = atoi(item.c_str());
//         getline(i_stream, item, ',');
//         o.day = atoi(item.c_str());
//         getline(i_stream, item, ',');
//         o.days = atoi(item.c_str());
//         getline(i_stream, item, ',');
//         o.week = atoi(item.c_str());

//         getline(i_stream, o.customerName, ',');
//         getline(i_stream, o.driverName, ',');
//         getline(i_stream, o.carType, ',');
//         getline(i_stream, o.pickupLocation, ',');
//         getline(i_stream, o.destination, ',');
//         getline(i_stream, item, ',');
//         o.fare = atoi(item.c_str());
        
//         orders.push_back(o);
//     }
// }

// void readInquiryList(vector <Inquiries> &inquiries){
//     ifstream inquiryList("InquiryList.csv");
//     string line, item;
//     struct Inquiries i;

//     while (getline(inquiryList, line)) {    
//         istringstream i_stream(line);
        
//         getline(i_stream, item, ',');
//         i.year = atoi(item.c_str());
//         getline(i_stream, item, ',');
//         i.month = atoi(item.c_str());
//         getline(i_stream, item, ',');
//         i.day = atoi(item.c_str());

//         getline(i_stream, i.name, ',');
//         getline(i_stream, i.userType, ',');
//         getline(i_stream, i.phone, ',');
//         getline(i_stream, i.email, ',');
//         getline(i_stream, i.topic, ',');
//         getline(i_stream, i.detail, ',');

//         inquiries.push_back(i);
//     }
// }

// void readCustomerList(vector <Customers> &customers){
//     ifstream customerList("CustomerList.csv");
//     string line, item;
//     struct Customers c;

//     while (getline(customerList, line)) {    
//         istringstream i_stream(line);

//         getline(i_stream, c.name, ',');
//         getline(i_stream, c.phone, ',');
//         getline(i_stream, c.email, ',');
//         getline(i_stream, c.street, ',');
//         getline(i_stream, c.city, ',');
//         getline(i_stream, c.state, ',');
//         getline(i_stream, c.country, ',');
//         getline(i_stream, c.postalCode, ',');
//         getline(i_stream, c.password, ',');
//         getline(i_stream, c.payment, ',');

//         customers.push_back(c);  
//     }
// }

// void readDriverList(vector <Drivers> &drivers){
//     ifstream driverList("DriverList.csv");
//     string line, item;
//     struct Drivers d;

//     while (getline(driverList, line)) {    
//         istringstream i_stream(line);

//         getline(i_stream, d.name, ',');
//         getline(i_stream, d.phone, ',');
//         getline(i_stream, d.email, ',');
//         getline(i_stream, d.street, ',');
//         getline(i_stream, d.city, ',');
//         getline(i_stream, d.state, ',');
//         getline(i_stream, d.country, ',');
//         getline(i_stream, d.postalCode, ',');
//         getline(i_stream, d.password, ',');
//         getline(i_stream, d.license, ',');
//         getline(i_stream, d.area, ',');

//         drivers.push_back(d); 
//     }
// }

// void readAdminList(vector <Admins> &admins){
//     ifstream adminList("AdminList.csv");
//     string line, item;
//     struct Admins a;

//     while (getline(adminList, line)) {    
//         istringstream i_stream(line);

//         getline(i_stream, a.name, ',');
//         getline(i_stream, a.phone, ',');
//         getline(i_stream, a.email, ',');
//         getline(i_stream, a.street, ',');
//         getline(i_stream, a.city, ',');
//         getline(i_stream, a.state, ',');
//         getline(i_stream, a.country, ',');
//         getline(i_stream, a.postalCode, ',');
//         getline(i_stream, a.password, ',');

//         admins.push_back(a); 
//     }
// }



// bool isPhoneValid(string& phone){
//    regex pattern("(\\d+)(\\-)(\\d+)(\\-)(\\d+)");         // define a regular expression
   
//    return regex_match(phone, pattern);                          // try to match the string with the regular expression
// }

// bool isEmailValid(string& email){
//    regex pattern("(\\w+)(\\.|_)?@(\\w+)(\\.(\\w+))");       
   
//    return regex_match(email, pattern);                           
// }

// bool isPasswordValid(string& password){
//     bool digit, upperCase, lowerCase, specialCharacter, number, result; 
//     int digitFlag = 0, upperFlag = 0, lowerFlag = 0, specialCharacterFlag = 0, numberFlag = 0;

//     regex digitExpression( ".{8,}" );
//     regex upperCaseExpression( "[A-Z]+" );
//     regex lowerCaseExpression( "[a-z]+" );
//     regex specialCharacterExpression( "[@!?#]+");
//     regex numberExpression( "[0-9]+" );

//     digit = regex_match(password, digitExpression);                         //Determine if the password is 8 characters or more
//     upperCase = regex_search(password, upperCaseExpression);                //Determine if there is a part that matches the upper case
//     lowerCase = regex_search(password, lowerCaseExpression);                //Determine if there is a part that matches the lower case
//     specialCharacter = regex_search(password, specialCharacterExpression);  //Determine if there is a part that matches the special character
//     number = regex_search(password, numberExpression);                      //Determine if there is a part that matches the number

//     if (digit == false){
//         cout << "  ❗️At least 8 characters\n";
//         digitFlag = 1;
//     }
//     if (upperCase == false){
//         cout << "  ❗️At least one upper case character\n";
//         upperFlag = 1;
//     }
//     if (lowerCase == false){
//         cout << "  ❗️At least one lower case character\n";
//         lowerFlag = 1;
//     }
//     if (specialCharacter == false){
//         cout << "  ❗️At least one special character (@, !, ?, #)\n";
//         specialCharacterFlag = 1;
//     } 
//     if (number == false){
//         cout << "  ❗️At least one number\n";
//         numberFlag = 1;
//     }

//     int totalFlagNum = digitFlag + upperFlag + lowerFlag + numberFlag + specialCharacterFlag; 

//     if (totalFlagNum == 0){
//         result = true;
//     } else {
//         result = false;
//     }

//     return result;
// }



int calculateDays(int month, int day){
    int days;

    switch (month){
        case 1:     //Jan
        days = day;
        break;

        case 2:     //Feb
        days = 31 + day;
        break;

        case 3:     //Mar
        days = 31 + 28 + day;
        break;

        case 4:     //Apr
        days = 31 + 28 + 31 + day;
        break;

        case 5:     //May
        days = 31 + 28 + 31 + 30 + day;
        break;

        case 6:     //Jun
        days = 31 + 28 + 31 + 30 + 31 + day;
        break;

        case 7:     //Jul
        days = 31 + 28 + 31 + 30 + 31 + 30 + day;
        break;

        case 8:     //Aug
        days = 31 + 28 + 31 + 30 + 31 + 30 + 31 + day;
        break;

        case 9:     //Sep
        days = 31 + 28 + 31 + 30 + 31 + 30 + 31 + 31 + day;
        break;

        case 10:    //Oct
        days = 31 + 28 + 31 + 30 + 31 + 30 + 31 + 31 + 30 + day;
        break;

        case 11:    //Nov
        days = 31 + 28 + 31 + 30 + 31 + 30 + 31 + 31 + 30 + 31 + day;
        break;

        case 12:    //Dec
        days = 31 + 28 + 31 + 30 + 31 + 30 + 31 + 31 + 30 + 31 + 30 + day;
        break;
    }

    return days;
}


int calculateWeeks(int days){
    int week;

    if (days % 7 == 0){             //ex) 7%7=0, 14%7=0,....
        week = days / 7;            //ex) 7/7=1 (-->week1), 14/7=2 (-->week2), ....
    } else {
        week = (days / 7) + 1;      //ex) 3/7=0(int) +1 =1 (week1)
    }

    return week;
}

bool isIntegerValid(string& number){
   regex pattern("[0-9]");                  //Determine if the number is integer

   return regex_match(number, pattern);                    
}

void customerInquiry(vector <Customers> &customers, vector <Orders> &orders, vector <Inquiries> &inquiries){
    struct Customers c;
    struct Inquiries iq;
    string inquiryDetail;

    int option1, option2;
    int j;
    int i = inquiries.size();
    bool isUserInfo = false;
    time_t now = time(0);
    tm *ltm = localtime(&now);

    iq.year = 1900 + ltm->tm_year;
    iq.month = 1 + ltm->tm_mon;
    iq.day = ltm->tm_mday;

    //select service
    cout << " ------------------------------------------------\n";
    cout << " Please select a topic: \n";
    cout << "  1. Service \n";
    cout << "  2. Lost Item\n";
    cout << "  3. Others \n";
    cout << " ------------------------------------------------\n";
    cout << "  Enter option: ";
    cin >> option1;
    cout << "\n";

    cout << " ------------------------------------------------\n";
    cout << " Please tell me the details of your inquiry: \n\t";
    getline (cin, inquiryDetail);
    getline (cin, inquiryDetail);
    iq.detail = inquiryDetail;

    cout << " ------------------------------------------------\n";
    cout << " Do you have Yoobee Taxi account?: \n";
    cout << "  1. Login       (if you have our account)\n";
    cout << "  2. Sign up     (if you don't have our account and  want to create(free))\n";
    cout << "  3. Guest       (If you don't want to create our account)\n";
    cout << " ------------------------------------------------\n";
    cout << "  Enter option: ";
    cin >> option2;
    // cout << " ------------------------------------------------\n";
    switch (option2){
        case 1:
        j = customerLogin(customers);
        if (j != 0){
            isUserInfo = true;
        }
        break;

        case 2:
        customerSignup(customers);
        j = customers.size() -1;

        if (j != 0){
            isUserInfo = true;
        }
        break;


        case 3:
        cout << " ------------------------------------------------\n";
        cout << "Enter your information \n";
        cout << " Name: ";
        cin >> iq.name;
        while (true){
            cout << " Phone number (e.g. 000-0000-0000): ";
            cin  >> iq.phone;

            if (isPhoneValid(iq.phone) == true){
                break;
            } else {
                cout << "\n  ❗️Please enter a valid phone number\n\n";
            }
        }

        //email validation
        while (true){
            cout << " Email address (e.g. test@email.com): ";
            cin  >> iq.email;

            if (isEmailValid(iq.email) == true){
                break;
            } else {
                cout << "\n  ❗️Please enter a valid email address\n\n";
            }
        }
        isUserInfo = true;
    }



    if (isUserInfo == true){
        cout << " ------------------------------------------------\n";
        cout << " Please check and confirm your inquiry \n\n";
        
        if (option2 == 1 || option2 == 2){
            cout << "  Your Name:\t\t" << customers[j].name <<"\n";
            cout << "  Your Phone number:\t" << customers[j].phone << "\n";
        } else {
            cout << "  Your Name:\t\t" << iq.name <<"\n";
            cout << "  Your Phone number:\t" << iq.phone << "\n"; 
        }


        switch (option1) {
            case 1:
            iq.topic = "Service";
            cout << "  Topic:\t" << iq.topic << "\n";
            break;

            case 2:
            iq.topic = "Lost Item";
            cout << "  Topic:\t\t\t" << iq.topic << "\n";
            break;

            case 3:
            iq.topic = "Others";
            cout << "  Topic:\t" << iq.topic << "\n";
            break;
        }
    
        cout << "  Detail:\t\t" << iq.detail << "\n";

        if (option2 == 3){
            iq.name = iq.name;
        } else {
            iq.name = customers[j].name;
        }

        iq.userType = "Customer";
        iq.phone = customers[j].phone;
        iq.email = customers[j].email;

        
        inquiries.push_back(iq);


        //confirm order
        char confirm;
        ofstream inquiryList("InquiryList.csv", ios::app);

        cout << "------------------------------------------------\n";
        cout << "Confirm order (y/n): ";
        cin >> confirm;
        
        if (confirm == 'y'){
            cout << "------------------------------------------------\n";
            cout << "\n  Thank you!\n  See you later!\n";
            inquiryList << inquiries[i].year << "," << inquiries[i].month << "," << inquiries[i].day << "," << inquiries[i].name << "," << inquiries[i].userType << "," << inquiries[i].phone << "," << inquiries[i].email << "," << inquiries[i].topic << "," << inquiries[i].detail << ",\n" ;

        } else {
            cout << "\n  Your inquiry was canceled.\n";
        }

        //go back to the admin menu
        cout << "\nPress any key to go back to the Customer Menu\n";
        system("read");
        customerMenu(customers, orders, inquiries);
    }
    cout << "\n\n";

}