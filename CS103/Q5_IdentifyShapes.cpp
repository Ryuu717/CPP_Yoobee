#include <iostream>
#include <ctime>
#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>     /* srand, rand */
using namespace std;


//funtion prototypes
void menu(int* ptr);
void play(int* ptr);
void rectangle(int height, int width);




int main(){
    //declare variables and pointer
    int correct_count = 0;
    int* ptr = &correct_count ;

    //call menu
    menu(ptr);

}


//square (without any argument and without return type)
void square(){
    cout <<  " ・・・・ \n ・    ・\n ・    ・\n ・・・・ \n";
}

//triangle (without any argument and without return type)
void triangle(){
    cout << "    ・\n   ・・\n  ・  ・\n ・    ・\n・・・・・\n";
}


//rectangle (with arguments and without return type)
void rectangle(int height, int width){

    //draw upper base
    for (int i = 0; i < width; i++){
        cout << "・";
    }
    cout << "\n";

    //draw height
    for (int i = 0; i < height -2; i++){
        cout << "・";
        for (int j =0; j < width-2; j++){
            cout << "　";
        }
        cout << "・\n";
    }

    //draw lower base
    for (int i = 0; i < width; i++){
        cout << "・";
    }
    cout << "\n";
}


//calculate score
int calculate_score(int* correct_count){
    //with argument and with the return value
    //For each right answer, increment the score by 10. 
    //Return the score to the calling place.

    int score = *correct_count * 10;

    return score;
}


//show menu
void menu(int* ptr){
    //display Main Menu (Play, Final Score and Exit)
    cout << "=============================\n";
    cout << "Menu\n";
    cout << "  1. Play\n";
    cout << "  2. Final Score\n";
    cout << "  3. Exit\n";
    cout << "=============================\n";

    //user's input
    int option;
    cout << "Choose the option: ";
    cin >> option;
    cout << "\n";

    //execute option
    switch (option){
        case 1:
            play(ptr);
            break;

        case 2:
            cout << "Your final score : " << calculate_score(ptr) << " / 30 " << "\n\n";
            menu(ptr);
            break;

        case 3:
            cout << "See you again!" << "\n";
            break;
    }
    cout << "\n";
}

void play(int* ptr){
    // string shape[] = {"▭", "△", "▢"};

    int shape[] = {1, 2, 3};    //numbers for switch types
    int answer;
    int quiz_number = 0;

    //initialize the score
    *ptr = 0;

    //run the quiz until three times
    while (quiz_number < 3){     
        srand(time(NULL));
        int random_number = rand() % 3;

        cout << "--------------------------------\n";
        cout << "Question " << quiz_number + 1 << "\n";
        cout << "What's this?\n";
        switch (shape[random_number]){
            case 1:
                rectangle(4,8);
                break;

            case 2:
                triangle();
                break;

            case 3:
                square();
                break;
        }
        cout << " 1. Rectangle\n";
        cout << " 2. Triangle\n";
        cout << " 3. Square\n";
        cout << " 4. None of the above\n\n";
        cout << "Your answer : ";
        cin >> answer;

        if (answer - 1 == random_number){
            cout << "You are correct!\n\n";
            *ptr = *ptr + 1;
        } else {
            cout << "You are wrong!\n\n";
        }
        quiz_number++;
    }

    
    //change the comment depend on the result
    cout << "===================\n";
    if (*ptr == quiz_number){
        cout << "Your score : " << calculate_score(ptr) << " / " << quiz_number *10 << "\n";    
        cout << "Congratulations!!\n";
    } else {
        cout << "Your score : " << calculate_score(ptr) << " / " << quiz_number *10 << "\n";
        cout << "Good luck next time!\n";
    }
    // cout << "Your score : " << calculate_score(ptr) << " / " << quiz_number *10 << "\n";
    cout << "===================\n\n";

    menu(ptr);
}