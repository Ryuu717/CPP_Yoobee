#include <iostream>
#include "Player.h"
#include "Warrior.h"
#include "Priest.h"
#include "Mage.h"
#include <vector>
using namespace std;

//update hitPoints, magicPoints, attach()
// Warrior
Warrior::Warrior(int playerType = 1, string name = "Player", int race = 1, int hitPoints = 100, int magicPoints = 0) : Player(playerType, name, race, hitPoints, magicPoints) {     //Passing argument
}
string Warrior::attack() {
    return "I will destroy you with my sword!\n";
}
// Priest
Priest::Priest(int playerType = 1, string name = "Player", int race = 1, int hitPoints = 100, int magicPoints = 200) : Player(playerType, name, race, hitPoints, magicPoints) {
}
string Priest::attack() {
    return "I will assault you with holy wrath!\n";
}
// Mage
Mage::Mage(int playerType = 1, string name = "Player", int race = 1, int hitPoints = 200, int magicPoints = 0) : Player(playerType, name, race, hitPoints, magicPoints) {
}
string Mage::attack() {
    return "I will crush you with my arcane missiles!\n";
}

int main (){
    Player player;
    Warrior warrior;
    Priest priest;
    Mage mage;
    vector<Player> vectorPlayers;       //to store players
    char answer = 'y';                  //yes
    int playerType, race, hitPoints, magicPoints;
    string name;

    //get user input
    cout << "*******************************************\n";
    cout << "Welcome to the character creation\n";
    cout << "Enter player information\n";
    cout << "*******************************************\n";
    while (answer == 'y'){                          //continue until user enter 'n'
        cout << "  Player type (1.Warrior, 2.Priest, 3.Mage): ";
        cin >> playerType;
        cout << "  Race (1.Human, 2.Elf, 3.Dwarf, 4.Orc, 5.Troll): ";
        cin >> race;
        cout << "  Name: ";
        cin >> name;
        cout << "\n";

        switch(playerType){
        case 1:
            hitPoints = warrior.getHitPoints();
            magicPoints = warrior.getMagicPoints();
            break;
        case 2:
            hitPoints = priest.getHitPoints();
            magicPoints = priest.getMagicPoints();
            break;
        case 3:
            hitPoints = mage.getHitPoints();
            magicPoints = mage.getMagicPoints();
            break;
        }

        //set all user input
        player.setPlayerType(playerType);
        player.setName(name);
        player.setRace(race);
        player.setHitPoints(hitPoints);
        player.setMagicPoints(magicPoints);

        //store the player data into the vector
        vectorPlayers.push_back(player);

        //continue?
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
        cout << "Name:\t\t" << vectorPlayers[i].getName() << "\n";
        cout << "Race:\t\t" << vectorPlayers[i].getRace() << "\n";
        cout << "Type:\t\t" << vectorPlayers[i].getPlayerType() << "\n";
        cout << "Hit Points:\t" << vectorPlayers[i].getHitPoints() << "\n";
        cout << "Magic Points:\t" << vectorPlayers[i].getMagicPoints() << "\n";

        //change attack option depends on the player type
        if(vectorPlayers[i].getPlayerType() == "Warrior"){
            cout << "Attack:\t\t" << warrior.attack() << "\n\n";
        } else if(vectorPlayers[i].getPlayerType() == "Priest") {
            cout << "Attack:\t\t" << priest.attack() << "\n\n";
        } else {
            cout << "Attack:\t\t" << mage.attack() << "\n\n";
        }
    }
    return 0;
}