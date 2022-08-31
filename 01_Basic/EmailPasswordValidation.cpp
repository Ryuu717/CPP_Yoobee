// emailValidation.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
using namespace std;
int main()
{   //********************
    //email validation - checking if @ symbol is found in the email entered by the user.
    //********************
    string email;
    cout << "\nEnter the email:";
    getline(cin, email);
    int i, flag = 0 ; //i is the index variable
    cout <<"\nThe size of email is " << email.size()<< endl;
    for (i = 0; i < email.size(); i++) {
        //cout << "\n" << email[i];
        if (email[i] == '@') {
            flag = 1; //when @ symbol is found, a flag is set to 1
        }
        
    }
    if (flag == 1) {
        cout << "\nThis is a valid email" << endl;
    }
    else {
        cout << "\nThis is an invalid email" << endl;
    }

    //*******************
    //password validation
    //********************

    /*Rule: minimum 8 characters
    atleast one upper case, 
    one lower case, 
    one special symbol 
    and one number*/
    string password;
    cout << "\nEnter the password: ";
    getline(cin, password);
    if (password.size() >= 8) {
        int passwordIndex, digitFlag = 0, lowerFlag = 0, upperFlag = 0, specialCharacterFlag = 0;
        //checking if pasword contains a number
        for (passwordIndex = 0; passwordIndex < password.size(); passwordIndex++) {
            if (isdigit(password[passwordIndex])) {
                digitFlag = 1;
            }
        }
        if (digitFlag == 0)
            cout << "\nNumber missing";

        //checking if password contains a lower case
        for (passwordIndex = 0; passwordIndex < password.size(); passwordIndex++) {
            if (islower(password[passwordIndex])) {
                lowerFlag = 1;
            }
        }
        if (lowerFlag == 0)
            cout << "\nLower case missing";

        //checking if password contains an upper case
        for (passwordIndex = 0; passwordIndex < password.size(); passwordIndex++) {
            if (isupper(password[passwordIndex])) {
                upperFlag = 1;
            }
        }
        if (upperFlag == 0)
            cout << "\nUpper case missing";

        //checking if password contains a special character
        for (passwordIndex = 0; passwordIndex < password.size(); passwordIndex++) {
            if (!(isupper(password[passwordIndex])) && !(islower(password[passwordIndex])) && !(isdigit(password[passwordIndex]))) {
                specialCharacterFlag = 1;
            }
        }
        if (specialCharacterFlag == 0)
            cout << "\nSpecial character missing";

        //Checking if all flags are 1 to be a valid password
        if ((digitFlag == 1) && (lowerFlag == 1) && (upperFlag == 1) && (specialCharacterFlag == 1)) {
            cout << "\nThe password contains atleast a number, a special character, a lower case and an upper case. It is a valid password. ";
        }
        else {
            cout << "\nThe password must contain alteast a number, a special character, a lower case and an upper case. It is an invalid password. ";
        }
    }
    else {
        cout << "\nPassword must contain 8 or more characters.";
    }
}
