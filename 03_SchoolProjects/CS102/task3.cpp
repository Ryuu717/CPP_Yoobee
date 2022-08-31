#include <iostream>
#include <ctime>    //for time() (to generate the random number)
#include <cstdlib>  //for srand(),rand()
using namespace std;

int main() {
    // 1. Generate the random number
    srand (time(0));

    int randNum;
    int evenCounter=0;
    int oddCounter=0;

    cout << "Random numbers between 10 to 20" << endl; 
    cout << "*****************************************" << endl;

    for (int i = 0; i < 6; i++){
        randNum = 10 + rand() % 10; 

        // 2. Count even and odd
        if (randNum%2 == 0){
            evenCounter++;
        } else {
            oddCounter++;
        }
        
        // 3. Output 6 different random numbers(no comma at the end)
        if(i<5){
            cout << randNum << ",";
        } else {
            cout << randNum <<endl;
        }
    }

    // 4. show counts
    cout << "Number of even numbers in the list: " << evenCounter << endl;
    cout << "Number of odd numbers in the list: " << oddCounter << endl;
    cout << endl;
    

    return 0;
}