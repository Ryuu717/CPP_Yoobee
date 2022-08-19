#include <string>
using namespace std;

class Player{
// private:
    int playerType;
    string name;
    int race;
    int hitPoints;
    int magicPoints;
    

public:
    //constructor
    Player(int playerType = 1, string name = "Player", int race = 1, int hitPoints = 0, int magicPoints = 0){
        this->name = name;
        this->race = race;
        this->hitPoints = hitPoints;
        this->magicPoints = magicPoints;
        this->playerType = playerType;
    }

    //setter
    void setPlayerType(int playerType)  {
    this->playerType = playerType;
    }
    void setName(string name) {
        this->name = name;
    }
    void setRace(int race)  {
        this->race = race;
    }
    void setHitPoints(int hitPoints)  {
        this->hitPoints = hitPoints;
    }
    void setMagicPoints(int magicPoints)  {
        this->magicPoints = magicPoints;
    }

    //getter
    string getPlayerType() {
        switch (playerType){
            case 1:
                return "Warrior";
                break;
            case 2:
                return "Priest";
                break;
            case 3:
                return "Mage";
                break;
        };
        return 0;
    }
    string getName()  {
        return name;
    }
    string getRace()  {
        switch (race){
            case 1:
                return "Human";
                break;
            case 2:
                return "Elf";
                break;
            case 3:
                return "Dwarf";
                break;
            case 4:
                return "Orc";
                break;
            case 5:
                return "Troll";
                break;
        };
        return 0;
    }
    int getHitPoints() {
        return hitPoints;
    }
    int getMagicPoints()  {
        return magicPoints;   
    }
    string attack() {
        return "No attack method defined yet!\n";
    }
};
