//https://stackoverflow.com/questions/36903985/phone-validation-in-c
//https://ez-net.jp/article/B3/4WP0_0BF/lJx6ZlC9pIpj/

#include <iostream>
// #include <string>
#include <regex>    //include regular expressions library

using namespace std;

bool isPhoneValid(const string& phone){
   const regex pattern("(\\d+)(\\-)(\\d+)(\\-)(\\d+)");         // define a regular expression
   
   return regex_match(phone, pattern);                          // try to match the string with the regular expression
}


int main()
{
    string phone;

    while (true){
        cout << "Enter your phone number(e.g. 000-0000-0000): ";
        cin  >> phone;

        if (isPhoneValid(phone) == true){
            break;
        } else {
            cout << "Please enter a valid phone number\n";
        }
    }
}