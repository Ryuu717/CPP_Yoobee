#include <iostream>
#include <vector>
#include <fstream>      //for ofstream, ifstream
#include <sstream>      //for istringstream
#include <regex>        //include regular expressions library
#include <ctime>

using namespace std;




/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Declare function prototypes
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//driver function
void driverMenu(vector <Drivers> &drivers, vector <Orders> &orders, vector <Inquiries> &inquiries, int* sId);
void driverSignup(vector <Drivers> &drivers, int* sId);
int driverLogin(vector <Drivers> &drivers, vector <Orders> &orders, vector <Inquiries> &inquiries);
void driverPage(vector <Drivers> &drivers, vector <Orders> &orders, vector <Inquiries> &inquiries, int* sId);
void driverInquiry(vector <Drivers> &drivers, vector <Orders> &orders, vector <Inquiries> &inquiries, int* sId);
void getOrder(vector <Drivers> &drivers, vector <Orders> &orders, vector <Inquiries> &inquiries, int* sId);



/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Functions (Menu)
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void driverMenu(vector <Drivers> &drivers, vector <Orders> &orders, vector <Inquiries> &inquiries, int* sId){
    int option;

    string driverMenuOptS;
    int driverMenuOptI;

    cout << "************************************************\n";
    cout << "Welcome Yoobee Drivers!\n";
    cout << "Please select a number from the menu\n";
    cout << "************************************************\n";
    cout << "Menu\n";
    cout << "  1.Get Order\n";
    cout << "  2.My Page\n";
    cout << "  3.Inquiry\n";
    cout << "  4.Exit\n";

    //integer & option validation
    while(true){
        cout << " ------------------------------------------------\n";
        cout << "  Enter option: ";
        getline(cin, driverMenuOptS);                                                                 
        if(isIntegerValid(driverMenuOptS) == false){
            cout << " ------------------------------------------------\n";
            cout << "\n !Select a number from the menu. (Press any key) \n\n";
            cin.clear();
            cin.ignore(10000, '\n');
        } else if (driverMenuOptS == "1" || driverMenuOptS == "2" || driverMenuOptS == "3" || driverMenuOptS == "4"){  
            cout << "\n\n";
            break;
        } else {
            cout << " ------------------------------------------------\n";
            cout << "\n !Select a number from the menu. (Press any key) \n\n";
            cin.clear();
            cin.ignore(10000, '\n');
        }
    }
    driverMenuOptI = stoi(driverMenuOptS);


    switch (driverMenuOptI) {
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
//Functions (Sign up, Login)
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void driverSignup(vector <Drivers> &drivers, int* sId){
    struct Drivers d;
    int option;
    int i = drivers.size();
    string driverNameS, areaOptS, streetS, cityS, stateS, countryS;

    d.driverId = i;

    cout << "\n************************************************\n";
    cout << "Sign up\n";
    cout << "************************************************\n";
    cout << "Enter your information \n";

    while(true){
        cout << " ------------------------------------------------\n";
        cout << " Name: ";
        getline(cin, driverNameS);                                            
        if(isNameValid(driverNameS) == true){
            d.name = driverNameS;
            break;
        } else {
            cout << " ------------------------------------------------\n";
            cout << "\n !Enter your name. (Press any key) \n\n";
            cin.clear();
            cin.ignore(10000, '\n');
        }
    }

    //phone validation
    while (true){
        cout << " Phone number (e.g. 000-0000-0000): ";
        cin  >> d.phone;

        if (isPhoneValid(d.phone) == true){
            break;
        } else {
            cout << "\n  !Please enter a valid phone number\n\n";
        }
    }

    //email validation
    while (true){
        cout << " Email address (e.g. test@email.com): ";
        cin  >> d.email;

        if (isEmailValid(d.email) == true){
            cin.clear();
            cin.ignore(10000, '\n');
            break;
        } else {
            cout << "\n  !Please enter a valid email address\n\n";
        }
    }


    cout << " ------------------------------------------------\n";
    cout << " Home address: \n";

    //street validation
    while(true){
        // cout << " ------------------------------------------------\n";
        cout << "    Street: ";
        getline(cin, streetS);                                            
        if(isAddressValid(streetS) == true){
            d.street = streetS;
            break;
        } else {
            cout << " ------------------------------------------------\n";
            cout << "\n !Enter valid street name. (Press any key) \n\n";
            cin.clear();
            cin.ignore(10000, '\n');
        }
    }

    //city validation
    while(true){
        // cout << " ------------------------------------------------\n";
        cout << "    City: ";
        getline(cin, cityS);                                            
        if(isAddressValid(cityS) == true){
            d.city = cityS;
            break;
        } else {
            cout << " ------------------------------------------------\n";
            cout << "\n !Enter valid street name. (Press any key) \n\n";
            cin.clear();
            cin.ignore(10000, '\n');
        }
    }

    //state validation
    while(true){
        // cout << " ------------------------------------------------\n";
        cout << "    State: ";
        getline(cin, stateS);                                            
        if(isAddressValid(stateS) == true){
            d.state = stateS;
            break;
        } else {
            cout << " ------------------------------------------------\n";
            cout << "\n !Enter valid street name. (Press any key) \n\n";
            cin.clear();
            cin.ignore(10000, '\n');
        }
    }

    //country validation
    while(true){
        // cout << " ------------------------------------------------\n";
        cout << "    Country: ";
        getline(cin, countryS);                                            
        if(isAddressValid(countryS) == true){
            d.country = countryS;
            break;
        } else {
            // cout << " ------------------------------------------------\n";
            cout << "\n !Enter valid street name. (Press any key) \n\n";
            cin.clear();
            cin.ignore(10000, '\n');
        }
    }
    
    //postal code validation
    while (true){
        cout << "    Postal Code(e.g. 000-0000): ";
        cin  >> d.postalCode;

        if (isPostalCodeValid(d.postalCode) == true){
            break;
        } else {
            cout << "\n  !Please enter a valid postal code\n\n";
            cin.clear();
            cin.ignore(10000, '\n');
        }
    }

    string passwordAgain;

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
            cout << "---------------------------------------------------------\n";
            cout << "   Please enter again: ";
            cin >> passwordAgain;
            
            if (d.password == passwordAgain){
                cin.clear();
                cin.ignore(10000, '\n');
                cout << "\n\n";
                break;
            } else {
                cout << "---------------------------------------------------------\n";
                cout << "\n   !Your password is wrong\n";
                cout << "   Please try entering the password from the beginning\n\n";
            }
            cin.clear();
            cin.ignore(10000, '\n');
        } else {
            cout << "\nPlease enter a valid password.\n";
            cin.clear();
            cin.ignore(10000, '\n');
        }
    }

    //license validation
    while (true){
        cout << "License Number (e.g. 000000): ";
        cin >> d.license;

        if (isLicenseValid(d.license) == true){
            cin.clear();
            cin.ignore(10000, '\n');
            break;
        } else {
            cout << "\n  !Please enter a valid license number\n\n";
            cin.clear();
            cin.ignore(10000, '\n');
        }
    }


    //integer & option validation
    while(true){
        cout << "Area Number (1 = Downtown, 2 = Suburb): ";
        getline(cin, areaOptS);                                            
        if(isIntegerValid(areaOptS) == false){
            cout << " ------------------------------------------------\n";
            cout << "\n !Select a number from the menu. (Press any key) \n\n";
            cin.clear();
            cin.ignore(10000, '\n');
        } else if (areaOptS == "1" || areaOptS == "2"){
            d.area = areaOptS;
            cout << "\n\n";
            break;
        } else {
            cout << " ------------------------------------------------\n";
            cout << "\n !Select a number from the menu. (Press any key) \n\n";
            cin.clear();
            cin.ignore(10000, '\n');
        }
    }
    drivers.push_back(d);

    cout << "\n\n";

    //result
    cout << " ------------------------------------------------\n";
    cout << " Please check and confirm your information \n\n";
    cout << "  Name:\t\t\t" << d.name <<"\n";
    cout << "  Phone:\t\t" << d.phone << "\n";
    cout << "  Email:\t\t" << d.email << "\n";
    cout << "  Street:\t\t" << d.street << "\n";
    cout << "  City:\t\t\t" << d.city << "\n";
    cout << "  State:\t\t" << d.state << "\n";
    cout << "  Country:\t\t" << d.country << "\n";
    cout << "  Postal Code:\t\t" << d.postalCode << "\n";
    cout << "  License Number:\t" << d.license << "\n";
    cout << "  Area:\t\t\t" << d.area << "\n";

    //confirm order
    string confirm;
    ofstream driverList("DriverList.csv", ios::app);

    while(true){
        cout << " ------------------------------------------------\n";
        cout << "Confirm sign up (y/n): ";
        cin >> confirm;

        if (isYesNoValid(confirm) == true){
            if (confirm == "y"){
                cout << "------------------------------------------------\n";
                cout << "\n  Thank you!\n  Registred successfully!\n\n\n";
                driverList << drivers[i].driverId << "," << drivers[i].name << "," << drivers[i].phone << "," << drivers[i].email << "," << drivers[i].street << "," << drivers[i].city << "," << drivers[i].state << "," << drivers[i].country << "," << drivers[i].postalCode << "," << drivers[i].password << "," << drivers[i].license << "," << drivers[i].area << ",\n" ;
                cin.clear();
                cin.ignore(10000, '\n');
            } else {
                cout << "\n  Your register was canceled.\n\n\n";
                cin.clear();
                cin.ignore(10000, '\n');
            }
            break;
        } else {
            cout << "\n  !Please answer with y or n\n\n";
            cin.clear();
            cin.ignore(10000, '\n');
        }
    }
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
            break;
            
        } else if (attemptCounts == 0){
            cout << "----------------------------------------------------------------\n";
            cout << "The number of login attempts has exceeded the limit.\n";
            cout << "Please wait a while and try again.\n";

            driverNo = 0;

        } else {
            if (emailFlag == 1 && passwordFlag == 0){
                cout << "\n  !Your password is wrong\n";
                cout << "    Please try again.\n\n";
            } else if (emailFlag == 0 & passwordFlag == 0){
                cout << "\n  !Your email address is not registered.\n";
                cout << "    Please try again.\n\n";
            } 
        }
    }
    //reset user input
    cin.clear();
    cin.ignore(10000, '\n');
    cout << "\n";

    return driverNo;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Functions (Driver Page, Driver Inquiry)
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void driverPage(vector <Drivers> &drivers, vector <Orders> &orders, vector <Inquiries> &inquiries, int* sId){
    int s = *sId;
    int option;
    int driverPoints = 0; 
    string myPageOptS;
    int myPageOptI;

    cout << "************************************************\n";
    cout << "My Page \n";
    cout << "************************************************\n";
    cout << "Menu \n";
    cout << "  1. Account Info\n";
    cout << "  2. Trip History \n";
    cout << "  3. Acquired Points \n";
    cout << "  4. Go Back \n";

    //integer & option validation
    while(true){
        cout << " ------------------------------------------------\n";
        cout << "  Enter option: ";
        getline(cin, myPageOptS);                                                //integer validation
        if(isIntegerValid(myPageOptS) == false){
            cout << " ------------------------------------------------\n";
            cout << "\n !Select a number from the menu. (Press any key) \n\n";
            cin.clear();
            cin.ignore(10000, '\n');
        } else if (myPageOptS == "1" || myPageOptS == "2" || myPageOptS == "3" || myPageOptS == "4"){   //option validation
            cout << "\n\n";
            // cin.clear();
            // cin.ignore(10000, '\n');
            break;
        } else {
            cout << " ------------------------------------------------\n";
            cout << "\n !Select a number from the menu. (Press any key to go back) \n\n";
            cin.clear();
            cin.ignore(10000, '\n');
        }
    }
    myPageOptI = stoi(myPageOptS);
    cout << "\n";


    switch (myPageOptI){
        case 1:
        cout << "************************************************\n";
        cout << "Account Information\n";
        cout << "************************************************\n";
        cout << "  Driver ID:\t\t" << drivers[s].driverId <<"\n";
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

        //go back to the My Page
        cout << "\nPress any key to go back to the My Page\n";
        system("read");
        driverPage(drivers, orders, inquiries, sId);
        break;

        case 2:
        cout << "************************************************\n";
        cout << "Trip History\n";
        cout << "************************************************\n";
        cout << "Order ID  Date(Pickup)\t\tCustomer\tDriver\t\tCar Type\t\tArea(from)  Area(to)\tPickup Location\tDestination\tFare(NZD)\n";
        for (int i = 1; i < orders.size(); i++){
            if (orders[i].driverName == drivers[s].name){
                const char *str1 = orders[i].customerName.c_str();      //convert string to char*
                const char *str2 = orders[i].driverName.c_str();
                const char *str3 = orders[i].carType.c_str();
                const char *str4 = orders[i].pickupLocation.c_str();
                const char *str5 = orders[i].destination.c_str();

                printf("%-8d  %d/%d/%d %02d:%02d  \t%-15s\t%-15s\t%-24s%-12d%-12d%-15s\t%-15s %-2.2f\n", orders[i].orderId,orders[i].year,orders[i].month,orders[i].day,orders[i].hour,orders[i].min,str1,str2,str3,orders[i].pickupArea,orders[i].destinationArea,str4,str5,orders[i].fare);
            }
        }

        //go back to the My Page
        cout << "\nPress any key to go back to the My Page\n";
        system("read");
        driverPage(drivers,orders, inquiries, sId);
        break;

        case 3:
        cout << "************************************************\n";
        cout << "Acquired Points\n";
        cout << "************************************************\n";
        
        for (int i = 1; i < orders.size(); i++){
            if (orders[i].driverName == drivers[s].name){
                driverPoints++;
            }
        }
        if (driverPoints > 0){
            cout << "Congratulations!\n";
            cout << "Your point is " << driverPoints * 100 << " (NZD)" << "\n";
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

void driverInquiry(vector <Drivers> &drivers, vector <Orders> &orders, vector <Inquiries> &inquiries, int* sId){
    struct Drivers d;
    struct Inquiries iq;
    string inquiryDetail;
    string inquiryOptS, accountOptS;
    int inquiryOptI, accountOptI;
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
    
    //integer & option validation
    while(true){
        cout << " ------------------------------------------------\n";
        cout << "  Enter option: ";
        getline(cin, inquiryOptS);                                                //integer validation
        if(isIntegerValid(inquiryOptS) == false){
            cout << " ------------------------------------------------\n";
            cout << "\n !Select a number from the menu. (Press any key) \n\n";
            cin.clear();
            cin.ignore(10000, '\n');
        } else if (inquiryOptS == "1" || inquiryOptS == "2" || inquiryOptS == "3"){   //option validation
            cout << "\n\n";
            break;
        } else {
            cout << " ------------------------------------------------\n";
            cout << "\n !Select a number from the menu. (Press any key to go back) \n\n";
            cin.clear();
            cin.ignore(10000, '\n');
        }
    }
    inquiryOptI = stoi(inquiryOptS);

    cout << " ------------------------------------------------\n";
    cout << " Please tell me the details of your inquiry: \n  ";
    while(true){
        cout << " ------------------------------------------------\n";
        cout << "   Enter inquiry: ";
        getline (cin, inquiryDetail);

        //null check
        if(inquiryDetail == ""){
            cout << "\n !Please enter messages (Press any key) \n\n";
            cin.clear();
            cin.ignore(10000, '\n');
        } else {
            iq.detail = inquiryDetail;
            break;
        }
    }


    int s = *sId;

    //result
    cout << " ------------------------------------------------\n";
    cout << " Please check and confirm your inquiry \n\n";
    cout << "  Driver ID:\t\t" << drivers[s].driverId <<"\n";
    cout << "  Name:\t\t\t" << drivers[s].name <<"\n";
    cout << "  Email Address:\t" << drivers[s].email <<"\n";
    cout << "  Phone Number:\t\t" << drivers[s].phone << "\n";

    switch (inquiryOptI) {
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
        cin.clear();
        cin.ignore(10000, '\n');
    }
    cin.clear();
    cin.ignore(10000, '\n');

    //go back to the driver menu
    cout << "\nPress any key to go back to the Driver Menu\n";
    system("read");
    driverMenu(drivers, orders, inquiries, sId);
    cout << "\n\n";

}


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Functions (getOrder)
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void getOrder(vector <Drivers> &drivers, vector <Orders> &orders, vector <Inquiries> &inquiries, int* sId){
    int option;

    cout << "************************************************\n";
    cout << "Pickup Requests\n";
    cout << "************************************************\n";
    cout << "Order ID  Date(Pickup)\t\tCustomer Name\tCustomer Phone\tDriver Name\tDriver Phone\tCar Type\t\tArea(from)  Area(to)\tPickup Location\tDestination\tFare(NZD)\n";
    for (int i = 1; i < orders.size(); i++){
        const char *str1 = orders[i].customerName.c_str();      //convert string to char*
        const char *str2 = orders[i].customerPhone.c_str();
        const char *str3 = orders[i].driverName.c_str();
        const char *str4 = orders[i].driverPhone.c_str();
        const char *str5 = orders[i].carType.c_str();
        const char *str6 = orders[i].pickupLocation.c_str();
        const char *str7 = orders[i].destination.c_str();

        printf("%-8d  %d/%d/%d %02d:%02d  \t%-15s\t%-15s\t%-15s\t%-15s\t%-24s%-12d%-12d%-15s\t%-15s %-2.2f\n", orders[i].orderId,orders[i].year,orders[i].month,orders[i].day,orders[i].hour,orders[i].min,str1,str2,str3,str4,str5,orders[i].pickupArea,orders[i].destinationArea,str6,str7,orders[i].fare);
    }

    string receiveOptS, orderOptS;
    int orderOptI;
    int oid;            //to store order ID which driver selected
    int s = *sId;


    //Yes or No Validation
    while(true){
        cout << " ------------------------------------------------\n";
        cout << "Are you going to receive order? (y/n): ";
        cin >> receiveOptS;

        if (isYesNoValid(receiveOptS) == true){
            if (receiveOptS == "y"){
                ofstream orderList("OrderList.csv", ios::out);

                cin.clear();
                cin.ignore(10000, '\n');
                
                cout << "------------------------------------------------\n";
                cout << "Which order do you receive? (choose Order ID)\n";

                //integer & option validation
                while(true){
                    cout << " ------------------------------------------------\n";
                    cout << "  Enter option: ";
                    getline(cin, orderOptS);

                    if(isMultiDigitValid(orderOptS) == false){
                        cout << " ------------------------------------------------\n";
                        cout << "\n !Select a number from the menu. (Press any key) \n\n";
                        cin.clear();
                        cin.ignore(10000, '\n');
                    } else {
                        orderOptI = stoi(orderOptS);

                        if (orderOptI >0 && orderOptI <= orders.size()-1){
                            oid = orderOptI;
                            cout << "\n\n";
                            break;
                        } else {
                            cout << " ------------------------------------------------\n";
                            cout << "\n !Select a number from the menu. (Press any key) \n\n";
                            cin.clear();
                            cin.ignore(10000, '\n');
                        }
                    }
                }

                orderList << "Order ID,Year,Month,Day,Hour,Minute,Days,Weeks,Customer,Driver,Car Type,Pickup Area,Destination Area,Pickup Location,Destination,Fare(NZD)\n";

                for (int i = 1; i <orders.size(); i++){

                    //store all order data on the list
                    //if order ID is driver's selected one, driver information is current driver's data(assign driver)
                    if (i == oid){
                        orders[oid].orderId = orders[oid].orderId;
                        orders[oid].year = orders[oid].year;
                        orders[oid].month = orders[oid].month;
                        orders[oid].day = orders[oid].day;
                        orders[oid].days = orders[oid].days;
                        orders[oid].week = orders[oid].week;
                        orders[oid].customerName = orders[oid].customerName;
                        orders[oid].customerPhone = orders[oid].customerPhone;
                        orders[oid].driverName = drivers[s].name;
                        orders[oid].driverPhone = drivers[s].phone;
                        orders[oid].carType = orders[oid].carType;
                        orders[oid].pickupLocation = orders[oid].pickupLocation;
                        orders[oid].destination = orders[oid].destination;
                        orders[oid].fare = orders[oid].fare;

                        orderList << orders[oid].orderId << "," << orders[oid].year << "," << orders[oid].month << "," << orders[oid].day << "," << orders[oid].hour << "," << orders[oid].min << "," << orders[oid].days << "," << orders[oid].week << "," << orders[oid].customerName << "," << orders[oid].customerPhone << "," << orders[oid].driverName << "," << orders[oid].driverPhone << "," << orders[oid].carType << "," << orders[oid].pickupArea << "," << orders[oid].destinationArea << "," << orders[oid].pickupLocation << "," << orders[oid].destination << "," << orders[oid].fare << ",\n" ;
                    } else {
                        orderList << orders[i].orderId << "," << orders[i].year << "," << orders[i].month << "," << orders[i].day << "," << orders[i].hour << "," << orders[i].min << "," << orders[i].days << "," << orders[i].week << "," << orders[i].customerName << "," << orders[i].customerPhone << "," << orders[i].driverName << "," << orders[i].driverPhone << "," << orders[i].carType << "," << orders[i].pickupArea << "," << orders[i].destinationArea << "," << orders[i].pickupLocation << "," << orders[i].destination << "," << orders[i].fare << ",\n" ;
                    }
                }

                cout << "------------------------------------------------\n";
                cout << "You are assigned!\n";

                cout << "------------------------------------------------\n";
                cout << "Order ID  Date(Pickup)\t\tCustomer Name\tCustomer Phone\tDriver Name\tDriver Phone\tCar Type\t\tArea(from)  Area(to)\tPickup Location\tDestination\tFare(NZD)\n";
                for (int i = 1; i < orders.size(); i++){
                    const char *str1 = orders[i].customerName.c_str();      //convert string to char*
                    const char *str2 = orders[i].customerPhone.c_str();
                    const char *str3 = orders[i].driverName.c_str();
                    const char *str4 = orders[i].driverPhone.c_str();
                    const char *str5 = orders[i].carType.c_str();
                    const char *str6 = orders[i].pickupLocation.c_str();
                    const char *str7 = orders[i].destination.c_str();

                    //define the space
                    printf("%-8d  %d/%d/%d %02d:%02d  \t%-15s\t%-15s\t%-15s\t%-15s\t%-24s%-12d%-12d%-15s\t%-15s %-2.2f\n", orders[i].orderId,orders[i].year,orders[i].month,orders[i].day,orders[i].hour,orders[i].min,str1,str2,str3,str4,str5,orders[i].pickupArea,orders[i].destinationArea,str6,str7,orders[i].fare);
                }

                //go back to the driver menu
                cout << "\nPress any key to go back to the Driver Menu\n";
                system("read");
                driverMenu(drivers, orders, inquiries, sId);
                break;

            } else {
                cin.clear();
                cin.ignore(10000, '\n');

                //go back to the driver menu
                cout << "\nPress any key to go back to the Driver Menu\n";
                system("read");
                driverMenu(drivers, orders, inquiries, sId);
                break;
            }
        } else {
            cout << "\n  !Please answer with y or n\n\n";
            cin.clear();
            cin.ignore(10000, '\n');
        }
    }
}