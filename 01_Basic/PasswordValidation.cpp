#include <iostream>
#include <regex>

using namespace std;

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


int main(){
    string password;

    cout << "Enter your password: \n";
    cout << "  -At least 8 characters\n";
    cout << "  -At least one upper case character\n";
    cout << "  -At least one lower case character\n";
    cout << "  -At least one special character (@, !, ?, #)\n";
    cout << "  -At least one number\n";
    
    while (true){
        cout << "---------------------------------------------------------\n";
        cout << "   Your password is: ";
        cin  >> password;
        cout << "\n";

        if (isPasswordValid(password) == true){
            break;
        } else {
            cout << "\nPlease enter a valid password.\n";
        }
    }

    return 0;
}