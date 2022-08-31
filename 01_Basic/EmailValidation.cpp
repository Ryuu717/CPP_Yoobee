//https://stackoverflow.com/questions/36903985/email-validation-in-c
//https://ez-net.jp/article/B3/4WP0_0BF/lJx6ZlC9pIpj/

#include <iostream>
#include <regex>    //include regular expressions library

using namespace std;

bool isEmailValid(string& email){
   regex pattern("(\\w+)(\\.|_)?@(\\w+)(\\.(\\w+))");   // define a regular expression
   
   return regex_match(email, pattern);                  // Determine if the entire string matches the regular expression
}


int main(){
    string email;

    while (true){
        cout << "Enter your email address (e.g. test@gmail.com): ";
        cin  >> email;

        if (isEmailValid(email) == true){
            break;
        } else {
            cout << "Please enter a valid email address\n";
        }
    }
}