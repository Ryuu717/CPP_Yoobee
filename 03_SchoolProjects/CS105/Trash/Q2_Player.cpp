#include <iostream>
#include <vector>

using namespace std;

class Player {
    public:
        string name;
        int race;
        int hitPoints;
        int magicPoints;
        int playerType;

    // constructor
    Player (string n = "name", string  r = "race", int hp = 100, int mp = 100, int pt = 0){
        n = name;
        r = race;
        hp = hitPoints;
        mp = magicPoints;
        pt = playerType;
    }

    // method
    void setter(){
        cout << "  Player type (1.Warrior, 2.Priest, 3.Mage): ";
        cin >> playerType;
        cout << "  Race (1.Human, 2.Elf, 3.Dwarf, 4.Orc, 5.Troll): ";
        cin >> race;
        cout << "  Name: ";
        cin >> name;
        cout << "\n";
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
    }

    void attack(){
        cout << "No attack method defined yet!\n";
    }
};

// Derived class
class Warrior: public Player {        
  public:
    int hitPoints = 200;
    int magicPoints = 0;

    void attack(){
        cout << "I will destroy you with my sword!\n";
    }
};

class Priest: public Player {
  public:
    int hitPoints = 100;
    int magicPoints = 200;

    void attack(){
        cout << "I will assault you with holy wrath!\n";
    }
};

class Mage: public Player {
  public:
    int hitPoints = 200;
    int magicPoints = 0;

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
    char answer = 'y';

    //get user input
    cout << "*******************************************\n";
    cout << "Welcome to the character creation\n";
    cout << "Enter player information\n";
    cout << "*******************************************\n";

    while (answer == 'y'){              //continue until user enter 'n'
        player.setter();
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
        int type = vectorPlayers[i].playerType;

        vectorPlayers[i].getter();

        switch (type){
        case 1:
            cout << "  Hit points: \t\t" << warrior.hitPoints << "\n";
            cout << "  Magic Points: \t" << warrior.magicPoints << "\n";
            cout << "  Attack: \t\t";
            warrior.attack();
            break;
        
        case 2:
            cout << "  Hit points: \t\t" << priest.hitPoints << "\n";
            cout << "  Magic Points: \t" << priest.magicPoints << "\n";
            cout << "  Attack: \t\t";
            priest.attack();
            break;

        case 3:
            cout << "  Hit points: \t\t" << mage.hitPoints << "\n";
            cout << "  Magic Points: \t" << mage.magicPoints << "\n";
            cout << "  Attack: \t\t";
            mage.attack();
            break;
        }
        cout << "\n";
    }

    return 0;
}