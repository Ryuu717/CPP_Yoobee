#include <iostream>
#include <vector>
using namespace std;

class MinistryOfHealth{
// private:
    string LOI;
    int date;

public:
    //constructor
    MinistryOfHealth(string l = " ", int d = 0){
        LOI = l;
        date = d;
    }

    void setData(){
        cout << "Enter the location: ";
        cin >> LOI;
        cout << "Enter the date: ";
        cin >> date;
    }
    void display(){
        cout << "LOI: " << LOI << "\n";
        cout << "Date: " << date << "\n";
    }
};


//Normal (without pointer)
// int main(){
//     MinistryOfHealth mPtr[3];
//     MinistryOfHealth m;

//     for(int i = 0; i < 3; i++){
//         m.setData();
//         mPtr[i] = m;
//     }

//     //output
//     for(int i=0; i<3; i++){
//         mPtr[i].display();
//     }

//     return 0;
// }

//with Pointer
int main(){
    MinistryOfHealth* mPtr[100];
    int n = 0;
    char isContinue = 'y'; 

    while(isContinue == 'y'){
        //New object
        mPtr[n] = new MinistryOfHealth(); // using New
        mPtr[n]->setData();
        n++; 
        
        cout << " Do you want to continue?(y / n)\n"; 
        cin >> isContinue; 
    } 


    //output
    for(int i=0; i<3; i++){
        mPtr[i]->display();
    }


    return 0;
}