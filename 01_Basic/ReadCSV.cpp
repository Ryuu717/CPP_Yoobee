#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>   //for istringstream
using namespace std;


//Declare structures
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
        pickupLocation = pl;
        destination = des;
        selectedService = ss;
    }
};

//Declare function prototypes
void readFile(vector <Customers> &customers);



int main(){
    vector <Customers> customers;

    readFile(customers);

    return 0;
}



// Read File & Output all data directory
void readFile(vector <Customers> &customers){
    ifstream customerList("CustomerList.csv");
    string line, item;

    while (getline(customerList, line)) {    
        istringstream i_stream(line);

        //Read all data
        while (getline(i_stream, item, ',')) {
        cout << item << "   ";
        }
        cout << "\n";
    }
}

// Read File & Store it in the vector
// void readFile(vector <Customers> &customers){
//     ifstream customerList("CustomerList.csv");
//     string line, item;
//     struct Customers c;

//     while (getline(customerList, line)) {    
//         istringstream i_stream(line);

//         //String to integer conversion
//         // getline(i_stream, item, ',');
//         // o.year = atoi(item.c_str());
//         // getline(i_stream, item, ',');
//         // o.month = atoi(item.c_str());
//         // getline(i_stream, item, ',');
//         // o.day = atoi(item.c_str());
//         // getline(i_stream, item, ',');
//         // o.days = atoi(item.c_str());
//         // getline(i_stream, item, ',');
//         // o.week = atoi(item.c_str());

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