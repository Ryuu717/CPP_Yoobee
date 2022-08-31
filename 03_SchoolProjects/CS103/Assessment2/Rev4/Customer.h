#include <iostream>
#include <vector>
#include <fstream>      //for ofstream, ifstream
#include <sstream>      //for istringstream
#include <regex>        //include regular expressions library
#include <ctime>        //to get current time

using namespace std;


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Declare function prototypes
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void customerMenu(vector <Customers> &customers, vector <Orders> &orders, vector <Inquiries> &inquiries, int* sId);
void ride(vector <Customers> &customers, vector <Orders> &orders, vector <Inquiries> &inquiries, int* sId);
void customerSignup(vector <Customers> &customers, int* sId);
int customerLogin(vector <Customers> &customers);
void customerPage(vector <Customers> &customers, vector <Orders> &orders, vector <Inquiries> &inquiries, int* sId);
void customerInquiry(vector <Customers> &customers, vector <Orders> &orders, vector <Inquiries> &inquiries, int* sId);
int calculateDays(int month, int day);
int calculateWeeks(int days);



/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Functions (Menu)
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void customerMenu(vector <Customers> &customers, vector <Orders> &orders, vector <Inquiries> &inquiries, int* sId){
    string cusMenuOptS, accountOptS;        //to store strings from getline()
    int cusMenuOptI, accountOptI;           //to convert string to integer

    cout << "************************************************\n";
    cout << "Welcome Yoobee Customers!\n";
    cout << "Please select a number from the menu\n";
    cout << "************************************************\n";
    cout << "Menu\n";
    cout << "  1.Ride*\n";
    cout << "  2.My Page\n";
    cout << "  3.Inquiry\n";
    cout << "  4.Exit\n";
    cout << "                   *Direct Call: 012-3456-7890\n";                                 //give direct call option

    //integer & option validation
    while(true){
        cout << " ------------------------------------------------\n";
        cout << "  Enter option: ";
        getline(cin, cusMenuOptS);                                                                    //integer validation
        if(isIntegerValid(cusMenuOptS) == false){
            cout << " ------------------------------------------------\n";
            cout << "\n !Select a number from the menu. (Press any key) \n\n";
            cin.clear();
            cin.ignore(10000, '\n');
        } else if (cusMenuOptS == "1" || cusMenuOptS == "2" || cusMenuOptS == "3" || cusMenuOptS == "4"){   //option validation
            cout << "\n\n";
            break;
        } else {
            cout << " ------------------------------------------------\n";
            cout << "\n !Select a number from the menu. (Press any key) \n\n";
            cin.clear();
            cin.ignore(10000, '\n');
        }
    }
    cusMenuOptI = stoi(cusMenuOptS);


    switch (cusMenuOptI) {
        case 1:
        ride(customers, orders, inquiries, sId);
        break;


        case 2:
        //if user did't login
        if (*sId == 0){
            cout << " ------------------------------------------------\n";
            cout << " Do you have Yoobee Taxi Customer Account?: \n";
            cout << "  1. Login       (if you have our account)\n";
            cout << "  2. Sign up     (if you don't have our account and  want to create(free))\n";
            cout << "  3. Go Back\n";

            //integer & option validation
            while(true){
                cout << " ------------------------------------------------\n";
                cout << "  Enter option: ";
                getline(cin, accountOptS); 
                if(isIntegerValid(accountOptS) == false){
                    cout << " ------------------------------------------------\n";
                    cout << "\n !Select a number from the menu. \n\n";
                    cin.clear();
                    cin.ignore(10000, '\n');
                } else if (accountOptS == "1" || accountOptS == "2" || accountOptS == "3"){ 
                    cout << "\n\n";
                    break;
                } else {
                    cout << " ------------------------------------------------\n";
                    cout << "\n !Select a number from the menu. \n\n";
                    cin.clear();
                    cin.ignore(10000, '\n');
                }
            }
            int accountOptI = stoi(accountOptS);

            switch (accountOptI){
                case 1:
                *sId = customerLogin(customers);            //get customer ID as a session ID
                break;

                case 2:
                customerSignup(customers, sId);
                break;

                case 3:
                customerMenu(customers, orders, inquiries, sId);
                break;
            }
            if (*sId != 0){
                customerPage(customers, orders, inquiries, sId);    //only logged in customers
            } else {
                customerMenu(customers, orders, inquiries, sId);
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

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Functions (Sign up, Login)
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void customerSignup(vector <Customers> &customers, int* sId){
    struct Customers c;
    int i = customers.size();               //get customer list size
    string payOptS, customerNameS, streetS, cityS, stateS, countryS;
    int payOptI;

    c.customerId = i;       //assign customer ID

    cout << "\n************************************************\n";
    cout << "Sign up\n";
    cout << "************************************************\n";
    cout << "Enter your information \n";

    //name validation
    while(true){
        cout << " ------------------------------------------------\n";
        cout << " Name: ";
        getline(cin, customerNameS);                                            
        if(isNameValid(customerNameS) == true){
            c.name = customerNameS;
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
        cin  >> c.phone;
        if (isPhoneValid(c.phone) == true){
            break;
        } else {
            cout << "\n  !Please enter a valid phone number\n\n";
            cin.clear();
            cin.ignore(10000, '\n');
        }
    }

    //email validation
    while (true){
        cout << " Email address (e.g. test@email.com): ";
        cin  >> c.email;

        if (isEmailValid(c.email) == true){
            cin.clear();
            cin.ignore(10000, '\n');
            break;
        } else {
            cout << "\n  !Please enter a valid email address\n\n";
            cin.clear();
            cin.ignore(10000, '\n');
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
            c.street = streetS;
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
            c.city = cityS;
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
            c.state = stateS;
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
            c.country = countryS;
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
        cin  >> c.postalCode;

        if (isPostalCodeValid(c.postalCode) == true){
            break;
        } else {
            cout << "\n  !Please enter a valid postal code\n\n";
            cin.clear();
            cin.ignore(10000, '\n');
        }
    }



    string passwordAgain;

    cout << "\nEnter your password: \n";
    cout << "  -At least 8 characters\n";
    cout << "  -At least one upper case character\n";
    cout << "  -At least one lower case character\n";
    cout << "  -At least one special character (@, !, ?, #)\n";
    cout << "  -At least one number\n";
    
    //password validation
    while (true){
        cout << "---------------------------------------------------------\n";
        cout << "   Your password is: ";
        cin  >> c.password;
        cout << "\n";

        if (isPasswordValid(c.password) == true){
            //check password again
            cout << "---------------------------------------------------------\n";
            cout << "   Please enter again for confirmation: ";
            cin >> passwordAgain;

            if (c.password == passwordAgain){
                cin.clear();
                cin.ignore(10000, '\n');
                cout << "\n\n";
                break;
            } else {
                cout << "---------------------------------------------------------\n";
                cout << "\n   !Your password is wrong\n";
                cout << "     Please try entering the password from the beginning\n\n";
            }
            cin.clear();
            cin.ignore(10000, '\n');
        } else {
            cout << "\nPlease enter a valid password.\n";
            cin.clear();
            cin.ignore(10000, '\n');
        }
    }

    cout << " Payment method: \n";
    cout << "  1. Cash \n";
    cout << "  2. Credit Card \n";
    cout << "  3. Online Payment \n";

    //integer & option validation
    while(true){
        cout << " ------------------------------------------------\n";
        cout << "  Enter option: ";
        getline(cin, payOptS);                                                                   
        if(isIntegerValid(payOptS) == false){
            cout << " ------------------------------------------------\n";
            cout << "\n !Select a number from the menu. \n\n";
            cin.clear();
            cin.ignore(10000, '\n');
        } else if (payOptS == "1" || payOptS == "2" || payOptS == "3"){ 
            payOptI = stoi(payOptS);

            switch(payOptI){
                case 1:
                c.payment = "Cash";
                c.creditCardNumber = "-";
                break;

                case 2:
                c.payment = "Credit Card";

                //credit card number validation
                while (true){
                    cout << "\n";
                    cout << " ------------------------------------------------\n";
                    cout << "   Enter Credit card number (e.g. 0000-0000-0000-0000): ";
                    cin  >> c.creditCardNumber;

                    if (isCreditValid(c.creditCardNumber) == true){
                        break;
                    } else {
                        cout << "\n  !Please enter a valid credit card number\n\n";
                        cin.clear();
                        cin.ignore(10000, '\n');
                    }
                }
                break;

                case 3:
                c.payment = "Online Payment";
                c.creditCardNumber = "-";
                break;
            }
            cout << "\n\n";
            break;
        } else {
            cout << " ------------------------------------------------\n";
            cout << "\n !Select a number from the menu. \n\n";
            cin.clear();
            cin.ignore(10000, '\n');
        }
    }
    payOptI = stoi(payOptS);

    customers.push_back(c);

    cout << "\n\n";

    //result
    cout << " ------------------------------------------------\n";
    cout << " Please check and confirm your information \n\n";
    cout << "  Name:\t\t\t" << c.name <<"\n";
    cout << "  Phone:\t\t" << c.phone << "\n";
    cout << "  Email:\t\t" << c.email << "\n";
    cout << "  Street:\t\t" << c.street << "\n";
    cout << "  City:\t\t\t" << c.city << "\n";
    cout << "  State:\t\t" << c.state << "\n";
    cout << "  Country:\t\t" << c.country << "\n";
    cout << "  Postal Code:\t\t" << c.postalCode << "\n";
    switch(payOptI){
        case 1:
        cout << "  Payment Method:\t" << "Cash" << "\n";
        break;

        case 2:
        cout << "  Payment Method:\t" << "Credit Card (" << c.creditCardNumber << ")" << "\n";
        break;

        case 3:
        cout << "  Payment Method:\t" << "Online Payment" << "\n";
        break;
    }


    //confirm order
    string confirm;
    ofstream customerList("CustomerList.csv", ios::app);        //output file stream

    //yes or no validation
    while(true){
        cout << " ------------------------------------------------\n";
        cout << "Confirm sign up (y/n): ";
        cin >> confirm;

        if (isYesNoValid(confirm) == true){
            if (confirm == "y"){
                cout << "------------------------------------------------\n";
                cout << "\n  Thank you!\n  Registred successfully!\n\n\n";

                //write data to csv file
                customerList << customers[i].customerId << "," << customers[i].name << "," << customers[i].phone << "," << customers[i].email << "," << customers[i].street << "," << customers[i].city << "," << customers[i].state << "," << customers[i].country << "," << customers[i].postalCode << "," << customers[i].password << "," << customers[i].payment << "," << customers[i].creditCardNumber << ",\n" ;
                *sId = customers.size() -1;
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


int customerLogin(vector <Customers> &customers){
    string userEmail, userPassword;
    int attemptCounts = 3;          //limit of attempts
    int customerNo;

    cout << "\n************************************************\n";
    cout << "Customer Login\n";
    cout << "************************************************\n";
    cout << "Enter your information \n";
    
    //email address validation
    while (attemptCounts > 0){
        cout << " Email address: ";
        cin >> userEmail;
        cout << " Password: ";
        cin >> userPassword;

        int emailFlag = 0, passwordFlag = 0;                    //initialize flag

        for (int i = 1; i < customers.size(); i++){      
            //success case  
            if (customers[i].email == userEmail && customers[i].password == userPassword){
                emailFlag = 1;
                passwordFlag = 1;

                customerNo = i;
                break;
            }
            //email is correct, password is wrong
            if (customers[i].email == userEmail && customers[i].password != userPassword){
                emailFlag = 1;
                passwordFlag = 0;
                break;
            }
            //both are wrong
            if (customers[i].email != userEmail){
                emailFlag = 0;
                passwordFlag = 0;
            }
        }
        attemptCounts--;        //lose the attempt count
        
        //judge based on flag count and type
        if (emailFlag == 1 & passwordFlag == 1){
            cout << "----------------------------------------------------------------\n";
            cout << "Logged in successfully\n\n";
            break;
            
        } else if (attemptCounts == 0){
            cout << "----------------------------------------------------------------\n";
            cout << "The number of login attempts has exceeded the limit.\n";
            cout << "Please wait a while and try again.\n";

            customerNo = 0;

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

    return customerNo;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Functions (CustomerPage, Customer Inquiry)
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void customerPage(vector <Customers> &customers, vector <Orders> &orders, vector <Inquiries> &inquiries, int* sId){
    int s = *sId;
    int option;
    string myPageOptS;
    int myPageOptI;

    cout << "************************************************\n";
    cout << "My Page \n";
    cout << "************************************************\n";
    cout << "Menu \n";
    cout << "  1. Account Info\n";
    cout << "  2. Trip History \n";
    cout << "  3. Coupons \n";
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
            break;
        } else {
            cout << " ------------------------------------------------\n";
            cout << "\n !Select a number from the menu. (Press any key) \n\n";
            cin.clear();
            cin.ignore(10000, '\n');
        }
    }
    myPageOptI = stoi(myPageOptS);


    string creditCardNumber = customers[s].creditCardNumber;

    switch (myPageOptI){
        case 1:
        cout << "************************************************\n";
        cout << "Account Information\n";
        cout << "************************************************\n";
        cout << "  Customer ID:\t\t" << customers[s].customerId <<"\n";
        cout << "  Name:\t\t\t" << customers[s].name <<"\n";
        cout << "  Phone number:\t\t" << customers[s].phone << "\n";
        cout << "  Email address:\t" << customers[s].email <<"\n";
        cout << "  Street:\t\t" << customers[s].street << "\n";
        cout << "  City:\t\t\t" << customers[s].city << "\n";
        cout << "  State:\t\t" << customers[s].state << "\n";
        cout << "  Country:\t\t" << customers[s].country << "\n";
        cout << "  Postal Code:\t\t" << customers[s].postalCode << "\n";

        //in the case of credit card, need to show credit number
        //only the last 4 digits are visible
        if (customers[s].payment == "Credit Card"){
            cout << "  Payment Method:\t" << customers[s].payment << " (Last 4 digits: " << creditCardNumber.substr(creditCardNumber.length()-4) << ")" << "\n";
        } else {
            cout << "  Payment Method:\t" << customers[s].payment << "\n\n";
        }
        

        //go back to the My Page
        cout << "\nPress any key to go back to the My Page\n";
        system("read");
        customerPage(customers, orders, inquiries, sId);
        break;

        case 2:
        cout << "************************************************\n";
        cout << "Trip History\n";
        cout << "************************************************\n";
        cout << "Order ID  Date(Pickup)\t\tCustomer Name\tCustomer Phone\tDriver Name\tDriver Phone\tCar Type\t\tArea(from)  Area(to)\tPickup Location\tDestination    Fare(NZD)\n";
        for (int i = 1; i < orders.size(); i++){
            if (orders[i].customerName == customers[s].name){
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
        cout << " - 30% off coupon" << "\n";

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

void customerInquiry(vector <Customers> &customers, vector <Orders> &orders, vector <Inquiries> &inquiries, int* sId){
    struct Customers c;
    struct Inquiries iq;
    string inquiryDetail;
    string inquiryOptS, accountOptS;
    int inquiryOptI, accountOptI;
    int i = inquiries.size();            //get inquiry list size
    time_t now = time(0);               //get current time
    tm *ltm = localtime(&now);
    string guestNameS;

    iq.year = 1900 + ltm->tm_year;      //get current year
    iq.month = 1 + ltm->tm_mon;         //get current month
    iq.day = ltm->tm_mday;              //get current day


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
    inquiryOptI = stoi(inquiryOptS);



    cout << " ------------------------------------------------\n";
    cout << " Please tell me the details of your inquiry: \n  ";
    while(true){
        cout << " ------------------------------------------------\n";
        cout << "   Enter inquiry: ";
        getline (cin, inquiryDetail);

        if(inquiryDetail == ""){
            cout << "\n !Please enter messages (Press any key) \n\n";
            cin.clear();
            cin.ignore(10000, '\n');
        } else {
            iq.detail = inquiryDetail;
            break;
        }
    }


    //check sseion ID
    if (*sId == 0){
        cout << " ------------------------------------------------\n";
        cout << " Do you have Yoobee Taxi account?: \n";
        cout << "  1. Login       (if you have our account)\n";
        cout << "  2. Sign up     (if you don't have our account and  want to create(free))\n";
        cout << "  3. Guest       (If you don't want to create our account)\n";


        while(true){
            cout << " ------------------------------------------------\n";
            cout << "  Enter option: ";
            getline(cin, accountOptS);              
            if(isIntegerValid(accountOptS) == false){
                cout << " ------------------------------------------------\n";
                cout << "\n !Select a number from the menu. \n\n";
                cin.clear();
                cin.ignore(10000, '\n');
            } else if (accountOptS == "1" || accountOptS == "2" || accountOptS == "3"){
                cout << "\n\n";
                break;
            } else {
                cout << " ------------------------------------------------\n";
                cout << "\n !Select a number from the menu. \n\n";
                cin.clear();
                cin.ignore(10000, '\n');
            }
        }
        accountOptI = stoi(accountOptS);

        switch (accountOptI){
            case 1:
            *sId = customerLogin(customers);
            break;

            case 2:
            customerSignup(customers, sId);
            break;

            case 3:
            cout << " ------------------------------------------------\n";
            cout << "Enter your information \n";

            //name validation
            while(true){
                cout << " ------------------------------------------------\n";
                cout << " Name: ";
                getline(cin, guestNameS);                                            
                if(isNameValid(guestNameS) == true){
                    iq.name = guestNameS;
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
                cin  >> iq.phone;

                if (isPhoneValid(iq.phone) == true){
                    break;
                } else {
                    cout << "\n  !Please enter a valid phone number\n\n";
                }
            }

            //email validation
            while (true){
                cout << " Email address (e.g. test@email.com): ";
                cin  >> iq.email;

                if (isEmailValid(iq.email) == true){
                    break;
                } else {
                    cout << "\n  !Please enter a valid email address\n\n";
                }
            }
        }
    }
    int s = *sId;       //get sseion ID


    if (s != 0 || accountOptI == 3){
        cout << " ------------------------------------------------\n";
        cout << " Please check and confirm your order information \n\n";

        if (s != 0){
            cout << "  Customer ID:\t\t" << customers[s].customerId <<"\n";
            cout << "  Name:\t\t\t" << customers[s].name <<"\n";
            cout << "  Phone number:\t\t" << customers[s].phone << "\n";
            cout << "  Emainl Address:\t" << customers[s].email << "\n";
        } else if (accountOptI == 3) {
            cout << "  Name:\t\t" << c.name <<"\n";
            cout << "  Phone number:\t" << iq.phone << "\n";
            cout << "  Email Address:\t" << iq.email << "\n";
        }
    }

    if (s != 0 || accountOptI == 3){
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
    }

    cout << "  Detail:\t\t" << iq.detail << "\n";


    if (accountOptI != 3){
        iq.name = customers[s].name;
        iq.phone = customers[s].phone;
        iq.email = customers[s].email;
    }
    iq.userType = "Customer";

    
    inquiries.push_back(iq);


    //confirm order
    string confirm;
    ofstream inquiryList("InquiryList.csv", ios::app);

    //yes or no validation
    while(true){
        cout << " ------------------------------------------------\n";
        cout << "Confirm order (y/n): ";
        cin >> confirm;

        if (isYesNoValid(confirm) == true){
            if (confirm == "y"){
                cout << "------------------------------------------------\n";
                cout << "\n  Thank you!\n  See you later!\n";
                inquiryList << inquiries[i].year << "," << inquiries[i].month << "," << inquiries[i].day << "," << inquiries[i].name << "," << inquiries[i].userType << "," << inquiries[i].phone << "," << inquiries[i].email << "," << inquiries[i].topic << "," << inquiries[i].detail << ",\n" ;
                cin.clear();
                cin.ignore(10000, '\n');
            } else {
                cout << "\n  Your inquiry was canceled.\n";
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


    //go back to the admin menu
    cout << "\nPress any key to go back to the Customer Menu\n";
    system("read");
    customerMenu(customers, orders, inquiries, sId);

    cout << "\n\n";
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Functions (Ride)
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void ride(vector <Customers> &customers, vector <Orders> &orders, vector <Inquiries> &inquiries, int* sId){
    struct Customers c;
    struct Orders o;
    string requestNow;
    int i = orders.size();               //get orders list size
    o.orderId = i;

    time_t now = time(0);
    tm *ltm = localtime(&now);
    int currentYear, currentMonth, currentDay, currentHour, currentMin;
    int  pickupDay, pickupHour, pickupMin;

    string pickOptS, desOptS, serOptS, payOptS, accountOptS;        //to store strings from getline()   opt=option, s = string
    int pickOptI, desOptI, serOptI, payOptI, accountOptI;           //to convert string to integer

    string userInputYearS, userInputMonthS, userInputDayS, userInputHourS, userInputMinuteS;
    int userInputYearI, userInputMonthI, userInputDayI, userInputHourI, userInputMinuteI;

    string pickLocationS, destinationS;
    string customerNameS;
    

    //integer & option validation
    while(true){
        cout << " ------------------------------------------------\n";
        cout << " Choose pickup area number (1.Downtown 2.Suburb): ";
        getline(cin, pickOptS);                                            
        if(isIntegerValid(pickOptS) == false){
            cout << " ------------------------------------------------\n";
            cout << "\n !Select a number from the menu. (Press any key) \n\n";
            cin.clear();
            cin.ignore(10000, '\n');
        } else if (pickOptS == "1" || pickOptS == "2"){  
            cout << "\n\n";
            break;
        } else {
            cout << " ------------------------------------------------\n";
            cout << "\n !Select a number from the menu. (Press any key) \n\n";
            cin.clear();
            cin.ignore(10000, '\n');
        }
    }
    o.pickupArea = stoi(pickOptS);

    //name validation
    while(true){
        cout << " ------------------------------------------------\n";
        cout << " Enter pickup location (address): ";
        getline(cin, pickLocationS);                                            
        if(isAddressValid(pickLocationS) == true){
            o.pickupLocation = pickLocationS;
            break;
        } else {
            cout << " ------------------------------------------------\n";
            cout << "\n !Enter valid address. (Press any key) \n\n";
            cin.clear();
            cin.ignore(10000, '\n');
        }
    }
    cout << "\n";

    //integer validaton
    while(true){
        cout << " ------------------------------------------------\n";
        cout << " Choose destination area number(1.Downtown 2.Suburb): ";
        getline(cin, desOptS);                                            
        if(isIntegerValid(desOptS) == false){
            cout << " ------------------------------------------------\n";
            cout << "\n !Select a number from the menu. (Press any key) \n\n";
            cin.clear();
            cin.ignore(10000, '\n');
        } else if (desOptS == "1" || desOptS == "2"){  
            cout << "\n\n";
            break;
        } else {
            cout << " ------------------------------------------------\n";
            cout << "\n !Select a number from the menu. (Press any key) \n\n";
            cin.clear();
            cin.ignore(10000, '\n');
        }
    }
    o.destinationArea = stoi(desOptS);


    //name validation
    while(true){
        cout << " ------------------------------------------------\n";
        cout << " Enter destination(address): ";
        getline(cin, destinationS);                                            
        if(isAddressValid(destinationS) == true){
            o.destination = destinationS;
            break;
        } else {
            cout << " ------------------------------------------------\n";
            cout << "\n !Enter valid address. (Press any key) \n\n";
            cin.clear();
            cin.ignore(10000, '\n');
        }
    }
    cout << "\n";
    



    //yes or no Validation
    while(true){
        cout << " ------------------------------------------------\n";
        cout << " Request Now? (y/n): ";
        cin >> requestNow;

        if (isYesNoValid(requestNow) == true){
            cin.clear();
            cin.ignore(10000, '\n');
            break;
        } else {
            cout << "\n  !Please answer with y or n\n\n";
            cin.clear();
            cin.ignore(10000, '\n');
        }
    }
    
    
    //request now
    if (requestNow == "y"){

        // get current date
        currentYear = 1900 + ltm->tm_year;
        currentMonth = 1 + ltm->tm_mon;
        currentDay = ltm->tm_mday;
        currentHour = ltm->tm_hour;
        currentMin = ltm->tm_min;

        o.days = calculateDays(currentMonth, currentDay);
        o.week = calculateWeeks(o.days);

        pickupDay = currentDay;
        pickupHour = currentHour;
        pickupMin = currentMin + 20;        //pickup in 20min
        
        //minute needs to be less than 60 minutes
        if (pickupMin > 60){
            pickupMin = pickupMin -60;
            pickupHour = pickupHour + 1;
        }

        //store to the structure
        o.year = currentYear;
        o.month = currentMonth;
        o.day = pickupDay;
        o.hour = pickupHour;
        o.min = pickupMin;
    } 

    //request later (booking)
    if(requestNow == "n") {
        cout << "------------------------------------------------\n";
        cout << "When are you going to ride?\n";


        //integer & option validation
        while(true){
            cout << "------------------------------------------------\n";
            cout << "  Year (e.g. 2022): ";
            getline(cin, userInputYearS); 
            if(isMultiDigitValid(userInputYearS) == true){
                userInputYearI = stoi(userInputYearS);

                if (userInputYearI >= 2022 && userInputYearI <= 2023){          //booking is available fron 2022 to 2023
                    o.year = userInputYearI;
                    break;
                } else {
                    cout << "\n !Reservations are possible from 2022(Jan) to 2023(Dec) (Press any key)\n\n";
                    cin.clear();
                    cin.ignore(10000, '\n');
                }
            } else {
                cout << " ------------------------------------------------\n";
                cout << "\n !Please enter a valid number. (Press any key)\n\n";
                cin.clear();
                cin.ignore(10000, '\n');
            }
        }

        //month validaton
        while(true){
            cout << "------------------------------------------------\n";
            cout << "  Month (e.g. 01): ";
            getline(cin, userInputMonthS); 
            if(isMultiDigitValid(userInputMonthS) == true){
                userInputMonthI = stoi(userInputMonthS);

                if (userInputMonthI >= 1 && userInputMonthI <= 12){
                    o.month = userInputMonthI;
                    break;
                } else {
                    cout << "\n !Please enter a valid number. (Press any key)\n\n";
                    cin.clear();
                    cin.ignore(10000, '\n');
                }
            } else {
                cout << " ------------------------------------------------\n";
                cout << "\n !Please enter a valid number. (Press any key)\n\n";
                cin.clear();
                cin.ignore(10000, '\n');
            }
        }

        //day validation
        while(true){
            cout << "------------------------------------------------\n";
            cout << "  Day (e.g. 01): ";
            getline(cin, userInputDayS); 
            if(isMultiDigitValid(userInputDayS) == true){
                userInputDayI = stoi(userInputDayS);

                if (userInputDayI >= 1 && userInputDayI <= 31){
                    o.day = userInputDayI;
                    break;
                } else {
                    cout << "\n !Please enter a valid number. (Press any key)\n\n";
                    cin.clear();
                    cin.ignore(10000, '\n');
                }
            } else {
                cout << " ------------------------------------------------\n";
                cout << "\n !Please enter a valid number. (Press any key)\n\n";
                cin.clear();
                cin.ignore(10000, '\n');
            }
        }

        //hour validation
        while(true){
            cout << "------------------------------------------------\n";
            cout << "  Hour (e.g. 01): ";
            getline(cin, userInputHourS); 
            if(isMultiDigitValid(userInputHourS) == true){
                userInputHourI = stoi(userInputHourS);

                if (userInputHourI >= 0 && userInputHourI <= 24){
                    o.hour = userInputHourI;
                    break;
                } else {
                    cout << "\n !Please enter a valid number. (Press any key)\n\n";
                    cin.clear();
                    cin.ignore(10000, '\n');
                }
            } else {
                cout << " ------------------------------------------------\n";
                cout << "\n !Please enter a valid number. (Press any key)\n\n";
                cin.clear();
                cin.ignore(10000, '\n');
            }
        }

        //minute validation
        while(true){
            cout << "------------------------------------------------\n";
            cout << "  Minute (e.g. 01): ";
            getline(cin, userInputMinuteS); 
            if(isMultiDigitValid(userInputMinuteS) == true){
                userInputMinuteI = stoi(userInputMinuteS);

                if (userInputMinuteI >= 0 && userInputMinuteI <= 59){
                    o.min = userInputMinuteI;
                    break;
                } else {
                    cout << "\n !Please enter a valid number. (Press any key)\n\n";
                    cin.clear();
                    cin.ignore(10000, '\n');
                }
            } else {
                cout << " ------------------------------------------------\n";
                cout << "\n !Please enter a valid number. (Press any key)\n\n";
                cin.clear();
                cin.ignore(10000, '\n');
            }
        }

        o.days = calculateDays(o.month, o.day);
        o.week = calculateWeeks(o.days);

    }  


    //calcurate the fare
    float basicCharge, areaCharge, taxiFare, vanFare,premiumVanFare;

    basicCharge = 10;          
    areaCharge = abs(o.destinationArea - o.pickupArea)*10; 
    taxiFare = basicCharge + areaCharge;
    vanFare = (basicCharge + areaCharge) * 1.15;
    premiumVanFare = (basicCharge + areaCharge) * 1.30;


    cout << " ------------------------------------------------\n";
    cout << " Please select a service: \n";
    printf("  1. Taxi\t\t4 people\tNZD%2.2f\t\t%d/%d/%d %02d:%02d(Pick up)\n", taxiFare,o.year,o.month,o.day,o.hour,o.min);    //printf is for showing two digits
    printf("  2. Van\t\t5 people\tNZD%2.2f\t\t%d/%d/%d %02d:%02d(Pick up)\n", vanFare, o.year,o.month,o.day,o.hour,o.min);
    printf("  3. Premium Van\t6 people\tNZD%2.2f\t\t%d/%d/%d %02d:%02d(Pick up)\n", premiumVanFare, o.year,o.month,o.day,o.hour,o.min);

    //integer & option validation
    while(true){
        cout << " ------------------------------------------------\n";
        cout << "  Enter option: ";
        getline(cin, serOptS);              
        if(isIntegerValid(serOptS) == false){
            cout << " ------------------------------------------------\n";
            cout << "\n !Select a number from the menu. \n\n";
            cin.clear();
            cin.ignore(10000, '\n');
        } else if (serOptS == "1" || serOptS == "2" || serOptS == "3"){
            cout << "\n\n";
            break;
        } else {
            cout << " ------------------------------------------------\n";
            cout << "\n !Select a number from the menu. \n\n";
            cin.clear();
            cin.ignore(10000, '\n');
        }
    }
    o.selectedService = stoi(serOptS);


    //check session ID
    if (*sId == 0){
        cout << " ------------------------------------------------\n";
        cout << " Do you have Yoobee Taxi account?: \n";
        cout << "  1. Login       (if you have our account)\n";
        cout << "  2. Sign up     (if you don't have our account and  want to create(free))\n";
        cout << "  3. Guest Order (If you don't want to create our account)\n";

        //inteeger validation
        while(true){
            cout << " ------------------------------------------------\n";
            cout << "  Enter option: ";
            getline(cin, accountOptS);              
            if(isIntegerValid(accountOptS) == false){
                cout << " ------------------------------------------------\n";
                cout << "\n !Select a number from the menu. \n\n";
                cin.clear();
                cin.ignore(10000, '\n');
            } else if (accountOptS == "1" || accountOptS == "2" || accountOptS == "3"){
                cout << "\n\n";
                break;
            } else {
                cout << " ------------------------------------------------\n";
                cout << "\n !Select a number from the menu. \n\n";
                cin.clear();
                cin.ignore(10000, '\n');
            }
        }
        accountOptI = stoi(accountOptS);


        switch (accountOptI){
            case 1:
            *sId = customerLogin(customers);
            break;

            case 2:
            customerSignup(customers, sId);
            break;


            case 3:
            while(true){
                cout << " ------------------------------------------------\n";
                cout << " Name: ";
                getline(cin, customerNameS);                                            
                if(isNameValid(customerNameS) == true){
                    c.name = customerNameS;
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
                cin  >> c.phone;

                if (isPhoneValid(c.phone) == true){
                    break;
                } else {
                    cout << "\n  !Please enter a valid phone number\n\n";
                }
            }

            //email validation
            while (true){
                cout << " Email address (e.g. test@email.com): ";
                cin  >> c.email;

                if (isEmailValid(c.email) == true){
                    cin.clear();
                    cin.ignore(10000, '\n');
                    break;
                } else {
                    cout << "\n  !Please enter a valid email address\n\n";
                    cin.clear();
                    cin.ignore(10000, '\n');
                }
            }

            cout << " ------------------------------------------------\n";
            cout << " Payment method: \n";
            cout << "  1. Cash \n";
            cout << "  2. Credit Card \n";
            cout << "  3. Online Payment \n";
            
            //integer & option validation
            while(true){
                cout << " ------------------------------------------------\n";
                cout << "  Enter option: ";
                getline(cin, payOptS);                                                                   
                if(isIntegerValid(payOptS) == false){
                    cout << " ------------------------------------------------\n";
                    cout << "\n !Select a number from the menu. (Press any key) \n\n";
                    cin.clear();
                    cin.ignore(10000, '\n');
                } else if (payOptS == "1" || payOptS == "2" || payOptS == "3"){ 
                    cout << "\n\n";
                    break;
                } else {
                    cout << " ------------------------------------------------\n";
                    cout << "\n !Select a number from the menu. (Press any key) \n\n";
                    cin.clear();
                    cin.ignore(10000, '\n');
                }
            }
            payOptI = stoi(payOptS);


            switch(payOptI){
                case 1:
                c.payment = "Cash";
                break;

                case 2:
                c.payment = "Credit Card";
                break;

                case 3:
                c.payment = "Online Payment";
                break;
            }
        }
    }


    int s = *sId;
    
    if (s != 0 || accountOptI == 3){
        cout << " ------------------------------------------------\n";
        cout << " Please check and confirm your order information \n\n";

        if (s != 0){
            cout << "  Name:\t\t\t" << customers[s].name <<"\n";
            cout << "  Phone number:\t\t" << customers[s].phone << "\n";
        } else if (accountOptI == 3) {
            cout << "  Name:\t\t\t" << c.name <<"\n";
            cout << "  Phone number:\t\t" << c.phone << "\n";
        }
    }
    
    if (s != 0 || accountOptI == 3){
        cout << "  Pickup location:\t" << o.pickupLocation << "\n";
        cout << "  Destination:\t\t" << o.destination << "\n";

        switch (o.selectedService) {
            case 1:
            o.carType = "Taxi(4 people)";

            cout << "  Car type:\t\tTaxi(4 people)\n";
            printf("  Fare:\t\t\tNZD%2.2f\n", taxiFare);
            printf("  Pick up date:\t\t%d/%d/%d %02d:%02d\n", o.year,o.month,o.day,o.hour,o.min);
            o.fare = taxiFare;
            break;

            case 2:
            o.carType = "Van(5 people)";

            cout << "  Car type:\t\tVan(5 people)\n";
            printf("  Fare:\t\t\tNZD%2.2f\n", vanFare);
            printf("  Pick up date:\t\t%d/%d/%d %02d:%02d\n", o.year,o.month,o.day,o.hour,o.min);
            o.fare = vanFare;
            break;

            case 3:
            o.carType = "Premium Van(6 people)";

            cout << "  Car type:\t\tPremium Van(6 people)\n";
            printf("  Fare:\t\t\tNZD%2.2f\n", premiumVanFare);
            printf("  Pick up date:\t\t%d/%d/%d %02d:%02d\n", o.year,o.month,o.day,o.hour,o.min);
            o.fare = premiumVanFare;
            break;
        }

       if (s != 0){
            cout << "  Payment Method:\t" << customers[s].payment <<"\n";
        } else if (accountOptI == 3) {
            cout << "  Payment Method:\t" << c.payment <<"\n";
        }



        if (accountOptI == 3){
            o.customerName = c.name;
            o.customerPhone = c.phone;
        } else {
            o.customerName = customers[s].name;
            o.customerPhone = customers[s].phone;
        }
        o.driverName = "Not assigned";
        o.driverPhone = "Not assigned";
        
        orders.push_back(o);


        //confirm order
        string confirm;
        ofstream orderList("OrderList.csv", ios::app);


        //Yes or No Validation
        while(true){
            cout << " ------------------------------------------------\n";
            cout << "Confirm order (y/n): ";
            cin >> confirm;

            if (isYesNoValid(confirm) == true){
                if (confirm == "y"){
                    cout << "------------------------------------------------\n";
                    cout << "\n  Thank you!\n  See you later!\n";
                    orderList << orders[i].orderId << "," << orders[i].year << "," << orders[i].month << "," << orders[i].day << "," << orders[i].hour << "," << orders[i].min << "," << orders[i].days << "," << orders[i].week << "," << orders[i].customerName << "," << orders[i].customerPhone << "," << orders[i].driverName << "," << orders[i].driverPhone << "," << orders[i].carType << "," << orders[i].pickupArea << "," << orders[i].destinationArea << "," << orders[i].pickupLocation << "," << orders[i].destination << "," << orders[i].fare << ",\n" ;
                    cin.clear();
                    cin.ignore(10000, '\n');
                } else {
                    cout << "\n  Your order was canceled.\n";
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


    //go back to the admin menu
    cout << "\nPress any key to go back to the Customer Menu\n";
    system("read");
    customerMenu(customers, orders, inquiries, sId);
    cout << "\n\n";

}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Functions (calculate)
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
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
