#include <iostream>
#include <vector>
#include <fstream>      //for ofstream, ifstream
#include <sstream>      //for istringstream
// #include <limits>
#include <regex>    //include regular expressions library
#include <ctime>

using namespace std;



/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Declare structures
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
struct Customers{
    string name;
    string phone;
    string email;
    string street;
    string city;
    string state;
    string country;
    string postalCode;
    string password;
    string payment;
    // string creditCardNumber;
    string pickupLocation;
    string destination;
    int selectedService;

    //constructor
    Customers(string n="name", string pn="000-0000-0000", string e="email@email.com", string p="password", string str="street", string cit="city", string sta="state", string cou="country", string pc="000-0000", string pm="credit", string ccn="NA", string pl="area1",string des="area2",int ss=1){
        name = n;
        phone = pn;
        email = e;
        street = str;
        city = cit;
        state = sta;
        country = cou;
        postalCode = pc;
        password = p;
        payment = pm;
        // creditCardNumber = ccn;
        pickupLocation = pl;
        destination = des;
        selectedService = ss;
    }
};


struct Drivers{
    string name;
    string phone;
    string email;
    string street;
    string city;
    string state;
    string country;
    string postalCode;
    string password;
    string license;
    string area;

    //constructor
    Drivers(string n="name", string pn="000-0000-0000", string e="email@email.com", string p="password", string str="street", string cit="city", string sta="state", string cou="country", string pc="000-0000", string li="0000-0000", string a="area"){
        name = n;
        phone = pn;
        email = e;
        street = str;
        city = cit;
        state = sta;
        country = cou;
        postalCode = pc;
        password = p;
        license = li;
        area = a;
    }
};


struct Admins{
    string name;
    string phone;
    string email;
    string street;
    string city;
    string state;
    string country;
    string postalCode;
    string password;
    string payment;

    //constructor
    Admins(string n="name", string pn="000-0000-0000", string e="email@email.com", string p="password", string str="street", string cit="city", string sta="state", string cou="country", string pc="000-0000", string pm="credit"){
        name = n;
        phone = pn;
        email = e;
        street = str;
        city = cit;
        state = sta;
        country = cou;
        postalCode = pc;
        password = p;
        payment = pm;
    }
};

struct Orders{
    int year;
    int month;
    int day;
    int days;
    int week;
    string customerName;
    string driverName;
    string carType;
    string pickupLocation;
    string destination;
    float fare;
    int selectedService;

    Orders(int y=2022, int m=01, int d=01, int ds=01, int w=01, string cn="customer name", string dn="driver name", string ct="taxi", string pl="pickup location", string des="destination", float fa=10.00, int ss=1){
        year = y;
        month = m;
        day = d;
        days = ds;
        week = w;
        customerName = cn; 
        driverName = dn; 
        carType = ct;
        pickupLocation = pl; 
        destination = des;
        fare = fa;
        selectedService = ss;
    }
};

struct Inquiries{
    int year;
    int month;
    int day;
    string name;
    string userType;
    string phone;
    string email;
    string topic;
    string detail;

    Inquiries(int y=2022, int m=01, int d=01, string n="name", string ut="user type", string p="000-0000-0000", string e="email@email.com", string t="topic", string de="detail"){
        year = y;
        month = m;
        day = d;
        name = n; 
        userType = ut; 
        phone = p;
        email = e; 
        topic = t;
        detail = de;
    }
};






/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Declare function prototypes
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void mainMenu(vector <Customers> &customers, vector <Drivers> &drivers, vector <Admins> &admins, vector <Orders> &orders, vector <Inquiries> &inquiries, int* sId);

//customer function
void customerMenu(vector <Customers> &customers, vector <Orders> &orders, vector <Inquiries> &inquiries, int* sId);
void ride(vector <Customers> &customers, vector <Orders> &orders, vector <Inquiries> &inquiries, int* sId);
void customerSignup(vector <Customers> &customers);
int customerLogin(vector <Customers> &customers);
void customerPage(vector <Customers> &customers, vector <Orders> &orders, vector <Inquiries> &inquiries, int* sId);
void customerInquiry(vector <Customers> &customers, vector <Orders> &orders, vector <Inquiries> &inquiries, int* sId);
int calculateDays(int month, int day);
int calculateWeeks(int days);

//driver function
void driverMenu(vector <Drivers> &drivers, vector <Orders> &orders, vector <Inquiries> &inquiries, int* sId);
void driverSignup(vector <Drivers> &drivers);
int driverLogin(vector <Drivers> &drivers, vector <Orders> &orders, vector <Inquiries> &inquiries);
void driverPage(vector <Drivers> &drivers, vector <Orders> &orders, vector <Inquiries> &inquiries, int* sId);
void driverInquiry(vector <Drivers> &drivers, vector <Orders> &orders, vector <Inquiries> &inquiries, int* sId);
void getOrder(vector <Drivers> &drivers, vector <Orders> &orders, vector <Inquiries> &inquiries, int* sId);


//read files
void readCustomerList(vector <Customers> &customers);
void readDriverList(vector <Drivers> &drivers);
// void readAdminList(vector <Admins> &admins);
void readOrderList(vector <Orders> &orders);
void readInquiryList(vector <Inquiries> &inquiries);

//Validation//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
bool isPhoneValid(string& phone);
bool isEmailValid(string& email);
bool isPasswordValid(string& password);






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
    // readAdminList(admins);
    readOrderList(orders);
    readInquiryList(inquiries);

    //store session user id
    int sessionId = 0;          //initial value is 0 (= no session)
    int* sId = &sessionId;



    mainMenu(customers, drivers, admins, orders, inquiries, sId);



    return 0;
}






/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Functions (Menu)
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void mainMenu(vector <Customers> &customers, vector <Drivers> &drivers, vector <Admins> &admins, vector <Orders> &orders, vector <Inquiries> &inquiries, int* sId){
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
    cout << "  4.Exit\n";
    cout << "------------------------\n";
    cout << "  Enter option: ";
    cin >> option;
    cout << "\n\n";

    switch (option) {
        case 1:
        customerMenu(customers, orders, inquiries, sId);
        break;

        case 2:
        cout << " ------------------------------------------------\n";
        cout << " Do you have Yoobee Taxi Driver Account?: \n";
        cout << "  1. Login       (if you have our account)\n";
        cout << "  2. Sign up     (if you don't have our account and want to create(free))\n";
        cout << "  3. Exit\n";
        cout << " ------------------------------------------------\n";
        cout << "  Enter option: ";
        cin >> option;

        switch (option){
            case 1:
            *sId = driverLogin(drivers, orders, inquiries);
            if (*sId != 0){
                driverMenu(drivers, orders, inquiries, sId);
            }
            break;

            case 2:
            driverSignup(drivers);
            *sId = drivers.size() -1;

            if (*sId != 0){
                driverMenu(drivers, orders, inquiries, sId);
            }
            break;

            case 3:
            break;
        }
        break;

        case 3:
        // adminLogin(customers, drivers, admins, orders, inquiries);
        cout << "admin login\n";
        break;
        case 4:
        break;
    }

}

void customerMenu(vector <Customers> &customers, vector <Orders> &orders, vector <Inquiries> &inquiries, int* sId){
    int option;

    cout << "************************************************\n";
    cout << "Welcome Yoobee Customers!\n";
    cout << "Please select a number from the menu\n";
    cout << "************************************************\n";
    cout << "Menu\n";
    cout << "  1.Ride*\n";
    cout << "  2.My Page\n";
    cout << "  3.Inquiry\n";
    cout << "  4.Exit\n";
    cout << "                   *Direct Call: 012-3456-7890\n";
    cout << " ------------------------------------------------\n";
    cout << "  Enter option: ";
    cin >> option;
    cout << "\n\n";

    switch (option) {
        case 1:
        ride(customers, orders, inquiries, sId);
        break;


        case 2:
        int option;

        if (*sId == 0){
            cout << " ------------------------------------------------\n";
            cout << " Do you have Yoobee Taxi Customer Account?: \n";
            cout << "  1. Login       (if you have our account)\n";
            cout << "  2. Sign up     (if you don't have our account and  want to create(free))\n";
            cout << "  3. Go Back\n";
            cout << " ------------------------------------------------\n";
            cout << "  Enter option: ";
            cin >> option;
            // cout << " ------------------------------------------------\n";
            switch (option){
                case 1:
                *sId = customerLogin(customers);
                break;

                case 2:
                customerSignup(customers);
                *sId = customers.size() -1;
                break;

                case 3:
                customerMenu(customers, orders, inquiries, sId);
                break;
            }
            if (*sId != 0){
                customerPage(customers, orders, inquiries, sId);
            } 

        } else {
            customerPage(customers, orders, inquiries, sId);
        }
        break;


        case 3:
        customerInquiry(customers, orders, inquiries, sId);
        break;

        case 4:
        break;
    }
}

void driverMenu(vector <Drivers> &drivers, vector <Orders> &orders, vector <Inquiries> &inquiries, int* sId){
    int option;

    cout << "************************************************\n";
    cout << "Welcome Yoobee Drivers!\n";
    cout << "Please select a number from the menu\n";
    cout << "************************************************\n";
    cout << "Menu\n";
    cout << "  1.Get Order\n";
    cout << "  2.My Page\n";
    cout << "  3.Inquiry\n";
    cout << "  4.Exit\n";
    cout << " ------------------------------------------------\n";
    cout << "  Enter option: ";
    cin >> option;
    cout << "\n\n";

    switch (option) {
        case 1:
        getOrder(drivers, orders, inquiries, sId);
        break;


        case 2:
        driverPage(drivers,orders, inquiries, sId);
        
        break;


        case 3:
        driverInquiry(drivers, orders, inquiries, sId);
        break;

        case 4:
        break;
    }
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Functions (Ride, etc..)
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void ride(vector <Customers> &customers, vector <Orders> &orders, vector <Inquiries> &inquiries, int* sId){
    struct Customers c;
    struct Orders o;
    char requestNow;
    int option1, option2;
    // int j;
    int i = orders.size();
    bool isUserInfo = false;
    time_t now = time(0);
    tm *ltm = localtime(&now);

    cout << " ------------------------------------------------\n";
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


    if (*sId == 0){
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
            *sId = customerLogin(customers);
            break;

            case 2:
            customerSignup(customers);
            *sId = customers.size() -1;
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
    }


    int s = *sId;

    cout << " ------------------------------------------------\n";
    cout << " Please check and confirm your order information \n\n";
    if (s != 0){
        cout << "  Your Name:\t\t" << customers[s].name <<"\n";
        cout << "  Your Phone number:\t" << customers[s].phone << "\n";
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
        o.customerName = customers[s].name;
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
    customerMenu(customers, orders, inquiries, sId);
    
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

    while (true){
        cout << " Phone number (e.g. 000-0000-0000): ";
        cin  >> c.phone;

        if (isPhoneValid(c.phone) == true){
            break;
        } else {
            cout << "\n  ❗️Please enter a valid phone number\n\n";
        }
    }

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


void driverSignup(vector <Drivers> &drivers){
    struct Drivers d;
    int option;
    int i = drivers.size();

    cout << "\n************************************************\n";
    cout << "Sign up\n";
    cout << "************************************************\n";
    cout << "Enter your information \n";
    cout << " Name: ";
    cin >> d.name;
    // cout << " Phone number (e.g. 000-0000-0000): ";
    // cin >> c.phone;
    //phone validation
    while (true){
        cout << " Phone number (e.g. 000-0000-0000): ";
        cin  >> d.phone;

        if (isPhoneValid(d.phone) == true){
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
        cin  >> d.email;

        if (isEmailValid(d.email) == true){
            break;
        } else {
            cout << "\n  ❗️Please enter a valid email address\n\n";
        }
    }

    cout << " Home address: \n";
    cout << "    Street: ";
    cin >> d.street;
    cout << "    City: ";
    cin >> d.city;
    cout << "    State: ";
    cin >> d.state;
    cout << "    Country: ";
    cin >> d.country;
    cout << "    Postal Code(e.g. 000-0000): ";
    cin >> d.postalCode;
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
        cin  >> d.password;
        cout << "\n";

        if (isPasswordValid(d.password) == true){
            break;
        } else {
            cout << "\nPlease enter a valid password.\n";
        }
    }

    cout << "    License Number(e.g. 000000): ";
    cin >> d.license;
    cout << "    Area(e.g. Area1): ";
    cin >> d.area;


    drivers.push_back(d);

    cout << "\n\n";

    ofstream driverList("DriverList.csv", ios::app);


    // customerList << "Name,Phone,Email,Street,City,State,Country,Postal Code,Password,Payment\n" ;
    driverList << drivers[i].name << "," << drivers[i].phone << "," << drivers[i].email << "," << drivers[i].street << "," << drivers[i].city << "," << drivers[i].state << "," << drivers[i].country << "," << drivers[i].postalCode << "," << drivers[i].password << "," << drivers[i].license << "," << drivers[i].area << ",\n" ;
}




int customerLogin(vector <Customers> &customers){
    string userEmail, userPassword;
    int attemptCounts = 3;          //limit of attempts
    int customerNo;

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

                customerNo = i;
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

            customerNo = 0;

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

    return customerNo;
}


int driverLogin(vector <Drivers> &drivers, vector <Orders> &orders, vector <Inquiries> &inquiries){
    string userEmail, userPassword;
    int attemptCounts = 3;          //limit of attempts
    int driverNo;

    cout << "\n************************************************\n";
    cout << "Driver Login\n";
    cout << "************************************************\n";
    cout << "Enter your information \n";
    
    while (attemptCounts > 0){
        cout << " Email address: ";
        cin >> userEmail;
        cout << " Password: ";
        cin >> userPassword;

        int emailFlag = 0, passwordFlag = 0;                    //initialize flag

        for (int i = 1; i < drivers.size(); i++){        
            if (drivers[i].email == userEmail && drivers[i].password == userPassword){
                emailFlag = 1;
                passwordFlag = 1;

                driverNo = i;
                break;
            }
            if (drivers[i].email == userEmail && drivers[i].password != userPassword){
                emailFlag = 1;
                passwordFlag = 0;
                break;
            }
            if (drivers[i].email != userEmail){
                emailFlag = 0;
                passwordFlag = 0;
            }
        }

        attemptCounts--;    
        
        //check results
        if (emailFlag == 1 & passwordFlag == 1){
            cout << "----------------------------------------------------------------\n";
            cout << "Logged in successfully\n\n";
            // driverMenu(drivers, orders, inquiries);
            break;
            
        } else if (attemptCounts == 0){
            cout << "----------------------------------------------------------------\n";
            cout << "The number of login attempts has exceeded the limit.\n";
            cout << "Please wait a while and try again.\n";

            driverNo = 0;

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

    return driverNo;
}


void customerPage(vector <Customers> &customers, vector <Orders> &orders, vector <Inquiries> &inquiries, int* sId){
    int s = *sId;
    int option;

    cout << "************************************************\n";
    cout << "My Page \n";
    cout << "************************************************\n";
    cout << "Menu \n";
    cout << "  1. Account Info\n";
    cout << "  2. Trip History \n";
    cout << "  3. Coupons \n";
    cout << "  4. Go Back \n";
    cout << " ------------------------------------------------\n";
    cout << "  Enter option: ";
    cin >> option;
    cout << "\n";

    switch (option){
        case 1:
        cout << "************************************************\n";
        cout << "Account Information\n";
        cout << "************************************************\n";
        cout << "  Name:\t\t\t" << customers[s].name <<"\n";
        cout << "  Phone number:\t\t" << customers[s].phone << "\n";
        cout << "  Email address:\t" << customers[s].email <<"\n";
        cout << "  Street:\t\t" << customers[s].street << "\n";
        cout << "  City:\t\t\t" << customers[s].city << "\n";
        cout << "  State:\t\t" << customers[s].state << "\n";
        cout << "  Country:\t\t" << customers[s].country << "\n";
        cout << "  Postal Code:\t\t" << customers[s].postalCode << "\n\n";
        cout << "  Do you want to edit? (Update later)\n\n";

        //go back to the My Page
        cout << "\nPress any key to go back to the My Page\n";
        system("read");
        customerPage(customers, orders, inquiries, sId);
        break;

        case 2:
        cout << "************************************************\n";
        cout << "Trip History\n";
        cout << "************************************************\n";
        cout << "Date\t\t Customer\tDriver\t\tCar Type\t\tPickup Location\t\tDestination\t\tFare\n";
        for (int i = 1; i < orders.size(); i++){
            if (orders[i].customerName == customers[s].name){
                cout << orders[i].year << "/" << orders[i].month << "/"<< orders[i].day << "  \t" << orders[i].customerName << "   \t" << orders[i].driverName << "   \t" << orders[i].carType << "   \t" << orders[i].pickupLocation << "   \t\t" << orders[i].destination << "\t" << orders[i].fare <<"   \n";
            }
        }

        //go back to the My Page
        cout << "\nPress any key to go back to the My Page\n";
        system("read");
        customerPage(customers, orders, inquiries, sId);
        break;

        case 3:
        cout << "************************************************\n";
        cout << "Coupons\n";
        cout << "************************************************\n";
        cout << " - 30% off coupon　🎁" << "\n";

        //go back to the My Page
        cout << "\nPress any key to go back to the My Page\n";
        system("read");
        customerPage(customers, orders, inquiries, sId);
        break;

        case 4:
        customerMenu(customers, orders, inquiries, sId);
        break;
    }
}



void driverPage(vector <Drivers> &drivers, vector <Orders> &orders, vector <Inquiries> &inquiries, int* sId){
    int s = *sId;
    int option;
    int driverPoints = 0; 

    cout << "************************************************\n";
    cout << "My Page \n";
    cout << "************************************************\n";
    cout << "Menu \n";
    cout << "  1. Account Info\n";
    cout << "  2. Trip History \n";
    cout << "  3. Driver's Point \n";
    cout << "  4. Go Back \n";
    cout << " ------------------------------------------------\n";
    cout << "  Enter option: ";
    cin >> option;
    cout << "\n";

    switch (option){
        case 1:
        cout << "************************************************\n";
        cout << "Account Information\n";
        cout << "************************************************\n";
        cout << "  Name:\t\t\t" << drivers[s].name <<"\n";
        cout << "  Phone number:\t\t" << drivers[s].phone << "\n";
        cout << "  Email address:\t" << drivers[s].email <<"\n";
        cout << "  Street:\t\t" << drivers[s].street << "\n";
        cout << "  City:\t\t\t" << drivers[s].city << "\n";
        cout << "  State:\t\t" << drivers[s].state << "\n";
        cout << "  Country:\t\t" << drivers[s].country << "\n";
        cout << "  Postal Code:\t\t" << drivers[s].postalCode << "\n";
        cout << "  License Number:\t" << drivers[s].license << "\n";
        cout << "  Area:\t\t\t" << drivers[s].area << "\n\n";
        cout << "  Do you want to edit? (Update later)\n\n";

        //go back to the My Page
        cout << "\nPress any key to go back to the My Page\n";
        system("read");
        driverPage(drivers, orders, inquiries, sId);
        break;

        case 2:
        cout << "************************************************\n";
        cout << "Trip History\n";
        cout << "************************************************\n";
        cout << "Date\t\t Customer\tDriver\t\tCar Type\t\tPickup Location\t\tDestination\t\tFare\n";
        for (int i = 1; i < orders.size(); i++){
            if (orders[i].driverName == drivers[s].name){
                cout << orders[i].year << "/" << orders[i].month << "/"<< orders[i].day << "  \t" << orders[i].customerName << "   \t" << orders[i].driverName << "   \t" << orders[i].carType << "   \t" << orders[i].pickupLocation << "   \t\t" << orders[i].destination << "\t" << orders[i].fare <<"   \n";
            }
        }

        //go back to the My Page
        cout << "\nPress any key to go back to the My Page\n";
        system("read");
        driverPage(drivers,orders, inquiries, sId);
        break;

        case 3:
        cout << "************************************************\n";
        cout << "Driver's Point\n";
        cout << "************************************************\n";
        
        for (int i = 1; i < orders.size(); i++){
            if (orders[i].driverName == drivers[s].name){
                driverPoints++;
            }
        }
        if (driverPoints > 0){
            cout << "Congratulations!\n";
            cout << "Your point is " << driverPoints * 100 << " (NZD)" <<  "\n";
        } else {
            cout << "Let's get customer requests!\n";
            cout << "Your point is " << 0 << "\n";
        }

        //go back to the My Page
        cout << "\nPress any key to go back to the My Page\n";
        system("read");
        driverPage(drivers,orders, inquiries, sId);
        break;

        case 4:
        driverMenu(drivers, orders, inquiries, sId);
        break;
    }
}



/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Functions (Read Files)
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void readOrderList(vector <Orders> &orders){
    ifstream orderList("OrderList.csv");
    string line, item;
    struct Orders o;

    while (getline(orderList, line)) {    
        istringstream i_stream(line);
        
        //String to integer conversion
        getline(i_stream, item, ',');
        o.year = atoi(item.c_str());
        getline(i_stream, item, ',');
        o.month = atoi(item.c_str());
        getline(i_stream, item, ',');
        o.day = atoi(item.c_str());
        getline(i_stream, item, ',');
        o.days = atoi(item.c_str());
        getline(i_stream, item, ',');
        o.week = atoi(item.c_str());

        getline(i_stream, o.customerName, ',');
        getline(i_stream, o.driverName, ',');
        getline(i_stream, o.carType, ',');
        getline(i_stream, o.pickupLocation, ',');
        getline(i_stream, o.destination, ',');
        getline(i_stream, item, ',');
        o.fare = atoi(item.c_str());
        
        orders.push_back(o);
    }
}

void readInquiryList(vector <Inquiries> &inquiries){
    ifstream inquiryList("InquiryList.csv");
    string line, item;
    struct Inquiries i;

    while (getline(inquiryList, line)) {    
        istringstream i_stream(line);
        
        getline(i_stream, item, ',');
        i.year = atoi(item.c_str());
        getline(i_stream, item, ',');
        i.month = atoi(item.c_str());
        getline(i_stream, item, ',');
        i.day = atoi(item.c_str());

        getline(i_stream, i.name, ',');
        getline(i_stream, i.userType, ',');
        getline(i_stream, i.phone, ',');
        getline(i_stream, i.email, ',');
        getline(i_stream, i.topic, ',');
        getline(i_stream, i.detail, ',');

        inquiries.push_back(i);
    }
}

void readCustomerList(vector <Customers> &customers){
    ifstream customerList("CustomerList.csv");
    string line, item;
    struct Customers c;

    while (getline(customerList, line)) {    
        istringstream i_stream(line);

        getline(i_stream, c.name, ',');
        getline(i_stream, c.phone, ',');
        getline(i_stream, c.email, ',');
        getline(i_stream, c.street, ',');
        getline(i_stream, c.city, ',');
        getline(i_stream, c.state, ',');
        getline(i_stream, c.country, ',');
        getline(i_stream, c.postalCode, ',');
        getline(i_stream, c.password, ',');
        getline(i_stream, c.payment, ',');

        customers.push_back(c);  
    }
}

void readDriverList(vector <Drivers> &drivers){
    ifstream driverList("DriverList.csv");
    string line, item;
    struct Drivers d;

    while (getline(driverList, line)) {    
        istringstream i_stream(line);

        getline(i_stream, d.name, ',');
        getline(i_stream, d.phone, ',');
        getline(i_stream, d.email, ',');
        getline(i_stream, d.street, ',');
        getline(i_stream, d.city, ',');
        getline(i_stream, d.state, ',');
        getline(i_stream, d.country, ',');
        getline(i_stream, d.postalCode, ',');
        getline(i_stream, d.password, ',');
        getline(i_stream, d.license, ',');
        getline(i_stream, d.area, ',');

        drivers.push_back(d); 
    }
}



bool isPhoneValid(string& phone){
   regex pattern("(\\d+)(\\-)(\\d+)(\\-)(\\d+)");         // define a regular expression
   
   return regex_match(phone, pattern);                          // try to match the string with the regular expression
}

bool isEmailValid(string& email){
   regex pattern("(\\w+)(\\.|_)?@(\\w+)(\\.(\\w+))");       
   
   return regex_match(email, pattern);                           
}

bool isPasswordValid(string& password){
    bool digit, upperCase, lowerCase, specialCharacter, number, result; 
    int digitFlag = 0, upperFlag = 0, lowerFlag = 0, specialCharacterFlag = 0, numberFlag = 0;

    regex digitExpression( ".{8,}" );
    regex upperCaseExpression( "[A-Z]+" );
    regex lowerCaseExpression( "[a-z]+" );
    regex specialCharacterExpression( "[@!?#]+");
    regex numberExpression( "[0-9]+" );

    digit = regex_match(password, digitExpression);                         //Determine if the password is 8 characters or more
    upperCase = regex_search(password, upperCaseExpression);                //Determine if there is a part that matches the upper case
    lowerCase = regex_search(password, lowerCaseExpression);                //Determine if there is a part that matches the lower case
    specialCharacter = regex_search(password, specialCharacterExpression);  //Determine if there is a part that matches the special character
    number = regex_search(password, numberExpression);                      //Determine if there is a part that matches the number

    if (digit == false){
        cout << "  ❗️At least 8 characters\n";
        digitFlag = 1;
    }
    if (upperCase == false){
        cout << "  ❗️At least one upper case character\n";
        upperFlag = 1;
    }
    if (lowerCase == false){
        cout << "  ❗️At least one lower case character\n";
        lowerFlag = 1;
    }
    if (specialCharacter == false){
        cout << "  ❗️At least one special character (@, !, ?, #)\n";
        specialCharacterFlag = 1;
    } 
    if (number == false){
        cout << "  ❗️At least one number\n";
        numberFlag = 1;
    }

    int totalFlagNum = digitFlag + upperFlag + lowerFlag + numberFlag + specialCharacterFlag; 

    if (totalFlagNum == 0){
        result = true;
    } else {
        result = false;
    }

    return result;
}



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



void customerInquiry(vector <Customers> &customers, vector <Orders> &orders, vector <Inquiries> &inquiries, int* sId){
    struct Customers c;
    struct Inquiries iq;
    string inquiryDetail;

    int option1, option2;
    // int s = *sId;
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

    if (*sId == 0){
        cout << " ------------------------------------------------\n";
        cout << " Do you have Yoobee Taxi account?: \n";
        cout << "  1. Login       (if you have our account)\n";
        cout << "  2. Sign up     (if you don't have our account and  want to create(free))\n";
        cout << "  3. Guest       (If you don't want to create our account)\n";
        cout << " ------------------------------------------------\n";
        cout << "  Enter option: ";
        cin >> option2;

        switch (option2){
            case 1:
            *sId = customerLogin(customers);
            break;

            case 2:
            customerSignup(customers);
            *sId = customers.size() -1;
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
        }
    }


    int s = *sId;


    if (s != 0){
        cout << " ------------------------------------------------\n";
        cout << " Please check and confirm your inquiry \n\n";
        cout << "  Your Name:\t\t" << customers[s].name <<"\n";
        cout << "  Your Phone number:\t" << customers[s].phone << "\n";
    } else {
        cout << "  Your Name:\t\t" << iq.name <<"\n";
        cout << "  Your Phone number:\t" << iq.phone << "\n";
    } 


    switch (option1) {
        case 1:
        iq.topic = "Service";
        cout << "  Topic:\t\t" << iq.topic << "\n";
        break;

        case 2:
        iq.topic = "Lost Item";
        cout << "  Topic:\t\t" << iq.topic << "\n";
        break;

        case 3:
        iq.topic = "Others";
        cout << "  Topic:\t\t" << iq.topic << "\n";
        break;
    }

    cout << "  Detail:\t\t" << iq.detail << "\n";

    if (option2 == 3){
        iq.name = iq.name;
    } else {
        iq.name = customers[s].name;
    }

    iq.userType = "Customer";
    iq.phone = customers[s].phone;
    iq.email = customers[s].email;

    
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
    customerMenu(customers, orders, inquiries, sId);

    cout << "\n\n";

}

void driverInquiry(vector <Drivers> &drivers, vector <Orders> &orders, vector <Inquiries> &inquiries, int* sId){
    struct Drivers d;
    struct Inquiries iq;
    string inquiryDetail;
    int option;

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
    cin >> option;
    cout << "\n";

    cout << " ------------------------------------------------\n";
    cout << " Please tell me the details of your inquiry: \n\t";
    getline (cin, inquiryDetail);
    getline (cin, inquiryDetail);
    iq.detail = inquiryDetail;

    int s = *sId;

    cout << " ------------------------------------------------\n";
    cout << " Please check and confirm your inquiry \n\n";
    cout << "  Your Name:\t\t" << drivers[s].name <<"\n";
    cout << "  Your Phone number:\t" << drivers[s].phone << "\n";

    switch (option) {
        case 1:
        iq.topic = "Service";
        cout << "  Topic:\t\t" << iq.topic << "\n";
        break;

        case 2:
        iq.topic = "Lost Item";
        cout << "  Topic:\t\t\t" << iq.topic << "\n";
        break;

        case 3:
        iq.topic = "Others";
        cout << "  Topic:\t\t" << iq.topic << "\n";
        break;
    }
    cout << "  Detail:\t\t" << iq.detail << "\n";



    iq.name = drivers[s].name;
    iq.userType = "Driver";
    iq.phone = drivers[s].phone;
    iq.email = drivers[s].email;
    
    inquiries.push_back(iq);


    //confirm order
    char confirm;
    ofstream inquiryList("InquiryList.csv", ios::app);

    cout << "------------------------------------------------\n";
    cout << "Confirm order (y/n): ";
    cin >> confirm;
    
    if (confirm == 'y'){
        cout << "------------------------------------------------\n";
        cout << "\n  Thank you!\n";
        inquiryList << inquiries[i].year << "," << inquiries[i].month << "," << inquiries[i].day << "," << inquiries[i].name << "," << inquiries[i].userType << "," << inquiries[i].phone << "," << inquiries[i].email << "," << inquiries[i].topic << "," << inquiries[i].detail << ",\n" ;

    } else {
        cout << "\n  Your inquiry was canceled.\n";
    }

    //go back to the admin menu
    cout << "\nPress any key to go back to the Customer Menu\n";
    system("read");
    driverMenu(drivers, orders, inquiries, sId);
    cout << "\n\n";

}


void getOrder(vector <Drivers> &drivers, vector <Orders> &orders, vector <Inquiries> &inquiries, int* sId){
    int option;

    cout << "************************************************\n";
    cout << "Pickup Requests\n";
    cout << "************************************************\n";
    cout << "Date\t\t Customer\tDriver\t\tCar Type\t\tPickup Location\t\tDestination\t\tFare\n";
    for (int i = 1; i < orders.size(); i++){
        cout << orders[i].year << "/" << orders[i].month << "/"<< orders[i].day << "  \t" << orders[i].customerName << "   \t" << orders[i].driverName << "   \t" << orders[i].carType << "   \t" << orders[i].pickupLocation << "   \t" << orders[i].destination << "\t" << orders[i].fare <<"   \n";
    }

    char answer;
    int orderId;
    int s = *sId;

    ofstream orderList("OrderList.csv", ios::out);

    //receive order
    cout << "------------------------------------------------\n";
    cout << "Are you going to receive order? (y/n): ";
    cin >> answer;

    if (answer == 'y'){
        cout << "------------------------------------------------\n";
        cout << "Which order do you want to receive? (choose number): ";
        cin >> orderId;

        cout << "------------------------------------------------\n";
        cout << "You are assigned!\n";

        cout << "------------------------------------------------\n";
        orderList << "Year,Month,Day,Days,Weeks,Customer,Driver,Car Type,Pickup Location,Destination,Fare\n";
        for (int i = 1; i <orders.size(); i++){
            if (i == orderId){
                orders[orderId].year = orders[orderId].year;
                orders[orderId].month = orders[orderId].month;
                orders[orderId].day = orders[orderId].day;
                orders[orderId].days = orders[orderId].days;
                orders[orderId].week = orders[orderId].week;
                orders[orderId].customerName = orders[orderId].customerName;
                orders[orderId].driverName = drivers[s].name;
                orders[orderId].carType = orders[orderId].carType;
                orders[orderId].pickupLocation = orders[orderId].pickupLocation;
                orders[orderId].destination = orders[orderId].destination;
                orders[orderId].fare = orders[orderId].fare;

                orderList << orders[orderId].year << "," << orders[orderId].month << "," << orders[orderId].day << "," << orders[orderId].days << "," << orders[orderId].week << "," << orders[orderId].customerName << "," << orders[orderId].driverName << "," << orders[orderId].carType << "," << orders[orderId].pickupLocation << "," << orders[orderId].destination << "," << orders[orderId].fare << ",\n" ;
            } else {
                orderList << orders[i].year << "," << orders[i].month << "," << orders[i].day << "," << orders[i].days << "," << orders[i].week << "," << orders[i].customerName << "," << orders[i].driverName << "," << orders[i].carType << "," << orders[i].pickupLocation << "," << orders[i].destination << "," << orders[i].fare << ",\n" ;
            }
        }

        

        //go back to the admin menu
        cout << "\nPress any key to go back to the Customer Menu\n";
        system("read");
        driverMenu(drivers, orders, inquiries, sId);

    } else {
        //go back to the admin menu
        cout << "\nPress any key to go back to the Customer Menu\n";
        system("read");
        driverMenu(drivers, orders, inquiries, sId);
    }
}