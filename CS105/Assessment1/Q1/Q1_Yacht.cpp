#include <iostream>
#include <vector>
using namespace std;

// class
class Yacht {
    // private:
    int serialNumber;
    static int yachtNumber;     //common variable for each yacht

    public:
    // constructor
    Yacht (int sn = 0){
        sn = serialNumber;
    };

    //methods
    void setPosition(int sn){
        serialNumber = sn;
    }
    int setYachtNumber(){
        return yachtNumber++;
    }
    int getYachtNumber(){
        return yachtNumber;
    }
    void display(){
        cout << "  Serial number: \t" << serialNumber << "\n";
    } 
};

class Location : public Yacht {         //inherit from Yacht class
    // private:
    int latitudeDegrees;
    float latitudeMinutes;
    char latitudeDirection;

    int longitudeDegrees;
    float longitudeMinutes;
    char longitudeDirection;

    public:
    // constructor
    Location (int lad = 0, float lam = 0, char ladi = '-', int lod = 0, float lom = 0, char lodi = '-'){
        lad = latitudeDegrees;
        lam = latitudeMinutes;
        ladi = latitudeDirection;
        lod = longitudeDegrees;
        lom = longitudeMinutes;
        lodi = longitudeDirection;
    };

    void setPosition(int lad, float lam, char ladi, int lod, float lom, char lodi){
        latitudeDegrees = lad;
        latitudeMinutes = lam;
        latitudeDirection = ladi;
        longitudeDegrees = lod;
        longitudeMinutes = lom;
        longitudeDirection = lodi;
    }

    void display(){
        cout << "  Location:\n";
        cout << "     Latitude: \t\t" << latitudeDegrees << "°" << latitudeMinutes << "'" << latitudeDirection << "\n";
        cout << "     Longitude: \t" << longitudeDegrees << "°" << longitudeMinutes << "'" << longitudeDirection << "\n";
        cout << "------------------------------------\n\n";
    } 

};

// definition for static variables
int Yacht::yachtNumber = 0;


int main(){
    Yacht yacht;                            //create object
    Location location;
    vector<Yacht> vectorYachts;             //create vector to store each yacht
    vector<Location> vectorLocations;       //create vector to store each yacht
    char answer = 'y';                      //yes

    int sn, lad, lod;
    float lam, lom;
    char ladi, lodi;

    //get user input
    cout << "*******************************************\n";
    cout << "Welcome to the Ocean Race 2021-22\n";
    cout << "Enter yacht information\n";
    cout << "*******************************************\n";

    while(answer == 'y'){                           //Repeat until no
        cout << "  Serial number: ";
        cin >> sn;
        cout << "  -Latitude-\n";
        cout << "    Degrees(0-180): ";
        cin >> lad;
        cout << "    Minutes(0-60): ";
        cin >> lam;
        cout << "    Direction(N,S): ";
        cin >> ladi;

        cout << "  -Longitude-\n";
        cout << "    Degrees(0-180): ";
        cin >> lod;
        cout << "    Minutes(0-60): ";
        cin >> lom;
        cout << "    Direction(E,W): ";
        cin >> lodi;
        cout << "\n";

        //set user input
        yacht.setPosition(sn);                                  
        location.setPosition(lad, lam, ladi, lod, lom, lodi);

        //store data
        vectorYachts.push_back(yacht);
        vectorLocations.push_back(location);

        //count yacht number
        yacht.setYachtNumber(); 

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
    cout << yacht.getYachtNumber() << " yachts are registered\n\n"; 
    for (int i = 0; i < vectorYachts.size(); i++) {
        cout << "Yacht " << i + 1 << "\n";
        vectorYachts[i].display();          //display serialNumber
        vectorLocations[i].display();       //display location
    }

    return 0;
}