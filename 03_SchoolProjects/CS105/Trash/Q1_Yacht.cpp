#include <iostream>
#include <vector>

using namespace std;

// class
class Yacht {
    public:                     //access specifiers
    int serialNumber;
    static int yachtNumber;     //common variable for each yacht

    int latitudeDegrees;
    float latitudeMinutes;
    char latitudeDirection;

    int longitudeDegrees;
    float longitudeMinutes;
    char longitudeDirection;

    // constructor
    Yacht (int sn = 0, int lad = 0, float lam = 0, char ladi = '-', int lod = 0, float lom = 0, char lodi = '-'){
        sn = serialNumber;
        lad = latitudeDegrees;
        lam = latitudeMinutes;
        ladi = latitudeDirection;
        lod = longitudeDegrees;
        lom = longitudeMinutes;
        lodi = longitudeDirection;
    };

    void getPosition(){
        cout << "  Serial number(e.g. 000001): ";
        cin >> serialNumber;
        cout << "  -Latitude-\n";
        cout << "    Degrees(0-180): ";
        cin >> latitudeDegrees;
        cout << "    Minutes(0-60): ";
        cin >> latitudeMinutes;
        cout << "    Direction(N,S): ";
        cin >> latitudeDirection;

        cout << "  -Longitude-\n";
        cout << "    Degrees(0-180): ";
        cin >> longitudeDegrees;
        cout << "    Minutes(0-60): ";
        cin >> longitudeMinutes;
        cout << "    Direction(E,W): ";
        cin >> longitudeDirection;
        cout << "\n";
    }

    void display(){
        cout << "  Serial number: \t" << serialNumber << "\n";
        cout << "  Location:\n";
        cout << "     Latitude: \t\t" << latitudeDegrees << "°" << latitudeMinutes << "'" << latitudeDirection << "\n";
        cout << "     Longitude: \t" << longitudeDegrees << "°" << longitudeMinutes << "'" << longitudeDirection << "\n";
        cout << "------------------------------------\n\n";
    } 
};

// definition for static variables
int Yacht::yachtNumber = 0;


int main(){
    Yacht yacht;                    //create object
    vector<Yacht> vectorYachts;     //create vector to store each yacht
    char answer = 'y';              //yes
    // int yachtNum = 0;

    //get user input
    cout << "*******************************************\n";
    cout << "Welcome to the Ocean Race 2021-22\n";
    cout << "Enter yacht information\n";
    cout << "*******************************************\n";

    while(answer == 'y'){                   //Repeat until no
        yacht.getPosition();                //get user input
        vectorYachts.push_back(yacht);      //store data
        cout << "------------------------------------\n";
        cout << "Do you want to continue? (y/n): ";
        cin >> answer;
        cout << "\n";

        yacht.yachtNumber++;                //count the number of yacht
    }

    //show user input
    cout << "*******************************************\n";
    cout << "Result\n";
    cout << "*******************************************\n";
    cout << yacht.yachtNumber << " yachts are registered\n\n"; 
    for (int i = 0; i < vectorYachts.size(); i++) {
        cout << "Yacht " << i + 1 << "\n";
        vectorYachts[i].display();              
    }

    return 0;
}