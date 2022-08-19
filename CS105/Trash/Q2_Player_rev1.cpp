#include <iostream>
#include <vector>

using namespace std;

class Player {
    // private:
    string name;
    int race;
    int hitPoints;
    int magicPoints;
    int playerType;

    public:
    // constructor
    Player (string n = "name", string  r = "race", int hp = 100, int mp = 100, int pt = 0){
        n = name;
        r = race;
        hp = hitPoints;
        mp = magicPoints;
        pt = playerType;
    }

    // method
    void setter(int pt, int r, string n, int hp, int mp){
        playerType = pt;
        race = r;
        name = n;
        hitPoints = hp;
        magicPoints = mp;
    }

    void getter(){
        cout << "  Name: \t\t" << name << "\n";
        switch (playerType){
            case 1:
                cout << "  Player type:\t\tWarrior\n";
                break;
            case 2:
                cout << "  Player type:\t\tPriest\n";
                break;
            case 3:
                cout << "  Player type:\t\tMage\n";
                break;
        };

        switch (race){
            case 1:
                cout << "  Race:\t\t\tHuman\n";
                break;
            case 2:
                cout << "  Race:\t\t\tElf\n";
                break;
            case 3:
                cout << "  Race:\t\t\tDwarf\n";
                break;
            case 4:
                cout << "  Race:\t\t\tOrc\n";
                break;
            case 5:
                cout << "  Race:\t\t\tTroll\n";
                break;
        };
        cout << "  Hit points: \t\t" << hitPoints << "\n";
        cout << "  Magic Points: \t" << magicPoints << "\n";
    }

    int getPlayerType(){
        return playerType;
    }

    void attack(){
        cout << "No attack method defined yet!\n";
    }
};

// Derived class
class Warrior: public Player {
    public:
    void attack(){
        cout << "I will destroy you with my sword!\n";
    }
};

class Priest: public Player {
    public:
    void attack(){
        cout << "I will assault you with holy wrath!\n";
    }
};

class Mage: public Player {
    public:
    void attack(){
        cout << "I will crush you with my arcane missiles!\n";
    }
};

int main(){
    Player player;                      //create object
    Warrior warrior;
    Priest priest;
    Mage mage;
    vector<Player> vectorPlayers;       //to store players
    char answer = 'y';                  //yes

    int playerType, race;
    string name;

    //get user input
    cout << "*******************************************\n";
    cout << "Welcome to the character creation\n";
    cout << "Enter player information\n";
    cout << "*******************************************\n";

    while (answer == 'y'){              //continue until user enter 'n'
        cout << "  Player type (1.Warrior, 2.Priest, 3.Mage): ";
        cin >> playerType;
        cout << "  Race (1.Human, 2.Elf, 3.Dwarf, 4.Orc, 5.Troll): ";
        cin >> race;
        cout << "  Name: ";
        cin >> name;
        cout << "\n";

        switch(playerType){
        case 1:
            player.setter(playerType, race, name, 200, 0);
            break;
        
        case 2:
            player.setter(playerType, race, name, 100, 200);
            break;

        case 3:
            player.setter(playerType, race, name, 200, 0);
            break;
        }

        vectorPlayers.push_back(player);
        cout << "------------------------------------\n";
        cout << "Do you want to continue? (y/n): ";
        cin >> answer;
        cout << "\n";
    }

    //show user input
    cout << "*******************************************\n";
    cout << "Result\n";
    cout << "*******************************************\n";

    for (int i = 0; i < vectorPlayers.size(); i++) {
        int type = vectorPlayers[i].getPlayerType();

        vectorPlayers[i].getter();

        switch (type){
        case 1:
            cout << "  Attack: \t\t";
            warrior.attack();
            break;
        
        case 2:
            cout << "  Attack: \t\t";
            priest.attack();
            break;

        case 3:
            cout << "  Attack: \t\t";
            mage.attack();
            break;
        }
        cout << "\n";
    }
    return 0;
}