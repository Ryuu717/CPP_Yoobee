#include <iostream>
using namespace std;


//define the structure
struct Soccer {
    int player_number;
    float top_speed;
    char position_type;

    //Constructor
    Soccer(int num = 0, float speed = 0, char position_type = ' ') {
        player_number = num;
        top_speed = speed;
        position_type = ' ';
    }
};


//funtion prototypes
void input();
void output(struct Soccer soccer[2]);


//main
int main() {
    
    //call input function
    input();

    return 0;
}


//output function (argument = array) 
void output(struct Soccer soccer[2]){
    cout << "=============================================================";

    //Output details of two players
    for(int i = 0; i < 2; i++){
        cout << "\nInformation of player " << i + 1;
        cout << "\n\tPlayer number : \t" << soccer[i].player_number;
        cout << "\n\tTop speed : \t\t" << soccer[i].top_speed << " mph";

        //Convert from initials to whole letters
        switch (soccer[i].position_type){
            case 'g':
                cout << "\n\tPosition type : \t" << "Goalkeeper\n";
                break;
            case 'm':
                cout << "\n\tPosition type : \t" << "Midfielder\n";
                break;
            case 's':
                cout << "\n\tPosition type : \t" << "Striker\n";
                break;
            case 'w':
                cout << "\n\tPosition type : \t" << "Winger\n";
                break;
            case 'd':
                cout << "\n\tPosition type : \t" << "Defender\n";
                break;
        }
    }
    cout << "=============================================================\n";
}


//Input function
void input(){
    //create instance
    struct Soccer soccer[2];

    //input form for two players
    for (int i = 0; i < 2; i++){
        cout << "\nEnter the information of player " << i + 1 << "\n";
        cout << " Player number : ";
        cin >> soccer[i].player_number;
        cout << " Top speed(mph) : ";
        cin >> soccer[i].top_speed;
        cout << " Position type";
        cout << "\n\tg = goalkeeper, \n\tm = midfielder, \n\ts = striker, \n\tw = winger, \n\td = defender\n \t\t\t: ";
        cin >> soccer[i].position_type;
        cout << "\n";
    }

    //call output (argument = array)
    output(soccer);
}



//Memo
//1. Need to add comment ✔️
//2. Need to add validation