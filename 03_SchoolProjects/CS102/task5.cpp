#include <iostream>
#include <ctime>    //for time() (to generate the random number)
#include <cstdlib>  //for srand(),rand()
using namespace std;

int main() {
    // 1. Generate the random number(Answer)
    srand(time(0));
    int randNum = 1 + rand() % 10;
    // cout << "Answer is " << randNum << endl << endl;


    // 2. Introduction
    cout << "You will get three chances to guess the number" << endl << endl;
    cout << "Guess a number in between 1 to 10." << endl << endl << endl;

    int answer;
    int choiceNum = 1;
    int life = 3;
    
    // 3. Ask the number (until the life get less than 1)
    while (life > 0){
        cout << "Choice " << choiceNum << " : Enter your answer : ";
        cin >> answer;
        cout << endl;

        if (answer == randNum){
            cout << "congratulations! You are correct!" << endl << endl;
            break;

        } else {
            if (life > 1){
                cout << "Sorry wrong Guess , Try Again" << endl << endl;
                choiceNum++;
                life--;
            } else {
                cout << "Sorry wrong Guess , you reached the limit" << endl << endl;
                break;
            }
        }
    }
    cout << endl;
    cout << "Correct number : " << randNum << endl;

    return 0;
}