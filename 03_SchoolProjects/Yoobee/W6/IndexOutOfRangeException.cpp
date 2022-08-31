// IndexOutOfRangeException.cpp : This file contains the 'main' function. Program execution begins and ends there.

// Adding two different range arrays 

#include <iostream>
using namespace std;

class IndexOutOfRange{
public :
    string error;
    
    IndexOutOfRange(){
        error = "";
    }
    
    IndexOutOfRange(string error){
        this->error = error;
    }
};


int main(){
    int a[3];

    int lower_range = 0;
    double b[3], result[3];
    int aindex = 0, bindex = 0, rindex = 0;
    char user_response = 'n', large_array = 'a';

   

    //Reading a array values 
    do{
        try {
                cout << " Enter a value : ";
                cin >> a[aindex];
                // ++aindex;
                aindex++;

                if (aindex > 3) throw IndexOutOfRange(" Out of Range error "); 
                else{
                    cout << " Do you want to continue ? (y/n)  ";
                    cin >> user_response;
                }
            } catch (IndexOutOfRange e){
                cout << e.error;
                user_response = 'n';
            }

    }while(user_response != 'n');

    // Reading b array 
    do {
        try {
            cout << " Enter b value : ";
            cin >> b[bindex];
            // ++bindex;
            bindex++;

            if (bindex > 3) throw IndexOutOfRange(" Out of Range error ");
            else{
                cout << " Do you want to continue ? (y/n)  ";
                cin >> user_response;
            }
        } catch (IndexOutOfRange e){
            cout << e.error;
            user_response = 'n';
        }

    } while (user_response != 'n');

    // calculate result array 
     
    if (aindex > bindex){
        rindex = aindex;
        large_array = 'a';
        lower_range = bindex;
    }else{
        rindex = bindex;
        lower_range = aindex;
        large_array = 'b';
    }

    // adding the range upto the common index limit
    for (int i = 0; i < lower_range; i++){
        result[i] = a[i] + b[i];
    }

    for (int i = lower_range; i < rindex; i++){
        if (large_array == 'a'){
            result[i] = a[i];
        }else{
            result[i] = b[i];
        }
    }

       cout << "\n\n a values : ";
       for (int i = 0; i < aindex; i++){
           cout << a[i]<<"  ";
       }

       cout << "\n\n b values : ";
       for (int i = 0; i < bindex; i++){
           cout << b[i] << "  ";
       }

       
       cout << "\n\n Result array values  : ";
       for (int i = 0; i < rindex; i++){
           cout << result[i] << "  ";
       }

       return 0;
}

