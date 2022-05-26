#include <iostream>
#include <ctime>
#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>     /* srand, rand */
using namespace std;


//funtion prototypes
void draw_line();
string draw_hangman(int life);
void draw_Walkman();
void invert_hangman();
void play();


int main(){
    //call play function
    play();

    return 0;
}



//draw line (without parameters)
void draw_line(){
    cout << "----------------------------------------------------------------\n";
}

//draw hangman (with parameters, with a return value)
//show different types of Hnagman depend on the remaining life
string draw_hangman(int life){
    string hangman_lives[] = {
    " +---+\n |   |\n |   O\n |  /|\\  \n |  / \\ \n |     \n=========\n",
    " +---+\n |   |\n |   O\n |  /|\\  \n |  \n |     \n=========\n",
    " +---+\n |   |\n |   \n |   \n |  \n |     \n=========\n",
    };


    return hangman_lives[life];
}

//draw walkman (without any return value)
void draw_Walkman(){
    string Walkman = "   \\O/ \n    |  \n   / \\ \n=========\n";
    
    cout << Walkman;
}

//draw invert hangman (without any return value)
void invert_hangman(){
    string invert_hangman = " +---+\n |   |\n |   |/ \n |   | \n |  /O\\\n |     \n=========\n";
    
    cout << invert_hangman;
}


//play game
void play(){
    //introduction
    // draw_line();
    cout << "\n////////////////////////////////////////////////////////////////\n";
    cout << "Welcome to play Hnagman.\n";
    cout << "This game is to check your spelling skill\n";
    // draw_line();
    cout << "////////////////////////////////////////////////////////////////\n";


    //randomly choose a word from the list
    srand(time(NULL));
    int random_num = rand() % 10;

    string word_list[] = { "apple", "banana", "orange", "peach", "strawberry", "kiwi", "grape", "melon", "mango", "yoobee"};
    string word = word_list[random_num];


    //show blanks and word length
    int word_length = word.length(); 
    string blanks;
    
    for (int i = 0; i < word_length; i++){
        blanks += "_";
    }


    //game loop
    char guess;
    int life = 3;
    int blank_length = word_length;
    string hangman = draw_hangman(life - 1);

    while (life > 0 && blank_length > 0){       //continue the game as long as the life is positive and there is a blank space
        draw_line();
        cout << "Your life is " << life << "\n";

        //draw hangman
        cout << hangman;

        //show blanks
        for (int i = 0; i < word_length; i++){
           cout << blanks[i] << " ";
        }
        cout << "("<< word_length << " words)\n\n";
            

        //user's input
        cout << "Guess a letter : ";
        cin >> guess;
        // cout << "\n";

        //check the user's input and the correct answer for each letter.
        //if correct, replace from blank space to correct letter
        for (int i = 0; i < word_length; i++){
            if (guess == word[i]){
                blanks[i] = guess;
                blank_length--;
            }
        }

        //check if the user's input is in the word
        //if not, lose life
        if (word.find(guess) != string::npos){
            cout << "  ->You are right!\n\n";
        } else {
            cout << "  ->You are wrong!\n\n";
            life--;
        }
    }

    //game over
    if (life == 0){
        draw_line();
        cout << "Game over\n";
        invert_hangman();
        cout << "Correct answer is " << word << "\n";
        draw_line();
    }

    //game clear
    if (blank_length == 0){
        draw_line();
        cout << "Conglatulations!!\n\n";
        draw_Walkman();
        cout << "Correct answer is " << word << "\n\n";
        draw_line();
    }
}


//Memo
//1. Create random words ✔️
//2. validate user input whether it is string or not
//3. Give initial value(a,i,u,e,o, etc...)  or increase life
//4. Create a level option