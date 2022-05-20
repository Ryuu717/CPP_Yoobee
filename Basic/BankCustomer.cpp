// structureArrayPointer.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;



//structure definition
    struct BankCustomer {
    long int accountNumber;
    string name;
    float balanceAmount;
    int order;


    //constructure
    BankCustomer(long int an = 213456235, string n = "Mark", float ba = 1250.75, int o = 0) {
        accountNumber = an;
        name = n;
        balanceAmount = ba;
        order = o;
    }
};





//function prototype
struct BankCustomer* inputCustomers(struct BankCustomer* p);
// struct BankCustomer* outputCustomers(struct BankCustomer* p);
void outputCustomers(struct BankCustomer* p);
// struct BankCustomer* ascending(struct BankCustomer* p);
void ascending(struct BankCustomer* p);




int main()
{
    struct BankCustomer customers[3]; // structure array
    struct BankCustomer* ptr; // structure pointer
    
    ptr = customers; //assigne the structure array to the structure pointer . For arrays do not use ampersand (&)

    inputCustomers(ptr); // calling a function and passing the pointer to the structure array.
    outputCustomers(ptr);
    ascending(ptr);
}



//function definition
struct BankCustomer* inputCustomers(struct BankCustomer* p) {
    cout << "\nEnter customer information\n";
    cout << "----------------------------------------------------------------\n";
    
    for (int i = 0; i < 3; i++) {
        // cout << " Enter the account number of the customer: ";
        // cin >> p->accountNumber;
        // cout << " Enter the name of the customer: ";
        // cin >> p->name;
        // cout << " Enter the balance amount: ";
        // cin >> p->balanceAmount;

        // p++;

        cout << " Enter the account number of the customer: ";
        cin >> (p+i)->accountNumber;
        cout << " Enter the name of the customer: ";
        cin >> (p+i)->name;
        cout << " Enter the balance amount: ";
        cin >> (p+i)->balanceAmount;
    }
    
    return(p);
}



// struct BankCustomer* outputCustomers(struct BankCustomer* p) {
//     for (int i = 0; i < 3; i++) {
//         // cout << "\nCustomer account number :" << p->accountNumber;
//         // cout << "\nCustomer name :" << p->name;
//         // cout << "\nBalance amount :" << p->balanceAmount;
//         // p++;

//         cout << "\nCustomer account number :" << (p+i)->accountNumber;
//         cout << "\nCustomer name :" << (p+i)->name;
//         cout << "\nBalance amount :" << (p+i)->balanceAmount;
//     }

//     return(p);
// }



void outputCustomers(struct BankCustomer* p) {
    cout << "\nAll Customer information\n";
    cout << "----------------------------------------------------------------";

    for (int i = 0; i < 3; i++) {
        // cout << "\nCustomer account number :" << p->accountNumber;
        // cout << "\nCustomer name :" << p->name;
        // cout << "\nBalance amount :" << p->balanceAmount;

        // p++;


        cout << "\n  Customer account number :\t" << (p+i)->accountNumber;
        cout << "\n  Customer name :\t\t" << (p+i)->name;
        cout << "\n  Balance amount :\t\t" << (p+i)->balanceAmount;
    }
    cout << "\n";
}



//add another function to arrange the balance amount in ascending order

// struct BankCustomer* ascending(struct BankCustomer* p){
//     cout << "\nAscending\n";
//     cout << "----------------------------------------------------------------";
    
//     //declare account size
//     int customerCount = 3;


//     //create ranking by comparing each customer balance.
//     //show smaller balances in order
//     //Continue as many as the number of customers
//     while(customerCount > 0){
//         int rank = 0;

//         for (int i = 0; i < 3; i++) {
//             rank = 0;                   //everytime reset the ranking

//             for (int j = 0; j < 3; j++){
//                 if (((p+i)->balanceAmount - (p+j)->balanceAmount) < 0){
//                     rank++;
//                 }
//             }

//             if (rank == (customerCount - 1)){
//                 cout << "\n Customer account number :\t" << (p+i)->accountNumber;
//                 cout << "\n Customer name :\t" << (p+i)->name;
//                 cout << "\n Balance amount :\t" << (p+i)->balanceAmount;
//                 customerCount--;
//             }
//         }
//     }
//     return(p);
// }

void ascending(struct BankCustomer* p){
    cout << "\nAscending\n";
    cout << "----------------------------------------------------------------";
    
    //declare account size
    int customerCount = 3;

    //create ranking by comparing each customer balance.
    //show smaller balances in order
    //Continue as many as the number of customers
    while(customerCount > 0){
        int rank = 0;

        for (int i = 0; i < 3; i++) {
            rank = 0;                   //everytime reset the ranking

            for (int j = 0; j < 3; j++){
                if (((p+i)->balanceAmount - (p+j)->balanceAmount) < 0){
                    rank++;
                }
            }

            if (rank == (customerCount - 1)){
                cout << "\n Customer account number :\t" << (p+i)->accountNumber;
                cout << "\n Customer name :\t\t" << (p+i)->name;
                cout << "\n Balance amount :\t\t" << (p+i)->balanceAmount;
                customerCount--;
            }
        }
    }
    cout << "\n";
}


