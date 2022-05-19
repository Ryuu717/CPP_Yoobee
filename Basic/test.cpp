// structureArrayPointer.cpp : This file contains the 'main' function. Program execution begins and ends there.
#include <iostream>
using namespace std;

//structure definition
struct BankCustomer {
    long int accountNumber;
    string name;
    float balanceAmount; 
    
    //constructure
    BankCustomer(long int an = 213456235, string n = "Mark", float ba = 1250.75) {
        accountNumber = an;
        name = n;
        balanceAmount = ba; 
    }
};



//function prototype
struct BankCustomer* inputCustomers(struct BankCustomer* p);
struct BankCustomer* outputCustomers(struct BankCustomer* p) ;



int main()
{
    struct BankCustomer customers[3]; //structure array
    struct BankCustomer* p; //structure pointer p = customers; // assign the structure array to the structure pointer . for arrays do not use ampersand (&) inputCustomers(p); //calling a function and passing the pointer to the structure array

    p = customers;

    inputCustomers(p);
    outputCustomers(p);
}


//function definition

struct BankCustomer* inputCustomers(struct BankCustomer* p) {
    int i; for (i = 0; i < 3; i++) {
        cout << "Enter the account number of the customer: ";
        cin >> p->accountNumber; 
        cout << "Enter the name of the customer: ";
        cin >> p->name; 
        cout << "Enter the balance amount: ";
        cin >> p->balanceAmount; 

        p++;
    }    
    return (p);
}

struct BankCustomer* outputCustomers(struct BankCustomer* p) {
    for (int i = 0; i < 3; i++){
        cout << p->accountNumber << "\n";
        cout << p->name << "\n";
        cout << p->balanceAmount << "\n";

        p++;
    }
    return (p);
}

